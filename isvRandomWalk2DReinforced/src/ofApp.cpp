#include "ofApp.h"

int durUpdate = 0;
int durDraw = 0;
bool willScreenGrab = false;
bool isRecording = false;

//--------------------------------------------------------------
void ofApp::setup(){
    myfont.load("RajdhaniM.ttf", 18);
    map.setup();
    for (int k = 0; k < 50; k++) {
        Ant tempAnt = Ant();
        ants.push_back(tempAnt);
        ants[k].setup();
    }
    
    ofLog() << "Press 's' to save a single screenshot or 'r' to record continuously";
}

//--------------------------------------------------------------
void ofApp::update(){
    int tempTime = (int) ofGetElapsedTimeMillis(); // used to monitor performance
    for (int l = 0; l < ants.size(); l++) {
        ants[l].signalStrengthLeft = map.getP(ants[l].antennaLocLeft); // TODO change this to some kind of method
        ants[l].signalStrengthRight = map.getP(ants[l].antennaLocRight);
        
        for (int m = l + 1; m < ants.size(); m++) {
            ants[l].checkCollisionWith(ants[m]);
        }
        
        ants[l].update();
        map.addP(ants[l].loc);
    }
    
    map.update();
    
    durUpdate = (int) (ofGetElapsedTimeMillis() - tempTime);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    int tempTime = (int) ofGetElapsedTimeMillis();
    ofBackground(30);
    
    map.draw();
    
    for (int m = 0; m < ants.size(); m++) {
        ants[m].draw();
    }
    
    
    if (willScreenGrab) {
        saveScreen();
        willScreenGrab = false;
    }
    
    if (isRecording) {
        saveScreen();
        if (ofGetFrameNum() % 20 < 10) {
            ofSetColor(ofColor::red);
            ofDrawCircle(ofGetWidth() * 0.9, ofGetHeight() * 0.9, 8);
        }
    }
    
    durDraw = (int) (ofGetElapsedTimeMillis() - tempTime);
    ofNoFill();
    ofSetColor(ofColor::orange);
    myfont.drawString("    draw " + ofToString(durDraw), ofGetWidth()/15, ofGetHeight()*18/20);
    ofDrawRectangle(ofGetWidth()*2/10, ofGetHeight()*71/80, durDraw*4, ofGetHeight()/80);
    myfont.drawString("update " + ofToString(durUpdate), ofGetWidth()/15, ofGetHeight()*19/20);
    ofDrawRectangle(ofGetWidth()*2/10, ofGetHeight()*75/80, durUpdate*4, ofGetHeight()/80);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
        willScreenGrab = true;
    }
    if(key == 'r'){
        isRecording = !isRecording;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::exit(){
    saveScreen();
}

void ofApp::saveScreen(){
    image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    image.save(ofGetTimestampString() + ".png");
}
