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
    
    void mouseMoved(ofMouseEventArgs & args);
    void mousePressed(ofMouseEventArgs & args);
    void mouseDragged(ofMouseEventArgs & args);
    void mouseReleased(ofMouseEventArgs & args);
    void mouseScrolled(ofMouseEventArgs & args);

    void draw();

private:
    string      param1;
};

#endif /* ofxAVUIButton_h */
