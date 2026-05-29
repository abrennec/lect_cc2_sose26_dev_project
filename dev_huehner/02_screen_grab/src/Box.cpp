#include "Box.h"

Box::Box() {
    size = 100.0f;
    color = ofColor(255, 100, 100);
}

void Box::update() {
    // Hier könnten Updates rein wenn nötig
}

void Box::draw() {
    // ✅ DIESER CODE KOMMT HIER HER:
    ofSetColor(color);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
    
    ofRotateY(ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, TWO_PI) *4);
    ofRotateX(ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, TWO_PI) *4);
    
    ofDrawBox(size);
}