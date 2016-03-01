//
//  ofxAVUISlider.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUISlider.h"

ofxAVUISlider::ofxAVUISlider(string _paramFloat, string _paramBool){
    x = 0;
    dragging = false;
//    if ((soundProperties->getPosition(_paramFloat) == 0 && soundProperties->getName(0)!=_paramFloat) ||
//        (soundProperties->getPosition(_paramBool) == 0 && soundProperties->getName(0)!=_paramBool)) {
//        ofLogWarning("Error in parameter names, expect the unexpected!");
//    }
    param1 = _paramFloat;
    param2 = _paramBool;
}

ofxAVUISlider::~ofxAVUISlider(){

}

void ofxAVUISlider::draw(){
    ofPushStyle();
    ofSetColor(255, 255, 0);
    ofDrawRectangle(shape);
    ofSetColor(0, 0, 0);
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
