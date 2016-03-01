//
//  ofxAVUIXYPad.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIXYPad.h"

ofxAVUIXYPad::ofxAVUIXYPad(string _paramFloat1, float _min1, float _max1, string _paramFloat2, float _min2, float _max2, string _paramBool, ofColor _bgColor, ofColor _fgColor){
    location.x=0;
    location.y=0;
    bgColor = _bgColor;
    fgColor = _fgColor;
    dragging = false;
    param1 = _paramFloat1;
    param2 = _paramFloat2;
    param3 = _paramBool;
    min1 = _min1;
    max1 = _max1;
    min2 = _min2;
    max2 = _max2;
}

ofxAVUIXYPad::~ofxAVUIXYPad(){

}

void ofxAVUIXYPad::draw(){
    ofPushStyle();
    ofSetColor(bgColor);
    ofDrawRectangle(shape);
    ofSetColor(fgColor);
    ofDrawLine(location.x-5, location.y, location.x+5, location.y);
    ofDrawLine(location.x, location.y-5, location.x, location.y+5);
    ofPopStyle();
}


bool ofxAVUIXYPad::mouseMoved(ofMouseEventArgs & args) {
}

bool ofxAVUIXYPad::mousePressed(ofMouseEventArgs & args) {
    dragging = false;
}

bool ofxAVUIXYPad::mouseDragged(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
        dragging = true;
        location.x = args.x;
        location.y = args.y;
        float horizVal = ofMap(args.x, shape.x, shape.x + shape.width, min1, max1);
        float vertVal = ofMap(args.y, shape.y, shape.y + shape.height, min2, max2);
        
        soundProperties->getFloat(param1) = horizVal;
        soundProperties->getFloat(param2) = vertVal;
    }
}

bool ofxAVUIXYPad::mouseReleased(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
        if (dragging) {
            location.x = args.x;
            location.y = args.y;
            float horizVal = ofMap(args.x, shape.x, shape.x + shape.width, min1, max1);
            float vertVal = ofMap(args.y, shape.y, shape.y + shape.height, min2, max2);
            
            soundProperties->getFloat(param1) = horizVal;
            soundProperties->getFloat(param2) = vertVal;
        } else {
            soundProperties->getBool(param3) = !soundProperties->getBool(param3);
        }
        dragging = false;
    }
}

bool ofxAVUIXYPad::mouseScrolled(ofMouseEventArgs & args) {
}
