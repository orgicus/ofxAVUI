//
//  ofxAVUIToggle.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIToggle.h"

ofxAVUIToggle::ofxAVUIToggle(){

}

ofxAVUIToggle::~ofxAVUIToggle(){

}

void ofxAVUIToggle::draw(){
    ofPushStyle();
    ofSetColor(0, 0, 255);
    ofDrawRectangle(x, y, width, height);
    ofPopStyle();
}
