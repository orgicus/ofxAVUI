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
    ofDrawRectangle(shape);
    ofSetColor(fgColor);
    drawTitle();
    ofPopStyle();
}

bool ofxAVUIEmpty::mouseMoved(ofMouseEventArgs & args) {
}

bool ofxAVUIEmpty::mousePressed(ofMouseEventArgs & args) {
}

bool ofxAVUIEmpty::mouseDragged(ofMouseEventArgs & args) {
}

bool ofxAVUIEmpty::mouseReleased(ofMouseEventArgs & args) {
}

bool ofxAVUIEmpty::mouseScrolled(ofMouseEventArgs & args) {
}
