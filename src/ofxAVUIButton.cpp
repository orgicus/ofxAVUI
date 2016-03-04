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
    ofDrawRectangle(shape);
    ofSetColor(fgColor);
    drawContour();
    drawTitle();
    ofPopStyle();
}

bool ofxAVUIButton::mouseMoved(ofMouseEventArgs & args) {
}

bool ofxAVUIButton::mousePressed(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
        soundProperties->getBool(param1) = !soundProperties->getBool(param1);
    }
}

bool ofxAVUIButton::mouseDragged(ofMouseEventArgs & args) {
}

bool ofxAVUIButton::mouseReleased(ofMouseEventArgs & args) {
}

bool ofxAVUIButton::mouseScrolled(ofMouseEventArgs & args) {
}
