//
//  particle.cpp
//  particlephysics
//
//  Created by OSAWASatoru on 5/28/17.
//
//

#include "./sphere.h"
Sphere::Sphere(ofVec2f position, ofVec2f velocity, float radius)
  : position_(position),
    velocity_(velocity),
    force_(ofVec2f(0, 0)),
    radius_(radius)
{}

void Sphere::update() {
  velocity_ += force_;
  position_ += velocity_;
  bounceOfWalls_();
}

void Sphere::draw() {
  ofDrawCircle(position_, radius_);
}

void Sphere::collision(Sphere &another) {
  ofVec2f to_another = another.getPosition() - position_;
  if (to_another.length() < radius_ + another.getRadius()) {
    std::cout << to_another.length() << std::endl;
    ofVec2f N_to_another = to_another.getNormalized();
    float velo_diff = another.getVelocity().dot(N_to_another) - velocity_.dot(N_to_another);
    velocity_ += velo_diff * N_to_another;
    another.addVelocity(-velo_diff * N_to_another);
    float buried_amount = radius_ + another.getRadius() - to_another.length();
    position_ += -N_to_another * buried_amount * 0.5;
    another.addPosition(N_to_another * buried_amount * 0.5);
  }
}

void Sphere::resetForce() {
  force_ = ofVec2f(0, 0);
}

void Sphere::addForce(const ofVec2f &force) {
  force_ += force;
}

void Sphere::addVelocity(const ofVec2f &velocity) {
  velocity_ += velocity;
}

void Sphere::addPosition(const ofVec2f p) {
  position_ += p;
}

void Sphere::bounceOfWalls_() {
  float xmin = radius_;
  float xmax = ofGetWidth() - radius_;
  float ymin = radius_;
  float ymax = ofGetHeight() - radius_;
  
  if (position_.x < xmin) {
    velocity_.x *= -1;
    position_.x = xmin + (xmin - position_.x);
  } else if (position_.x > xmax) {
    velocity_.x *= -1;
    position_.x = xmax - (position_.x - xmax);
  }
  if (position_.y < ymin) {
    velocity_.y *= -1;
    position_.y = ymin + (ymin - position_.y);
  } else if (position_.y > ymax) {
    velocity_.y *= -1;
    position_.y = ymax - (position_.y - ymax);
  }
}

