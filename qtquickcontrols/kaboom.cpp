#include "kaboom.h"

//Konstruktor
KaBoom::KaBoom(QObject *parent) : QObject(parent){
    //x = 0;
    //y = 0;
    liveLevel= 1;
}

void KaBoom::timerSlot(){

}

void KaBoom::hitByShot(){
    liveLevel = liveLevel-1;
    if(liveLevel == 0)
    {emit deathMan();}
}
