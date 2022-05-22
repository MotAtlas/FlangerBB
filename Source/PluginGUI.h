/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.1.6

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginGUI  : public juce::AudioProcessorEditor,
                   public juce::Slider::Listener
{
public:
    //==============================================================================
    PluginGUI (DelayFXAudioProcessor& p, AudioProcessorValueTreeState& vts);
    ~PluginGUI() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> juce__groupComponent3;
    std::unique_ptr<juce::GroupComponent> juce__groupComponent2;
    std::unique_ptr<juce::GroupComponent> juce__groupComponent;
    std::unique_ptr<juce::Slider> rateSlider;
    std::unique_ptr<juce::Slider> wfSlider;
    std::unique_ptr<juce::Slider> phaseSlider;
    std::unique_ptr<juce::Slider> rateSlider2;
    std::unique_ptr<juce::Slider> wfSlider2;
    std::unique_ptr<juce::Slider> phaseSlider2;
    std::unique_ptr<juce::Slider> amtSlider;
    std::unique_ptr<juce::ToggleButton> lfo2OnButton;
    std::unique_ptr<juce::Slider> fbSlider;
    std::unique_ptr<juce::Slider> dwSlider;
    std::unique_ptr<juce::TextEditor> juce__textEditor2;
    std::unique_ptr<juce::TextEditor> juce__textEditor3;
    std::unique_ptr<juce::TextEditor> juce__textEditor4;
    std::unique_ptr<juce::TextEditor> juce__textEditor6;
    std::unique_ptr<juce::TextEditor> juce__textEditor7;
    std::unique_ptr<juce::TextEditor> juce__textEditor8;
    std::unique_ptr<juce::TextEditor> juce__textEditor9;
    std::unique_ptr<juce::TextEditor> juce__textEditor10;
    std::unique_ptr<juce::Slider> timeSlider;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginGUI)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

