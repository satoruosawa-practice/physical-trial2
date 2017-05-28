//
//  particle.hpp
//  particlephysics
//
//  Created by OSAWASatoru on 5/28/17.
//
//

#ifndef particle_hpp
#define particle_hpp

#include <stdio.h>
#include "ofMain.h"

class Particle {
public:
  Particle(ofVec2f p, ofVec2f velo, float rad);
  void draw();
  void updateCollision(Particle &p);
  void updateWallCollision();
  void updatePosition();

  ofVec2f getVelosity() {
    return velosity_;
  }
  ofVec2f getPosition() {
    return position_;
  }
  float getRadius() {
    return radius_;
  }
private:
  ofVec2f velosity_;
  ofVec2f add_velosity_;
  ofVec2f position_;
  float radius_;
};


#endif /* particle_hpp */

