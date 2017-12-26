#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(185);
    ofSetFrameRate(50);
    ofEnableAlphaBlending();
    ofSetLineWidth(5);
    score.setup(30,8);
//  back.load("background.png");
    for(int i=0; i<WIDTH_MATH; i++){
        for(int j=0;j<HEIGHT_MATH; j++){
            animal[i][j].setAnimal();
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    score.update();
    
    interval_W = ofGetWidth()/WIDTH_MATH;
    interval_H = (ofGetHeight()-score_H)/HEIGHT_MATH;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    back.draw(0,0);
    
    //target,score draw()
    for(int i=0; i<WIDTH_MATH; i++){
        for(int j=0;j<HEIGHT_MATH;j++){
            ofPoint p(interval_W*i,interval_H*j+score_H);
            animal[i][j].draw( p ,interval_W,  interval_H);
        }
    }
    
    
    ofSetColor(0);
    for(int i=0;i<WIDTH_MATH;i++){
        ofDrawLine(interval_W*i, score_H, interval_W*i, ofGetHeight());
    }
    for(int i=0;i<HEIGHT_MATH;i++){
        ofDrawLine(0, interval_H*i+score_H, ofGetWidth(), interval_H*i+score_H);
    }
    ofSetColor(255);
    ofDrawRectangle(0, 0, ofGetWidth(), score_H);
    ofSetColor(0);
    score.drawScore();
    score.drawTime();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == ' '){
        score.gameStart();
        cout << "game start" << endl;
    }
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
    //マウスを使っての判定
    ofPoint mouse = ofPoint(mouseX,mouseY);
    bool isAllCollision = true;
    for(int i=0; i<WIDTH_MATH; i++){
        for(int j=0;j<HEIGHT_MATH;j++){
            if(interval_W*i < mouseX && mouseX < interval_W*(i+1) && interval_H*j +score_H<mouseY && mouseY < interval_H*(j+1)+score_H && score.isPlay()){
                score.scoreUp(animal[i][j].getPoint());
            }
            if(animal[i][j].getCollision()){
                isAllCollision = false;
            }
        }
    }
    
    if(isAllCollision){
        for(int i=0; i<WIDTH_MATH; i++){
            for(int j=0;j<HEIGHT_MATH;j++){
                animal[i][j].reset();
            }
        }
    }
    
    
    if(score.isFinish()){
        for(int i=0; i<WIDTH_MATH; i++){
            for(int j=0;j<HEIGHT_MATH;j++){
                animal[i][j].reset();
            }
        }
    }
    
    if(score.isTittle()){
        score.gameStart();
        cout << "game start" << endl;
    }
    score.changeMode();

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
