//
//  ConversationSoundPlayer.h
//  promenade_mobile_tvs
//
//  Created by Alain Barthelemy on 28/10/13.
//
//

#ifndef __promenade_mobile_tvs__ConversationSoundPlayer__
#define __promenade_mobile_tvs__ConversationSoundPlayer__

#include "ofMain.h"
#include "ofURLFileLoader.h"

class ConversationSoundPlayer{
    
public:
    
    void update();
    void draw();
    void start();
    void stop();
    void urlResponse(ofHttpResponse & response);
    void exit();
    
    //constructor
    ConversationSoundPlayer(float x, float y, float w, float h);
    
    float x;
    float y;
    float w;
    float h;
    
     ofSoundPlayer  sound;
    
private:
    
    
    
    
};

#endif /* defined(__promenade_mobile_tvs__ConversationSoundPlayer__) */
