//
//  PheromoneMap.cpp
//  imsReinforcedRandomWalk2D
//
//  Created by Bryan Costanza on 2/14/20.
//

#include "PheromoneMap.hpp"

PheromoneMap::PheromoneMap(){
    
}

void PheromoneMap::setup(){
    numRowsCols = 10;
    numSites = 1000;
    
    sites.resize(numRowsCols); // columns as bins
    for (int i = 0; i < numRowsCols; i++) {
        sites[i].resize(numRowsCols); // rows as bins
    }
    
}

void PheromoneMap::update(){
    
    // run update() for each pheromone site
    for (int i = 0; i < numRowsCols; i++) {
        for (int j = 0; j < numRowsCols; j++) {
            for (int k = 0; k < sites[i][j].size(); k++) {
                sites[i][j][k].update(); // empty spaces for pheromone sites
            }
        }
    }
    
    // delete pheromone sites that are old
    for (int i = 0; i < numRowsCols; i++) {
        for (int j = 0; j < numRowsCols; j++) {
            for (int k = (int) sites[i][j].size() - 1; k >=0 ; k--) {
                if (sites[i][j][k].ageFrames > 200) {
                    sites[i][j].erase(sites[i][j].begin() + k);
                }
            }
        }
    }
}

void PheromoneMap::draw(){

    for (int i = 0; i < numRowsCols; i++) {
        for (int j = 0; j < numRowsCols; j++) {
            for (int k = 0; k < sites[i][j].size(); k++) {
                sites[i][j][k].draw();
            }
        }
    }
    
}

void PheromoneMap::addP(ofVec2f pos){
    PheromoneSite site = PheromoneSite(); // try this without constructor
    site.setup(pos);
    int tempCol = (int) floor(pos.x/(ofGetWidth() /10)); // floor and (int) probably aren't needed but makes it clear
    tempCol = (tempCol < 0) ? 0 : tempCol;
    tempCol = (tempCol > numRowsCols - 1) ? numRowsCols - 1 : tempCol;
    int tempRow = (int) floor(pos.y/(ofGetHeight()/10));
    tempRow = (tempRow < 0) ? 0 : tempRow;
    tempRow = (tempRow > numRowsCols - 1) ? numRowsCols - 1 : tempRow;
    sites[tempCol][tempRow].push_back(site);
}

float PheromoneMap::getP(ofVec2f pos){
    
    int tempCol = (int) floor(pos.x/(ofGetWidth() /10)); // floor and (int) probably aren't needed but makes it clear
    tempCol = (tempCol < 0) ? 0 : tempCol;
    tempCol = (tempCol > numRowsCols - 1) ? numRowsCols - 1 : tempCol;
    int tempRow = (int) floor(pos.y/(ofGetHeight()/10));
    tempRow = (tempRow < 0) ? 0 : tempRow;
    tempRow = (tempRow > numRowsCols - 1) ? numRowsCols - 1 : tempRow;
    
    float tempSignal = 0;
        for (int k = 0; k < sites[tempCol][tempRow].size(); k++) {
            float tempDist = pos.distance(sites[tempCol][tempRow][k].loc);
            if (tempDist < 5){
                tempSignal += sites[tempCol][tempRow][k].strength;
            }
        }
    return tempSignal;
}
