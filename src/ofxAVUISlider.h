//
//  ofxAVUISlider.h
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#ifndef ofxAVUISlider_h
#define ofxAVUISlider_h

#include "ofMain.h"
#include "ofxAVUIBase.h"

#define DOUBLECLICK_MILLIS 200

class ofxAVUISlider : public ofxAVUIBase {
public:
    ofxAVUISlider() {};
    ofxAVUISlider(string _title, string _paramBool, string _paramFloat);
    virtual ~ofxAVUISlider();
    virtual void setPosition(int _x, int _y, int _width, int _height);   //polymorhing so we can set the starting position for cursor

    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseScrolled(ofMouseEventArgs & args);

    void draw();

private:
    int              x;
    bool             dragging;
    long             doubleClickTimer;
    bool             clicking;
    ofMouseEventArgs mouseArgs;
    string           param1, paramBool;
};

#endif /* ofxAVUISlider_h */
