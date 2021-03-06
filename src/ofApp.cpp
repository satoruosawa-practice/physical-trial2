#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetVerticalSync(false);
//    ofSetFrameRate(0);
  
  ofSetFrameRate(60);
  ofSetBackgroundColor(100);
  ofSetColor(200);
  
  for (int i = 0; i < 100; i++) {
    ofVec2f pos = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    ofVec2f velo = ofVec2f(5 - ofRandom(10), 5 - ofRandom(10));
    Sphere s = Sphere(pos, velo, ofRandom(20));
    spheres_.push_back(s);
  }

//  ofVec2f pos1 = ofVec2f(300, ofGetHeight() / 2);
//  ofVec2f velo1 = ofVec2f(5, 0);
//  Sphere s1 = Sphere(pos1, velo1, 20);
//  spheres_.push_back(s1);
//
//  ofVec2f pos2 = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
//  ofVec2f velo2 = ofVec2f(0, 0);
//  Sphere s2 = Sphere(pos2, velo2, 20);
//  spheres_.push_back(s2);
//
//  ofVec2f pos3 = ofVec2f(ofGetWidth() - 300, ofGetHeight() / 2);
//  ofVec2f velo3 = ofVec2f(-4, 0);
//  Sphere s3 = Sphere(pos3, velo3, 20);
//  spheres_.push_back(s3);
}

//--------------------------------------------------------------
void ofApp::update(){
  for (Sphere &s : spheres_){
    s.resetForce();
    s.update();
  }
  
  for (int i = 0; i < spheres_.size(); i++) {
    for (int j = 0; j < i; j++) {
      spheres_[i].collision(spheres_[j]);
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  for (Sphere &s : spheres_){
    s.draw();
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
