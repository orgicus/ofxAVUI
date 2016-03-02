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

//    ofxAVUISoundFxFilter(string _fxName, string _paramName1, float _min1, float _max1, float _default1,
//                                       string _paramName2, float _min2, float _max2, float _default2);
    double  compute(double _sampleIn);
    
private:
    maxiFilter myFilter;
};

#endif /* ofxAVUISoundFxFilter_h */
