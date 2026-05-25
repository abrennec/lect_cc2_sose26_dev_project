#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofEnableDepthTest();
	ofEnableLighting();

	icosphere.setup();

	ofBackground(0);

	int numBalls = 5;

	for (int i = 0; i < numBalls; i++)
	{
		balls.push_back(Ball());
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	for (int i = 0; i < balls.size(); i++)
	{
		balls[i].update();
	}

	icosphere.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	drawBall();

	// 3D Objekt
	icosphere.draw();

	// Screenshot aufnehmen
	takeScreenshot();

	// Pixel sortieren
	pixelSort();

	// 2D Overlay zeichnen
	ofDisableDepthTest();

	drawGrid();

	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::drawBall()
{
	for (int i = 0; i < balls.size(); i++)
	{
		balls[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::takeScreenshot()
{
	screenImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());

	// höhere Auflösung für besseres Pixel Sorting
	screenImage.resize(120, 120);
}

//--------------------------------------------------------------
void ofApp::pixelSort()
{
	ofPixels& pixels = screenImage.getPixels();

	int width = pixels.getWidth();
	int height = pixels.getHeight();

	// jede Spalte einzeln bearbeiten
	for (int x = 0; x < width; x++)
	{
		std::vector<ofColor> brightPixels;

		// helle Pixel sammeln
		for (int y = 0; y < height; y++)
		{
			ofColor c = pixels.getColor(x, y);

			float brightness = c.getBrightness();

			// threshold
			if (brightness > 100)
			{
				brightPixels.push_back(c);
			}
		}

		// nach Helligkeit sortieren
		std::sort(brightPixels.begin(), brightPixels.end(),
			[](const ofColor& a, const ofColor& b)
			{
				return a.getBrightness() < b.getBrightness();
			});

		// zurückschreiben
		int index = 0;

		for (int y = 0; y < height; y++)
		{
			ofColor c = pixels.getColor(x, y);

			if (c.getBrightness() > 100 && index < brightPixels.size())
			{
				pixels.setColor(x, y, brightPixels[index]);

				index++;
			}
		}
	}

	screenImage.update();
}

//--------------------------------------------------------------
void ofApp::drawGrid()
{
	float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);

	ofSetColor(0, alpha);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	int numCols = 120;
	int numRows = 120;

	float width = ofGetWidth() / (float)numCols;
	float height = ofGetHeight() / (float)numRows;

	for (int y = 0; y < numRows; y++)
	{
		for (int x = 0; x < numCols; x++)
		{
			ofColor color = screenImage.getColor(x, y);

			color.a = alpha;

			ofSetColor(color);

			ofDrawRectangle(
				x * width,
				y * height,
				width,
				height
			);
		}
	}
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