#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofClear(255, 250);
    ofSetBackgroundAuto(false);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);

    //myMesh.setMode(OF_PRIMITIVE_TRIANGLES);
    myMesh.setMode(OF_PRIMITIVE_LINES);
    myMesh.enableColors();
    myMesh.enableIndices();
    
    ofVec3f top(100.0, 50.0, 0.0);
    ofVec3f left(50.0, 150.0, 0.0);
    ofVec3f right(150.0, 150.0, 0.0);
    
    myMesh.addVertex(top);
    myMesh.addVertex(left);
    myMesh.addVertex(right);
    
    myMesh.addColor(ofFloatColor(1.0, 0.0, 0.0)); // Red
    myMesh.addColor(ofFloatColor(0.0, 1.0, 0.0)); // Green
    myMesh.addColor(ofFloatColor(0.0, 0.0, 1.0)); // Blue
    
    myMesh.addIndex(0);
    myMesh.addIndex(1);
    myMesh.addIndex(1);
    myMesh.addIndex(2);
    myMesh.addIndex(2);
    myMesh.addIndex(0);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(0);
    
    myMesh.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
