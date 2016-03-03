//
//  ofxAVUISoundFxBase.cpp
//
//  Created by Borut Kumperscak on 02/03/2016.
//
//

#include "ofxAVUISoundFxBase.h"


ofxAVUISoundFxBase::ofxAVUISoundFxBase() {
    name = "";
    enabled = false;
    param1.set("", 0, 0, 1);
    param2.set("", 0, 0, 1);
}

ofxAVUISoundFxBase::~ofxAVUISoundFxBase() {

}

void ofxAVUISoundFxBase::setup(string _fxName, bool _enabledByDefault, string _paramName1, float _min1, float _max1, float _default1,
                                                                       string _paramName2, float _min2, float _max2, float _default2) {
    name = _fxName;
    param1.set(_paramName1, _default1, _min1, _max1);
    param1.addListener(this, &ofxAVUISoundFxBase::param1Changed);
    param2.set(_paramName2, _default2, _min2, _max2);
    param2.addListener(this, &ofxAVUISoundFxBase::param2Changed);
    enabled.set(_fxName, _enabledByDefault);
    enabled.addListener(this, &ofxAVUISoundFxBase::toggled);
}

void ofxAVUISoundFxBase::param1Changed(float & _param1){
    param1 = _param1;
}

void ofxAVUISoundFxBase::param2Changed(float & _param2){
    param2 = _param2;
}

void ofxAVUISoundFxBase::toggled(bool & _enabled) {
    enabled = _enabled;
}

bool ofxAVUISoundFxBase::isEnabled() {
    return enabled;
}

string ofxAVUISoundFxBase::getName() {
    return name;
}

ofParameter<float> *ofxAVUISoundFxBase::getParameter(int _paramNo) {
    return _paramNo==0?&param1:&param2;
}

ofParameter<bool> *ofxAVUISoundFxBase::getToggle() {
    return &enabled;
}

