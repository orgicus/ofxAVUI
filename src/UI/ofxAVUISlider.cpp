//
//  ofxAVUISlider.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUISlider.h"

ofxAVUISlider::ofxAVUISlider(string _title, string _paramFloat, string _paramBool){
    x = 0;
    dragging = false;
    clicking = false;
    title = _title;
    param1 = _paramFloat;
    paramBool = _paramBool;
}

ofxAVUISlider::~ofxAVUISlider(){

}

void ofxAVUISlider::setPosition(int _x, int _y, int _width, int _height) {
    shape.x = _x;
    shape.y = _y;
    shape.width = _width;
    shape.height = _height;
    x = _x + _width/2;
}

void ofxAVUISlider::update() {
    ofParameter<float>  p1 = soundProperties->getFloat(param1);
    float horizVal = ofMap(p1, p1.getMin(), p1.getMax(), shape.x, shape.x + shape.width);
    x = horizVal;
}

void ofxAVUISlider::draw(){
//this is here so we dont need to call update() every cycle
//    if (clicking && (ofGetElapsedTimeMillis() - doubleClickTimer > DOUBLECLICK_MILLIS)) {
//        x = mouseArgs.x;
//        ofParameter<float>  p1 = soundProperties->getFloat(param1);
//        float horizVal = ofMap(x, shape.x, shape.x + shape.width, p1.getMin(), p1.getMax());
//        p1 = horizVal;
//        clicking = false;
//    }
    ofPushStyle();
    ofSetColor(bgColor);
    ofDrawRectangle(0,0,shape.width,shape.height);
    ofSetColor(fgColor);
    ofNoFill();
    drawContour();
    drawTitle();
    ofDrawLine(x-shape.x, 0, x-shape.x, shape.height);  //cursor
    if(soundProperties->getBool(paramBool)) ofDrawCircle(x - shape.x, shape.height/2,10);
    ofPopStyle();
}

void ofxAVUISlider::mouseMoved(ofMouseEventArgs & args) {
}

void ofxAVUISlider::mousePressed(ofMouseEventArgs & args) {
    dragging = false;
}

void ofxAVUISlider::mouseDragged(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
        dragging = true;
        x = args.x;
        ofParameter<float>  p1 = soundProperties->getFloat(param1);
        float horizVal = ofMap(args.x, shape.x, shape.x + shape.width, p1.getMin(), p1.getMax());
        p1 = horizVal;
    }
}

void ofxAVUISlider::mouseReleased(ofMouseEventArgs & args) {
    if (shape.inside(args.x, args.y)) {
//        if (ofGetElapsedTimeMillis() - doubleClickTimer <= DOUBLECLICK_MILLIS) {
//            if (!dragging) soundProperties->getBool(paramBool) = !soundProperties->getBool(paramBool);    //no toggle
            if (!dragging) soundProperties->getBool(paramBool) = true;                                      //just trigger
            x = args.x;
            ofParameter<float>  p1 = soundProperties->getFloat(param1);
            float horizVal = ofMap(args.x, shape.x, shape.x + shape.width, p1.getMin(), p1.getMax());
            p1 = horizVal;
//            clicking = false;
//        } else {
//            doubleClickTimer = ofGetElapsedTimeMillis();
//            clicking = true;
//            mouseArgs = args;
//        }
        dragging = false;
    }
}

void ofxAVUISlider::mouseScrolled(ofMouseEventArgs & args) {
}
