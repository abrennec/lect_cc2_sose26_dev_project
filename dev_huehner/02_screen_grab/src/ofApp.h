#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "Arrow.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
    // NEW functions
    void drawBalls(vector<Ball>& balls);
    void drawArrow(Arrow& arrow);
    void sampleColor(float alpha);
    void calcGrid(int numCols, int numRows, float& width, float& height);
    void sample(float alpha, float width, float height, int numCols, int numRows);

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
    Arrow arrow;
	
	ofImage screenImage; // store a "screenshot" of each frame
    
    //new variables
    float alpha = 0;
    int numCols = 0;
    int numRows = 0;
    float width = 0;
    float height = 0;
	
		
};
