#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetVerticalSync(false);
//    ofSetFrameRate(0);
  ofSetFrameRate(60);
  for (int i = 0; i < 1; i++) {
    ofVec2f pos = ofVec2f(300, ofGetHeight() / 2);
    ofVec2f velo = ofVec2f(0, 0);
    Particle p = Particle(pos, velo, 20);
    particles_.push_back(p);
  }
  ofVec2f pos2 = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
  ofVec2f velo2 = ofVec2f(0, 0);
  Particle p2 = Particle(pos2, velo2, 20);
    particles_.push_back(p2);

  ofVec2f pos3 = ofVec2f(ofGetWidth() - 300, ofGetHeight() / 2);
  ofVec2f velo3 = ofVec2f(-5, 0);
  Particle p3 = Particle(pos3, velo3, 20);
  particles_.push_back(p3);
  
}

//--------------------------------------------------------------
void ofApp::update(){
  for (Particle &p : particles_){
    for (Particle &other_p : particles_){
      if(&p != &other_p) {
        p.updateCollision(other_p);
      }
    }
  }
  
  for (Particle &p : particles_){
    p.updatePosition();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  for (Particle &p : particles_){
    p.draw();
  }
  ofDrawBitmapString(ofGetFrameRate(), 100, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
  
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
  
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
  
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
  
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
  
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
  
}
