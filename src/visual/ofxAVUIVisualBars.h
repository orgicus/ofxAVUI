//
//  ofxAVUIVisualBars.h
//
//  Part of ofxAVUI addon. Developed by Nuno Correia and Borut Kumperscak in 2016.
//  https://github.com/AVUIs/ofxAVUI
//

#ifndef ofxAVUIVisualBars_h
#define ofxAVUIVisualBars_h

#include "ofMain.h"
#include "ofxAVUIVisualBase.h"

class ofxAVUIVisualBars : public ofxAVUIVisualBase {
public:
    // put any setup code in a custom constructor
    ofxAVUIVisualBars(int nRects);
    
    void draw(float *buffer, float amplitude);
    
private:
    int numRects;

};

#endif /* ofxAVUIVisualBars_h */
