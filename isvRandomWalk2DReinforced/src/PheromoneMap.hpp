//
//  PheromoneMap.hpp
//  imsReinforcedRandomWalk2D
//
//  Created by Bryan Costanza on 2/14/20.
//

#ifndef PheromoneMap_hpp
#define PheromoneMap_hpp

#include <ofMain.h>
#include <PheromoneSite.hpp>

class PheromoneMap {
    public:
        void setup();
        void update();
        void draw();
    
        void addP(ofVec2f loc);
        float getP(ofVec2f loc);
    
        int numRowsCols;
        int numSites;
        vector<vector<vector<PheromoneSite>>> sites;
    
        PheromoneMap();
    
    private:
    
};

#endif /* PheromoneMap_hpp */
