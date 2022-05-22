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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginGUI::PluginGUI (DelayFXAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), valueTreeState (vts)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__groupComponent3.reset (new juce::GroupComponent ("new group",
                                                           TRANS("LFO2")));
    addAndMakeVisible (juce__groupComponent3.get());

    juce__groupComponent3->setBounds (48, 336, 560, 200);

    juce__groupComponent2.reset (new juce::GroupComponent ("new group",
                                                           TRANS("LFO1")));
    addAndMakeVisible (juce__groupComponent2.get());

    juce__groupComponent2->setBounds (48, 80, 560, 200);

    juce__groupComponent.reset (new juce::GroupComponent ("new group",
                                                          TRANS("Delay modulation")));
    addAndMakeVisible (juce__groupComponent.get());
    juce__groupComponent->setTextLabelPosition (juce::Justification::centred);

    juce__groupComponent->setBounds (16, 24, 768, 560);

    rateSlider.reset (new juce::Slider ("Mod freq (Hz) LFO1"));
    addAndMakeVisible (rateSlider.get());
    rateSlider->setRange (0, 10, 0);
    rateSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    rateSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    rateSlider->setBounds (48, 96, 160, 152);

    wfSlider.reset (new juce::Slider ("Shape LFO1"));
    addAndMakeVisible (wfSlider.get());
    wfSlider->setRange (0, 10, 0);
    wfSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    wfSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    wfSlider->setBounds (232, 96, 160, 152);

    phaseSlider.reset (new juce::Slider ("L/R Phase LFO1"));
    addAndMakeVisible (phaseSlider.get());
    phaseSlider->setRange (0, 10, 0);
    phaseSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    phaseSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    phaseSlider->setBounds (424, 96, 160, 152);

    rateSlider2.reset (new juce::Slider ("Mod freq (Hz) LFO2"));
    addAndMakeVisible (rateSlider2.get());
    rateSlider2->setRange (0, 10, 0);
    rateSlider2->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    rateSlider2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    rateSlider2->setBounds (50, 360, 160, 152);

    wfSlider2.reset (new juce::Slider ("Shape LFO2"));
    addAndMakeVisible (wfSlider2.get());
    wfSlider2->setRange (0, 10, 0);
    wfSlider2->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    wfSlider2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    wfSlider2->setBounds (234, 360, 160, 152);

    phaseSlider2.reset (new juce::Slider ("L/R Phase LFO2"));
    addAndMakeVisible (phaseSlider2.get());
    phaseSlider2->setRange (0, 10, 0);
    phaseSlider2->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    phaseSlider2->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);

    phaseSlider2->setBounds (426, 360, 160, 152);

    amtSlider.reset (new juce::Slider ("Mod depth"));
    addAndMakeVisible (amtSlider.get());
    amtSlider->setRange (0, 10, 0);
    amtSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    amtSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    amtSlider->addListener (this);

    amtSlider->setBounds (616, 216, 160, 152);

    lfo2OnButton.reset (new juce::ToggleButton ("On LFO2"));
    addAndMakeVisible (lfo2OnButton.get());
    lfo2OnButton->setButtonText (TRANS("ON"));

    lfo2OnButton->setBounds (664, 432, 72, 24);

    fbSlider.reset (new juce::Slider ("Feedback"));
    addAndMakeVisible (fbSlider.get());
    fbSlider->setRange (0, 10, 0);
    fbSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    fbSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    fbSlider->addListener (this);

    fbSlider->setBounds (808, 368, 160, 152);

    dwSlider.reset (new juce::Slider ("Dry/Wet"));
    addAndMakeVisible (dwSlider.get());
    dwSlider->setRange (0, 10, 0);
    dwSlider->setSliderStyle (juce::Slider::LinearVertical);
    dwSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    dwSlider->addListener (this);

    dwSlider->setBounds (976, 112, 112, 408);

    juce__textEditor2.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (juce__textEditor2.get());
    juce__textEditor2->setMultiLine (false);
    juce__textEditor2->setReturnKeyStartsNewLine (false);
    juce__textEditor2->setReadOnly (false);
    juce__textEditor2->setScrollbarsShown (true);
    juce__textEditor2->setCaretVisible (true);
    juce__textEditor2->setPopupMenuEnabled (true);
    juce__textEditor2->setText (TRANS("Frequency"));

    juce__textEditor2->setBounds (96, 296, 72, 24);

    juce__textEditor3.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (juce__textEditor3.get());
    juce__textEditor3->setMultiLine (false);
    juce__textEditor3->setReturnKeyStartsNewLine (false);
    juce__textEditor3->setReadOnly (false);
    juce__textEditor3->setScrollbarsShown (true);
    juce__textEditor3->setCaretVisible (true);
    juce__textEditor3->setPopupMenuEnabled (true);
    juce__textEditor3->setText (TRANS("Shape"));

    juce__textEditor3->setBounds (288, 296, 48, 24);

    juce__textEditor4.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (juce__textEditor4.get());
    juce__textEditor4->setMultiLine (false);
    juce__textEditor4->setReturnKeyStartsNewLine (false);
    juce__textEditor4->setReadOnly (false);
    juce__textEditor4->setScrollbarsShown (true);
    juce__textEditor4->setCaretVisible (true);
    juce__textEditor4->setPopupMenuEnabled (true);
    juce__textEditor4->setText (TRANS("L/R Phase"));

    juce__textEditor4->setBounds (472, 296, 72, 24);

    juce__textEditor6.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (juce__textEditor6.get());
    juce__textEditor6->setMultiLine (false);
    juce__textEditor6->setReturnKeyStartsNewLine (false);
    juce__textEditor6->setReadOnly (false);
    juce__textEditor6->setScrollbarsShown (true);
    juce__textEditor6->setCaretVisible (true);
    juce__textEditor6->setPopupMenuEnabled (true);
    juce__textEditor6->setText (TRANS("Depth"));

    juce__textEditor6->setBounds (672, 168, 48, 24);

    juce__textEditor7.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (juce__textEditor7.get());
    juce__textEditor7->setMultiLine (false);
    juce__textEditor7->setReturnKeyStartsNewLine (false);
    juce__textEditor7->setReadOnly (false);
    juce__textEditor7->setScrollbarsShown (true);
    juce__textEditor7->setCaretVisible (true);
    juce__textEditor7->setPopupMenuEnabled (true);
    juce__textEditor7->setText (TRANS("Delay time"));

    juce__textEditor7->setBounds (848, 72, 72, 24);

    juce__textEditor8.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (juce__textEditor8.get());
    juce__textEditor8->setMultiLine (false);
    juce__textEditor8->setReturnKeyStartsNewLine (false);
    juce__textEditor8->setReadOnly (false);
    juce__textEditor8->setScrollbarsShown (true);
    juce__textEditor8->setCaretVisible (true);
    juce__textEditor8->setPopupMenuEnabled (true);
    juce__textEditor8->setText (TRANS("Feedback"));

    juce__textEditor8->setBounds (856, 328, 64, 24);

    juce__textEditor9.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (juce__textEditor9.get());
    juce__textEditor9->setMultiLine (false);
    juce__textEditor9->setReturnKeyStartsNewLine (false);
    juce__textEditor9->setReadOnly (false);
    juce__textEditor9->setScrollbarsShown (true);
    juce__textEditor9->setCaretVisible (true);
    juce__textEditor9->setPopupMenuEnabled (true);
    juce__textEditor9->setText (TRANS("D/W"));

    juce__textEditor9->setBounds (1008, 72, 40, 24);

    juce__textEditor10.reset (new juce::TextEditor ("new text editor"));
    addAndMakeVisible (juce__textEditor10.get());
    juce__textEditor10->setMultiLine (false);
    juce__textEditor10->setReturnKeyStartsNewLine (false);
    juce__textEditor10->setReadOnly (false);
    juce__textEditor10->setScrollbarsShown (true);
    juce__textEditor10->setCaretVisible (true);
    juce__textEditor10->setPopupMenuEnabled (true);
    juce__textEditor10->setText (TRANS("Meter"));

    juce__textEditor10->setBounds (1112, 72, 40, 24);

    timeSlider.reset (new juce::Slider ("Delay time (s)"));
    addAndMakeVisible (timeSlider.get());
    timeSlider->setRange (0, 10, 0);
    timeSlider->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    timeSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    timeSlider->addListener (this);

    timeSlider->setBounds (808, 112, 160, 152);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1200, 600);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginGUI::~PluginGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__groupComponent3 = nullptr;
    juce__groupComponent2 = nullptr;
    juce__groupComponent = nullptr;
    rateSlider = nullptr;
    wfSlider = nullptr;
    phaseSlider = nullptr;
    rateSlider2 = nullptr;
    wfSlider2 = nullptr;
    phaseSlider2 = nullptr;
    amtSlider = nullptr;
    lfo2OnButton = nullptr;
    fbSlider = nullptr;
    dwSlider = nullptr;
    juce__textEditor2 = nullptr;
    juce__textEditor3 = nullptr;
    juce__textEditor4 = nullptr;
    juce__textEditor6 = nullptr;
    juce__textEditor7 = nullptr;
    juce__textEditor8 = nullptr;
    juce__textEditor9 = nullptr;
    juce__textEditor10 = nullptr;
    timeSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginGUI::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginGUI::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == amtSlider.get())
    {
        //[UserSliderCode_amtSlider] -- add your slider handling code here..
        //[/UserSliderCode_amtSlider]
    }
    else if (sliderThatWasMoved == fbSlider.get())
    {
        //[UserSliderCode_fbSlider] -- add your slider handling code here..
        //[/UserSliderCode_fbSlider]
    }
    else if (sliderThatWasMoved == dwSlider.get())
    {
        //[UserSliderCode_dwSlider] -- add your slider handling code here..
        //[/UserSliderCode_dwSlider]
    }
    else if (sliderThatWasMoved == timeSlider.get())
    {
        //[UserSliderCode_timeSlider] -- add your slider handling code here..
        //[/UserSliderCode_timeSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginGUI" componentName=""
                 parentClasses="public juce::AudioProcessorEditor" constructorParams="DelayFXAudioProcessor&amp; p, AudioProcessorValueTreeState&amp; vts"
                 variableInitialisers="AudioProcessorEditor (&amp;p), processor (p), valueTreeState (vts)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1200" initialHeight="600">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GROUPCOMPONENT name="new group" id="bb2cb5266f7faaad" memberName="juce__groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="48 336 560 200" title="LFO2"/>
  <GROUPCOMPONENT name="new group" id="b8af616ff5f40cc4" memberName="juce__groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="48 80 560 200" title="LFO1"/>
  <GROUPCOMPONENT name="new group" id="e093e204ef00402b" memberName="juce__groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="16 24 768 560" title="Delay modulation"
                  textpos="36"/>
  <SLIDER name="Mod freq (Hz) LFO1" id="aa1dda72e638725d" memberName="rateSlider"
          virtualName="" explicitFocusOrder="0" pos="48 96 160 152" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="Shape LFO1" id="1ecb7129858aefc1" memberName="wfSlider"
          virtualName="" explicitFocusOrder="0" pos="232 96 160 152" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="L/R Phase LFO1" id="19045bd58794380c" memberName="phaseSlider"
          virtualName="" explicitFocusOrder="0" pos="424 96 160 152" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="Mod freq (Hz) LFO2" id="8bc8192d6342544d" memberName="rateSlider2"
          virtualName="" explicitFocusOrder="0" pos="50 360 160 152" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="Shape LFO2" id="1b13644ab7bd8168" memberName="wfSlider2"
          virtualName="" explicitFocusOrder="0" pos="234 360 160 152" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="L/R Phase LFO2" id="69bc1dbfb6dc7e34" memberName="phaseSlider2"
          virtualName="" explicitFocusOrder="0" pos="426 360 160 152" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="0"/>
  <SLIDER name="Mod depth" id="8be73b5bc1b476e0" memberName="amtSlider"
          virtualName="" explicitFocusOrder="0" pos="616 216 160 152" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TOGGLEBUTTON name="On LFO2" id="a4a687803607df44" memberName="lfo2OnButton"
                virtualName="" explicitFocusOrder="0" pos="664 432 72 24" buttonText="ON"
                connectedEdges="0" needsCallback="0" radioGroupId="0" state="0"/>
  <SLIDER name="Feedback" id="448874b3f13c1169" memberName="fbSlider" virtualName=""
          explicitFocusOrder="0" pos="808 368 160 152" min="0.0" max="10.0"
          int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Dry/Wet" id="bdce1e72a4f81fb2" memberName="dwSlider" virtualName=""
          explicitFocusOrder="0" pos="976 112 112 408" min="0.0" max="10.0"
          int="0.0" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <TEXTEDITOR name="new text editor" id="68a8f8c8fa3d4a2d" memberName="juce__textEditor2"
              virtualName="" explicitFocusOrder="0" pos="96 296 72 24" initialText="Frequency"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="a85c7a57c7eef64" memberName="juce__textEditor3"
              virtualName="" explicitFocusOrder="0" pos="288 296 48 24" initialText="Shape"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="5e7d11c49101953c" memberName="juce__textEditor4"
              virtualName="" explicitFocusOrder="0" pos="472 296 72 24" initialText="L/R Phase"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="d97a74ffdbb9e536" memberName="juce__textEditor6"
              virtualName="" explicitFocusOrder="0" pos="672 168 48 24" initialText="Depth"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="9cf1a43b3738a566" memberName="juce__textEditor7"
              virtualName="" explicitFocusOrder="0" pos="848 72 72 24" initialText="Delay time"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="884e0ca5484d86db" memberName="juce__textEditor8"
              virtualName="" explicitFocusOrder="0" pos="856 328 64 24" initialText="Feedback"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="fca7633baf6d2c9b" memberName="juce__textEditor9"
              virtualName="" explicitFocusOrder="0" pos="1008 72 40 24" initialText="D/W"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="e486dfd715dd52d0" memberName="juce__textEditor10"
              virtualName="" explicitFocusOrder="0" pos="1112 72 40 24" initialText="Meter"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <SLIDER name="Delay time (s)" id="b982841b6536abfe" memberName="timeSlider"
          virtualName="" explicitFocusOrder="0" pos="808 112 160 152" min="0.0"
          max="10.0" int="0.0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

