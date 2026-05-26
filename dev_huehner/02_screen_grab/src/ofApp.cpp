#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){


	cout << "GL Version: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
    cout << "Renderer: " << glGetString(GL_RENDERER) << endl;
    cout << "Vendor: " << glGetString(GL_VENDOR) << endl;


	ofBackground(255);

	int numBalls = 5;

	// fill our vector
	for (int i = 0; i < numBalls; i++) {
		balls.push_back(Ball());
	}

}

//--------------------------------------------------------------
void ofApp::update(){

	for (int i = 0; i < balls.size(); i++) {
		balls[i].update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawBalls();
    updateScreenshot();
    drawPixelGrid();

    // 3D OBJEKT HINZUFÜGEN
    ofSetColor(255, 100, 100);  // Farbe: Rot
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);  // Mitte des Screens
    
    // Rotation basieren auf der Mausposition
    ofRotateY(ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, TWO_PI) *4);  // TWO_PI = 360°
    ofRotateX(ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, TWO_PI) *4);
    
    ofDrawBox(100);  // Box mit Größe 100
}

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

