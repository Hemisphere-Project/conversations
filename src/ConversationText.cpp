//
//  ConversationText.cpp
//  promenade_mobile_tvs
//
//  Created by Alain Barthelemy on 28/10/13.
//
//

#include "ConversationText.h"

ConversationText::ConversationText(float _x, float _y, float _w, float _h)
{
	x = _x;
	y = _y;
	w = _w;
    h = _h;
    
    verdana30.loadFont("verdana.ttf", 30, true, true);
	verdana30.setLineHeight(34.0f);
	verdana30.setLetterSpacing(1.035);
    verdana30.setEncoding(OF_ENCODING_UTF8);
    
    textIndex = 0;
    timestamp = ofGetUnixTime();
    textChangeTS = ofGetElapsedTimeMillis();
    load();
    
    //startThread();
    
}

void ConversationText::update(){
	w = ofGetWidth();
    h = ofGetHeight();

    // -- RELOAD CHECK ---------------------------------------------------//
    if(ofGetUnixTime() <= (timestamp + TEXT_RELOAD_PERIOD)){
    }else if(ofGetUnixTime() > (timestamp + TEXT_RELOAD_PERIOD)){
        timestamp = ofGetUnixTime();//reset the counter
        load();
    }

    
    // -- TEXT CHANGE CHECK ----------------------------------------------//
    if(ofGetElapsedTimeMillis() <= (textChangeTS + TEXT_CHANGE_PERIOD)){
    }else if(ofGetElapsedTimeMillis() > (textChangeTS + TEXT_CHANGE_PERIOD)){
        textChangeTS = ofGetElapsedTimeMillis();//reset the counter
        textIndex++;
        if(textIndex >= XML_LENGHT)
            textIndex = 0;
    }
    

}

void ConversationText::draw(){
    ofSetColor(0,0,0);
    ofRect(x,y,w,h);
    if(xml.exists("tag["+ofToString(textIndex)+"]")){
       //cout << xml.getValue("tag["+ofToString(textIndex)+"]") << "\n";
        ofSetColor(255);
        current_tag = xml.getValue("tag["+ofToString(textIndex)+"]");
        
        ofRectangle rect = verdana30.getStringBoundingBox(current_tag, 0,0);
        if(verdana30.isLoaded())
            verdana30.drawString(current_tag, w/2 - verdana30.stringWidth(current_tag)/2, h/2 );
    }
}

void ConversationText::threadedFunction() {
    
    while (isThreadRunning()) {
        
        
        // call the system command say
        
        #ifdef TARGET_OSX
                //string cmd = "say "+current_tag+" ";   // create the command
                string cmd = "say "+current_tag;   // create the command
                if(current_tag != "")
                system(cmd.c_str());
        #endif
        #ifdef TARGET_WIN32
                string cmd = "data\\SayStatic.exe "+current_tag;   // create the command
                cout << cmd << endl;
                system(cmd.c_str());
        #endif
        #ifdef TARGET_LINUX_ARM
                string cmd = "echo "+current_tag+" | espeak -v french -s 140";   // create the command
                system(cmd.c_str());
        #endif
        
        // slowdown boy
        ofSleepMillis(10);
    }
}

void ConversationText::load(){
    ofHttpResponse response = ofLoadURL("http://pm.alainbarthelemy.com/conversations/tags.xml");
    if(response.status==200 && response.request.name == "http://pm.alainbarthelemy.com/conversations/tags.xml"){
        string xmlFromServer = response.data;
        xml.loadFromBuffer(xmlFromServer);
        XML_LENGHT = xml.getNumChildren();
        cout << "NUM children  "<< XML_LENGHT << "\n";
        cout << "xml =  "<< xml.toString()<<"\n";
    }else{
        cout << response.status << " " << response.error << endl;
    }
}

void ConversationText::start(){

}

void ConversationText::stop(){

}

void ConversationText::exit(){
    //waitForThread(true);
}