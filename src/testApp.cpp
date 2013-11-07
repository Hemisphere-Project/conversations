#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    soundPlayer = new ConversationSoundPlayer(0,0,ofGetWindowWidth(),ofGetWindowHeight());
    text = new ConversationText(0,0,ofGetWindowWidth(),ofGetWindowHeight());
    
}

//--------------------------------------------------------------
void testApp::update(){
    //soundPlayer->update();
    text->update();
}

//--------------------------------------------------------------
void testApp::draw(){
    //soundPlayer->draw();
    text->draw();
}

//--------------------------------------------------------------
void testApp::exit(){
    //soundPlayer->stop();
    //text->exit();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
