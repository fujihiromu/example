#include "score.h"

score::score(){
    
    start.load("ヒラギノ角ゴシック W6.ttc", 120);
}

void score::setup(int pt,int _playTime){
    font.load("ヒラギノ角ゴシック W6.ttc", pt);
    time = _playTime;
    playTime = _playTime;
}

void score::drawScore(){
    switch(mode){
        case tittle:
            ofSetColor(255);
            ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
            ofSetColor(0);
            font.drawString("GAME START ", ofGetWidth()/2-150,ofGetHeight()/2);
            break;
        case play:
            ofSetColor(0);
            font.drawString("score : "+ofToString(scorePoint), 450,70);
            
            
            break;
        case finish:
            ofSetColor(255);
            ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
            ofSetColor(0);
            font.drawString("SCORE", ofGetWidth()/2-100,ofGetHeight()/2-200);
            start.drawString(ofToString(scorePoint)+" pt",ofGetWidth()/2-300,ofGetHeight()/2+100);
            break;
    }
}

void score::drawTime(){

    switch(mode){
        case tittle:
          
            break;
        case play:
            int alpha;
            alpha = 255 - (ofGetElapsedTimeMillis()-startTime)/10;
            ofSetColor(255,alpha);
            start.drawString("START", ofGetWidth()/2-300, ofGetHeight()/2+100);
            ofSetColor(0);
             font.drawString("time  : "+ofToString(time), 50, 70);
            break;
        case finish:
  
            break;
    }
    
}


void score::update(){
    if(mode == play){
        time = playTime - int((ofGetElapsedTimeMillis() - startTime)/1000);
        if(time == 0){
            mode = finish;
        }
    }
    
}

void score::scoreUp(int _score){
    scorePoint += _score;
}

void score::gameStart(){
    if(mode == tittle){
        startTime = ofGetElapsedTimeMillis();
        mode = play;
    }
}
bool score::isPlay(){
    if(mode == play){
        return true;
    }else{
        return false;
    }
}

bool score::isFinish(){
    if(mode == finish){
        return true;
    }else{
        return false;
    }
}

bool score::isTittle(){
    if(mode == tittle){
        return true;
    }else{
        return false;
    }
}

void score::changeMode(){
    switch(mode){
        case tittle:
            mode = play;
            break;
        case play:
            
            break;
        case finish:
            mode = tittle;
            reset();
            break;
            
    }
}

void score::reset(){
    scorePoint = 0;
    time = playTime;
}
