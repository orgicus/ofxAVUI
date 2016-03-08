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
