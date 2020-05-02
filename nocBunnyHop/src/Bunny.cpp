//
//  Bunny.cpp
//  nocBunnyHop
//
//  Created by Bryan Costanza on 1/31/20.
//

#include "Bunny.hpp"
#include "ofApp.h"

Bunny::Bunny(){
    
}

void Bunny::setup(){
    g.set(0,5);
    vel.set(0,0);
    loc.set(ofRandom(ofGetWidth()/4,ofGetWidth()*3/4),ofGetHeight()*3/4);
    framesWait = ofRandom(100, 200);
    hopVel.set(ofRandom(2,10),ofRandom(-5, -30));
}

void Bunny::update(){
    checkBoundary();
    applyGravity();
    calcNewtonianMotion();
    checkDanger();
}

void Bunny::draw(){
    inDanger ? ofSetColor(ofColor::darkorange) : ofSetColor(255);
    ofDrawCircle(loc.x,loc.y,4);
}

void Bunny::checkBoundary(){
    if (loc.x > ofGetWidth()) {
        loc.x = 0;
    } else if (loc.x < 0){
        loc.x = ofGetWidth();
    }
}

void Bunny::applyGravity(){
    // apply gravity if not on ground
    if (ofGetFrameNum() % (framesWait / (1 + inDanger)) == 0) {
        if(!inDanger){
            int direction = floor(ofRandom(6));
            if(direction == 0){
                vel = hopVel; // go right
            } else {
                vel = ofVec2f(-hopVel.x,hopVel.y); // go left
            }
        } else {
            if (osprey.loc.x < loc.x) {
                vel = hopVel; // go right
            } else {
                vel = ofVec2f(-hopVel.x,hopVel.y); // go left
            }
        }
        
        vel.x = inDanger ? vel.x * 2 : vel.x;
    } else if (loc.y >= ofGetHeight()*3/4) {
        vel.set(0,0);
    } else {
        vel = vel + g;
    }
}

void Bunny::calcNewtonianMotion(){
    // update location based on velocity
    loc = loc + vel;
    
    if (loc.y > ofGetHeight() * 3 /4){
        loc.y = ofGetHeight() * 3 /4;
    }
}

void Bunny::checkDanger(){
    inDanger = (loc.distance(osprey.loc) < 100) ? true : false;
}
