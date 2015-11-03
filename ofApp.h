#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "Star.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    ofVideoGrabber      vidGrabber;
    int                 camWidth, camHeight;
    ofxCvColorImage     colorImg;

    int avg_red;
    int avg_green;
    int avg_blue;

    ofTexture       vidTexture;
    ofPixels        vidPixels;

    ofImage starImg;
    vector<Star*> stars;
    ofRectangle* vidCollider;

    int counter = 0;
    int interval = 500;
    int maxLifetime = interval * 50;
};
