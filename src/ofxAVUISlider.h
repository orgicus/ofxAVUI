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


class ofxAVUISlider : public ofxAVUIBase {
public:
    ofxAVUISlider() {};
    ofxAVUISlider(string _title, string _paramBool, string _paramFloat);
    virtual ~ofxAVUISlider();

    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseScrolled(ofMouseEventArgs & args);

    void draw();

private:
    int         x;
    bool        dragging;
    string      param1, param2;
};

#endif /* ofxAVUISlider_h */
