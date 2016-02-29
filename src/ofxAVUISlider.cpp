//
//  ofxAVUISlider.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUISlider.h"

ofxAVUISlider::ofxAVUISlider(){

}

ofxAVUISlider::~ofxAVUISlider(){

}

void ofxAVUISlider::draw(){
    ofPushStyle();
    ofSetColor(255, 255, 0);
    ofDrawRectangle(shape);
    ofPopStyle();
}

bool ofxAVUISlider::mouseMoved(ofMouseEventArgs & args) {
}

bool ofxAVUISlider::mousePressed(ofMouseEventArgs & args) {
}

bool ofxAVUISlider::mouseDragged(ofMouseEventArgs & args) {
}

bool ofxAVUISlider::mouseReleased(ofMouseEventArgs & args) {
}

bool ofxAVUISlider::mouseScrolled(ofMouseEventArgs & args) {
}
