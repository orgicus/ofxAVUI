//
//  ofxAVUIVisualCircles.h
//
//  Part of ofxAVUI addon. Developed by Nuno Correia and Borut Kumperscak in 2016.
//  https://github.com/AVUIs/ofxAVUI
//

#ifndef ofxAVUIVisualCircles_h
#define ofxAVUIVisualCircles_h

#include "ofMain.h"
#include "ofxAVUIVisualBase.h"

class ofxAVUIVisualCircles : public ofxAVUIVisualBase {
public:
    // put any setup code in a custom constructor
    ofxAVUIVisualCircles(int nCircles);
    
    void draw(float *buffer, float amplitude);
    
private:
    int numCircles;

};

#endif /* ofxAVUIVisualCircles_h */
