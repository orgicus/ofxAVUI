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

#define DOUBLECLICK_MILLIS 200


class ofxAVUIXYPad : public ofxAVUIBase {
public:
    ofxAVUIXYPad() {};
    ofxAVUIXYPad(string _title, string _paramBool, string _paramFloat1, string _paramFloat2);
    ~ofxAVUIXYPad();
    virtual void setPosition(int _x, int _y, int _width, int _height);   //polymorhing so we can set the starting position for cursor
    
    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseScrolled(ofMouseEventArgs & args);
    
    void update();
    void draw();

private:
    float            savedX, savedY;
    float            savedHorizVal, savedVertVal;
    ofRectangle      location;
    bool             dragging;
    long             doubleClickTimer;
    bool             clicking;
    ofMouseEventArgs mouseArgs;
    string           paramX, paramY, paramBool;
};

#endif /* ofxAVUIXYPad_h */
