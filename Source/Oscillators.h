#pragma once
#include <JuceHeader.h>
#include "Parameters.h"

class NaiveOscillator
{
public:
	NaiveOscillator() {};
	~NaiveOscillator() {};

	void prepareToPlay(double sr)
	{
		samplePeriod = 1.0 / sr;
		frequency.reset(sr, GLIDE_TIME);
		phaseDelta.reset(sr, PH_SMOOTHING);
	}

	void setFrequency(float newValue)
	{
		frequency.setTargetValue(newValue);
	}

	void setWaveform(float newValue)
	{
		waveform = roundToInt(newValue);
	}

	void setPhaseDelta(float newValue)
	{
		phaseDelta.setTargetValue(newValue);
	}

	void setChannelPhaseDelta(float delta) 
	{
		for (int ch = 0; ch < JucePlugin_MaxNumInputChannels; ch++)
		{
			if (delta >= 0 && ((ch % 2) == 0)) 
			{
				channelPhaseOffset[ch] = delta;
			}

			if (delta <= 0 && !((ch % 2) == 0)) 
			{
				channelPhaseOffset[ch] = delta;
			}
		}
	}

	void getNextAudioBlock(AudioBuffer<float>& buffer, const int numSamples)
	{
		const int numCh = buffer.getNumChannels();
		auto bufferData = buffer.getArrayOfWritePointers();

		for (int smp = 0; smp < numSamples; ++smp)
		{
			auto nextFrequency = frequency.getNextValue();
			setChannelPhaseDelta(phaseDelta.getNextValue());
			for (int ch = 0; ch < numCh; ++ch) 
			{
				bufferData[ch][smp] = getNextAudioSample(currentPhase[ch], nextFrequency, channelPhaseOffset[ch]);
			}	
		}
	}

	float getNextAudioSample(float &phase, float nextFrequency, float delta = 0.0f)
	{
		auto sampleValue = 0.0f;
		auto offsettedPhase = phase + delta;
		offsettedPhase -= static_cast<int>(offsettedPhase);

		switch (waveform)
		{
		case 0: // Sine
			sampleValue = sin(MathConstants<float>::twoPi * offsettedPhase);
			break;
		case 1: // Triangular
			sampleValue = 4.0f * abs(offsettedPhase - 0.5f) - 1.0f;
			break;
		case 2: // Saw up
			sampleValue = 2.0f * offsettedPhase - 1.0f;
			break;
		case 3: // Saw down
			sampleValue = -2.0f * offsettedPhase - 1.0f;
			break;
		default:
			break;
		}

		//phaseIncrement = frequency.isSmoothing() ? frequency.getNextValue() * samplePeriod : phaseIncrement;
		phaseIncrement = nextFrequency * samplePeriod;
		phase += phaseIncrement;
		phase -= static_cast<int>(phase);

		return sampleValue;
	}

private:

	int waveform = 0; // Un enum sarebbe stato meglio, ma per ora teniamo le cose semplici

	double samplePeriod = 1.0;
	float currentPhase[JucePlugin_MaxNumInputChannels] = {0.0f, 0.0f};
	float channelPhaseOffset[JucePlugin_MaxNumInputChannels] = { 0.0f, 0.0f };
	float phaseIncrement = 0.0f;
	SmoothedValue<float, ValueSmoothingTypes::Linear> phaseDelta;
	SmoothedValue<float, ValueSmoothingTypes::Multiplicative> frequency;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NaiveOscillator)
};

class ParametrModulation
{
public:
	ParametrModulation() {}
	~ParametrModulation() {}

	void prepareToPlay(double sr)
	{
		parameter.reset(sr, SMOOTHING_TIME);
		modAmount.reset(sr, SMOOTHING_TIME);
	}

	void setParameter(float newValue)
	{
		parameter.setTargetValue(newValue);
	}

	void setModAmount(float newValue)
	{
		modAmount.setTargetValue(newValue);
	}

	void processBlock(AudioBuffer<float>& buffer, const int numSamples)
	{
		auto bufferData = buffer.getArrayOfWritePointers();
		auto numCh = buffer.getNumChannels();

		// Scalo la modulante tra 0 e 1
		for (int ch = 0; ch < numCh; ++ch)
		{
			FloatVectorOperations::add(bufferData[ch], 1.0, numSamples);
			FloatVectorOperations::multiply(bufferData[ch], 0.5f, numSamples);
		}

		// Scalo la modulante tra 0 e la modulaziuone massima desiderata
		modAmount.applyGain(buffer, numSamples);

		// Sommo alla modulante il tempo di delay proveniente dal parametro
		if (parameter.isSmoothing())
			for (int smp = 0; smp < numSamples; ++smp)
			{
				const auto param = parameter.getNextValue();

				for (int ch = 0; ch < numCh; ++ch)
					bufferData[ch][smp] += param;
			}
		else
			for (int ch = 0; ch < numCh; ++ch)
				FloatVectorOperations::add(bufferData[ch], parameter.getCurrentValue(), numSamples);

		// Controllo di essere dentro al tempo di delay massimo
		for (int ch = 0; ch < numCh; ++ch)
			FloatVectorOperations::min(bufferData[ch], bufferData[ch], MAX_DELAY_TIME, numSamples);
		
	}

private:

	SmoothedValue<float, ValueSmoothingTypes::Linear> modAmount;
	SmoothedValue<float, ValueSmoothingTypes::Linear> parameter;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParametrModulation)

};