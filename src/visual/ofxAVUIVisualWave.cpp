//
//  ofxAVUIVisualWave.cpp
//
//  Created by Borut Kumperscak on 03/03/2016.
//
//

#include "ofxAVUIVisualWave.h"

ofxAVUIVisualWave::ofxAVUIVisualWave(){
    red = ofMap(shape.x,0,ofGetWidth()-shape.width,0,127);
}

void ofxAVUIVisualWave::draw(float * buffer, float amplitude){
    //wave
    ofPushStyle();
    ofFill();
    ofSetColor(red,0,255, amplitude*255);
    for(int i=0; i<myBufferSize; i++){
    float p = i / (float)(myBufferSize);
    float y1 = shape.height/2;
    float y2 = buffer[i] * (shape.height);
        float x = p * shape.width;
        float rectWidth = shape.width/myBufferSize;
        ofDrawRectangle(shape.x + x, shape.y + y1, rectWidth, y2);
    }
    ofPopStyle();
}
