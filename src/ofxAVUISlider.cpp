//
//  ofxAVUISlider.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUISlider.h"

ofxAVUISlider::ofxAVUISlider(string _paramFloat, float _min, float _max, string _paramBool, ofColor _bgColor, ofColor _fgColor){
    bgColor = _bgColor;
    fgColor = _fgColor;
    x = 0;
    dragging = false;
    param1 = _paramFloat;
    param2 = _paramBool;
    min1 = _min;
    max1 = _max;
}

ofxAVUISlider::~ofxAVUISlider(){

}

void ofxAVUISlider::draw(){
    ofPushStyle();
    ofSetColor(bgColor);
    ofDrawRectangle(shape);
    ofSetColor(fgColor);
    ofDrawLine(x, shape.y, x, shape.y + shape.height);
    ofPopStyle();
}

bool ofxAVUISlider::mouseMoved(ofMouseEventArgs & args) {
}

bool ofxAVUISlider::mousePressed(ofMouseEventArgs & args) {
    dragging = false;
}

bool ofxAVUISlider::mouseDragged(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
        dragging = true;
        x = args.x;
        float horizVal = ofMap(args.x, shape.x, shape.x + shape.width, 0.0, 1.0);
        soundProperties->getFloat(param1) = horizVal;
    }
}

bool ofxAVUISlider::mouseReleased(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
        if (dragging) {
            x = args.x;
            float horizVal = ofMap(args.x, shape.x, shape.x + shape.width, 0.0, 1.0);
            soundProperties->getFloat(param1) = horizVal;
        } else {
            soundProperties->getBool(param2) = !soundProperties->getBool(param2);
        }
        dragging = false;
    }
}

bool ofxAVUISlider::mouseScrolled(ofMouseEventArgs & args) {
}
