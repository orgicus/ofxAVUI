//
//  ofxAVUIZonePlayer.cpp
//
//  Created by Borut Kumperscak on 01/03/2016.
//
//

#include "ofxAVUIZonePlayer.h"

void ofxAVUIZonePlayer::setup(string _sound, int bufferSize){
    myBufferSize=bufferSize;
    buffer = new float[bufferSize];
    sound.load(ofToDataPath(_sound));
    //properties
    speed=1;
    amplitude=0.5;
    looping=false;
    //filter
    filter1 = new ofxAVUISoundFxFilter();
    filter1->setup("filter", "frequency", 200, 20000, 5000, "resonance", 0, 100, 50);
    fxs.push_back(filter1);
    //delay
    delay1 = new ofxAVUISoundFxDelay();
    delay1->setup("delay", "size", 10000, 40000, 20000, "feedback", 0.5, 0.75, 1.0);
    fxs.push_back(delay1);
}

void ofxAVUIZonePlayer::trigger(float _speed, float _amplitude){
    sampleTrigger = 1;
    speed = _speed;
    amplitude = _amplitude;
}

void ofxAVUIZonePlayer::filter(float _val1, float _val2){
    filter1->toggle(true);  //test
    filter1->setParameter("frequency", _val1);
    filter1->setParameter("resonance", _val2);
}

void ofxAVUIZonePlayer::delay(float _val1, float _val2){
    delay1->toggle(true);  //test
    delay1->setParameter("size", _val1);
    delay1->setParameter("feedback", _val2);
}

void ofxAVUIZonePlayer::play(int pos, double pan){
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
}

