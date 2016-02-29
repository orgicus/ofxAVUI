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

    virtual bool mouseMoved(ofMouseEventArgs & args) = 0;
    virtual bool mousePressed(ofMouseEventArgs & args) = 0;
    virtual bool mouseDragged(ofMouseEventArgs & args) = 0;
    virtual bool mouseReleased(ofMouseEventArgs & args) = 0;
    virtual bool mouseScrolled(ofMouseEventArgs & args) = 0;
    virtual void mouseEntered(ofMouseEventArgs & args) {}
    virtual void mouseExited(ofMouseEventArgs & args) {}

protected:
    ofRectangle shape;
};

#endif /* ofxAVUIBase_h */
