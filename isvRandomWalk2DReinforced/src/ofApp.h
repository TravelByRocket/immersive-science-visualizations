#pragma once

#include "ofMain.h"
#include "Ant.hpp"
#include "PheromoneMap.hpp"
#include "PheromoneSite.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        ofTrueTypeFont myfont;
        vector<Ant> ants;
        PheromoneMap map;
        ofImage image;
    
        void saveScreen();

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
        
        void exit();
		
};
