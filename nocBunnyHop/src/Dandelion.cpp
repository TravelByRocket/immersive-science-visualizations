//
//  Dandelion.cpp
//  nocBunnyHop
//
//  Created by Bryan Costanza on 2/2/20.
//

#include "Dandelion.h"

void Dandelion::draw(){
    int height = 10;
    ofPushStyle();
    ofFill();
    ofSetColor(ofColor::lawnGreen);
    ofDrawLine(loc.x, loc.y, loc.x, loc.y - height);
    ofSetColor(ofColor::greenYellow);
    ofDrawCircle(loc.x, loc.y - height, 3);
    ofPopStyle();
    ofLog() << "Dandelion::draw() at " << loc << " frame " << ofGetFrameNum();
}
