//
//  ofxAVUISoundFxDelay.cpp
//
//  Created by Borut Kumperscak on 02/03/2016.
//
//

#include "ofxAVUISoundFxDelay.h"

double ofxAVUISoundFxDelay::compute(double _sampleIn) {
    return myDelayLine.dl(_sampleIn, (double)val1, (double)val2);
}
