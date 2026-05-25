#pragma once
#include "ofMain.h"

class Object3d {

public:

    Object3d();

    void setup();
    void draw();
    void update();
    

private:

    ofLight light;
    ofColor color;
    ofMaterial material;

    float rotation;
    ofVec3f lightPos;
    ofVec3f icoPos;
};