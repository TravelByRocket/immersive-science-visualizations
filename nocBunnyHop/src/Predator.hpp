//
//  Predator.hpp
//  nocBunnyHop
//
//  Created by Bryan Costanza on 2/1/20.
//

#ifndef Predator_hpp
#define Predator_hpp

#include "ofMain.h"

class Predator {
    public:

        void setup();
        void update();
        void draw();
        void position(ofVec2f position);

        ofVec2f loc;
        ofVec2f locPrev;

        Predator();

};

#endif /* Predator_hpp */
