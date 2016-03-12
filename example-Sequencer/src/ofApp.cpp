//
//  Part of ofxAVUI addon. Developed by Nuno Correia and Borut Kumperscak in 2016.
//  https://github.com/AVUIs/ofxAVUI
//

#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    //ENVIRONMENT AND MAXIMILIAN
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofBackground(0,0,0);
    sampleRate 	= 44100; /* Audio sampling rate */
    bufferSize	= 512; /* Audio buffer size */
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    
    ofColor bg(100,100,100,150);
    ofColor fg(0,255,255,255);
    
    //sequencing
    now = ofGetElapsedTimeMillis();
    delay = 1000;
    numSequencerSteps = 16;
    
    //UI positions and dimensions
    padBounds.x = 50;
    padBounds.y = 50;
    padBounds.width = 500;
    padBounds.height = 500;
    
    sequencerX = padBounds.x+padBounds.width+5;
    sequencerY = padBounds.y;
    sequencerW = 195;
    sequencerToggleH = 100;
    sequencerStepH = 20;
    
    //parameter names
    xParamName = "x";
    yParamName = "y";
    timerParamName = "timer";
    playbackParamName = "playback";
    filterSpeedParamName = "filter speed";
    resetParamName = "reset playback gesture";
    
    //ZONE SETUP
    //parameters: name, x, y, width, background color, foreground color, sound filename, sound buffer size
    //PAD
    zonePad.setup("padZone", padBounds.x, padBounds.y, padBounds.width, bg,fg, "synth.wav", bufferSize);
    zonePad.addParameterFloat(xParamName, 0.0, 1.0, 0.5);
    zonePad.addParameterFloat(yParamName, 0.0, 1.0, 0.5);
    zonePad.addUI(new ofxAVUIXYPad("Pad", "","", xParamName,yParamName), padBounds.height);
    
    //SEQUENCER
    //kick.wav = https://www.freesound.org/people/DWSD/sounds/171104/
    zoneSequencer.setup("toggleZone", sequencerX, sequencerY, sequencerW, bg, fg, "kick.wav", bufferSize);
    //ZONE UI
    zoneSequencer.addParameterBool(playbackParamName, true);
    zoneSequencer.addUI(new ofxAVUIToggle(playbackParamName,playbackParamName), sequencerToggleH);

    sequencerTogglePrefix = "toggle #";
    for(int i = 0 ; i < numSequencerSteps; i++){
        string toggleParamName = sequencerTogglePrefix + (ofToString(i));
        zoneSequencer.addParameterBool(toggleParamName, false);
        zoneSequencer.addUI(new ofxAVUIToggle(toggleParamName,toggleParamName), sequencerStepH);
    }
    //timer control
    //params
    zoneSequencer.addParameterFloat(timerParamName, 125, 2000, delay);
    zoneSequencer.addParameterBool(resetParamName, false);
    zoneSequencer.addParameterFloat(filterSpeedParamName, 0.010, 0.100, 0.025);
    //ui
    zoneSequencer.addUI(new ofxAVUIEmpty(""), sequencerStepH);
    //slider parameters: caption, trigger (single tap) parameter name, toggle (double tap) parameter name, x parameter name
    zoneSequencer.addUI(new ofxAVUISlider(timerParamName,"","",timerParamName), sequencerStepH);
    zoneSequencer.addUI(new ofxAVUISlider(filterSpeedParamName,"","",filterSpeedParamName), sequencerStepH);
    zoneSequencer.addUI(new ofxAVUIButton(resetParamName,resetParamName),sequencerStepH);
    //sound FX
    ofxAVUISoundFxFilter *sfx = new ofxAVUISoundFxFilter();
    //sound fx parameters:
    //- filter enabled toggle name (will be linked to any toggle UI with same name), start value
    //- 1st parameter float name (will be linked to any toggle UI with same name), min value, max value, start value
    //- 2nd parameter float name (will be linked to any toggle UI with same name), min value, max value, start value
    sfx->setup("filterToggle", true, "frequency", 200, 20000, 200, "resonance", 0, 100, 10);
    zoneSequencer.addSoundFx(sfx);
    //START SOUND
    ofSoundStreamSetup(2,2,this, sampleRate, bufferSize, 4); /* this has to happen at the end of setup*/
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //sequencer timing
    int millis = ofGetElapsedTimeMillis();
    if(millis - now >= delay){
        //increment sequencer step
        currentSequencerStep = (currentSequencerStep +1 ) % numSequencerSteps;
        
        bool isOn = zoneSequencer.getParamValueBool(sequencerTogglePrefix+ofToString(currentSequencerStep));
        
        if(zoneSequencer.getParamValueBool(playbackParamName))
            zoneSequencer.getParamValueBool(ofxAVUIZone::TOGGLE_PLAY) = isOn;
        
        now = millis;
    }
    //gesture traversal
    gestureTraversal += zoneSequencer.getParamValueFloat(filterSpeedParamName);
    if(gestureTraversal > 1.0) gestureTraversal = 0.0;
    gestureCurrentPoint = gesture.getPointAtIndexInterpolated(gestureTraversal * gesture.size());
    //map to filter
    if(gesture.size() > 0){
        ofParameter<float> frequencyParam = zoneSequencer.getParamValueFloat("frequency");
        ofParameter<float> resonanceParam = zoneSequencer.getParamValueFloat("resonance");
        
        float frequency = ofMap(gestureCurrentPoint.x, padBounds.x, padBounds.x+padBounds.width,
                                frequencyParam.getMin(), frequencyParam.getMax());
        float resonance = ofMap(gestureCurrentPoint.y, padBounds.y, padBounds.y+padBounds.height,
                                resonanceParam.getMin(), resonanceParam.getMax());
        
        zoneSequencer.getParamValueFloat("frequency") = frequency;
        zoneSequencer.getParamValueFloat("resonance") = resonance;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    zoneSequencer.draw();
    zonePad.draw();
    
    //isolate drawing styles
    ofPushStyle();
        ofSetColor(255, 32);
        //draw pad gesture
        gesture.draw();
        ofDrawCircle(gestureCurrentPoint, 30);
    
        //sequncer step preview
        ofDrawRectangle(sequencerX, sequencerY+sequencerToggleH+(sequencerStepH * currentSequencerStep), sequencerW, sequencerStepH);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    
    for (int i = 0; i < bufferSize; i++){
        
        output[i*nChannels    ] = 0;
        output[i*nChannels + 1] = 0;

        zoneSequencer.play(i);
        output[i*nChannels    ] += zoneSequencer.getOutput(0);
        output[i*nChannels + 1] += zoneSequencer.getOutput(1);
        
    }
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    for(int i = 0; i < bufferSize; i++){
        /* you can also grab the data out of the arrays*/
    }
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(padBounds.inside(x, y)){
        cout << zonePad.getParamValueFloat(xParamName) << "," << zonePad.getParamValueFloat(yParamName) << endl;
        gesture.addVertex(x, y);
    }
//    cout << zoneSequencer.getParamValueFloat("timer") << endl;
    delay = (int)zoneSequencer.getParamValueFloat(timerParamName);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(padBounds.inside(x,y)){
        gesture.clear();
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if((x >= 550 && x<= 750) && (y>= 530 && y <= 550)){
        cout << zoneSequencer.getParamValueBool(resetParamName) << endl;
        gesture.clear();
    }
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
