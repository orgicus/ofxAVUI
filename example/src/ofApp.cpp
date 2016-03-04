// Based on Maximillian integration example, see https://github.com/micknoise/Maximilian/tree/master/openFrameworks

#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    //housekeeping
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofBackground(0,0,0);
    
    //Maximillian setup
    sampleRate 	= 44100; /* Sampling Rate */
    bufferSize	= 512; /* Buffer Size. you have to fill this buffer with sound using the for loop in the audioOut method */
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    
    //ofxAVUI setup
    //Zone 0
    zones[0].setup("zone1", 100, 100, 200, 300, "sound.wav", ofColor(100,100,100, 0), ofColor(0,255,255, 255), bufferSize);
    ofxAVUIXYPad *pad1 = new ofxAVUIXYPad("", "trigger", "volume", "pitch");
    zones[0].addUI(pad1, 0.0, 0.33);
    ofxAVUIToggle *toggle1 = new ofxAVUIToggle("Looping", "looping");
    zones[0].addUI(toggle1, 0.33, 0.33);
    ofxAVUIButton *button1 = new ofxAVUIButton("trigger", "trigger");
    zones[0].addUI(button1, 0.66, 0.34);

    //Zone 1
    zones[1].setup("zone2", 300, 100, 200, 300, "Low.wav", ofColor(100,100,100, 0), ofColor(255,255,0, 255), bufferSize);
    ofxAVUIXYPad *pad2 = new ofxAVUIXYPad("PAD2", "trigger", "pitch", "volume");
    zones[1].addUI(pad2, 0.0, 0.33);
    ofxAVUIEmpty *empty1 = new ofxAVUIEmpty("POWER");
    zones[1].addUI(empty1, 0.33, 0.33);
    ofxAVUISlider *slider1 = new ofxAVUISlider("Pitch\nSlider", "pitch", "trigger");
    zones[1].addUI(slider1, 0.66, 0.34);

    //Zone 2
    zones[2].setup("zone3", 500, 100, 200, 300, "synth.wav", ofColor(100,100,100, 0), ofColor(255,0,255, 255), bufferSize);
    ofxAVUIXYPad *pad3 = new ofxAVUIXYPad("Pad3", "trigger", "pitch", "volume");
    zones[2].addUI(pad3, 0.0, 0.33);
    
    ofxAVUIVisualWave *visual1 = new ofxAVUIVisualWave();
    zones[2].addVisual(visual1, 0.0, 0.33);
    
    ofxAVUISoundFxFilter *filter1 = new ofxAVUISoundFxFilter();
    filter1->setup("filter", false, "frequency", 200, 20000, 5000, "resonance", 0, 100, 50);
    zones[2].addSoundFx(filter1);
    
    ofxAVUIXYPad *pad4 = new ofxAVUIXYPad("Filter", "filter", "frequency", "resonance");
    zones[2].addUI(pad4, 0.33, 0.33);

    ofxAVUISoundFxDelay *delay1 = new ofxAVUISoundFxDelay();
    delay1->setup("delay", false, "size", 10000, 40000, 20000, "feedback", 0.5, 0.75, 1.0);
    zones[2].addSoundFx(delay1);
    
    ofxAVUIXYPad *pad5 = new ofxAVUIXYPad("DELAY", "delay", "size", "feedback");
    zones[2].addUI(pad5, 0.66, 0.34);
    
    
    //OF sound start
    ofSoundStreamSetup(2,2,this, sampleRate, bufferSize, 4); /* this has to happen at the end of setup - it switches on the DAC */
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int k=0; k<3; k++) {
        zones[k].draw();
    }
    
    /* You can use any of the data from audio received and audiorequested to draw stuff here. */

}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    
    for (int i = 0; i < bufferSize; i++){
        
        output[i*nChannels    ] = 0;
        output[i*nChannels + 1] = 0;

        for (int k=0; k<3; k++) {
            zones[k].play(i);
            output[i*nChannels    ] += zones[k].getOutput(0);
            output[i*nChannels + 1] += zones[k].getOutput(1);
        }
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
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    
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
