#pragma once 
#include<JuceHeader.h> 
 
#include <math.h> 

#include "Parameters.h"
 
class Distorsion { 
public: 
    Distorsion() {}; 
    ~Distorsion() {};
    float static getNextAudioSample(float sample) { 
        return (2.f / MathConstants<float>::pi) * atan(DISTORTION_ALPHA * sample);
        /*
        * Implementazione del paper semplice
        auto a = 1 / 8;
        auto b = 1 / 18;
        if (sample > 1) {
            return 1 - a - b;
        }
        else if (sample < 1 && sample > -1) {
            return sample - a * pow(sample, 2) - b * pow(sample, 3) + a;
        }
        else {
            return -1 - a + b;
        }
        */
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