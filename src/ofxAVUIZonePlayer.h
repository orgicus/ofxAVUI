//
//  ofxAVUIZonePlayer.h
//
//  Created by Borut Kumperscak on 01/03/2016.
//
//

#ifndef ofxAVUIZonePlayer_h
#define ofxAVUIZonePlayer_h

#include "ofMain.h"
#include "ofxMaxim.h"
#include "ofxAVUISoundFxBase.h"
#include "ofxAVUISoundFxFilter.h"
#include "ofxAVUISoundFxDelay.h"

class ofxAVUIZonePlayer {
    
    public:
        void setup(string _sound, int bufferSize);
        void trigger(float _speed, float _amplitude);
        void filter(float _val1, float _val2);
        void delay(float _val1, float _val2);
        void play(int pos, double pan);

        //objects
        maxiEnv envelope;
        maxiSample sound;
        maxiMix bus;
    
        //audio streams
        double outputs[2];
        double sampleOut;
        double filtered;
        double delayed;
        float * buffer;
        int myBufferSize;

        //properties
        double speed;
        double amplitude;
        bool looping;
        int sampleTrigger;

        //filter
        ofxAVUISoundFxFilter  *filter1;

        //delay
        ofxAVUISoundFxDelay  *delay1;
    
        //list of fx
        std::vector <ofxAVUISoundFxBase *> fxs;
};


#endif /* ofxAVUIZonePlayer_h */
