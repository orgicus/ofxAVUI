//
//  ofxAVUISoundFxFilter.cpp
//
//  Created by Borut Kumperscak on 02/03/2016.
//
//

#include "ofxAVUISoundFxFilter.h"

double ofxAVUISoundFxFilter::compute(double _sampleIn) {
    return myFilter.lores(_sampleIn, (double)param1.get(), (double)param2.get());
}
