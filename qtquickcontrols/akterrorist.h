#ifndef AKTERRORIST_H
#define AKTERRORIST_H

//Bewgungsformen
#define goStopp           0
#define goToFront         1
#define goRigth           2
#define goLeft            3

//Position der Deckungen
#define yHolzdeckung            150
#define ySteindeckung           150
#define yMauerdeckung           250

//Anschläge bis wo sich die Terroristen bewegen
#define rechterAnschlag         500
#define linkerAnschlag          20

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QQmlApplicationEngine>

class AkTerrorist : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double xOrdinateAk READ getX NOTIFY PosChanged)
    Q_PROPERTY(double yOrdinateAk READ getY NOTIFY PosChanged)
    Q_PROPERTY(bool aCtiveAk READ getVisibel NOTIFY PosChanged)
    Q_PROPERTY(bool StateQml READ getTerroristFire NOTIFY PosChanged)

public:
    explicit AkTerrorist(QObject *parent = 0);
    ~AkTerrorist();

    double getX();
    double getY();
    bool getVisibel();
    bool getTerroristFire();
    //Positonsvariablen
    double x;
    double y;


/* Signale die von AkTerrorist gesendet werden*/
signals:

    void PosChanged();              // Signal zum Updaten von QML
    void fireAShot();               // Signal das der Terrorist ein Schuss abgefeuert hat -> Slot: mainGame (Leben abziehen)
    void deathMan(QObject*);        // Signal das der Terrorist gestorben ist -> Slot: mainGame(Objekt vernichten)

/*Öffentliche Slots*/
public slots:

    void timerSlot();                   // Slot für Bewegungs und Selbstschuss Timer
    void shotedCheck(double, double);   // mit den übergebenen Koordinaten überprüfen ob Terrorist getroffen wurde.
    void destroyTerrorist();            // manuelles Zestörenen des Terroristen (Wenn Spiel zuende)

private:
/* Variabeln der Klasse AkTerrorist*/


    // Für Bewegung
    double speed;       // Bewegungsgeschwindikeit
    char bewegungsform; // Richtung der Bewegung des Terroristen

    //Für schiessen
    int shootTime;   // Selbstschiesstimer

    // Gibt an ob Terrorist lebt oder Tot ist.
    bool liveLevel;         // Gibt an ob Terrorist lebt oder tot ist
    bool visibel;           // lässt Terroristen blicken wenn tot;
    char TerroristFire;
    double visableTime;     // Timer für Dauer des strobo.


};

#endif // AKTERRORIST_H
