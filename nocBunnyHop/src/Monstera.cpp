//
//  Monstera.cpp
//  nocBunnyHop
//
//  Created by Bryan Costanza on 2/2/20.
//

#include "Monstera.hpp"

int stalkCount;
int avgHeight;
int walkLimit;
vector <ofVec2f> stalks;
ofVec2f tempStalk;

void Monstera::setup(ofVec2f place){
    loc = place;
    stalkCount = ofRandom(3, 7);
    avgHeight = 15;
    walkLimit = 5;
    for (int i = 0; i < stalkCount; i++) {
        float randomWalkX = ofRandom(-walkLimit, walkLimit);
        float randomWalkY = ofRandom(-walkLimit, walkLimit);
        tempStalk = ofVec2f(randomWalkX,avgHeight + randomWalkY);
        stalks.push_back(tempStalk);
    }
    ofLog() << "Monstera::setup() at " << loc << " frame " << ofGetFrameNum();
}

void Monstera::draw(){
    ofPushStyle();
    ofSetColor(ofColor::seaGreen);
    for (int i = 0; i < stalkCount; i++) {
        ofDrawLine(loc.x, loc.y, loc.x + stalks[i].x, loc.y - stalks[i].y);
        ofDrawCircle(loc.x + stalks[i].x, loc.y - stalks[i].y, 4);
    }
    ofPopStyle();
    ofLog() << "Monstera::draw() at " << loc << " frame " << ofGetFrameNum();
}
