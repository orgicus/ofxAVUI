//
//  ofxAVUIEmpty.h
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#ifndef ofxAVUIEmpty_h
#define ofxAVUIEmpty_h

#include "ofMain.h"
#include "ofxAVUIBase.h"


class ofxAVUIEmpty : public ofxAVUIBase {
public:
    ofxAVUIEmpty(string _title);
    virtual ~ofxAVUIEmpty();

    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseScrolled(ofMouseEventArgs & args);

    void draw();

};

#endif /* ofxAVUIEmpty_h */
