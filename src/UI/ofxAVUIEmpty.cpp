//
//  ofxAVUIEmpty.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIEmpty.h"

ofxAVUIEmpty::ofxAVUIEmpty(string _title){
    title = _title;
}

ofxAVUIEmpty::~ofxAVUIEmpty(){

}

void ofxAVUIEmpty::draw(){
    ofPushStyle();
    ofSetColor(bgColor);
    ofDrawRectangle(0,0,shape.width,shape.height);
    ofSetColor(fgColor);
    drawTitle();
    ofPopStyle();
}

void ofxAVUIEmpty::mouseMoved(ofMouseEventArgs & args) {
}

void ofxAVUIEmpty::mousePressed(ofMouseEventArgs & args) {
}

void ofxAVUIEmpty::mouseDragged(ofMouseEventArgs & args) {
}

void ofxAVUIEmpty::mouseReleased(ofMouseEventArgs & args) {
}

void ofxAVUIEmpty::mouseScrolled(ofMouseEventArgs & args) {
}
