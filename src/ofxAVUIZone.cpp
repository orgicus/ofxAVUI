//
//  ofxAVUIZone.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofMain.h"
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
    ofDrawRectangle(x, y, width, height);
    ofDrawBitmapString(sound, x, y);
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
