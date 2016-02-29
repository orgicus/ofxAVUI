//
//  ofxAVUILabel.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUILabel.h"

ofxAVUILabel::ofxAVUILabel(){

}

ofxAVUILabel::~ofxAVUILabel(){

}

void ofxAVUILabel::draw(){
    ofPushStyle();
    ofSetColor(0, 255, 255);
    ofDrawRectangle(x, y, width, height);
    ofPopStyle();
}
