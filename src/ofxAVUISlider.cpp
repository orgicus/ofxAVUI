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
    title = _title;
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
    drawContour();
    drawTitle();
    ofDrawLine(x, shape.y, x, shape.y + shape.height);  //cursor
    if(soundProperties->getBool(param2)) ofDrawCircle(x,shape.y + shape.height/2,10);
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
