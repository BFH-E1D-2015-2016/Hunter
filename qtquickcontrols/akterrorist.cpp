#include "akterrorist.h"



//AkTerrorist::AkTerrorist()

//Konstruktor
AkTerrorist::AkTerrorist (QObject *parent) : QObject(parent){
    x = (int) qrand() % (int) 3; // Zufallszahl bis 2
    if(x==0){x=0;bewegungsform=0;}         // Hinter Holzdeckung auftauchen
    else if(x==1){x=240;bewegungsform=(int) qrand() % (int) 2;}// Hinter Mauerdeckung auftauchen BEWEGUNGSRICHTUNG
    else if(x==2){x=480;bewegungsform=1;}// Hinter Steindeckung auftauchen
    //qDebug() << " X = " << x;
    y = 250;
    //qDebug() << " Y = " << y;
    liveLevel= 1;
    visibel = true;
    shootTime = 0;
    visableTime = 2;

    //Bewegungen
    speed=1;    // Geschwindikeit der Bewegung
}

void AkTerrorist::timerSlot(){
    // ncah rechts gehen
    if (bewegungsform == 0)     // Bewegt sich aus der Deckung
    {
        x=x+speed;
        if((x>150&&x<170)||(x>340&&x<360))
        {
            bewegungsform = 2;  // Bewegung  nach vorne wechseln
        }
    }
    //nach links gehen
    if (bewegungsform == 1)     // Bewegt sich aus der Deckung
    {
        x=x-speed;
        if((x>150&&x<170)||(x>340&&x<410))
        {
            bewegungsform = 2;  // Bewegung  nach vorne wechseln
        }
    }
    //nach vorne gehen
    else if (bewegungsform == 2)
    {
        y=y+speed;
        if(y>400)
        {
            bewegungsform = 3;  //Bewegung gestoppt
        }
    }
    emit PosChanged();

    //Schiessen beim nach vorne laufen


    if(((x>150&&x<170)||(x>340&&x<360))&&liveLevel!=0)    //Befindet sich nicht hinter einer Deckung und lebt noch.
    {if(shootTime<200){
           shootTime++;
        }
     else {
            emit fireAShot();
            qDebug()<<"shot fired";
            shootTime=0;
        }
    }

    //strobo bei tot
    if((liveLevel == 0)&&(visableTime != 0)){
        visableTime--;         //Timer für den strobo
        visibel = !visibel;     //strobo
        }
    else if((liveLevel == 0)&&(visableTime == 0)){  // strob beenden und Objekt vernichten
        visibel= false; // strobo beende

        // Objekt vernichten!!!
        emit deathMan(this);

        }
}

void AkTerrorist::shotedCheck(double PosX, double PosY){

    if((PosX==x)&&(PosY==y)){
       qDebug() << this << "wurde getroffen";
       liveLevel = 0;       // Tot einstellen
       visibel = false;
       visableTime = 100; // 1 sek strobo. bei Timer 10ms
       bewegungsform = 3;   // nicht mehr weiterlaufen
    }

    }

double AkTerrorist::getX(){
    return x;
}

double AkTerrorist::getY(){
    return y;

}

bool AkTerrorist::getVisibel(){
    return visibel;
}



AkTerrorist::~AkTerrorist()
{
    //qDebug() << "Terrorist dead!!!";
}








