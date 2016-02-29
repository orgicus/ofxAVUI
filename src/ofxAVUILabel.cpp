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
    ofDrawRectangle(shape);
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
