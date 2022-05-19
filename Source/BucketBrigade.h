#pragma once 
#include<JuceHeader.h> 
 
#include <math.h> 
 
class Distorsion { 
public: 
 Distorsion() {}; 
 ~Distorsion() {}; 
 
 void static getNextAudioBlock(AudioBuffer<float>& buffer, const int numSamples) { 
  const int numCh = buffer.getNumChannels(); 
  auto bufferData = buffer.getArrayOfWritePointers(); 
 
  for (int smp = 0; smp < numSamples; ++smp) { 
   for (auto ch = 0; ch < numCh; ++ch) { 
    bufferData[ch][smp] = computeSample(bufferData[ch][smp]); 
   } 
  } 
 } 
 
 float static computeSample(float x) { 
  if (x > 0) 
   return 1 - exp(-x); 
  else 
   return -1 + exp(x); 
 } 
}; 
 
 
class OnePole { 
public: 
 OnePole() { a0 = 1.0; b1 = 0.0; z1 = 0.0; }; 
 OnePole(double Fc) { z1 = 0.0; setFc(Fc); }; 
 ~OnePole(); 
 
 void getNextAudioBlock(AudioBuffer<float>& buffer, const int numSamples, int ch) { 
  a0 = 1.0; b1 = 0.0; z1 = 0.0; 
  setFc(2000); 
 
 
  const int numCh = buffer.getNumChannels(); 
  auto bufferData = buffer.getArrayOfWritePointers(); 
 
   for (int smp = 0; smp < numSamples; ++smp) { 
    bufferData[ch][smp] = process(bufferData[ch][smp]); 
   } 
 } 
 
 void setFc(double Fc) { 
  b1 = exp(-2.0 * MathConstants<float>::pi * Fc); 
  a0 = 1.0 - b1; 
 } 
 float process(float in) { 
  return z1 = in * a0 + z1 * b1; 
 } 
 
 
protected: 
 double a0, b1, z1; 
};