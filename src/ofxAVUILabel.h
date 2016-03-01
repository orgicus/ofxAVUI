//
//  ofxAVUILabel.h
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#ifndef ofxAVUILabel_h
#define ofxAVUILabel_h

#include "ofMain.h"
#include "ofxAVUIBase.h"


class ofxAVUILabel : public ofxAVUIBase {
public:
    ofxAVUILabel(string _label, ofColor _bgColor, ofColor _fgColor);
    virtual ~ofxAVUILabel();

    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseScrolled(ofMouseEventArgs & args);

    void draw();

private:
    ofColor     bgColor, fgColor;
    string      label;
};

#endif /* ofxAVUILabel_h */
