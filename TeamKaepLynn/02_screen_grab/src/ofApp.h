#pragma once

#include "ofMain.h"
#include "Ball.h"

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();

	// newly added functions :)
	void drawGridOverlay();
	void drawBalls();
	void drawSpiralBalls();  // ===== NEW (spiral feature) =====
	void captureScreen();
	void changeSomething();
	void drawWebCamInput();
	void drawBrushStrokes();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	std::vector<Ball> balls;
	std::vector<ofPolyline> brushStrokes;
	ofPolyline currentStroke;
	ofColor newcolor;
	float camSize;
	ofVideoGrabber webCam;
	ofImage screenImage;
};
