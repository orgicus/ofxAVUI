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
    ofxAVUIButton(string _title, string _paramBool);
    virtual ~ofxAVUIButton();
    
    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseScrolled(ofMouseEventArgs & args);

    void draw();

private:
    string      param1;
};

#endif /* ofxAVUIButton_h */
