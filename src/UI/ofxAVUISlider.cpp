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

void ofxAVUISlider::draw(){
//this is here as we dont call update()
//    if (clicking && (ofGetElapsedTimeMillis() - doubleClickTimer > DOUBLECLICK_MILLIS)) {
//        x = mouseArgs.x;
//        ofParameter<float>  p1 = soundProperties->getFloat(param1);
//        float horizVal = ofMap(x, shape.x, shape.x + shape.width, p1.getMin(), p1.getMax());
//        p1 = horizVal;
//        clicking = false;
//    }
    ofPushStyle();
    ofSetColor(bgColor);
    ofDrawRectangle(shape);
    ofSetColor(fgColor);
    ofNoFill();
    drawContour();
    drawTitle();
    ofDrawLine(x, shape.y, x, shape.y + shape.height);  //cursor
    if(soundProperties->getBool(paramBool)) ofDrawCircle(x,shape.y + shape.height/2,10);
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

bool ofxAVUISlider::mouseScrolled(ofMouseEventArgs & args) {
}
