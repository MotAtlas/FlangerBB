#pragma once 
#include<JuceHeader.h> 
 
#include <math.h> 

#include "Parameters.h"
 
class Distorsion { 
public: 
    Distorsion() {}; 
    ~Distorsion() {};
    float static getNextAudioSample(float sample) { 
        //return (2.f / MathConstants<float>::pi) * atan(DISTORTION_ALPHA * sample);
        
        // Implementazione del paper semplice
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
        
    } 
}; 
 
 
class LowPass { 
public: 
    LowPass() {};
    ~LowPass();
    
    /*
    void preapareToPlay(float sampleRate, float cutoffFrequency, float Q) { 
        sr = sampleRate;
        setBiquad(cutoffFrequency, Q);
    }
    
    void setBiquad(float cutoffFrequency, float Q) {
        this->Q = Q;
        this->Fc = cutoffFrequency;
        calcBiquad();
    }

    void setFc(double cutFrequency) {
        Fc = cutFrequency / sr;
        calcBiquad();
    }

    void calcBiquad() {
        double norm;
        double K = tan(MathConstants<float>::pi * Fc);
        norm = 1 / (1 + K / Q + K * K);
        a0 = K * K * norm;
        a1 = 2 * a0;
        a2 = a0;
        b1 = 2 * (K * K - 1) * norm;
        b2 = (1 - K / Q + K * K) * norm;
    }
    */

    float getNextAudioSample(float in) {
        double out = in * a0 + z1;
        z1 = in * a1 + z2 - b1 * out;
        z2 = in * a2 - b2 * out;
        return out;
    }

protected: 
    float a0 = 0.08132510149151759f;
    float a1 = 0.16265020298303517f;
    float a2 = 0.08132510149151759f;
    float b1 = -1.0123320751226288f;
    float b2 = 0.33763248108869903f;

    /*
    float sr = 44100;
    float Fc = 0.50f;
    float Q = 2.62f;
    float peakGain = 0.0f;
    */

    float z1 = 0.0f;
    float z2 = 0.0f;

};