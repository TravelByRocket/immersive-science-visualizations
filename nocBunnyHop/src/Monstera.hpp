//
//  Monstera.hpp
//  nocBunnyHop
//
//  Created by Bryan Costanza on 2/2/20.
//

#ifndef Monstera_hpp
#define Monstera_hpp

#include "ofMain.h"
#include "Plant.hpp"

class Monstera : public Plant {
    public:
        virtual void draw();
        virtual void setup(ofVec2f place);
};

#endif /* Monstera_hpp */
