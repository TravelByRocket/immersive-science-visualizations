//
//  Plant.hpp
//  nocBunnyHop
//
//  Created by Bryan Costanza on 2/2/20.
//

#ifndef Plant_hpp
#define Plant_hpp

#include "ofMain.h"

class Plant {
    public:
        void setup(ofVec2f place);
        void update();
        void draw();
    
        ofVec2f loc;
        
        Plant();
    
    private:

    
};

#endif /* Plant_hpp */
