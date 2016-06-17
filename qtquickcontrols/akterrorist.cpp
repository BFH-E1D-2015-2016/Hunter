#include "akterrorist.h"


//AkTerrorist::AkTerrorist()

///Konstruktor
AkTerrorist::AkTerrorist (QObject *parent) : QObject(parent){
    x = (int) qrand() % (int) 3; // Zufallszahl bis 2
    if(x==0){x=0;y = yHolzdeckung;bewegungsform=goRigth;}         // Hinter Holzdeckung auftauchen
    else if(x==1){x=240;y = yMauerdeckung;bewegungsform=((int) qrand() % (int) 2)+2;}// Hinter Mauerdeckung auftauchen BEWEGUNGSRICHTUNG
    else if(x==2){x=480;y = ySteindeckung;bewegungsform=goLeft;}// Hinter Steindeckung auftauchen
    liveLevel= 1;
    visibel = true;
    shootTime = 0;         
    visableTime = 0;        // Sichtbarikeitstimer
    TerroristFire = 0;      // Selbstschusstimer auf 0 setzen
    speed=1;                // Geschwindikeit der Bewegung
}

void AkTerrorist::timerSlot(){


    // Bewegung
    switch(bewegungsform) {
        case goRigth:
            x=x+speed;
            // Wenn sich Terrorist aus der Deckung bewegt soll er bei einer best. Pos. nach vorne gehen,
            if(((x>150&&x<170)||(x>340&&x<360))&&((y==yHolzdeckung)||(y==ySteindeckung)||(y==yMauerdeckung)))
            {
                bewegungsform = goToFront;  // Bewegung  nach vorne wechseln
            }
            // Beim Rechten Anschlag wieder nach links gehen
            else if((x>rechterAnschlag)&&((y!=yHolzdeckung)||(y!=ySteindeckung)||(y!=yMauerdeckung)))
            {
                bewegungsform = goLeft; // Wieder nach links gehen
            }

        break;
        case goLeft:
            x=x-speed;
            // Wenn sich Terrorist aus der Deckung bewegt soll er bei einer best. Pos. nach vorne gehen,
            if(((x>150&&x<170)||(x>340&&x<410))&&((y==yHolzdeckung)||(y==ySteindeckung)||(y==yMauerdeckung)))
            {
                bewegungsform = goToFront;  // Bewegung  nach vorne wechseln
            }
            else if((x<linkerAnschlag)&&((y!=yHolzdeckung)||(y!=ySteindeckung)||(y!=yMauerdeckung)))
            {
                bewegungsform = goRigth; // Wieder nach rechts gehen
            }
        break;
        case goToFront:
            y=y+speed;
            if(y>400)
            {
                bewegungsform = (((int) qrand() % (int) 2)+2); // Zufallszahl von 2 bis 3
            }
        break;
        default:
            bewegungsform= goStopp;
        break;
    }
    emit PosChanged();

    /// Timer für Sichtbarikeit des Schusses ween Terrorist Schiesst
    if(TerroristFire>0){
        TerroristFire--;
    }

    //AkTerrorist: Schiessen beim nach vorne laufen


    if( (((x>150&&x<170)||(x>340&&x<410)) || ((y!=150)&&(y!=250)) )&&liveLevel!=0)    //Schiesstimer läuft nur wenn sicch der Terrorist nicht  hinter einer Deckung befindet.
    {if(shootTime<200){     //Zählen bis 199 -> 2Sek. S
           shootTime++;
        }
     else {
            emit fireAShot();
            qDebug()<<"shot fired from"  << (this);
            shootTime=0;
            TerroristFire = 10; // Timer für Bild mit Feuer
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

///Diese Funktion ist der Slot zum Signal hit im MainGame und überprüft ob, der Terrorist getroffen wurde.
void AkTerrorist::shotedCheck(double PosX, double PosY){

    if(((PosX==x)&&(PosY==y))&&(liveLevel!=0)){
       qDebug() << this << "wurde getroffen";
       liveLevel = 0;       // Tot einstellen
       visibel = false;
       visableTime = 100; // 1 sek strobo. bei Timer 10ms
       bewegungsform = goStopp;   // nicht mehr weiterlaufen
    }

}

///Diese Funktion ist der Slot der von mainGame verwwendet wird, um den Terroristen "manuell" zu zestöre, wenn dieser stribt.
void AkTerrorist::destroyTerrorist(){

    liveLevel = 0;  // Tot einstellen
}

/*! Diese Funktion gibt einfach den
 *X Wert der Koordinate des jeweiligen
 *C++ Objektes zurück, der dann beim jeweiligen
 *QML Objekt geändert wird. -> Signal zum QML Objekt*/
double AkTerrorist::getX(){

    return x;
}
/*! Diese Funktion gibt einfach den
 *Y Wert der Koordinate des jeweiligen
 *C++ Objektes zurück, der dann beim jeweiligen
 *QML Objekt geändert wird. -> Signal zum QML Objekt*/
double AkTerrorist::getY(){

    return y;

}

/*! Diese Funktion gibt an ob der Terrorist sichtbar
 *oder unsichtbar ist. Diese wird verwendet um
 *den Strobo Effekt zu realisieren, wenn der Terrorist stirbt.-> Signal zum QML Objekt*/
bool AkTerrorist::getVisibel(){


    return visibel;
}

///Funktion gibt zurück, ob Terrorist gerade am schiessen ist.-> Signal zum QML Objekt
bool AkTerrorist::getTerroristFire(){

    bool State;
    if(TerroristFire == 0)
        {State = false;}
    else
        {State = true;}
    return State;
}


///Destruktor
AkTerrorist::~AkTerrorist()
{

}








