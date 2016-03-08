//
//  ofxAVUISoundFxDelay.h
//
//  Part of ofxAVUI addon. Developed by Nuno Correia and Borut Kumperscak in 2016.
//  https://github.com/AVUIs/ofxAVUI
//

#ifndef ofxAVUISoundFxDelay_h
#define ofxAVUISoundFxDelay_h

#include "ofMain.h"
#include "ofxMaxim.h"
#include "ofxAVUISoundFxBase.h"

class ofxAVUISoundFxDelay : public ofxAVUISoundFxBase {
public:
// put any setup code in a custom constructor

    double  compute(double _sampleIn);
    
private:
    maxiDelayline myDelayLine;
};

#endif /* ofxAVUISoundFxDelay_h */
