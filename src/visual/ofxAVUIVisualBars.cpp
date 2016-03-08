//
//  ofxAVUIVisualBars.cpp
//
//  Created by Borut Kumperscak on 03/03/2016.
//
//

#include "ofxAVUIVisualBars.h"

ofxAVUIVisualBars::ofxAVUIVisualBars(int nRects){
    numRects=nRects;
}

void ofxAVUIVisualBars::draw(float * buffer, float amplitude){
    //wave
    ofPushStyle();
    ofFill();
    ofSetColor(visColor);
    for(int i=0; i<numRects; i++){
        float y1 = shape.height/2;
        int bufferSlice=myBufferSize/numRects;
        float y2 = buffer[bufferSlice*i] * (shape.height);
        float rectWidth = shape.width/numRects;
        float x = i*rectWidth;
        ofDrawRectangle(x, y1, rectWidth, y2);
    }
    ofPopStyle();
}
