//
//  ofxAVUIVisualWave.cpp
//
//  Created by Borut Kumperscak on 03/03/2016.
//
//

#include "ofxAVUIVisualWave.h"

ofxAVUIVisualWave::ofxAVUIVisualWave(){
}

void ofxAVUIVisualWave::draw(float * buffer, float amplitude){
    //wave
    ofPushStyle();
    ofFill();
    ofSetColor(visColor);
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
