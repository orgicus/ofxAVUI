//
//  ofxAVUILabel.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUILabel.h"

ofxAVUILabel::ofxAVUILabel(string _label, ofColor _bgColor, ofColor _fgColor){
    bgColor = _bgColor;
    fgColor = _fgColor;
    label = _label;
}

ofxAVUILabel::~ofxAVUILabel(){

}

void ofxAVUILabel::draw(){
    ofPushStyle();
    ofSetColor(bgColor);
    ofDrawRectangle(shape);
    ofSetColor(fgColor);
    ofDrawBitmapString(label, shape.x, shape.y + shape.height);
    ofPopStyle();
}

bool ofxAVUILabel::mouseMoved(ofMouseEventArgs & args) {
}

bool ofxAVUILabel::mousePressed(ofMouseEventArgs & args) {
}

bool ofxAVUILabel::mouseDragged(ofMouseEventArgs & args) {
}

bool ofxAVUILabel::mouseReleased(ofMouseEventArgs & args) {
}

bool ofxAVUILabel::mouseScrolled(ofMouseEventArgs & args) {
}
