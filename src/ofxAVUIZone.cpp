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
    ofSetCircleResolution(100);
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

void ofxAVUIZone::addSoundFx(ofxAVUISoundFxBase * _fxElement) {
    player.addSoundFx(_fxElement);
//    soundProperties.add(delayOn.set("delayToggle", false));
    soundProperties.add(*_fxElement->getParameter(0));
    soundProperties.add(*_fxElement->getParameter(1));
    soundProperties.add(*_fxElement->getToggle());
}

//void ofxAVUIZone::nullChanged(char & _null){
//    cout << name << " null = " << _null << endl;
//}

void ofxAVUIZone::pitchChanged(float & _pitch){
    player.speed = _pitch;
}

void ofxAVUIZone::volumeChanged(float & _volume){
    player.amplitude = _volume;
}

void ofxAVUIZone::triggerReceived(bool &_trigger){
    cout << "BUM ! " << "pitch " << pitch << " volume " << volume << endl;
    player.trigger(pitch, volume);
}

void ofxAVUIZone::loopingChanged(bool & _looping){
    player.looping = !player.looping;
}

void ofxAVUIZone::update() {
}

void ofxAVUIZone::draw() {
    ofPushStyle();
    ofNoFill();
    ofDrawRectangle(shape);
    ofPopStyle();
    for(std::size_t i = 0; i < uis.size(); i++){
        uis[i]->draw();
    }
    for(std::size_t i = 0; i < visuals.size(); i++){
        visuals[i]->draw(player.buffer, player.amplitude);
    }
}

void ofxAVUIZone::play(int pos) {
    if (loaded) {
        double sample = player.play(pos, 0.5);
//        for(std::size_t i = 0; i < visuals.size(); i++){
//            visuals[i]->compute(pos, sample);
//        }
    }
}

double ofxAVUIZone::getOutput(int channel) {
    return player.outputs[channel];
}


void ofxAVUIZone::addUI(ofxAVUIBase * _element, float _pctFromTop, float _pctHeight) {
    uis.push_back(_element);
	_element->setPosition(shape.x, shape.y + shape.height*_pctFromTop, shape.width, shape.height*_pctHeight);
    _element->bindProperties(&soundProperties);
}

void ofxAVUIZone::addVisual(ofxAVUIVisualBase * _element, float _pctFromTop, float _pctHeight) {
    visuals.push_back(_element);
    _element->setup(player.myBufferSize);
	_element->setPosition(shape.x, shape.y + shape.height*_pctFromTop, shape.width, shape.height*_pctHeight);
}



