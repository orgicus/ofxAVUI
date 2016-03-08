//
//  ofxAVUIVisualBase.h
//
//  Created by Borut Kumperscak on 03/03/2016.
//
//

#ifndef ofxAVUIVisualBase_h
#define ofxAVUIVisualBase_h

#include "ofMain.h"


class ofxAVUIVisualBase {

public:
    ofxAVUIVisualBase();
    void setup(int _bufferSize, ofColor _visColor);
    void setPosition(int _x, int _y, int _width, int _height);
    
    virtual void draw(float *buffer, float amplitude) = 0;                   //every child needs to implement this

protected:
    ofRectangle     shape;
    int             myBufferSize;
    ofColor visColor;
};




#endif /* ofxAVUIVisualBase_h */
