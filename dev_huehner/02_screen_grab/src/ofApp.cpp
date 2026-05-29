#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


	cout << "GL Version: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
    cout << "Renderer: " << glGetString(GL_RENDERER) << endl;
    cout << "Vendor: " << glGetString(GL_VENDOR) << endl;


	ofBackground(157);

	int numBalls = 5;

	// fill our vector
	for (int i = 0; i < numBalls; i++) {
		balls.push_back(Ball());
	}
    
    box = Box();
    arrow = Arrow();

}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < balls.size(); i++) {
		balls[i].update();
	}
    
    arrow.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawBalls();
    updateScreenshot();
    drawPixelGrid();
	drawArrow(arrow);
    box.draw();


	/* KATHA 1.1. FUNCTION REFRACTION
    //-------- NEW FUNCTION ----------
    drawBalls(balls);
    
	// now, take a "screenshot" of the frame
	screenImage.grabScreen(0,0,ofGetWidth(),ofGetHeight());
	
	// resize the screenshot to 10x10 pixels
	screenImage.resize(10,10);
	

    //-------- NEW FUNCTIONS ----------
    // overlay opacity based on mouse x
    alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);
    sampleColor(alpha);
    
    //calculate Grid
    int numCols = 10;
    int numRows = 10;
    float width, height;
    calcGrid(numCols, numRows, width, height);
    
    // sampling with rectangles
    sample(alpha, width, height, numRows, numCols);*/
    
}

void ofApp::drawArrow(Arrow& arrow){
    arrow.draw();
}


/*KATHA
// Function Refractoring START
//--------------------------------------------------------------

void ofApp::drawBalls(vector<Ball>& balls){

    for (int i = 0; i < balls.size(); i++) {
        balls[i].draw();
    }
}

void ofApp::calcGrid(int numRows, int numCols, float& width, float& height){
    // grid square size for drawing:
    width = ofGetWidth() / (float)numCols;
    height = ofGetHeight() / (float)numRows;
};

void ofApp::sample(float alpha, float width, float height, int numCols, int numRows){
   
    for (int y=0; y<numRows; y++) {
        for (int x=0; x<numCols; x++) {
            
            // sample the color of the screenshot at this grid pos
            ofColor color = screenImage.getColor(x,y);
            color.a = alpha;
            
            // draw a rectangle on screen
            ofSetColor(color);
            ofDrawRectangle(x * width, y * height, width, height);
        }
    }

}

void ofApp::sampleColor(float alpha){
    // sample colors from the screenshot, and draw as a grid overlay:
    ofSetColor(0, alpha);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());    // draw black rect to clear screen
}

//Function Refractoring END
*/



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::drawBalls(){
    for (int i = 0; i < balls.size(); i++) {
        balls[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::updateScreenshot(){
    screenImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    screenImage.resize(10, 10);
}

//--------------------------------------------------------------
void ofApp::drawPixelGrid(){
    // overlay opacity based on mouse x
    float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255, true);
    
    // ofSetColor(0, alpha);
    // ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    int numCols = 10;
    int numRows = 10;
    
    float width = ofGetWidth() / (float)numCols;
    float height = ofGetHeight() / (float)numRows;
    
    for (int y = 0; y < numRows; y++) {
        for (int x = 0; x < numCols; x++) {
            ofColor color = screenImage.getColor(x, y);
            color.a = alpha;
            
            ofSetColor(color);
            ofDrawRectangle(x * width, y * height, width, height);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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

