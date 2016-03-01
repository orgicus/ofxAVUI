//
//  ofxAVUIToggle.h
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#ifndef ofxAVUIToggle_h
#define ofxAVUIToggle_h

#include "ofMain.h"
#include "ofxAVUIBase.h"


class ofxAVUIToggle : public ofxAVUIBase {
public:
    ofxAVUIToggle() {};
    ofxAVUIToggle(string _paramBool, ofColor _bgColor, ofColor _fgColor);
    virtual ~ofxAVUIToggle();

    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseScrolled(ofMouseEventArgs & args);

    void draw();

private:
    ofColor     bgColor, fgColor;
    string      param1;

};

#endif /* ofxAVUIToggle_h */
