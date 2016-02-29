//
//  ofxAVUIXYPad.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIXYPad.h"

ofxAVUIXYPad::ofxAVUIXYPad(){
    location.x=0;
    location.y=0;
}

ofxAVUIXYPad::~ofxAVUIXYPad(){

}

void ofxAVUIXYPad::draw(){
    ofPushStyle();
    ofSetColor(0, 255, 0);
    ofDrawRectangle(shape);
    ofSetColor(0, 0, 0);
    ofDrawLine(location.x-5, location.y, location.x+5, location.y);
    ofDrawLine(location.x, location.y-5, location.x, location.y+5);
    ofPopStyle();
}


bool ofxAVUIXYPad::mouseMoved(ofMouseEventArgs & args) {
}

bool ofxAVUIXYPad::mousePressed(ofMouseEventArgs & args) {
}

bool ofxAVUIXYPad::mouseDragged(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
        location.x = args.x;
        location.y = args.y;
    }
}

bool ofxAVUIXYPad::mouseReleased(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
        location.x = args.x;
        location.y = args.y;
    }
}

bool ofxAVUIXYPad::mouseScrolled(ofMouseEventArgs & args) {
}
