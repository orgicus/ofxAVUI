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
    title = _title;
    paramX = _paramFloat1;
    paramY = _paramFloat2;
    paramBool = _paramBool;
}

ofxAVUIXYPad::~ofxAVUIXYPad(){

}

void ofxAVUIXYPad::draw(){
    ofPushStyle();
    ofSetColor(bgColor);
    ofDrawRectangle(shape);
    ofSetColor(fgColor);
    ofNoFill();
<<<<<<< HEAD
    drawContour();
    drawTitle();
    ofDrawLine(location.x-5, location.y, location.x+5, location.y);
    ofDrawLine(location.x, location.y-5, location.x, location.y+5);
=======
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
    ofDrawLine(location.x-10, location.y, location.x+10, location.y);
    ofDrawLine(location.x, location.y-10, location.x, location.y+10);
    
    if(soundProperties->getBool(param3)==true) ofDrawCircle(location.x,location.y,10);
    
>>>>>>> 9511d2c1093c307d91e51f3aa9f55e0937ec0768
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
        if (dragging) {
            location.x = args.x;
            location.y = args.y;
        ofParameter<float>  px = soundProperties->getFloat(paramX);
        ofParameter<float>  py = soundProperties->getFloat(paramY);
        float horizVal = ofMap(args.x, shape.x, shape.x + shape.width, px.getMin(), px.getMax());
        float vertVal = ofMap(args.y, shape.y, shape.y + shape.height, py.getMin(), py.getMax());
        px = horizVal;
        py = vertVal;
        } else {
            soundProperties->getBool(paramBool) = !soundProperties->getBool(paramBool);
        }
        dragging = false;
    }
}

bool ofxAVUIXYPad::mouseScrolled(ofMouseEventArgs & args) {
}
