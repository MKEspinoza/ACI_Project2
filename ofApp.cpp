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

    unsigned char *pixels=vidGrabber.getPixels();
    avg_red = 0;
    avg_green = 0;
    avg_blue = 0;


    //printf(">>>>%i >>>%i >>>%i\n",pixels[0],pixels[1],pixels[2]);

    for (int i = 0; i < camWidth*camHeight*3; i=i+3){

        if (pixels[i] < 85) avg_red += 0;
        else if (pixels[i] > 170) avg_red += 255;
        else avg_red += pixels[i];

        if (pixels[i+1] < 85) avg_green += 0;
        else if (pixels[i+1] > 170) avg_green += 255;
        else avg_green += pixels[i+1];

        if (pixels[i+2] < 85) avg_blue += 0;
        else if (pixels[i+2] > 170) avg_blue += 255;
        else avg_blue += pixels[i+2];




/**
        avg_red += pixels[i];
        avg_green += pixels[i];
        avg_blue += pixels[i];
        **/



    };
    avg_red = avg_red/(camWidth*camHeight);
    avg_green = avg_green/(camWidth*camHeight);
    avg_blue = avg_blue/(camWidth*camHeight);


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::white);
    vidGrabber.draw(ofGetWidth()/2 - camWidth/2, ofGetHeight()/2 - camHeight/2);

    ofColor c(avg_red,avg_green,avg_blue);
    c.setSaturation( 100 );
    ofSetColor(c);
    ofCircle(20,20,0, 20);

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
