//
//  ofxAVUIVisualBars.h
//
//  Created by Borut Kumperscak on 03/03/2016.
//
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
