#pragma once

#include "ofMain.h"
#include "Bunny.hpp"
#include "Predator.hpp"
#include "Plant.hpp"
#include "Dandelion.h"
#include "Monstera.hpp"

#define NUMBUNS 10
#define NUMPLANTS 10

extern Predator osprey;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        Bunny bunbuns[NUMBUNS];
//        Plant plants[NUMPLANTS];
        Dandelion dandy;
        Monstera monster;
        vector <Plant> manyPlantees;
        
        ofCamera cam;
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
