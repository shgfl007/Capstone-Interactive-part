#pragma once

#include "ofMain.h"
#include "LeapMotion.h"

class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
        void exit();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    LeapMotion leap;
    Leap::Controller leapController;
    bool phase1 = false;
    bool phase2 = false;
    bool phase3 = false;
    bool phase4 = false;
    bool phase5 = false;
    bool phase6 = false;
    bool phase7 = false;
};
