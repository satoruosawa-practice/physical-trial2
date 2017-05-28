//
//  particle.cpp
//  particlephysics
//
//  Created by OSAWASatoru on 5/28/17.
//
//

#include "particle.hpp"
Particle::Particle(ofVec2f p, ofVec2f velo, float rad)
: position_(p),
velosity_(velo),
add_velosity_(ofVec2f(0, 0)),
radius_(rad)
{}

void Particle::draw() {
  ofDrawCircle(position_, radius_);
}

void Particle::updateCollision(Particle &p) {
  ofVec2f p_vec = p.getPosition() - position_;
  if (p_vec.length() < radius_ + p.getRadius()) {
    std::cout << p_vec.length() << std::endl;
    ofVec2f n_p_vec = p_vec.getNormalized();
    float velo_diff = p.getVelosity().dot(n_p_vec) - velosity_.dot(n_p_vec);
    add_velosity_ += velo_diff * p_vec.getNormalized();
  }
}

void Particle::updateWallCollision() {
  if (position_.x < radius_ || position_.x > ofGetWidth() - radius_) {
    velosity_.x = -velosity_.x;
  }
  if (position_.y < radius_ || position_.y > ofGetHeight() - radius_) {
    velosity_.y = -velosity_.y;
  }
}

void Particle::updatePosition() {
  velosity_ += add_velosity_;
  updateWallCollision();
  add_velosity_ = ofVec2f(0, 0);
  position_ += velosity_;
}
