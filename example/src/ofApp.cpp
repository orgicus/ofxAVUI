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
    zones[0].setup(100, 100, 200, 300, "sound.wav");
    zones[0].addUI(new ofxAVUIXYPad(), 0.0, 0.33);
    zones[0].addUI(new ofxAVUIToggle(), 0.33, 0.33);
    zones[0].addUI(new ofxAVUIButton(), 0.66, 0.34);
    
    zones[1].setup(300, 100, 200, 300, "Low.wav");
    zones[1].addUI(new ofxAVUILabel(), 0.0, 0.33);
    zones[1].addUI(new ofxAVUISlider(), 0.33, 0.33);
    
    zones[2].setup(500, 100, 200, 300, "synth.wav");
    
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
