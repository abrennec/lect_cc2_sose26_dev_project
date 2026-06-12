#include "ofApp.h"
#include <algorithm>


//--------------------------------------------------------------
void ofApp::setup(){

    cout << "GL Version: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;

    cout << "Renderer: " << glGetString(GL_RENDERER) << endl;
    cout << "Vendor: " << glGetString(GL_VENDOR) << endl;

    ofBackground(0);

    int numBalls = 5;

    // fill our vector
    for (int i = 0; i < numBalls; i++) {
        balls.push_back(Ball());
    }

    grabber.setDeviceID(2);
    grabber.setup(640, 480);
    display = img;


}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i = 0; i < balls.size(); i++) {
        balls[i].update();
    }

grabber.update();
if (grabber.isFrameNew()) {
    ofPixels src = grabber.getPixels();
    ofPixels dst = src;

    applyPosterize(dst, src, levels);
    applyLens(dst, src, ofGetMouseX(), ofGetMouseY(), lensRadius);
    display.setFromPixels(dst);
}


}

//--------------------------------------------------------------
void ofApp::draw(){
    drawBalls();
  //Screenshot();
   //PixelGrid();
   display.draw(0, 0);


  

}

//--------------------------------------------------------------
void ofApp::drawBalls(){

    for (int i = 0; i < balls.size(); i++) {
        balls[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::Screenshot(){

    // take a screenshot of the frame
    screenImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());

    // resize screenshot to 10x10 pixels
    screenImage.resize(10, 10);
}

//--------------------------------------------------------------
void ofApp::PixelGrid(){

    // overlay opacity based on mouse x
    float alpha = ofMap(
        ofGetMouseX(),
        0,
        ofGetWidth(),
        0,
        255,
        true
    );

    ofSetColor(0, alpha);
    ofDrawRectangle(
        0,
        0,
        ofGetWidth(),
        ofGetHeight()
    );

    int numCols = 10;
    int numRows = 10;

    // grid square size
    float width = ofGetWidth() / (float)numCols;
    float height = ofGetHeight() / (float)numRows;

    for (int y = 0; y < numRows; y++) {

        for (int x = 0; x < numCols; x++) {

            // sample color from screenshot
            ofColor color = screenImage.getColor(x, y);
            color.a = alpha;

            // draw rectangle
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
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

void ofApp::applyPosterize(ofPixels& dst, const ofPixels& src, int levels) {
    float step = 255.0 / (levels - 1);
    for (int y = 0; y < src.getHeight(); y++) {
        for (int x = 0; x < src.getWidth(); x++) {
            ofColor c = src.getColor(x, y);
            c.r = round(c.r / step) * step;
            c.g = round(c.g / step) * step;
            c.b = round(c.b / step) * step;
            dst.setColor(x, y, c);
        }
    }
}


void ofApp::applyLens(ofPixels& dst, const ofPixels& src, int mx, int my, float r) {
    for (int y = std::max(0, (int)(my - r)); y <= std::min((int)src.getHeight() - 1, (int)(my + r)); y++) {
        for (int x = std::max(0, (int)(mx - r)); x <= std::min((int)src.getWidth() - 1, (int)(mx + r)); x++) {
            float dx = x - mx, dy = y - my;
            if (dx * dx + dy * dy <= r * r) {
                ofColor c = src.getColor(x, y);
                c.r = round(c.r / 64.0) * 64.0;
                c.g = round(c.g / 64.0) * 64.0;
                c.b = round(c.b / 64.0) * 64.0;
                dst.setColor(x, y, c);
            }
        }
    }
}


