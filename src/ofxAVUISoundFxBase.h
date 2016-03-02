//
//  ofxAVUISoundFxBase.h
//
//  Created by Borut Kumperscak on 02/03/2016.
//
//

#ifndef ofxAVUISoundFxBase_h
#define ofxAVUISoundFxBase_h

#include "ofMain.h"


class ofxAVUISoundFxBase {

public:
    ofxAVUISoundFxBase();
    virtual ~ofxAVUISoundFxBase();
    void setup(string _fxName, string _paramName1, float _min1, float _max1, float _default1,
                               string _paramName2, float _min2, float _max2, float _default2);
    void toggle(bool _enabled);
    bool isEnabled();
    void setParameter(string param, float _val);
    
    virtual double compute(double _sampleIn) = 0;   //every child needs to implement this
    
protected:
    bool    enabled;
    string  name;
    string  param1, param2;
    float   min1, max1, val1, min2, max2, val2;
};

#endif /* ofxAVUISoundFxBase_h */
