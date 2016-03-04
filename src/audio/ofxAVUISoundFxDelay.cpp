//
//  ofxAVUISoundFxDelay.cpp
//
//  Created by Borut Kumperscak on 02/03/2016.
//
//

#include "ofxAVUISoundFxDelay.h"

double ofxAVUISoundFxDelay::compute(double _sampleIn) {
    return myDelayLine.dl(_sampleIn, (double)param1, (double)param2);
}
