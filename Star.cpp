#include "Star.h"

// Constructor - only the image is specified.
Star::Star(ofImage img, ofColor c) {
    image = img;
    img_ratio = ofRandom(0.1,0.5);
    image.resize(image.getWidth() * img_ratio, image.getHeight() * img_ratio );

    int direction = (int)ofRandom(0, 4); // Generate random direction
    float x,y,dx,dy;
    if(direction == 0) {
        x = 0;
        y = ofRandom(0, ofGetHeight());
        dx = ofRandom(0.5, 1.5);
        dy = ofRandom(-1.5, 1.5);
    } else if(direction == 1) {
        x = ofRandom(0, ofGetWidth() - image.getWidth());
        y = 0;
        dx = ofRandom(-1.5, 1.5);
        dy = ofRandom(0.5, 1.5);
    } else if(direction == 2) {
        x = ofGetWidth() - image.getWidth();
        y = ofRandom(0, ofGetHeight());
        dx = ofRandom(-1.5, -0.5);
        dy = ofRandom(-1.5, 1.5);
    } else {
        x = ofRandom(0, ofGetWidth());
        y = ofGetHeight() - image.getHeight();
        dx = ofRandom(-1.5, 1.5);
        dy = ofRandom(-1.5, -0.5);
    }
    position = ofVec2f(x, y);
    velocity = ofVec2f(dx, dy);
    collider.x = position.x;
    collider.y = position.y;
    collider.width = image.getWidth();
    collider.height = image.getHeight();
    enteredScreen = false;

    color.r = c.r;
    color.g = c.g;
    color.b = c.b;

    lifetime = 0;
}

bool Star::isOffScreen() {
    int radius = image.getHeight()/2;
    int leftmost = position.x;
    int rightmost = position.x + image.getWidth();
    int uppermost = position.y;
    int bottommost = position.y + image.getHeight();

    bool answer = (uppermost > ofGetHeight()) || (bottommost < 0 ) || (leftmost > ofGetWidth() || (rightmost < 0));
    if(answer) {
        enteredScreen = true;
    }
    return answer;
}

int Star::getLifetime() {
    return lifetime;
}

//Mutators
void Star::update(ofRectangle otherCollider){
    position.x += velocity.x;
    position.y += velocity.y;
    collider.x += velocity.x;
    collider.y += velocity.y;
    if(collider.intersects(otherCollider)) {
        if(!(ofInRange(collider.getBottom(), otherCollider.getTop(), otherCollider.getBottom()) &&
           ofInRange(collider.getTop(), otherCollider.getTop(), otherCollider.getBottom()))) {
            velocity.y = -velocity.y;
        } else {
            velocity.x = -velocity.x;
        }
    } else if(isOffScreen()) {
        if(!(ofInRange(collider.getBottom(), 0, ofGetHeight()) &&
           ofInRange(collider.getTop(), 0, ofGetHeight()))) {
            velocity.y = -velocity.y;
        } else {
            velocity.x = -velocity.x;
        }
    }
    lifetime += 1;
}


//Call back
void Star::draw() {
    ofSetColor( color );
    image.draw(position.x, position.y);
}
