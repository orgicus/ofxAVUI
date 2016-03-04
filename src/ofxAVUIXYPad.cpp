//
//  ofxAVUIXYPad.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIXYPad.h"

ofxAVUIXYPad::ofxAVUIXYPad(string _title, string _paramBool, string _paramFloat1, string _paramFloat2){
    location.x=0;
    location.y=0;
    dragging = false;
    doubleClickTimer = 0;
    clicking = false;
    title = _title;
    paramX = _paramFloat1;
    paramY = _paramFloat2;
    paramBool = _paramBool;
}

ofxAVUIXYPad::~ofxAVUIXYPad(){

}

void ofxAVUIXYPad::setPosition(int _x, int _y, int _width, int _height) {
    shape.x = _x;
    shape.y = _y;
    shape.width = _width;
    shape.height = _height;
    location.x = _x + _width/2;
    location.y = _y + _height/2;
}

void ofxAVUIXYPad::draw(){
    if (clicking && (ofGetElapsedTimeMillis() - doubleClickTimer > DOUBLECLICK_MILLIS)) {
        location.x = mouseArgs.x;
        location.y = mouseArgs.y;
        ofParameter<float>  px = soundProperties->getFloat(paramX);
        ofParameter<float>  py = soundProperties->getFloat(paramY);
        float horizVal = ofMap(location.x, shape.x, shape.x + shape.width, px.getMin(), px.getMax());
        float vertVal = ofMap(location.y, shape.y, shape.y + shape.height, py.getMin(), py.getMax());
        px = horizVal;
        py = vertVal;
        clicking = false;
    }
    ofPushStyle();
    ofSetColor(bgColor);
    ofDrawRectangle(shape);
    ofSetColor(fgColor);
    ofNoFill();
    drawContour();
    drawTitle();
    ofDrawLine(location.x-5, location.y, location.x+5, location.y);
    ofDrawLine(location.x, location.y-5, location.x, location.y+5);
    if(soundProperties->getBool(paramBool)) ofDrawCircle(location.x,location.y,10);
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
        ofParameter<float>  px = soundProperties->getFloat(paramX);
        ofParameter<float>  py = soundProperties->getFloat(paramY);
        float horizVal = ofMap(args.x, shape.x, shape.x + shape.width, px.getMin(), px.getMax());
        float vertVal = ofMap(args.y, shape.y, shape.y + shape.height, py.getMin(), py.getMax());
        px = horizVal;
        py = vertVal;
    }
}

bool ofxAVUIXYPad::mouseReleased(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
        if (ofGetElapsedTimeMillis() - doubleClickTimer <= DOUBLECLICK_MILLIS) {
            soundProperties->getBool(paramBool) = !soundProperties->getBool(paramBool);
            clicking = false;
        } else {
            doubleClickTimer = ofGetElapsedTimeMillis();
            clicking = true;
            mouseArgs = args;
        }
        dragging = false;
    }
}

bool ofxAVUIXYPad::mouseScrolled(ofMouseEventArgs & args) {
}
