//
//  ofxAVUIXYPad.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIXYPad.h"

ofxAVUIXYPad::ofxAVUIXYPad(string _paramBool, string _paramFloat1, string _paramFloat2, ofColor _bgColor, ofColor _fgColor){
    location.x=0;
    location.y=0;
    bgColor = _bgColor;
    fgColor = _fgColor;
    dragging = false;
    param1 = _paramFloat1;
    param2 = _paramFloat2;
    param3 = _paramBool;
}

ofxAVUIXYPad::~ofxAVUIXYPad(){

}

void ofxAVUIXYPad::draw(){
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
        ofParameter<float>  p1 = soundProperties->getFloat(param1);
        ofParameter<float>  p2 = soundProperties->getFloat(param2);
        float horizVal = ofMap(args.x, shape.x, shape.x + shape.width, p1.getMin(), p1.getMax());
        float vertVal = ofMap(args.y, shape.y, shape.y + shape.height, p2.getMin(), p2.getMax());
        p1 = horizVal;
        p2 = vertVal;
    }
}

bool ofxAVUIXYPad::mouseReleased(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
        if (dragging) {
            location.x = args.x;
            location.y = args.y;
            ofParameter<float>  p1 = soundProperties->getFloat(param1);
            ofParameter<float>  p2 = soundProperties->getFloat(param2);
            float horizVal = ofMap(args.x, shape.x, shape.x + shape.width, p1.getMin(), p1.getMax());
            float vertVal = ofMap(args.y, shape.y, shape.y + shape.height, p2.getMin(), p2.getMax());
            p1 = horizVal;
            p2 = vertVal;
        } else {
            soundProperties->getBool(param3) = !soundProperties->getBool(param3);
        }
        dragging = false;
    }
}

bool ofxAVUIXYPad::mouseScrolled(ofMouseEventArgs & args) {
}
