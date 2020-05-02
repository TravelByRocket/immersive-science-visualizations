#include "ofApp.h"


Predator osprey;
//vector <Plant> manyPlantees;

//--------------------------------------------------------------
void ofApp::setup(){
    osprey.setup();
    for (int i = 0; i < NUMBUNS; i++) {
        bunbuns[i].setup();
    }
    dandy.setup(ofVec2f(ofRandomWidth(),ofGetHeight()*3/4));
    monster.setup(ofVec2f(ofRandomWidth(),ofGetHeight()*3/4));
    
    for (int k = 0; k < 5; k++){
        Dandelion newD;
        newD.setup(ofVec2f(ofRandomWidth(),ofGetHeight()*3/4));
        manyPlantees.push_back(newD);
        
        Monstera newM;
        newM.setup(ofVec2f(ofRandomWidth(),ofGetHeight()*3/4));
        manyPlantees.push_back(newM);
    }
//    cam.disableOrtho();
//    cam.setupPerspective(true,120,0,10000);
//    cam.setGlobalPosition(ofGetWidth()/2, ofGetHeight()/2, -300);
//    cam.setFov(180);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(200);
    // plants: nothing to update
    for (int i = 0; i < NUMBUNS; i++) {
        bunbuns[i].update();
    }
    osprey.update();
    cam.lookAt(ofVec3f(osprey.loc.x,osprey.loc.y,0));
    float someFOV = 180*((float)mouseY/(float)ofGetHeight());
    cam.setFov(someFOV);
    ofLog() << "FOV set to " << someFOV;
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofSetColor(ofColor::royalBlue);
//    cam.drawFrustum();
//    cam.draw();
//    cam.begin();
//    for (int j = 0; j < NUMPLANTS; j++) {
//        plants[j].draw();
//    }
    dandy.draw();
    monster.draw();
    for (int i = 0; i < NUMBUNS; i++) {
        bunbuns[i].draw();
    }
    osprey.draw();
    for (int l = 0; l < manyPlantees.size(); l++){
        manyPlantees[l].draw();
        ofLog() << "drew a plant at " << manyPlantees[l].loc << " frame " << ofGetFrameNum();
    }
//    cam.end();
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
    osprey.position(ofVec2f(x,y));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    osprey.position(ofVec2f(x,y));
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
