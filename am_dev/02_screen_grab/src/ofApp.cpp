#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofEnableDepthTest();
	ofEnableLighting();

	icosphere.setup();

	ofBackground(0);

	int numBalls = 20;

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

	if (particleMode)
	{

		for (auto &p : particlesArray)
		{
			p.update(ofVec2f(ofGetMouseX(), ofGetMouseY()));
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw()
{
	drawBall();
	icosphere.draw();

	takeScreenshot();
	pixelSort();

	ofDisableDepthTest();
	drawGrid();
	ofEnableDepthTest();

	// Only draw particles when in particle mode
	if (particleMode)
	{
		for (auto &p : particlesArray)
		{
			p.draw();
		}
	}
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
	screenImage.resize(160, 160);
}

//--------------------------------------------------------------
void ofApp::pixelSort() // by Amelie
{
	ofPixels &pixels = screenImage.getPixels();

	int width = pixels.getWidth();
	int height = pixels.getHeight();

	// PixelData integrated by Maria to additionally retrieve the position along with the color

	// clear pixels from last frame
	pixelParticles.clear();

	// jede Spalte einzeln bearbeiten
	for (int x = 0; x < width; x++)
	{
		std::vector<PixelData> brightPixels;

		// helle Pixel sammeln
		for (int y = 0; y < height; y++)
		{
			ofColor c = pixels.getColor(x, y);

			float brightness = c.getBrightness();

			// threshold
			if (brightness > 40)
			{
				// changed by Maria, added position retrieving
				brightPixels.push_back(PixelData{c, ofVec2f(x, y)});
			}
		}

		// nach Helligkeit sortieren
		std::sort(brightPixels.begin(), brightPixels.end(),
				  [](const PixelData &a, const PixelData &b)
				  {
					  return a.color.getBrightness() < b.color.getBrightness();
				  });

		// added by maria to get 1/4 of the bright pixels
		int cutoff = brightPixels.size() * 0.75f;
		for (int i = cutoff; i < brightPixels.size(); i++)
		{
			pixelParticles.push_back(brightPixels[i]);
		}

		// zurückschreiben
		int index = 0;

		for (int y = 0; y < height; y++)
		{
			ofColor c = pixels.getColor(x, y);

			if (c.getBrightness() > 100 && index < brightPixels.size())
			{
				pixels.setColor(x, y, brightPixels[index].color);

				index++;
			}
		}
	}

	screenImage.update();
}

void ofApp::pixelsToParticles()
{
	particlesArray.clear();

	float scaleX = ofGetWidth() / 160.0f;
	float scaleY = ofGetHeight() / 160.0f;

	for (int i = 0; i < pixelParticles.size(); i++)
	{
		ofVec2f scaledPos = pixelParticles[i].pos * ofVec2f(scaleX, scaleY);
		particlesArray.emplace_back(scaledPos, pixelParticles[i].color);
	}
}

//--------------------------------------------------------------
void ofApp::drawGrid()
{
	float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);

	ofSetColor(0, alpha);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	int numCols = 160;
	int numRows = 160;

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
				height);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == '1')
	{
		particleMode = !particleMode;

		if (particleMode)
		{
			pixelsToParticles(); // spawn once from frozen frame
		}
		else
		{
			particlesArray.clear(); // go back to normal
		}
	}
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
