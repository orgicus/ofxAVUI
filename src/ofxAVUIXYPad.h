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
    ofxAVUIXYPad(string _paramFloat1, float _min1, float _max1,
                 string _paramFloat2, float _min2, float _max2,
                 string _paramBool,
                 ofColor _bgColor, ofColor _fgColor);
    ~ofxAVUIXYPad();

    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseScrolled(ofMouseEventArgs & args);

    void draw();

private:
    ofColor     bgColor, fgColor;
    ofRectangle location;
    bool        dragging;
    string      param1, param2, param3;
    float       min1, max1, min2, max2;
};

#endif /* ofxAVUIXYPad_h */
