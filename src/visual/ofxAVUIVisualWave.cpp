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
    //ofSetLineWidth(1);
    for(int i=0; i<myBufferSize; i++){
        float p = i / (float)(myBufferSize);
        float y2 = buffer[i] * (shape.height);
//        if(fullscreen){
//            float x = p * ofGetWidth();
//            float rectWidth=ofGetWidth()/myBufferSize;
//            ofRect(x, posY+y1,rectWidth,posY+y2);
//        }else{
            float x = p * shape.width;
            float rectWidth = shape.width/myBufferSize;
            ofRect(shape.x + x, shape.y, rectWidth, shape.y + y2);
//        }
    }
    ofPopStyle();
}
