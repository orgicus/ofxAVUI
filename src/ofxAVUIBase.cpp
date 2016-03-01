//
//  ofxAVUIBase.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIBase.h"

ofxAVUIBase::ofxAVUIBase(){
    ofRegisterMouseEvents(this, OF_EVENT_ORDER_BEFORE_APP);
}

ofxAVUIBase::~ofxAVUIBase(){
	ofUnregisterMouseEvents(this, OF_EVENT_ORDER_BEFORE_APP);
}

void ofxAVUIBase::setPosition(int _x, int _y, int _width, int _height) {
    shape.x = _x;
    shape.y = _y;
    shape.width = _width;
    shape.height = _height;
}

void ofxAVUIBase::bindProperties(ofParameterGroup *_soundProperties) {
    soundProperties = _soundProperties;
}


