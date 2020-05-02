//
//  Ant.hpp
//  imsReinforcedRandomWalk2D
//
//  Created by Bryan Costanza on 2/14/20.
//

#ifndef Ant_hpp
#define Ant_hpp

#include <ofMain.h>

class Ant {
    public:
    
    void updateAntennaeLocations();
    
    //    void updateAntennaLocations();
    
    void setup();
        void update();
        void draw();
        void checkCollisionWith(Ant& target);
    
        float theta, omega;
        ofVec2f loc;
        ofVec2f antennaLocLeft, antennaLocRight;
        float signalStrengthLeft, signalStrengthRight;
        vector<ofVec2f> trail;
        int framesSinceCollision;
    
        // antenna location in screen coordinates // 60 degree whole angle from "stochastic model of collective behavior of ants" p.27 by Miriam Malickova
        float antennaLength = 8.0;
        float wholeAngleAntennae = 60;
        float halfAngleAntennae = wholeAngleAntennae / 2;
    
        Ant();
    
    private:
    
        void redirectEdgeCollisionsTangentially();
    
};

#endif /* Ant_hpp */
