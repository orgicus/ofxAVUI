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

class ofxAVUIZone {
	
public:
	ofxAVUIZone();
	~ofxAVUIZone();
    ofxAVUIZone* setup(int _x, int _y, int _width, int _height, string _sound);
    void update();
    void draw();
    void play(int pos);
    double getOutput(int channel);
    
//    void addUI(int _type, float _pctFromTop, float _pctHeight);
    void addUI(ofxAVUIBase * _element, float _pctFromTop, float _pctHeight);

private:
    bool        loaded;
    int         x, y;
    int         width, height;
    string      sound;
    maxiSample  sample;
    double      output[2];
    
    std::vector <ofxAVUIBase *> elements;

};


#endif /* ofxAUVIZone_h */
