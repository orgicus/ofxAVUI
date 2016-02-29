//
//  ofxAVUIButton.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIButton.h"

ofxAVUIButton::ofxAVUIButton(){

}

ofxAVUIButton::~ofxAVUIButton(){

}

void ofxAVUIButton::draw(){
    ofPushStyle();
    ofSetColor(255, 0, 0);
    ofDrawRectangle(shape);
    ofPopStyle();
}

bool ofxAVUIButton::mouseMoved(ofMouseEventArgs & args) {
}

bool ofxAVUIButton::mousePressed(ofMouseEventArgs & args) {
}

bool ofxAVUIButton::mouseDragged(ofMouseEventArgs & args) {
}

bool ofxAVUIButton::mouseReleased(ofMouseEventArgs & args) {
}

bool ofxAVUIButton::mouseScrolled(ofMouseEventArgs & args) {
}
