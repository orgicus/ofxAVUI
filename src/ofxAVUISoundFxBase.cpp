//
//  ofxAVUISoundFxBase.cpp
//
//  Created by Borut Kumperscak on 02/03/2016.
//
//

#include "ofxAVUISoundFxBase.h"


ofxAVUISoundFxBase::ofxAVUISoundFxBase() {
    name = "";
    param1 = "";
    min1 = 0;
    max1 = 0;
    val1 = 0;
    param2 = "";
    min2 = 0;
    max2 = 0;
    val2 = 0;
}

ofxAVUISoundFxBase::~ofxAVUISoundFxBase() {

}

void ofxAVUISoundFxBase::setup(string _fxName, string _paramName1, float _min1, float _max1, float _default1,
                                               string _paramName2, float _min2, float _max2, float _default2) {
    name = _fxName;
    param1 = _paramName1;
    min1 = _min1;
    max1 = _max1;
    val1 = _default1;
    param2 = _paramName2;
    min2 = _min2;
    max2 = _max2;
    val2 = _default2;
    
}

void ofxAVUISoundFxBase::toggle(bool _enabled) {
    enabled = _enabled;
}

bool ofxAVUISoundFxBase::isEnabled() {
    return enabled;
}

void ofxAVUISoundFxBase::setParameter(string _param, float _val) {
    if (_param == param1) val1 = ofMap(_val,0,1,min1,max1);
    else if (_param == param2) val2 = ofMap(_val,0,1,min2,max2);
}
