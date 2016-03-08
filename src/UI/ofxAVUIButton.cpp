//
//  ofxAVUIButton.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIButton.h"

ofxAVUIButton::ofxAVUIButton(string _title, string _paramBool){
    title = _title;
    param1 = _paramBool;
}

ofxAVUIButton::~ofxAVUIButton(){

}

void ofxAVUIButton::draw(){
    ofPushStyle();
    ofSetColor(bgColor);
    ofDrawRectangle(0,0,shape.width,shape.height);
    ofSetColor(fgColor);
    drawContour();
    drawTitle();
    ofPopStyle();
}

void ofxAVUIButton::mouseMoved(ofMouseEventArgs & args) {
}

void ofxAVUIButton::mousePressed(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
        soundProperties->getBool(param1) = !soundProperties->getBool(param1);
    }
}

void ofxAVUIButton::mouseDragged(ofMouseEventArgs & args) {
}

void ofxAVUIButton::mouseReleased(ofMouseEventArgs & args) {
}

void ofxAVUIButton::mouseScrolled(ofMouseEventArgs & args) {
}
