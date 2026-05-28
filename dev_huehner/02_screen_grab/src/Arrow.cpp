#include "Arrow.h"

// constructor
Arrow::Arrow() {
    
    //middle position
    x =  ofGetWidth()/2;
    y =  ofGetHeight()/2;
    
    start = glm::vec3(x, y, 0);
   
    // initial end position
    end = glm::vec3(ofGetMouseX(), ofGetMouseY(), 0);

    
    // inside the constructor you initialize the object's variables

    arrowSize = 10.0f;
}

// update position, etc.
void Arrow::update() {

    mouseX = ofGetMouseX();
    mouseY = ofGetMouseY();

    // arrow to mouse
    end = glm::vec3(mouseX, mouseY, 0);
}


// draw the ball
void Arrow::draw() {
    ofSetColor(color);    
    ofDrawArrow(start, end, arrowSize);
}

