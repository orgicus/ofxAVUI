//
//  ofxAVUIBase.h
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#ifndef ofxAVUIBase_h
#define ofxAVUIBase_h

#include "ofMain.h"

class ofxAVUIBase {

public:
    ofxAVUIBase();
    virtual ~ofxAVUIBase();
    void setPosition(int _x, int _y, int _width, int _height);
    virtual void draw() = 0;

protected:
    int         x, y;
    int         width, height;
};

#endif /* ofxAVUIBase_h */
