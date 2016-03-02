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

    soundProperties.add(frequency.set("frequency", 5000, 20, 20000));
    frequency.addListener(this,&ofxAVUIZone::frequencyChanged);

    soundProperties.add(resonance.set("resonance", 50, 0, 100));
    resonance.addListener(this,&ofxAVUIZone::resonanceChanged);

    soundProperties.add(filterOn.set("filterToggle", false));
    filterOn.addListener(this,&ofxAVUIZone::filterOnChanged);

    soundProperties.add(size.set("size", 10000, 20000, 40000));
    size.addListener(this,&ofxAVUIZone::sizeChanged);

    soundProperties.add(feedback.set("feedback", 0.75, 0.5, 0.999));
    feedback.addListener(this,&ofxAVUIZone::feedbackChanged);

    soundProperties.add(delayOn.set("delayToggle", false));
    delayOn.addListener(this,&ofxAVUIZone::delayOnChanged);

    loaded = true;
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
    player.trigger(pitch, volume);
}

void ofxAVUIZone::loopingChanged(bool & _looping){
    player.looping = !player.looping;
}

void ofxAVUIZone::frequencyChanged(float & _frequency){
    player.filter(frequency, resonance);
}

void ofxAVUIZone::resonanceChanged(float & _resonance){
    player.filter(frequency, resonance);
}

void ofxAVUIZone::filterOnChanged(bool &_filterOn){
//    player.filterOn = !player.filterOn;
}

void ofxAVUIZone::sizeChanged(float & _size){
    player.delay(size, feedback);
}

void ofxAVUIZone::feedbackChanged(float & _feedback){
    player.delay(size, feedback);
}

void ofxAVUIZone::delayOnChanged(bool &_delayOn){
//    player.delayOn = !player.delayOn;
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



