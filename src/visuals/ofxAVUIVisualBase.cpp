//
//  ofxAVUIVisualBase.cpp
//
//  Created by Borut Kumperscak on 03/03/2016.
//
//

#include "ofxAVUIVisualBase.h"

ofxAVUIVisualBase::ofxAVUIVisualBase(){
    shape.x = 0;
    shape.y = 0;
    shape.width = 0;
    shape.height = 0;
}

void ofxAVUIVisualBase::setup(int _bufferSize) {
    myBufferSize = _bufferSize;
}

void ofxAVUIVisualBase::setPosition(int _x, int _y, int _width, int _height) {
    shape.x = _x;
    shape.y = _y;
    shape.width = _width;
    shape.height = _height;
}

