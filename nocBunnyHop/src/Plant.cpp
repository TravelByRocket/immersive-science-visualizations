//
//  Plant.cpp
//  nocBunnyHop
//
//  Created by Bryan Costanza on 2/2/20.
//

#include "Plant.hpp"

Plant::Plant(){
    
}

void Plant::setup(ofVec2f place){
    loc = place;
}

void Plant::update(){
    
}

void Plant::draw(){
    ofPushStyle();
    ofSetColor(ofColor::deepPink);
//    ofDrawCircle(loc.x, loc.y, 4);
    ofDrawLine(loc.x, loc.y, loc.x, loc.y-10);
    ofPopStyle();
    ofLog() << "Plant::draw() was called at frame " << ofGetFrameNum();
}
