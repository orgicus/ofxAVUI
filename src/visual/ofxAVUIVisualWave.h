//
//  ofxAVUIVisualWave.h
//
//  Part of ofxAVUI addon. Developed by Nuno Correia and Borut Kumperscak in 2016.
//  https://github.com/AVUIs/ofxAVUI
//

#ifndef ofxAVUIVisualWave_h
#define ofxAVUIVisualWave_h

#include "ofMain.h"
#include "ofxAVUIVisualBase.h"

class ofxAVUIVisualWave : public ofxAVUIVisualBase {
public:
    // put any setup code in a custom constructor
    ofxAVUIVisualWave();
    
    void draw(float *buffer, float amplitude);
    
private:

};

#endif /* ofxAVUIVisualWave_h */
