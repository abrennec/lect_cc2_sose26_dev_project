#pragma once
#include "ofMain.h"

class Particle
{

public:
    Particle(ofVec2f _pos, ofColor _color);

    void draw();
    void update(ofVec2f mouse);

protected:
    Particle() {};

    // Coordinates
    ofVec2f pos;
    ofVec2f p2;

    // Shape
    float radius;
    float width;
    float height;
    ofColor color;

    // Noise Variables
    ofVec2f velocity;
    float noiseStrength;
    float noiseFrequency;
    float noiseSeed;
};