//
//  ConversationText.h
//  promenade_mobile_tvs
//
//  Created by Alain Barthelemy on 28/10/13.
//
//

#ifndef __promenade_mobile_tvs__ConversationText__
#define __promenade_mobile_tvs__ConversationText__

#include "ofMain.h"
#include "ofURLFileLoader.h"
#include "ofxXmlSettings.h"

#define TEXT_RELOAD_PERIOD 10 // in sec
#define TEXT_CHANGE_PERIOD 1000 // in millis

class ConversationText : public ofThread {

public:
    
    void update();
    void draw();
    
    void threadedFunction();
    
    void load();
    
    void start();
    void stop();
    
    void exit();
    
    //constructor
    ConversationText(float x, float y, float w, float h);
    
    float x;
    float y;
    float w;
    float h;
    
    unsigned int timestamp;
    unsigned long long textChangeTS;
    int textIndex;
    int XML_LENGHT;
    
    string current_tag;
    
    ofXml xml;
    
    ofTrueTypeFont	verdana30;
    
private:
    
    
    
    
};

#endif /* defined(__promenade_mobile_tvs__ConversationSoundPlayer__) */
