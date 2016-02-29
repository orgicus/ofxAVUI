//
//  ofxAVUIXYPad.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIXYPad.h"

ofxAVUIXYPad::ofxAVUIXYPad(){

}

ofxAVUIXYPad::~ofxAVUIXYPad(){

}

void ofxAVUIXYPad::draw(){
    ofPushStyle();
    ofSetColor(0, 255, 0);
    ofDrawRectangle(x, y, width, height);
    ofPopStyle();
}
