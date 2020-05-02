//
//  Predator.cpp
//  nocBunnyHop
//
//  Created by Bryan Costanza on 2/1/20.
//

#include "Predator.hpp"

Predator::Predator(){
    
}

void Predator::setup(){
    locPrev = ofVec2f(0,0);
}

void Predator::update(){
    float mag1 = ofGetWidth()/4;
    float mag2 = ofGetHeight()/4;
    float offset = 1; // radians offset
    float period1 = 3;
    float period2 = 7;
    
    locPrev = loc;
    
    loc.x = (mag1 * sin((ofGetElapsedTimef() / period1) + offset)) + (ofGetWidth()  / 2);
    loc.y = (mag2 * sin((ofGetElapsedTimef() / period2) - offset)) + (ofGetHeight() / 2);
}

void Predator::draw(){
    ofPushStyle();
        ofSetColor(220, 20, 50);
        ofFill();
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofPushMatrix();
            ofTranslate(loc);
            ofRotateDeg(90-(loc - locPrev).angle(ofVec2f(-1,0))); // I don't know why this was the right combo but it works as intended
            ofDrawCircle(0, 3, 3);
            ofDrawRectangle(0,-5, 5, 15);
            ofDrawRectangle(0,0, 30, 5);
        ofPopMatrix();
    ofPopStyle();
}

void Predator::position(ofVec2f position){
    loc.set(position.x,position.y);
}
