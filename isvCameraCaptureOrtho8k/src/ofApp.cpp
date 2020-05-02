#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setGlobalPosition(0, 0, 0);
    cam.lookAt(ofVec3f(0,0,1));
    cam.enableOrtho();
    
    ofSetCircleResolution(100);
    ofNoFill();
    
    fbo.allocate(8192,8192,GL_RGBA);
    fbo.begin();
    ofClear(50,50,50,0);
    fbo.end();
    
    willSave = false;
    
    ofLog() << "Press 's' to save the window as PNG and 'd' so save the equivalent 8k FBO as PNG";
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    drawTestPattern(ofGetWidth() * 0.4);
    cam.end();
    
    if (willSave) {
        fbo.begin();
        cam.begin();
        drawTestPattern(fbo.getWidth() * 0.4);
        fbo.draw(0,0);
        saveFboToFile();
        cam.end();
        fbo.end();
    }

}

void ofApp::drawTestPattern(float radius) {
    /// draw a line every 10 degrees of elevation and azimith
    ofPushMatrix();
    ofRotateXDeg(90);
    for (int i = 0; i < 360; i += 10) {
        ofDrawCircle(0, 0, radius);
        ofRotateYDeg(10);
        ofDrawBitmapString(i, glm::vec3(radius, 0, 0));
    }
    ofPopMatrix();
    
    for (int j = 0; j < 90; j += 10) {
        ofDrawCircle(0, 0, radius * sin(ofDegToRad(j)), radius * cos(ofDegToRad(j)));
        ofDrawBitmapString(j, glm::vec3(radius * cos(ofDegToRad(j)), 0, radius * sin(ofDegToRad(j))));
    }
}

void ofApp::saveFboToFile() {
    // https://forum.openframeworks.cc/t/ofxfenster-addon-to-handle-multiple-windows-rewrite/6499/61
    // fbo is the main drawing canvas displayed in the second window
    int w = fbo.getWidth();
    int h = fbo.getHeight();
    unsigned char* pixels = new unsigned char[w*h*3];  ;
    ofImage screenGrab;
    screenGrab.allocate(w,h,OF_IMAGE_COLOR);
    screenGrab.setUseTexture(false);
    
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0, 0, fbo.getWidth(), fbo.getHeight(), GL_RGB, GL_UNSIGNED_BYTE, pixels);
    screenGrab.setFromPixels(pixels, fbo.getWidth(), fbo.getHeight(), OF_IMAGE_COLOR);
    if (willSave) {
        screenGrab.save(ofGetTimestampString() + ".png");
        willSave = false;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
        saveScreen();
    }
    if(key == 'd'){
        willSave = true;
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
