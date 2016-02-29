//
//  ofxAVUIZone.h
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#ifndef ofxAVUIZone_h
#define ofxAVUIZone_h

#include "ofxMaxim.h"

class ofxAVUIZone {
	
public:
	ofxAVUIZone();
	~ofxAVUIZone();
    ofxAVUIZone* setup(int _x, int _y, int _width, int _height, string _sound);
    void update();
    void draw();
    void play(int pos);
    double getOutput(int channel);

private:
    bool        loaded;
    int         x, y;
    int         width, height;
    string      sound;
    maxiSample  sample;
    double      output[2];
};


#endif /* ofxAUVIZone_h */
