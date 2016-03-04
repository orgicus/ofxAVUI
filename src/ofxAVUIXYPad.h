//
//  ofxAVUIXYPad.h
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#ifndef ofxAVUIXYPad_h
#define ofxAVUIXYPad_h

#include "ofMain.h"
#include "ofxAVUIBase.h"


class ofxAVUIXYPad : public ofxAVUIBase {
public:
    ofxAVUIXYPad() {};
    ofxAVUIXYPad(string _title, string _paramBool, string _paramFloat1, string _paramFloat2);
    ~ofxAVUIXYPad();
    virtual void setPosition(int _x, int _y, int _width, int _height);   //overloaded so we can set the starting position for cursor
    
    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseScrolled(ofMouseEventArgs & args);

    void draw();

private:
    ofRectangle location;
    bool        dragging;
    string      paramX, paramY, paramBool;
};

#endif /* ofxAVUIXYPad_h */
