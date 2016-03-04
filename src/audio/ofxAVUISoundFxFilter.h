//
//  ofxAVUISoundFxFilter.h
//
//  Created by Borut Kumperscak on 02/03/2016.
//
//

#ifndef ofxAVUISoundFxFilter_h
#define ofxAVUISoundFxFilter_h

#include "ofMain.h"
#include "ofxMaxim.h"
#include "ofxAVUISoundFxBase.h"

class ofxAVUISoundFxFilter : public ofxAVUISoundFxBase {
public:
// put any setup code in a custom constructor

    double  compute(double _sampleIn);
    
private:
    maxiFilter myFilter;
};

#endif /* ofxAVUISoundFxFilter_h */
