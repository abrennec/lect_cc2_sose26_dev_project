#include "Object3d.h"

Object3d::Object3d(){

    color = {255, 50, 100};
    lightPos = {300,300,600};
    rotation = 0;
    icoPos = {350, 250, 150};


}

void Object3d::setup(){


    light.setup();
    light.setPosition(lightPos);

    material.setDiffuseColor(ofColor(255, 50, 100));
    material.setSpecularColor(ofColor::white);
    material.setShininess(200);

}

    void Object3d::update() {
    rotation += 2.5;  
}

    void Object3d::draw() {

        light.enable();

        ofPushMatrix();

        ofTranslate(icoPos);

        ofRotateZDeg(rotation);
        ofRotateXDeg(rotation);

        material.begin();
        ofDrawIcoSphere(icoPos, 120);
        material.end();

        ofPopMatrix();

        light.disable();
    }