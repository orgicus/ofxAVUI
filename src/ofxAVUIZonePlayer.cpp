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
    //delay
    size = 20000;
    feedback = 0.75;
    //filter
    frequencyLoRes=5000;
    resonance=50;
    filterOn=false;
}

void ofxAVUIZonePlayer::trigger(float _speed, float _amplitude){
    sampleTrigger = 1;
    speed = _speed;
    amplitude = _amplitude;
}

void ofxAVUIZonePlayer::filter(float _val1, float _val2){
    frequencyLoRes = ofMap(_val1,0,1,200,20000);
}

void ofxAVUIZonePlayer::delay(float _val1, float _val2){
    feedback = ofMap(_val1,0,1,0.5,0.999);
    size = ofMap(_val2,0,1,10000,40000);
}

void ofxAVUIZonePlayer::play(int pos, double pan){
    if(looping){
        sampleOut=envelope.ar(sound.play(speed), 0.1, 1, 1, sampleTrigger);
    }else{
        sampleOut=envelope.ar(sound.play(speed), 0.1, 0.9999, 1, sampleTrigger);
    }
    
    if(filterOn&&!delayOn){
    
        filtered=myFilter.lores(sampleOut, frequencyLoRes, resonance);
        buffer[pos]=filtered;
        bus.stereo(filtered*amplitude, outputs, pan);
    
    }else if(delayOn&&!filterOn){
    
        delayed=myDelayLine.dl(sampleOut,size,feedback);
        buffer[pos]=delayed;
        bus.stereo(delayed*amplitude, outputs, pan);
    
    }else if(delayOn&&filterOn){
    
        delayed=myDelayLine.dl(sampleOut,size,feedback);
        filtered=myFilter.lores(delayed, frequencyLoRes, resonance);
        buffer[pos]=filtered;
        bus.stereo(filtered*amplitude, outputs, pan);
        
    }else{
    
        buffer[pos]=sampleOut;
        bus.stereo(sampleOut*amplitude, outputs, pan);
    
    }
    sampleTrigger = 0;
}

