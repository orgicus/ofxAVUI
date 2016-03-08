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

    void mouseMoved(ofMouseEventArgs & args);
    void mousePressed(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);
    void mouseScrolled(ofMouseEventArgs & args);

    void draw();

};

#endif /* ofxAVUIEmpty_h */
