//
//  ofxAVUIVisualCircles.cpp
//
//  Created by Borut Kumperscak on 03/03/2016.
//
//

#include "ofxAVUIVisualCircles.h"

ofxAVUIVisualCircles::ofxAVUIVisualCircles(int nCircles){
    numCircles=nCircles;
}

void ofxAVUIVisualCircles::draw(float * buffer, float amplitude){
    //wave
    ofPushStyle();
    ofFill();
    ofSetColor(visColor);
    for(int i=0; i<numCircles; i++){
        float y1 = shape.height/2;
        int bufferSlice=myBufferSize/numCircles;
        float y2 = buffer[bufferSlice*i] * (shape.height);
        float circleSpacing = shape.width/numCircles;
        float x = i*circleSpacing+circleSpacing/2;
        ofDrawCircle(shape.x + x, shape.y+ y1, y2);
    }
    ofPopStyle();
}
