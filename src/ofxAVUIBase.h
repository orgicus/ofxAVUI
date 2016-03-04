//
//  ofxAVUIBase.h
//
//  Created by Borut Kumperscak on 29/02/2016.
//
//

#ifndef ofxAVUIBase_h
#define ofxAVUIBase_h

#include "ofMain.h"

class ofxAVUIBase {

public:
    ofxAVUIBase();
    virtual ~ofxAVUIBase();
    void setPosition(int _x, int _y, int _width, int _height);
    void setColor(ofColor _bgColor, ofColor _fgColor);
    void setTitle(string _title);
    void bindProperties(ofParameterGroup *_soundProperties);
    void drawContour(); //specific ofxAVUI contour shape
    void drawTitle();
    virtual void draw() = 0;
    
    virtual bool mouseMoved(ofMouseEventArgs & args) = 0;
    virtual bool mousePressed(ofMouseEventArgs & args) = 0;
    virtual bool mouseDragged(ofMouseEventArgs & args) = 0;
    virtual bool mouseReleased(ofMouseEventArgs & args) = 0;
    virtual bool mouseScrolled(ofMouseEventArgs & args) = 0;
    virtual void mouseEntered(ofMouseEventArgs & args) {}
    virtual void mouseExited(ofMouseEventArgs & args) {}

protected:
    ofRectangle         getBitmapStringBoundingBox(string text);
    ofRectangle         shape;
    ofColor             bgColor, fgColor;
    string              title;
    ofParameterGroup   *soundProperties;
};

#endif /* ofxAVUIBase_h */
