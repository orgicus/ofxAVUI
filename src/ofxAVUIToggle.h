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
    ofxAVUIToggle();
    virtual ~ofxAVUIToggle();

    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseScrolled(ofMouseEventArgs & args);

    void draw();

};

#endif /* ofxAVUIToggle_h */
