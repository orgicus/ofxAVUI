//
//  ofxAVUIZone.h
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#ifndef ofxAVUIZone_h
#define ofxAVUIZone_h

#include "ofMain.h"
#include "ofxMaxim.h"
#include "ofxAVUIBase.h"
#include "ofxAVUIXYPad.h"
#include "ofxAVUIButton.h"
#include "ofxAVUIToggle.h"
#include "ofxAVUILabel.h"
#include "ofxAVUISlider.h"
#include "ofxAVUIZonePlayer.h"

class ofxAVUIZone {
	
public:
	ofxAVUIZone();
	~ofxAVUIZone();
    ofxAVUIZone* setup(string _name, int _x, int _y, int _width, int _height, string _sound, int _bufferSize);
    void update();
    void draw();
    
    //sound
    void play(int pos);
    double getOutput(int channel);

    //event handlers for parameters
//    void nullChanged(char &_null);    //debug
    void pitchChanged(float &_pitch);
    void volumeChanged(float &_volume);
    void loopingChanged(bool &_looping);
    void triggerReceived(bool &_trigger);
    
    //UI
    void addUI(ofxAVUIBase * _element, float _pctFromTop, float _pctHeight);

private:
    bool                loaded;
    ofRectangle         shape;
    string              name;
    ofxAVUIZonePlayer   player;

    //properties
    ofParameter<char>  devNull; //we don't use first parameter in the group, as it is returned by parameterGroup->get(param1) whenever param1 doesn't match any of the parameter namess
    ofParameter<float>  pitch; //speed;
    ofParameter<float>  volume; //amplitude;
    ofParameter<bool>   looping;
    ofParameter<bool>   trigger;
    ofParameterGroup    soundProperties;
    
    std::vector <ofxAVUIBase *> elements;   //UI elements

};


#endif /* ofxAUVIZone_h */
