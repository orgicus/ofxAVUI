//
//  ofxAVUIToggle.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIToggle.h"

ofxAVUIToggle::ofxAVUIToggle(string _paramBool, ofColor _bgColor, ofColor _fgColor){
    bgColor = _bgColor;
    fgColor = _fgColor;
    param1 = _paramBool;
}

ofxAVUIToggle::~ofxAVUIToggle(){

}

void ofxAVUIToggle::draw(){
    ofPushStyle();
    ofSetColor(bgColor);
    ofDrawRectangle(shape);
    ofSetColor(fgColor);
    if (soundProperties->getBool(param1)) ofDrawRectangle(shape.x + shape.width * 0.1, shape.y + shape.height * 0.1, shape.width * 0.8, shape.height * 0.8);
    ofPopStyle();
}

bool ofxAVUIToggle::mouseMoved(ofMouseEventArgs & args) {
}

bool ofxAVUIToggle::mousePressed(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
        soundProperties->getBool(param1) = !soundProperties->getBool(param1);
    }
}

bool ofxAVUIToggle::mouseDragged(ofMouseEventArgs & args) {
}

bool ofxAVUIToggle::mouseReleased(ofMouseEventArgs & args) {
}

bool ofxAVUIToggle::mouseScrolled(ofMouseEventArgs & args) {
}
