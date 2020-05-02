//
//  Bunny.hpp
//  nocBunnyHop
//
//  Created by Bryan Costanza on 1/31/20.
//

#ifndef Bunny_hpp
#define Bunny_hpp

#include "ofMain.h"
#include "Predator.hpp"

class Bunny {
    public:
    
        void setup();
        void update();
        void draw();
        
        ofVec2f g;
        ofVec2f vel;
        ofVec2f loc;
        int framesWait;
        ofVec2f hopVel;
        bool inDanger;
        
        Bunny();
    
    private:
    
        void checkBoundary();
        void applyGravity();
        void calcNewtonianMotion();
        void checkDanger();
    
};

#endif /* Bunny_hpp */
