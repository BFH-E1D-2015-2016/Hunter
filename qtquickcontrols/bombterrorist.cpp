#include "bombterrorist.h"

///Konstruktor
BombTerrorist::BombTerrorist (QObject *parent) : QObject(parent){
    // Anfangsposition
    x = (int) qrand() % (int) 3; // Zufallszahl bis 2
    if(x==0){x=0;y = yHolzdeckung;bewegungsform=goRigth;}         // Hinter Holzdeckung auftauchen
    else if(x==1){x=240;y = yMauerdeckung;bewegungsform=((int) qrand() % (int) 2)+2;}// Hinter Mauerdeckung auftauchen BEWEGUNGSRICHTUNG
    else if(x==2){x=480;y = ySteindeckung;bewegungsform=goLeft;}// Hinter Steindeckung auftauchen
    // Weitere Anfangszusände
    liveLevel= 1;
    visibel = true;
    bombTime = 100;
    visableTime = 2;
    bombTime = 100;

    //Bewegungen
    speed=1;    // Geschwindikeit der Bewegung
}

void BombTerrorist::timerSlot(){
// BEWGUNGEN
    switch(bewegungsform) {
        case goRigth:
            x=x+speed;
            // Wenn sich Terrorist aus der Deckung bewegt soll er bei einer best. Pos. nach vorne gehen,
            if(((x>150&&x<170)||(x>340&&x<360))&&((y==yHolzdeckung)||(y==ySteindeckung)||(y==yMauerdeckung)))
            {
                bewegungsform = goToFront;  // Bewegung  nach vorne wechseln
            }
            // Beim Rechten Anschlag wieder nach links gehen
            else if(x>rechterAnschlag)
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
            else if(x<linkerAnschlag)
            {
                bewegungsform = goLeft; // Wieder nach links gehen
            }
        break;
        case goToFront:
            y=y+speed;
            if(y>400)
            {
                bewegungsform = goStopp; // Zufallszahl von 2 bis 3
                emit bottomReached();
            }
        break;
        case goStopp:
            ;
        break;
        default:
            bewegungsform= goStopp;
        break;
    }
    emit PosChanged();


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
    //Timer zur Selbstexplosion
    if((y>400)&&(liveLevel==true)){
        if(bombTime>0){
            bombTime--;
        }
        if((bombTime==0)){
            liveLevel = 0;
            emit detonates();
            qDebug()<<"detonated";
        }
    }

}

///Diese Funktion ist der Slot zum Signal hit im MainGame und überprüft ob, der Terrorist getroffen wurde.
void BombTerrorist::shotedCheck(double PosX, double PosY){

    if(((PosX==x)&&(PosY==y))&&(liveLevel!=0)){
       qDebug() << this << "wurde getroffen";
       liveLevel = 0;       // Tot einstellen
       visibel = false;
       visableTime = 100; // 1 sek strobo. bei Timer 10ms
       bewegungsform = goStopp;   // nicht mehr weiterlaufen
    }

}

/*!
 * Diese Funktion ist der Slot der von mainGame verwwendet
 * wird, um den Terroristen "manuell" zu zestöre, wenn dieser stribt.
 */
void BombTerrorist::destroyTerrorist(){
    liveLevel = 0;  // Tot einstellen
}

/*! Diese Funktion gibt einfach den
 *Y Wert der Koordinate des jeweiligen
 *C++ Objektes zurück, der dann beim jeweiligen
 *QML Objekt geändert wird. -> Signal zum QML Objekt*/
double BombTerrorist::getX(){

    return x;
}

/*! Diese Funktion gibt einfach den
 *Y Wert der Koordinate des jeweiligen
 *C++ Objektes zurück, der dann beim jeweiligen
 *QML Objekt geändert wird. -> Signal zum QML Objekt*/
double BombTerrorist::getY(){

    return y;

}

/*! Diese Funktion gibt an ob der Terrorist sichtbar
 *oder unsichtbar ist. Diese wird verwendet um
 *den Strobo Effekt zu realisieren, wenn der Terrorist stirbt.-> Signal zum QML Objekt*/
bool BombTerrorist::getVisibel(){

    return visibel;
}

/*! Diese Funktion gibt an ob der explodiert. Diese Funktion sollte eine Animation
 * im QML starten die eine Explosion darstellt wenn der Terrorist stirbt.-> Signal zum QML Objekt*/
bool BombTerrorist::getTerroristDetonates(){

    return true;
}

/// Destruktor
BombTerrorist::~BombTerrorist()
{

}
