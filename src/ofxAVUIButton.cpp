//
//  ofxAVUIButton.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIButton.h"

ofxAVUIButton::ofxAVUIButton(string _paramBool){
//    if (soundProperties->getPosition(_paramBool) == 0 && soundProperties->getName(0)!=_paramBool) {
//        ofLogWarning("Error in parameter names, expect the unexpected!");
//    }
    param1 = _paramBool;
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
    if (shape.inside(args.x, args.y)) {
        soundProperties->getBool(param1) = !soundProperties->getBool(param1);
    }
}

bool ofxAVUIButton::mouseDragged(ofMouseEventArgs & args) {
}

bool ofxAVUIButton::mouseReleased(ofMouseEventArgs & args) {
}

bool ofxAVUIButton::mouseScrolled(ofMouseEventArgs & args) {
}
