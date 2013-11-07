//
//  ConversationSoundPlayer.cpp
//  promenade_mobile_tvs
//
//  Created by Alain Barthelemy on 28/10/13.
//
//

#include "ConversationSoundPlayer.h"

ConversationSoundPlayer::ConversationSoundPlayer(float _x, float _y, float _w, float _h)
{
	x = _x;
	y = _y;
	w = _w;
    h = _h;
    
    //sound.loadSound("sounds/01 Boring Angel.mp3");
    //sound.loadSound("sounds/sound1.m4a",true);
	sound.setVolume(1.0f);
	sound.setMultiPlay(true);
    sound.setLoop(true);
    
    
    ofRegisterURLNotification(this);

    ofSaveURLAsync("http://pm.alainbarthelemy.com/conversations/sounds/sound3.mp3", "../data/sounds/sound3.mp3");
}

void ConversationSoundPlayer::update(){
	//w = ofGetWidth();
    //h = ofGetHeight();
    
    //ofSoundUpdate();
	
}

void ConversationSoundPlayer::draw(){
}

void ConversationSoundPlayer::start(){
    //ofSaveURLAsync("http://pm.alainbarthelemy.com/conversations/sounds/sound3.mp3", "../data/sounds/sound3.mp3");

    sound.setVolume(1.0f);
}

void ConversationSoundPlayer::stop(){
    sound.setVolume(0.0f);
}

void ConversationSoundPlayer::urlResponse(ofHttpResponse & response ){
    if(response.status==200 && response.request.name == "../data/sounds/sound3.mp3"){
        sound.loadSound("sounds/sound3.mp3",true);
        sound.play();
	}else {
		cout << response.status << " " << response.error << endl;
	}
}

void ConversationSoundPlayer::exit() {
    //loader.stopThread();
    ofUnregisterURLNotification(this);
    
}