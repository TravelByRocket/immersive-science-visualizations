#include "ofApp.h"

//TODO highlight area that tesing probe is pointing at as well as neighboring cells or at least neighboring cells within some effectiveness region. This will ikely include making a struct or class for each ring and cell and then a function that takes a point and returns the focused and appropriate nearby cells

//--------------------------------------------------------------
void ofApp::setup(){
    
    radiusHemisphere = 350;
    
    cam.setGlobalPosition(0, 0, radiusHemisphere * 1.1); // added arbitrary 10% buffer to trimming a few close pixels even with cam.setNearClip(0);
    cam.enableOrtho(); // planetarium-ready view and removes distracting distortion for this demonstration
    
    ofNoFill(); // do not fill circles
    ofSetCircleResolution(100);
    
// TODO this is a workaround for declaring empty array in ofApp.h so that values are set here but very dissatisfied with this
//    for (int m = 0; m < ringsCount; m++) {
//        int temp[] = {10,25,46,73,107,147,193,245,304,369,440,518,602,692,788,891,1000};
//        cellsPerRingCumulative[m] = temp[m];
//    }
    
    ringsCount = sizeof(cellsPerRingCumulative)/sizeof(cellsPerRingCumulative[0]);
    ofLog() << "ringsCount = " + ofToString(ringsCount);
    
    for (int k = 0; k <= ringsCount; k++) { // each loop calculates inside of each rings so use <= to get outside of last ring. TODO change to outer logic and manually add first inner values to make for loop syntax be more standard
        
        int ringThetaInner = (k+1) * 90 / (ringsCount+1); // `k+1` because skipping theta=0 case; `ringsCount+1` because n+1 boundaries need to be calculated for n regions
        thetaRingBoundaries.push_back(ringThetaInner);
        
        int ringRadiusInner = radiusHemisphere * sin(ofDegToRad(ringThetaInner));
        ringRadii.push_back(ringRadiusInner);
        
        int ringInnerHeight = -radiusHemisphere * cos(ofDegToRad(ringThetaInner));
        ringHeights.push_back(ringInnerHeight);
        
    }
    
    ofLog() << "thetaRingBoundaries = " + ofToString(thetaRingBoundaries);
    ofLog() << "ringRadii = " + ofToString(ringRadii);
    ofLog() << "ringHeights = " + ofToString(ringHeights);
    
    origin = ofVec3f(0,0,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // TEST PROBE WANDER CALCS
    azimuthWander = ofGetElapsedTimef() * 50;
    thetaWander = 45 + 44 * sin(ofDegToRad(ofGetElapsedTimef() * 100 / 2.5));
    wanderer = ofVec3f( radiusHemisphere * cos(ofDegToRad(90 - thetaWander)) * cos(ofDegToRad(azimuthWander)),
                        radiusHemisphere * cos(ofDegToRad(90 - thetaWander)) * sin(ofDegToRad(azimuthWander)),
                       -radiusHemisphere * cos(ofDegToRad(thetaWander)));
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    ofRotateDeg(ofGetMouseX(), 0, 1, 0); // spin about Y with left-right motion
    ofRotateDeg(ofGetMouseY(), 1, 0, 0); // spin about X with up-down motion
    
    for (int i = 0; i < ringsCount; i++) { // for each ring
        ofDrawCircle(0,0,ringHeights[i],ringRadii[i]); // draw the inner radius
        ofDrawCircle(0,0,ringHeights[i+1],ringRadii[i+1]); // draw the outer radius
        ofDrawBitmapString(i+1,(ringRadii[i] + ringRadii[i+1])/2,0,(ringHeights[i] + ringHeights[i+1])/2); // label each ring with the 1-indexed count
        
        int cellsInRing = i == 0 ? cellsPerRingCumulative[i] : cellsPerRingCumulative[i] - cellsPerRingCumulative[i-1]; // get cells per ring but can't subtract previous cumulative cell count for the first ring
        
        for (int j = 0; j < cellsInRing; j++) { // for each cell in a ring
            
            float azimuth = ((float) j * 360) / (float) cellsInRing; // find the azimuth of the first edge
            ofVec3f innerPoint = ofVec3f(ringRadii[i] * cos(ofDegToRad(azimuth)),
                                         ringRadii[i] * sin(ofDegToRad(azimuth)),
                                         ringHeights[i]); // point that first edge touches inner radius
            ofVec3f outerPoint = ofVec3f(ringRadii[i+1] * cos(ofDegToRad(azimuth)),
                                         ringRadii[i+1] * sin(ofDegToRad(azimuth)),
                                         ringHeights[i+1]); // point that first edge touches outer radius
            ofDrawLine(innerPoint,outerPoint); // line to show edge, though this is a straight line, not an arc following curve of hemisphere
        }
    }
    
    ofDrawLine(origin,wanderer); // draw the test probe line from origin
    ofDrawSphere(wanderer,5); // draw a spehere on the end of the probe
    
    cam.end();
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
