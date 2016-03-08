//
//  ofxAVUIToggle.h
//
//  Part of ofxAVUI addon. Developed by Nuno Correia and Borut Kumperscak in 2016.
//  https://github.com/AVUIs/ofxAVUI
//

#ifndef ofxAVUIToggle_h
#define ofxAVUIToggle_h

#include "ofMain.h"
#include "ofxAVUIBase.h"


class ofxAVUIToggle : public ofxAVUIBase {
public:
    ofxAVUIToggle() {};
    ofxAVUIToggle(string _title, string _paramBool);
    virtual ~ofxAVUIToggle();

    void mouseMoved(ofMouseEventArgs & args);
    void mousePressed(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);
    void mouseScrolled(ofMouseEventArgs & args);

    void draw();

private:
    string      param1;
};

#endif /* ofxAVUIToggle_h */
