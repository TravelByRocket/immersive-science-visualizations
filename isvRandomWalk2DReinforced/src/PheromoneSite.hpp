//
//  PheromoneSite.hpp
//  imsReinforcedRandomWalk2D
//
//  Created by Bryan Costanza on 2/14/20.
//

#ifndef PheromoneSite_hpp
#define PheromoneSite_hpp

#include <ofMain.h>

class PheromoneSite{
    public:
        void setup(ofVec2f theLoc);
        void update();
        void draw();
        
        ofVec2f loc;
        float timeDroppedSec;
        float ageSec;
        int ageFrames;
        float strength;
    
        PheromoneSite();
        
    private:
        
};

#endif /* PheromoneSite_hpp */
