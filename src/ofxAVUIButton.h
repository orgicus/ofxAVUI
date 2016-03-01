//
//  ofxAVUIButton.h
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#ifndef ofxAVUIButton_h
#define ofxAVUIButton_h

#include "ofMain.h"
#include "ofxAVUIBase.h"


class ofxAVUIButton : public ofxAVUIBase {
public:
    ofxAVUIButton() {};
    ofxAVUIButton(string _paramBool, ofColor _bgColor, ofColor _fgColor);
    virtual ~ofxAVUIButton();
    
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

#endif /* ofxAVUIButton_h */
