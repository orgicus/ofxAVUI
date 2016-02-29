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
    ofxAVUIButton();
    virtual ~ofxAVUIButton();
    
    bool mouseMoved(ofMouseEventArgs & args);
    bool mousePressed(ofMouseEventArgs & args);
    bool mouseDragged(ofMouseEventArgs & args);
    bool mouseReleased(ofMouseEventArgs & args);
    bool mouseScrolled(ofMouseEventArgs & args);

    void draw();

};

#endif /* ofxAVUIButton_h */
