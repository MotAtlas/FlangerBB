#pragma once
#include <JuceHeader.h>

// Useful constants
#define MAX_DELAY_TIME 5.00f
#define TIME_SMOOTHING 0.02f
#define FBK_SMOOTHING  0.02f
#define PH_SMOOTHING 0.02f
#define FREQ_LFO2_SMOOTHING 0.2f

#define LEVEL_SMOOTHING_TIME 0.02f

#define GLIDE_TIME 0.01
#define SMOOTHING_TIME 0.04

#define DISTORTION_ALPHA 0.9f
#define BIQUAD_CUTOFF_FREQ 5000.0f
#define BIQUAD_Q 5.0f

// Actual parameters
#define NAME_DW "dw"
#define NAME_DT "dt"
#define NAME_FB "fb"
#define NAME_FREQ "lfoFreq"
#define NAME_PH_DELTA "lfoPhaseDelta"
#define NAME_FREQ_LFO2 "lfo2Freq"
#define NAME_MOD "timeMod"
#define NAME_WF "waveform"
#define NAME_LFO2_ON "lfo2On"

#define DEFAULT_DW 0.5f
#define DEFAULT_DT 0.5f
#define DEFAULT_FB 0.0f
#define DEFAULT_FREQ 1.0f
#define DEFAULT_PH_DELTA 0.0f
#define DEFAULT_FREQ_LFO2 0.0f
#define DEFAULT_MOD 0.0f
#define DEFAULT_WF 0

namespace Parameters
{
	static AudioProcessorValueTreeState::ParameterLayout createParameterLayout()
	{
		std::vector<std::unique_ptr<RangedAudioParameter>> params;

		params.push_back(std::make_unique<AudioParameterFloat>(NAME_DW, "Dry/Wet", 0.0f, 1.0f, DEFAULT_DW));
		params.push_back(std::make_unique<AudioParameterFloat>(NAME_FB, "Feedback", 0.0f, 1.0f, DEFAULT_FB));
		params.push_back(std::make_unique<AudioParameterFloat>(NAME_DT, "Delay time (s)", NormalisableRange<float>(0.0f, MAX_DELAY_TIME, 0.001f, 0.3f), DEFAULT_DT));
		params.push_back(std::make_unique<AudioParameterFloat>(NAME_FREQ, "LFO Freq (Hz)", NormalisableRange<float>(0.1f, 20.0f, 0.01f, 0.3f), DEFAULT_FREQ));
		params.push_back(std::make_unique<AudioParameterFloat>(NAME_PH_DELTA, "LFO channel phase delta", -1.0f, 1.0f, DEFAULT_PH_DELTA));
		params.push_back(std::make_unique<AudioParameterFloat>(NAME_MOD, "Mod amount (s)", NormalisableRange<float>(0.0f, MAX_DELAY_TIME / 2.0f, 0.001f), DEFAULT_MOD));
		params.push_back(std::make_unique<AudioParameterChoice>(NAME_WF, "LFO shape", StringArray{ "Sin", "Tri", "Saw up", "Saw down" }, DEFAULT_WF));
		params.push_back(std::make_unique<AudioParameterFloat>(NAME_FREQ_LFO2, "LFO2 Freq (Hz)", NormalisableRange<float>(0.1f, 20.0f, 0.01f, 0.3f), DEFAULT_FREQ_LFO2));
		params.push_back(std::make_unique<AudioParameterBool>(NAME_LFO2_ON, "LFO2 ON", 1));

		return {params.begin(), params.end()};
	}
}