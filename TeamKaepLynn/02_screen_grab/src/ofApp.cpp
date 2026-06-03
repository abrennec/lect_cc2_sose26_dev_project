#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup()
{

	std::cout << "GL Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;

	ofBackground(0);
	int numBalls = 5;

	// fill our vector
	for (int i = 0; i < numBalls; i++)
	{
		balls.push_back(Ball());
	}

	// New
	newcolor = ofColor(255, 255, 255, 255);
	webCam.setup(640, 480);
	camSize = 1.0f;
}

//--------------------------------------------------------------
void ofApp::update()
{

	for (int i = 0; i < balls.size(); i++)
	{
		balls[i].update();
	}

	// Update the webcam input
	webCam.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{

	// Draw webcam box
	drawWebCamInput();

	// Executing Ball logic function
	drawBalls();
	drawSpiralBalls(); // ===== NEW (spiral feature) =====

	// Executing Screen Capture function
	captureScreen();

	// Executing the Grid Overlay function
	drawGridOverlay();

	// draw brush strokes on top
	drawBrushStrokes();
}

//--------------------------------------------------------------
void ofApp::drawBrushStrokes()
{
	ofSetLineWidth(4);
	ofSetColor(255, 255, 255, 200);
	for (auto &stroke : brushStrokes)
	{
		stroke.draw();
	}
	if (currentStroke.size() > 0)
	{
		currentStroke.draw();
	}
	ofSetLineWidth(1);
}

//--------------------------------------------------------------
void ofApp::captureScreen()
{
	// now, take a "screenshot" of the frame
	screenImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());

	// resize the screenshot to 10x10 pixels
	screenImage.resize(10, 10);
}

//--------------------------------------------------------------
void ofApp::drawBalls()
{
	for (int i = 0; i < balls.size(); i++)
	{
		balls[i].draw();
	}
}

//--------------------------------------------------------------
// ===== NEW FEATURE: Spiral Pixel Manipulation (added after "this is my task now") =====
void ofApp::drawSpiralBalls()
{
	float time = ofGetElapsedTimef();
	int numParticles = 120;
	float pixelSize = 5.0f;

	for (auto &ball : balls)
	{
		for (int i = 0; i < numParticles; i++)
		{
			float t = (float)i / numParticles;

			// Archimedean spiral: angle grows with t, radius grows outward
			float angle = t * TWO_PI * 5.0f + time * 2.0f;
			float r = t * ball.radius;

			float px = ball.x + cos(angle) * r;
			float py = ball.y + sin(angle) * r;

			// sample color from the 10x10 screenImage at this pixel's position
			int sx = ofMap(px, 0, ofGetWidth(), 0, 9, true);
			int sy = ofMap(py, 0, ofGetHeight(), 0, 9, true);
			ofColor c = screenImage.getColor(sx, sy);

			// blend with the ball's own color so each spiral looks distinct
			c = c.getLerped(ball.color, 0.4f);
			c.a = ofMap(t, 0, 1, 255, 80); // fade towards the tail

			ofSetColor(c);
			ofDrawRectangle(px - pixelSize * 0.5f, py - pixelSize * 0.5f, pixelSize, pixelSize);
		}
	}
}
// ===== END NEW FEATURE =====

//--------------------------------------------------------------
void ofApp::drawWebCamInput()
{
	ofSetColor(newcolor);
	float camWidth = ofGetWidth() * camSize;
	float camHeight = ofGetHeight() * camSize;
	float x = (ofGetWidth() - camWidth) / 2;
	float y = (ofGetHeight() - camHeight) / 2;
	webCam.draw(x, y, camWidth, camHeight);
}

//--------------------------------------------------------------
void ofApp::drawGridOverlay()
{

	// sample colors from the screenshot, and draw as a grid overlay:
	// overlay opacity based on mouse x
	float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);

	ofSetColor(0, alpha);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	int numCols = 10;
	int numRows = 10;

	// grid square size for drawing:
	float width = ofGetWidth() / (float)numCols;
	float height = ofGetHeight() / (float)numRows;

	for (int y = 0; y < numRows; y++)
	{
		for (int x = 0; x < numCols; x++)
		{

			// sample the color of the screenshot at this grid pos
			ofColor color = screenImage.getColor(x, y);
			color.a = alpha;

			// draw a rectangle on screen
			ofSetColor(color);
			ofDrawRectangle(x * width, y * height, width, height);
		}
	}
}

//--------------------------------------------------------------
void ofApp::changeSomething()
{
	newcolor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 255);
	camSize = ofRandom(0.5f, 1.5f);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

// ===== NEW: Interactive Drawing with Mouse (added after "this is my task now") =====
void ofApp::mouseDragged(int x, int y, int button)
{
	// Sample color from screenImage at mouse position
	int sx = ofMap(x, 0, ofGetWidth(), 0, 9, true);
	int sy = ofMap(y, 0, ofGetHeight(), 0, 9, true);
	ofColor drawColor = screenImage.getColor(sx, sy);

	// Add point to current stroke
	currentStroke.addVertex(x, y);

	// Optional: Set color for this stroke
	// currentStroke.setFillColor(drawColor);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	// Start new stroke
	currentStroke.clear();
	currentStroke.addVertex(x, y);
	changeSomething(); // Keep existing functionality
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	// Save completed stroke
	if (currentStroke.size() > 0)
	{
		brushStrokes.push_back(currentStroke);
		currentStroke.clear();
	}
}
// ===== END NEW FEATURE =====

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
