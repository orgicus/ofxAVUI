//
//  ofxAVUIToggle.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIToggle.h"

ofxAVUIToggle::ofxAVUIToggle(string _paramBool){
//    if (soundProperties->getPosition(_paramBool) == 0 && soundProperties->getName(0)!=_paramBool) {
//        ofLogWarning("Error in parameter names, expect the unexpected!");
//    }
    param1 = _paramBool;
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
    if (shape.inside(args.x, args.y)) {
        soundProperties->getBool(param1) = !soundProperties->getBool(param1);
    }
}

bool ofxAVUIToggle::mouseDragged(ofMouseEventArgs & args) {
}

bool ofxAVUIToggle::mouseReleased(ofMouseEventArgs & args) {
}

bool ofxAVUIToggle::mouseScrolled(ofMouseEventArgs & args) {
}
