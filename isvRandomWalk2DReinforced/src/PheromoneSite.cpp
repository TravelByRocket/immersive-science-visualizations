//
//  PheromoneSite.cpp
//  imsReinforcedRandomWalk2D
//
//  Created by Bryan Costanza on 2/14/20.
//

#include "PheromoneSite.hpp"

PheromoneSite::PheromoneSite(){
    
}

void PheromoneSite::setup(ofVec2f theLoc){
    loc = theLoc;
    timeDroppedSec = ofGetElapsedTimef();
    ageSec = 0;
    ageFrames = 0;
    strength = 1;
}

void PheromoneSite::update(){
    ageSec = ofGetElapsedTimef() - timeDroppedSec;
    ageFrames++;
    strength *= .97;
}

void PheromoneSite::draw(){
    ofNoFill();
    ofSetColor(ofColor::pink, strength*100);
    ofDrawCircle(loc, 5);
}
