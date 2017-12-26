#pragma once
#include "ofMain.h"

#define ANIMAL_KIND 8



class Animal {
    
public:
    Animal();
    void setAnimal();
    void update();
    void draw(ofPoint pos,float width,float height);
    void collsion();
    void reset();
    int getPoint();
    int rouletteChoice(int _rate[]);
    bool getCollision();
    
    enum rateList {
        dog_rate = 20,
        cat_rate = 20,
        cow_rate = 10,
        pig_rate = 10,
        sheep_rate = 10,
        panda_rate = 7,
        elephant_rate = 5,
        Lion_rate = 3
    };
    
    enum pointList {
        dog_point = 10,
        cat_point = 20,
        cow_point = 30,
        pig_point = 40,
        sheep_point = 50,
        panda_point = 100,
        elephant_point = 200,
        Lion_point = 1000
    };

    
private:
    ofImage img;
    int point;
    bool isCollision = true;
    int collisiontime;

};
