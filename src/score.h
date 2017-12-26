#include <ofMain.h>
#include <ofxTrueTypeFontUC.h>

class score {
    
    public:
    score();
    
    enum gamemode{
        tittle,
        play,
        finish
    };
    
    void setup(int pt,int playTime);
    void drawScore();
    void drawTime();
    void update();
    void gameStart();
    void scoreUp(int _score);
    void changeMode();
    void reset();
    bool isPlay();
    bool isFinish();
    bool isTittle();
    
    gamemode mode;
    
    private:
    ofxTrueTypeFontUC font,start;
    int scorePoint;
    int time;
    int playTime;
    float startTime;
    

};
