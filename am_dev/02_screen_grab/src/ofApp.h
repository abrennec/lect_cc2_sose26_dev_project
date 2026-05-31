#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "Object3d.h"
#include "Particle.h"

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();
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

	void drawBall();
	void takeScreenshot();
	void drawGrid();

	void pixelSort();
	void pixelsToParticles();

	Object3d icosphere;

	std::vector<Ball> balls;

	ofImage screenImage; // store a "screenshot" of each frame

	struct PixelData
	{
		ofColor color;
		ofVec2f pos;
	};

	bool particleMode = false;

	std::vector<PixelData> pixelParticles;
	std::vector<Particle> particlesArray;
};
