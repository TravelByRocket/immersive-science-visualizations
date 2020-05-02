//
//  Ant.cpp
//  imsReinforcedRandomWalk2D
//
//  Created by Bryan Costanza on 2/14/20.
//

#include "Ant.hpp"

Ant::Ant(){
    
}



void Ant::setup(){
    // ant initial conditions
    theta = ofRandom(360); // pick a random direction to start
    loc.x = ofRandom(ofGetWidth()/4,ofGetWidth()*3/4); // random starting x location
    loc.y = ofRandom(ofGetHeight()/4,ofGetHeight()*3/4); // random starting y location
    
    updateAntennaeLocations();
    
    framesSinceCollision = 0;
}

void Ant::update(){
    if (signalStrengthLeft > 0.1 || signalStrengthRight > 0.1){ // if either antenna registers a strong enough signal
        float tempSigDiff = ofClamp(signalStrengthLeft - signalStrengthRight, -2, 2); // take the difference in L-R strength
        omega = ofMap(tempSigDiff, 2, -2, -5, 5); // and command a rotation rate to turn into the stronger signal direction
        if (ofRandom(500) < 1){
            omega = ofRandom(-120, 120); // occasionallly pick a different direction regardless
        }
    } else { // otherwise do a random walk
        omega = ofRandom(-20,20); // random rate to change theta
    }
    
    
    theta += omega; // update the heading based on the rotation rate
    
    updateAntennaeLocations();
    
    if (theta < 0) { // prevent angle from winding up or down
        theta += 360;
    } else if (theta > 360){
        theta = theta - 360;
    }
    
    loc.x += cos(ofDegToRad(theta)); // move in the pointed direction
    loc.y += sin(ofDegToRad(theta));
    
    redirectEdgeCollisionsTangentially();
    framesSinceCollision++;
}

void Ant::draw(){
    ofFill();
    
    // draw body limeGreen normally but purple if recently collided
    ofSetColor(framesSinceCollision < 10 ? ofColor::purple : ofColor::limeGreen);
    ofDrawCircle(loc, 4);
    
    // draw head
    ofSetColor(ofColor::cyan);
    ofDrawCircle(loc.x+4*cos(ofDegToRad(theta)), loc.y+4*sin(ofDegToRad(theta)), 2);
}

void Ant::redirectEdgeCollisionsTangentially(){
    if (loc.x <= 0) { // if off the LEFT edge
        loc.x = 0; // set on the edge
        theta = (theta < 180) ? 90 : 270; // and redirect tangentially
    } else if (loc.x >= ofGetWidth()) { // if off the RIGHT edge
        loc.x = ofGetWidth(); // set on the edge
        theta = (theta < 180) ? 90 : 270; // and redirect tangentially
    }
    
    if (loc.y <= 0) { // if off the TOP edge
        loc.y = 0; // set on the edge
        theta = (theta > 270 || theta < 90) ? 0 : 180; // and redirect tangentially
    } else if (loc.y >= ofGetHeight()) { // if off the BOTTOM edge
        loc.y = ofGetHeight(); // set on the edge
        theta = (theta > 270 || theta < 90) ? 0 : 180; // and redirect tangentially
    }
}

void Ant::checkCollisionWith(Ant& target) { // must pass by reference with &
    if (loc.distance(target.loc) < 10 && target.framesSinceCollision > 10) { // if less than specified distance
        if (framesSinceCollision > 10) { // and if it has not recently had a collision
            theta = ofRandom(360); // then pick a random new direction
            framesSinceCollision = 0; // and restart the collision frame timer
        }
        if (target.framesSinceCollision > 10) { // do the same for the target ant. TODO only disrupt an ant if the colliding ant is in front of it.
            target.theta = ofRandom(360);
            target.framesSinceCollision = 0;
        }
    }
}

void Ant::updateAntennaeLocations() {
    antennaLocLeft  = ofVec2f(loc.x + antennaLength * cos(ofDegToRad(theta - halfAngleAntennae)),
                              loc.y + antennaLength * sin(ofDegToRad(theta - halfAngleAntennae)));
    antennaLocRight = ofVec2f(loc.x + antennaLength * cos(ofDegToRad(theta + halfAngleAntennae)),
                              loc.y + antennaLength * sin(ofDegToRad(theta + halfAngleAntennae)));
}
