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
    ofxAVUIToggle(string _title, string _paramBool);
    virtual ~ofxAVUIToggle();

    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseScrolled(ofMouseEventArgs & args);

    void draw();

private:
    string      param1;
};

#endif /* ofxAVUIToggle_h */
