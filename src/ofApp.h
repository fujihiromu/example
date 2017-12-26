#pragma once

#include "ofMain.h"
#include "score.h"
#include "Animal.h"

#define MOVIENUM 15
#define WIDTH_MATH 5
#define HEIGHT_MATH 5

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    // ゲーム機能
    Animal animal[WIDTH_MATH][HEIGHT_MATH];
    score score;
    ofImage back;
    
    int interval_W;
    int interval_H;
    int score_H = 100;
};
