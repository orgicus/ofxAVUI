//
//  ofxAVUISoundFxDelay.h
//
//  Created by Borut Kumperscak on 02/03/2016.
//
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
