//
//  ofxAVUIVisualBars.cpp
//
//  Created by Borut Kumperscak on 03/03/2016.
//
//

#include "ofxAVUIVisualBars.h"

ofxAVUIVisualBars::ofxAVUIVisualBars(int nRects){
    red = ofMap(shape.x,0,ofGetWidth()-shape.width,0,127);
    numRects=nRects;
}

void ofxAVUIVisualBars::draw(float * buffer, float amplitude){
    //wave
    ofPushStyle();
    ofFill();
    //ofSetColor(red,0,255, amplitude*255);
    ofSetColor(0,0,255);
    for(int i=0; i<numRects; i++){
        float y1 = shape.height/2;
        int bufferSlice=myBufferSize/numRects;
        float y2 = buffer[bufferSlice*i] * (shape.height);
        float rectWidth = shape.width/numRects;
        float x = i*rectWidth;
        ofDrawRectangle((shape.x + x), shape.y + y1, rectWidth, y2);
    }
    ofPopStyle();
}
