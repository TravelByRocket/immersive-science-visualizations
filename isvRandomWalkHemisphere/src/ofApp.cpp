#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    float omega = ofRandom(-20,20);
    walker.theta += omega;
    
    float stepDistance = 0.02;
    float dx = cos(ofDegToRad(walker.theta)) * stepDistance;
    float dy = sin(ofDegToRad(walker.theta)) * stepDistance;
    
    glm::quat latRot = glm::angleAxis(dx, glm::vec3(1, 0, 0));
    glm::quat lonRot = glm::angleAxis(dy, glm::vec3(0, 1, 0));
    walker.curRot = latRot * lonRot * walker.curRot;
    
//    alternative to using lat/lon is adjusting unit vector to make quat from, same or similar results to above
//    glm::quat wander = glm::angleAxis(stepDistance, glm::vec3(dx, dy, 0));
//    ofDrawLine(glm::vec3(0,0,0),wander * glm::vec3(0,0,300));
//    walker.curRot = wander * walker.curRot;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2); // move to middle of screen
    ofRotateDeg(ofGetMouseX(), 0, 1, 0); // rotate about Y when moving Left-Right
    ofRotateDeg(ofGetMouseY(), 1, 0, 0); // rotate about X when moving Up-Down
    
    ofBackground(50);
    ofSetColor(200);
    
    glm::vec3 center = glm::vec3(0,0,300); // the quat example I found uses "center" but not sure it's a good name for my use
    glm::vec3 position = walker.curRot * center;
    
    // bounce the walker off of the z=0 plane
    if (position.z <= 0 && position.x <=0) {
        walker.theta = 90;
    } else if (position.z <= 0 && position.x >0) {
        walker.theta = -90;
    }
    
    ofDrawSphere(position, 10); // draw the walker position as a sphere
    ofDrawLine(glm::vec3(0,0,0),position); // draw line to the walker
    
    ofSetLineWidth(2);
    trail.push_back(position);
    if (trail.size() > 4){ // if there are some point in the trail to draw
        for (int i = 0; i < trail.size() - 2; i++) { // for each trail point
            ofSetColor((trail[i].z / 300) * 255, // set some RGB variation basd on XYZ
                       (trail[i].y / 300) * 255,
                       ((300 - trail[i].z) / 300) * 255);
            ofDrawLine(trail[i], trail[i+1]); // draw a line between adjacent trail point
        }
    }
    ofLog() << ofVec3f(position).distance(trail[trail.size()-2]); // monitor the distance, looking for cause of distorted travel neasr z=0
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
        saveScreen();
    } else if(key == 'd'){ // press 'd' to print distance between trail points and their locations. Only one axis was a candidate for causing step length change but then step length changed seemed more closely related to turns than it did to distortion neasr z=0
        for (int i = 0; i < trail.size() - 2; i++) {
            ofLog() << trail[i];
            ofLog() << trail[i].distance(trail[i+1]);
        }
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

void ofApp::saveScreen(){
    image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    image.save(ofGetTimestampString() + ".png");
}
