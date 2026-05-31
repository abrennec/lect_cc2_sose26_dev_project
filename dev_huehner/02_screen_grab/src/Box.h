#pragma once
#include "ofMain.h"

class Box {
public:
    Box();
    void update();
    void draw();
    
private:
    float size;
    ofColor color;
};