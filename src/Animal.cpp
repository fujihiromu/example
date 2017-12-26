
#include "Animal.h"

Animal::Animal(){
    
}

int Animal::rouletteChoice(int _rate[]){
    int sumRate = 0;
    for(int i=0;i<ANIMAL_KIND;i++){
        sumRate += _rate[i];
    }
    
    int choiceAnimal = int(ofRandom(sumRate));
    cout << choiceAnimal << endl;
    for(int i=0;i<ANIMAL_KIND;i++){
        choiceAnimal -= _rate[i];
        if(choiceAnimal < 0){
            return i;
        }
    }
    return 0;
}

void Animal::setAnimal(){
    int setrate[] = {dog_rate,cat_rate,cow_rate,pig_rate,sheep_rate,panda_rate,elephant_rate,Lion_rate};
    
    int setpoint[] = {dog_point,cat_point,cow_point,pig_point,sheep_point,panda_point,elephant_point,Lion_point};
    
    int animalNumber = rouletteChoice(setrate);
    point = setpoint[animalNumber];
    img.allocate(500, 500, OF_IMAGE_COLOR);
    
    if(animalNumber == 0){
        img.load("ANIMAL00.png");
    }else if(animalNumber == 1){
        img.load("ANIMAL01.png");
    }else if(animalNumber == 2){
        img.load("ANIMAL02.png");
    }else if(animalNumber == 3){
        img.load("ANIMAL03.png");
    }else if(animalNumber == 4){
        img.load("ANIMAL04.png");
    }else if(animalNumber == 5){
        img.load("ANIMAL05.png");
    }else if(animalNumber == 6){
        img.load("ANIMAL06.png");
    }else if(animalNumber == 7){
        img.load("ANIMAL07.png");
    }else if(animalNumber == 8){
        img.load("ANIMAL08.png");
    }
    
}


void Animal::update(){
    
   
}

void Animal::draw(ofPoint pos,float width,float height){
    if(isCollision){
        ofSetColor(255);
        if(width > height){
            pos.x += (width - height)/2;
            img.draw(pos, height, height);
        }else if(height > width){
            pos.y += (height - width)/2;
            img.draw(pos,width,width);
        }else{
            img.draw(pos,width,height);
        }
        
    }else{
        ofSetColor(220);
        ofDrawRectangle(pos,width,height);

    }
}


int Animal::getPoint(){
    if(isCollision){
        isCollision = false;
        collisiontime = ofGetFrameNum();
        return point;
    }else{
        return 0;
    }
}

void Animal::reset(){
    int setrate[] = {dog_rate,cat_rate,cow_rate,pig_rate,sheep_rate,panda_rate,elephant_rate,Lion_rate};
    
    int setpoint[] = {dog_point,cat_point,cow_point,pig_point,sheep_point,panda_point,elephant_point,Lion_point};
    
    int animalNumber = rouletteChoice(setrate);
    point = setpoint[animalNumber];
    
    if(animalNumber == 0){
        img.load("ANIMAL00.png");
    }else if(animalNumber == 1){
        img.load("ANIMAL01.png");
    }else if(animalNumber == 2){
        img.load("ANIMAL02.png");
    }else if(animalNumber == 3){
        img.load("ANIMAL03.png");
    }else if(animalNumber == 4){
        img.load("ANIMAL04.png");
    }else if(animalNumber == 5){
        img.load("ANIMAL05.png");
    }else if(animalNumber == 6){
        img.load("ANIMAL06.png");
    }else if(animalNumber == 7){
        img.load("ANIMAL07.png");
    }else if(animalNumber == 8){
        img.load("ANIMAL08.png");
    }
    
    isCollision = true;
}

bool Animal::getCollision(){
    return isCollision;
}

