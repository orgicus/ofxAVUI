//
//  ofxAVUIZonePlayer.cpp
//
//  Created by Borut Kumperscak on 01/03/2016.
//
//

#include "ofxAVUIZonePlayer.h"

ofxAVUIZonePlayer::ofxAVUIZonePlayer() {
}

ofxAVUIZonePlayer::~ofxAVUIZonePlayer() {
}

void ofxAVUIZonePlayer::setup(string _sound, int bufferSize){
    myBufferSize=bufferSize;
    buffer = new float[bufferSize];
    sound.load(ofToDataPath(_sound));
    //properties
    speed=1;
    amplitude=0.5;
    looping=false;
    sampleOut = 0;
}

void ofxAVUIZonePlayer::addSoundFx(ofxAVUISoundFxBase * _fxElement) {
    fxs.push_back(_fxElement);
}

void ofxAVUIZonePlayer::trigger(float _speed, float _amplitude){
    sampleTrigger = 1;
    speed = _speed;
    amplitude = _amplitude;
}

double ofxAVUIZonePlayer::play(int pos, double pan){
    if(looping){
        sampleOut=envelope.ar(sound.play(speed), 0.1, 1, 1, sampleTrigger);
    }else{
        sampleOut=envelope.ar(sound.play(speed), 0.1, 0.9999, 1, sampleTrigger);
    }
    
    for(std::size_t i = 0; i < fxs.size(); i++){
        if (fxs[i]->isEnabled()) sampleOut = fxs[i]->compute(sampleOut);
    }
    
    buffer[pos]=sampleOut;
    bus.stereo(sampleOut*amplitude, outputs, pan);
    sampleTrigger = 0;
    return sampleOut*amplitude; //used for visualisation
}

