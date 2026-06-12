#pragma once

#include "ofMain.h"
#include "Ball.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	ofVideoGrabber grabber;         
	ofImage img;                    
	ofImage display;             
	int levels = 4;                
	void applyPosterize(ofPixels& dst, const ofPixels& src, int levels);

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

	std::vector<Ball> balls;
	
	ofImage screenImage; // store a "screenshot" of each frame
	

	

		
};
