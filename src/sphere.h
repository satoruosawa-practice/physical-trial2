//
//  particle.hpp
//  particlephysics
//
//  Created by OSAWASatoru on 5/28/17.
//
//

#pragma once

#include <stdio.h>
#include "ofMain.h"

class Sphere {
public:
  Sphere(ofVec2f position, ofVec2f velocity, float radius);
  void update();
  void draw();
  void collision(Sphere &p);
  void addForce(const ofVec2f &force);
  void addVelocity(const ofVec2f &velocity);
  void addPosition(const ofVec2f p);
  void resetForce();
//  getter
  ofVec2f getVelocity() {
    return velocity_;
  }
  ofVec2f getPosition() {
    return position_;
  }
  float getRadius() {
    return radius_;
  }

private:
  void bounceOfWalls_();
  ofVec2f velocity_;
  ofVec2f force_;
  ofVec2f position_;
  float radius_;
};
