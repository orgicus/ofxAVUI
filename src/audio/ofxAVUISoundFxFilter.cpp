//
//  ofxAVUISoundFxFilter.cpp
//
//  Part of ofxAVUI addon. Developed by Nuno Correia and Borut Kumperscak in 2016.
//  https://github.com/AVUIs/ofxAVUI
//

#include "ofxAVUISoundFxFilter.h"

double ofxAVUISoundFxFilter::compute(double _sampleIn) {
    return myFilter.lores(_sampleIn, (double)param1.get(), (double)param2.get());
}
