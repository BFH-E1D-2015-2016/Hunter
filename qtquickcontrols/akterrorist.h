#ifndef AKTERRORIST_H
#define AKTERRORIST_H

//int xPosition [3]{100,200,300};
//int yPosition [3]{100,200,300};
//int startVisableTimes [3];

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

    double x;
    double y;



signals:
    void PosChanged();


    void takeShelter();   // geht in Deckung
    void fireAShot();     // Schussabgabe
    void deathMan(QObject*);      // Gestorben

public slots:
    void timerSlot();   // Spielzeit Runde
    void shotedCheck(double, double);   // Wurde getroffen

private:
    // TerroristTyp
    bool TerroristTyp;

    // Für Bewegung
    double speed;       // Bewegungsgeschwindikeit
    char bewegungsform;

    //Für schiessen
    int shootTime;   // Selbstschiesstimer

    //Für Bombe
    int bombTime;

    // Gibt an ob Terrorist lebt oder Tot ist.
    bool liveLevel;
    bool visibel;        //lässt Terroristen blicken wenn tot;
    char TerroristFire;

    double visableTime; // Timer für Dauer des strobo.


};

#endif // AKTERRORIST_H
