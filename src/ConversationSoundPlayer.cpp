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
	sound1.setVolume(0.5f);
	sound1.setMultiPlay(false);
    sound1.setLoop(false);
    sound2.setVolume(0.5f);
	sound2.setMultiPlay(false);
    sound2.setLoop(false);
    
    timestamp = ofGetUnixTime();
    
    ofRegisterURLNotification(this);

    ofSaveURLAsync("http://pm.alainbarthelemy.com/conversations/sounds/sound1.mp3", "../data/sounds/sound1.mp3");
    ofSaveURLAsync("http://pm.alainbarthelemy.com/conversations/sounds/sound2.mp3", "../data/sounds/sound2.mp3");
}

void ConversationSoundPlayer::update(){
	//w = ofGetWidth();
    //h = ofGetHeight();
    
    ofSoundUpdate();
    
    // -- RELOAD CHECK ---------------------------------------------------//
    if(ofGetUnixTime() <= (timestamp + SOUND_RELOAD_PERIOD)){
    }else if(ofGetUnixTime() > (timestamp + SOUND_RELOAD_PERIOD)){
        timestamp = ofGetUnixTime();//reset the counter
        ofSaveURLAsync("http://pm.alainbarthelemy.com/conversations/sounds/sound1.mp3", "../data/sounds/sound1.mp3");
        ofSaveURLAsync("http://pm.alainbarthelemy.com/conversations/sounds/sound2.mp3", "../data/sounds/sound2.mp3");
    }
	
}

void ConversationSoundPlayer::draw(){
}

void ConversationSoundPlayer::start(){
    //sound.setVolume(1.0f);
}

void ConversationSoundPlayer::stop(){
    //sound.setVolume(0.0f);
}

void ConversationSoundPlayer::urlResponse(ofHttpResponse & response ){
    if(response.status==200 && response.request.name == "../data/sounds/sound1.mp3"){
        sound1.stop();
        sound1.unloadSound();
        sound1.loadSound("sounds/sound1.mp3",true);
        sound1.play();
	}else if(response.status==200 && response.request.name == "../data/sounds/sound2.mp3"){
        sound2.stop();
        sound2.unloadSound();
        sound2.loadSound("sounds/sound2.mp3",true);
        sound2.play();
    }else {
		cout << response.status << " " << response.error << endl;
	}
}

void ConversationSoundPlayer::exit() {
    //loader.stopThread();
    ofUnregisterURLNotification(this);
    
}