#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    theta = 0;
    myfont.load("RajdhaniM.ttf", 32);
}

//--------------------------------------------------------------
void ofApp::update(){
    theta = (theta < 360) ? theta + 0.5 : 0;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawLine(ofGetHeight()/4, ofGetWidth()/2, ofGetHeight()*3/4, ofGetWidth()/2);
    ofDrawLine(ofGetHeight()/2, ofGetWidth()/4, ofGetHeight()/2, ofGetWidth()*3/4);
    ofDrawLine(
               ofGetWidth()/2, ofGetHeight()/2,
               ofGetHeight()/3*cos(ofDegToRad(theta))+ofGetWidth() /2,
               ofGetHeight()/3*sin(ofDegToRad(theta))+ofGetHeight()/2);
    myfont.drawString(ofToString(theta), ofGetWidth()/2, ofGetHeight()/6);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
