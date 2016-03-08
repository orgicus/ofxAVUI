//
//  ofxAVUISlider.h
//
//  Part of ofxAVUI addon. Developed by Nuno Correia and Borut Kumperscak in 2016.
//  https://github.com/AVUIs/ofxAVUI
//

#ifndef ofxAVUISlider_h
#define ofxAVUISlider_h

#include "ofMain.h"
#include "ofxAVUIBase.h"

#define DOUBLECLICK_MILLIS 200

class ofxAVUISlider : public ofxAVUIBase {
public:
    ofxAVUISlider() {};
    ofxAVUISlider(string _title, string _paramBoolTrigger, string _paramBoolToggle, string _paramFloat);
    virtual ~ofxAVUISlider();
    virtual void setPosition(int _x, int _y, int _width, int _height);   //polymorhing so we can set the starting position for cursor

    void mouseMoved(ofMouseEventArgs & args);
    void mousePressed(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);
    void mouseScrolled(ofMouseEventArgs & args);

    void update();  //set UI state based on parameters
    void draw();

private:
    int              x;
    bool             dragging;
    long             doubleClickTimer;
    bool             clicking;
    ofMouseEventArgs mouseArgs;
    string           param1, paramBoolTrigger, paramBoolToggle;

};

#endif /* ofxAVUISlider_h */
