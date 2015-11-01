#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth = 320*2;
    camHeight = 240*2;

    vidGrabber.setVerbose(true);
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(camWidth, camHeight);

    vidPixels.allocate(camWidth, camHeight, OF_PIXELS_RGB);
    vidTexture.allocate(vidPixels);


}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();

    cvAvg( , IntPtr mask );

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::white);
    vidGrabber.draw(ofGetWidth()/2 - camWidth/2, ofGetHeight()/2 - camHeight/2);

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
