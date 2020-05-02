#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    ofRotateDeg(10, 1, 0.3, 0);
    
    int dist = 200;
    
    ofSetColor(150);
    ofDrawSphere(0,0,0,10);
    ofDrawBitmapString("(0,0,0)", glm::vec3(0 + 20, 0, 0));
    
    ofSetColor(255, 0, 0);
    ofDrawSphere(dist,0,0,10);
    ofDrawBitmapString("(s,o,o)", glm::vec3(dist + 20, 0, 0));
    
    ofSetColor(0, 255, 0);
    ofDrawSphere(0,dist,0,10);
    ofDrawBitmapString("(o,s,o)", glm::vec3(0 + 20, dist, 0));
    
    ofSetColor(0, 0, 255);
    ofDrawSphere(0,0,dist,10);
    ofDrawBitmapString("(0,0,s)", glm::vec3(0 + 20, 0, dist));
    
    ofSetColor(255, 255, 0);
    ofDrawSphere(dist,dist,dist,10);
    ofDrawBitmapString("(s,s,s)", glm::vec3(dist + 20, dist, dist));
    
    ofSetColor(255);
    ofDrawBitmapString("it's left-handed", glm::vec3(-100, -100, 0));
    
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
