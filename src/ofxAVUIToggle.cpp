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
    ofDrawRectangle(shape);
    ofPopStyle();
}

bool ofxAVUIToggle::mouseMoved(ofMouseEventArgs & args) {
}

bool ofxAVUIToggle::mousePressed(ofMouseEventArgs & args) {
}

bool ofxAVUIToggle::mouseDragged(ofMouseEventArgs & args) {
}

bool ofxAVUIToggle::mouseReleased(ofMouseEventArgs & args) {
}

bool ofxAVUIToggle::mouseScrolled(ofMouseEventArgs & args) {
}
