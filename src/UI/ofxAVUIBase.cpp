//
//  ofxAVUIBase.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIBase.h"

ofxAVUIBase::ofxAVUIBase(){
    ofRegisterMouseEvents(this, OF_EVENT_ORDER_BEFORE_APP);
}

ofxAVUIBase::~ofxAVUIBase(){
	ofUnregisterMouseEvents(this, OF_EVENT_ORDER_BEFORE_APP);
}

void ofxAVUIBase::setPosition(int _x, int _y, int _width, int _height) {
    shape.x = _x;
    shape.y = _y;
    shape.width = _width;
    shape.height = _height;
}
void ofxAVUIBase::setColor(ofColor _bgColor, ofColor _fgColor) {
    bgColor = _bgColor;
    fgColor = _fgColor;
}

void ofxAVUIBase::bindProperties(ofParameterGroup *_soundProperties) {
    soundProperties = _soundProperties;
}

void ofxAVUIBase::drawContour() {
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
}

void ofxAVUIBase::drawTitle() {
//    ofRectangle titleBounds = getBitmapStringBoundingBox(title);
//    ofDrawBitmapString(title, shape.x + shape.width/2 - titleBounds.width/2, shape.y + shape.height/2 - titleBounds.height/2 + 10);
    ofDrawBitmapString(title, shape.x + 5, shape.y + shape.height - 5);
}

ofRectangle ofxAVUIBase::getBitmapStringBoundingBox(string text){
    vector<string> lines = ofSplitString(text, "\n");
    int maxLineLength = 0;
    for(int i = 0; i < (int)lines.size(); i++) {
        // tabs are not rendered
        const string & line(lines[i]);
        int currentLineLength = 0;
        for(int j = 0; j < (int)line.size(); j++) {
            if (line[j] == '\t') {
                currentLineLength += 8 - (currentLineLength % 8);
            } else {
                currentLineLength++;
            }
        }
        maxLineLength = MAX(maxLineLength, currentLineLength);
    }
    
    int padding = 4;
    int fontSize = 8;
    float leading = 1.7;
    int height = lines.size() * fontSize * leading - 1;
    int width = maxLineLength * fontSize;
    return ofRectangle(0,0,width, height);
}