#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{

	cout << "GL Version: " << glGetString(GL_VERSION) << endl;
	cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
	cout << "Renderer: " << glGetString(GL_RENDERER) << endl;
	cout << "Vendor: " << glGetString(GL_VENDOR) << endl;

	ofBackground(0);
	int numBalls = 5;

	videoGrabber.setup(1920, 1080); // [NEU 1.2 Aufgabe] Webcam initialisieren

	// fill our vector
	for (int i = 0; i < numBalls; i++)
	{
		balls.push_back(Ball());
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	videoGrabber.update(); // [NEU 1.2] Webcam-Frame aktualisieren

	for (int i = 0; i < balls.size(); i++)
	{
		balls[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	// Executing WebCam function
	drawWebCamInput();

	// Executing Ball logic function
	drawBalls();

	// Executing Screen Capture function
	captureScreen();

	// Executing the Grid Overlay function
	drawGridOverlay();
}

void ofApp::drawWebCamInput()
{
	videoGrabber.draw(0, 0, ofGetWidth(), ofGetHeight());
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
    ofSetColor(255);
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

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

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
