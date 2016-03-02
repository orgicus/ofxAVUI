//
//  ofxAVUISoundFxFilter.cpp
//
//  Created by Borut Kumperscak on 02/03/2016.
//
//

#include "ofxAVUISoundFxFilter.h"

//ofxAVUISoundFxFilter::ofxAVUISoundFxFilter(string _fxName, string _paramName1, float _min1, float _max1, float _default1,
//                                           string _paramName2, float _min2, float _max2, float _default2) :
//    ofxAVUISoundFxBase (_fxName, _paramName1, _min1, _max1, _default1, _paramName2, _min2, _max2, _default2) {};
//

double ofxAVUISoundFxFilter::compute(double _sampleIn) {
    return myFilter.lores(_sampleIn, (double)val1, (double)val2);
}
