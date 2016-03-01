//
//  ofxAVUIZone.cpp
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#include "ofxAVUIZone.h"

ofxAVUIZone::ofxAVUIZone() {
    name = "";
    shape.x = 0;
    shape.y = 0;
    shape.width = 0;
    shape.height = 0;
    loaded = false;
}

ofxAVUIZone::~ofxAVUIZone() {
}

ofxAVUIZone* ofxAVUIZone::setup(string _name, int _x, int _y, int _width, int _height, string _sound, int _bufferSize) {
    name = _name;
    shape.x = _x;
    shape.y = _y;
    shape.width = _width;
    shape.height = _height;
    player.setup(ofToDataPath(_sound), _bufferSize);
    player.looping = true;

    soundProperties.add(devNull.set("null", 1.0, 0.0, 2.0));
//    devNull.addListener(this,&ofxAVUIZone::nullChanged);

    soundProperties.add(pitch.set("pitch", 1.0, 0.0, 2.0));
    pitch.addListener(this,&ofxAVUIZone::pitchChanged);

    soundProperties.add(volume.set("volume", 1.0, 0.0, 2.0));
    volume.addListener(this,&ofxAVUIZone::volumeChanged);

    soundProperties.add(looping.set("looping", true));
    looping.addListener(this,&ofxAVUIZone::loopingChanged);

    soundProperties.add(trigger.set("trigger", true));
    trigger.addListener(this,&ofxAVUIZone::triggerReceived);

    loaded = true;
}

//void ofxAVUIZone::nullChanged(char & _null){
//    cout << name << " null = " << _null << endl;
//}

void ofxAVUIZone::pitchChanged(float & _pitch){
    cout << name << " player.speed = " << _pitch << endl;
    player.speed = _pitch;
}

void ofxAVUIZone::volumeChanged(float & _volume){
    player.amplitude = _volume;
    cout << name << " player.amplitude = " << _volume << endl;
}

void ofxAVUIZone::triggerReceived(bool &_trigger){
    player.trigger(pitch, volume);
    cout << name << " player.trigger(pitch, volume);" << endl;
}

void ofxAVUIZone::loopingChanged(bool & _looping){
    player.looping = _looping;
    cout << name << " player.looping = " << _looping << endl;
}


void ofxAVUIZone::update() {
}

void ofxAVUIZone::draw() {
    ofPushStyle();
    ofNoFill();
    ofDrawRectangle(shape);
//    ofDrawBitmapString(sound, shape.x, shape.y);
    ofPopStyle();
    for(std::size_t i = 0; i < elements.size(); i++){
        elements[i]->draw();
    }
}

void ofxAVUIZone::play(int pos) {
    if (loaded) {
        player.play(pos, 0.5);
    }
}

double ofxAVUIZone::getOutput(int channel) {
    return player.outputs[channel];
}


void ofxAVUIZone::addUI(ofxAVUIBase * _element, float _pctFromTop, float _pctHeight) {
    elements.push_back(_element);
	_element->setPosition(shape.x, shape.y + shape.height*_pctFromTop, shape.width, shape.height*_pctHeight);
    _element->bindProperties(&soundProperties);
}



