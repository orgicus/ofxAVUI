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
