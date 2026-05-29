#include "Ball.h"

// constructor
Ball::Ball()
{

	// inside the constructor you initialize the object's variables

	// random radius between 10 and 50
	radius = ofRandom(50, 100);

	// random color
	float red = ofRandom(0, 255);
	float green = ofRandom(0, 255);
	float blue = ofRandom(0, 255);
	color = ofColor(red, green, blue);

	// random position in window
	x = ofRandom(radius, ofGetWidth() - radius);
	y = ofRandom(radius, ofGetHeight() - radius);

	// random x and y speeds/directions between -10 and 10
	dirX = ofRandom(-2, 2);
	dirY = ofRandom(-2, 2);
}

// update position, etc.
void Ball::update()
{

	x += dirX; // move along x by amount of dirX
	y += dirY; // move along y by amount of dirY

	// check for bounces at edges of window:

	// check left
	if (x <= radius)
	{
		x = radius;	  // set the position back to the edge of window
		dirX = -dirX; // and reverse direction
	}
	// check right
	else if (x >= ofGetWidth() - radius)
	{
		x = ofGetWidth() - radius; // similar to above
		dirX = -dirX;
	}

	// check top and bottom
	if (y <= radius)
	{
		y = radius;
		dirY = -dirY;
	}
	else if (y >= ofGetHeight() - radius)
	{
		y = ofGetHeight() - radius;
		dirY = -dirY;
	}

	// apply noise effect if hovered
	if (isHovered)
	{
		noiseEffect();
	}
}

// draw the ball
void Ball::draw()
{

	ofSetColor(color);

	if (isHovered)
	{
		noiseEffect();
	}
	else
	{
		ofDrawCircle(x, y, radius);
	}
}

void Ball::noiseEffect()
{
	noiseFrequency = 10f;
	noiseStrenght = 0.3f;
	noiseSeed = ofGetElapsedTimef();

	// get vertecies on circle
	int n = 100;

	ofBeginShape();
	for (int i = 0; i < n; i++)
	{
		float angle = (i / (float)n) * TWO_PI;
		float baseRadius = radius;
		float noiseValue = ofNoise(angle * noiseFrequency, noiseSeed);
		float wobblyRadius = baseRadius * (1.0f + noiseValue * noiseStrenght);

		float x = this->x + cos(angle) * wobblyRadius; // ← Ball-Position addieren!
		float y = this->y + sin(angle) * wobblyRadius;

		ofVertex(x, y); // ← Punkt direkt zeichnen!
	}
	ofEndShape();
}