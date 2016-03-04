//
//  ofxAVUIVisualWave.h
//
//  Created by Borut Kumperscak on 03/03/2016.
//
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
    int  red;

};

#endif /* ofxAVUIVisualWave_h */
