#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
    
        void setup();
		void update();
		void draw();

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
    
        int cellsPerRingCumulative[17] = {10,25,46,73,107,147,193,245,304,369,440,518,602,692,788,891,1000}; // cumulative cells starting with first ring around central dot. TODO this should have a 1 in the first position for the central circle to match the 9 (i.e. 10-1) cells in the first partitioned ring. Based on Table 4 and Figure 7 from https://www.sciencedirect.com/science/article/pii/S0925772112000296. TODO declare here and set values in setup() but finding it's not as easy as it seems.
        int radiusHemisphere; // radius of the hemisphere in the visualization
        ofCamera cam; // will set as orthographic
        vector<int> thetaRingBoundaries; // angle from "North" in spherical coordinates
        vector<int> ringRadii; // measured from the vector running from (0,0,0) to (0,0,-radius), or consider this the radius projected onto the x-y plane
        vector<int> ringHeights; // Z-value (i.e., height, more or less) from the x-y plane for each concentric circle, into the -Z direction
        int ringsCount; // the number of concentric rings in `cellsPerRingCumulative`

        ofVec3f origin;

        // testing probe
        float azimuthWander;
        float thetaWander;
        ofVec3f wanderer;
		
};
