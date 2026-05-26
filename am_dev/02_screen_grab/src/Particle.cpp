#include "Particle.h"

Particle::Particle(ofVec2f _pos, ofColor _color)
{
    pos = _pos;
    color = _color;

    velocity = {0, 100};
    noiseFrequency = 0.005f;
    noiseStrength = 300.0f;
    noiseSeed = ofRandom(800.0f);
}

void Particle::draw()
{
    ofSetColor(color);
    ofDrawRectangle(pos, 10, 10);

}

void Particle::update(ofVec2f mouse)
{
    ofVec2f dir = mouse - pos;
    float dist = dir.length();

    if (dist > 1.0f) dir.normalize();

    float strength = ofMap(dist, 0, 500, 6.0f, 0.3f, true);

    velocity += dir * strength;
    velocity *= 0.85f; // damping
    pos += velocity;
}