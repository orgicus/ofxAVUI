//
//  ofxAVUIZone.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIZone.h"

ofxAVUIZone::ofxAVUIZone() {
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    sound = "";
    output[0] = 0;
    output[1] = 0;
    loaded = false;
}

ofxAVUIZone::~ofxAVUIZone() {
}

ofxAVUIZone* ofxAVUIZone::setup(int _x, int _y, int _width, int _height, string _sound) {
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    sound = _sound;
    sample.load(ofToDataPath(_sound));
    output[0] = 0;
    output[1] = 0;
    loaded = true;
}

void ofxAVUIZone::update() {
}

void ofxAVUIZone::draw() {
    ofPushStyle();
    ofNoFill();
    ofDrawRectangle(x, y, width, height);
    ofDrawBitmapString(sound, x, y);
    ofPopStyle();
    for(std::size_t i = 0; i < elements.size(); i++){
        elements[i]->draw();
    }
}

void ofxAVUIZone::play(int pos) {
    if (loaded) {
        double wave = sample.play(1);
        output[0] = wave;
        output[1] = wave;
    }
}

double ofxAVUIZone::getOutput(int channel) {
    return output[channel];
}


void ofxAVUIZone::addUI(ofxAVUIBase * _element, float _pctFromTop, float _pctHeight) {
    elements.push_back(_element);
	_element->setPosition(x, y + height*_pctFromTop, width, height*_pctHeight);
}



