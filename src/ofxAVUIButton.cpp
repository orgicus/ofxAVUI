//
//  ofxAVUIButton.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIButton.h"

ofxAVUIButton::ofxAVUIButton(string _paramBool, ofColor _bgColor, ofColor _fgColor){
    bgColor = _bgColor;
    fgColor = _fgColor;
    param1 = _paramBool;
}

ofxAVUIButton::~ofxAVUIButton(){

}

void ofxAVUIButton::draw(){
    ofPushStyle();
    ofSetColor(bgColor);
    ofDrawRectangle(shape);
    ofSetColor(fgColor);
    //<contours>
    ofDrawLine(shape.x,shape.y,shape.x+shape.width*0.25,shape.y);
    ofDrawLine(shape.x+shape.width*0.75,shape.y,shape.x+shape.width,shape.y);
    ofDrawLine(shape.x,shape.y+shape.height,shape.x+shape.width*0.25,shape.y+shape.height);
    ofDrawLine(shape.x+shape.width*0.75,shape.y+shape.height,shape.x+shape.width,shape.y+shape.height);
    ofDrawLine(shape.x,shape.y,shape.x,shape.y+shape.height*0.25);
    ofDrawLine(shape.x+shape.width,shape.y,shape.x+shape.width,shape.y+shape.height*0.25);
    ofDrawLine(shape.x,shape.y+shape.height*0.75,shape.x,shape.y+shape.height);
    ofDrawLine(shape.x+shape.width,shape.y+shape.height*0.75,shape.x+shape.width,shape.y+shape.height);
    //</contours>

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
