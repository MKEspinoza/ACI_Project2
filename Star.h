#ifndef STAR_H
#define STAR_H

#include "ofMain.h"

class Star
{
    public:
        // Constructor
        Star(ofImage  img, ofColor c);

        // Observers
        bool isOffScreen();
        int getLifetime();

        // Mutators
        void update(ofRectangle rect);

        // Call back
        void draw();

    private:
        ofImage         image;
        ofColor         color;
        int             id;
        ofVec2f         position;
        ofVec2f         velocity;
        float           img_ratio;
        ofRectangle     collider;
        bool            enteredScreen;
        int             lifetime;
};

#endif // BUBBLE_H
