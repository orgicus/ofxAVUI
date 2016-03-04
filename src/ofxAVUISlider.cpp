//
//  ofxAVUISlider.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUISlider.h"

ofxAVUISlider::ofxAVUISlider(string _paramFloat, string _paramBool, ofColor _bgColor, ofColor _fgColor){
    bgColor = _bgColor;
    fgColor = _fgColor;
    x = 0;
    dragging = false;
    param1 = _paramFloat;
    param2 = _paramBool;
}

ofxAVUISlider::~ofxAVUISlider(){

}

void ofxAVUISlider::draw(){
    ofPushStyle();
    ofSetColor(bgColor);
    ofDrawRectangle(shape);
    ofSetColor(fgColor);
    ofNoFill();
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

bool ofxAVUISlider::mouseMoved(ofMouseEventArgs & args) {
}

bool ofxAVUISlider::mousePressed(ofMouseEventArgs & args) {
    dragging = false;
}

bool ofxAVUISlider::mouseDragged(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
        dragging = true;
        x = args.x;
        ofParameter<float>  p1 = soundProperties->getFloat(param1);
        float horizVal = ofMap(args.x, shape.x, shape.x + shape.width, p1.getMin(), p1.getMax());
        p1 = horizVal;
    }
}

bool ofxAVUISlider::mouseReleased(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
        if (dragging) {
            x = args.x;
            ofParameter<float>  p1 = soundProperties->getFloat(param1);
            float horizVal = ofMap(args.x, shape.x, shape.x + shape.width, p1.getMin(), p1.getMax());
            p1 = horizVal;
        } else {
            soundProperties->getBool(param2) = !soundProperties->getBool(param2);
        }
        dragging = false;
    }
}

bool ofxAVUISlider::mouseScrolled(ofMouseEventArgs & args) {
}
