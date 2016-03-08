//
//  ofxAVUISoundFxDelay.cpp
//
//  Part of ofxAVUI addon. Developed by Nuno Correia and Borut Kumperscak in 2016.
//  https://github.com/AVUIs/ofxAVUI
//

#include "ofxAVUISoundFxDelay.h"

double ofxAVUISoundFxDelay::compute(double _sampleIn) {
    return myDelayLine.dl(_sampleIn, (double)param1, (double)param2);
}
