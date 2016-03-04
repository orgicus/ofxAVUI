//
//  ofxAVUIToggle.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIToggle.h"

ofxAVUIToggle::ofxAVUIToggle(string _paramBool, ofColor _bgColor, ofColor _fgColor){
    bgColor = _bgColor;
    fgColor = _fgColor;
    param1 = _paramBool;
}

ofxAVUIToggle::~ofxAVUIToggle(){

}

void ofxAVUIToggle::draw(){
    ofPushStyle();
    ofSetColor(bgColor);
    ofDrawRectangle(shape);
    ofSetColor(fgColor);
    (soundProperties->getBool(param1))? ofFill() : ofNoFill();
    ofDrawCircle(shape.x + shape.width/2, shape.y + shape.height /2, shape.height /4) ;

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
