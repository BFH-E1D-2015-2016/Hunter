#ifndef BOMBTERRORIST_H
#define BOMBTERRORIST_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QQmlApplicationEngine>

class BombTerrorist  : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double xOrdinateBomb READ getX NOTIFY PosChanged)
    Q_PROPERTY(double yOrdinateBomb READ getY NOTIFY PosChanged)
    Q_PROPERTY(bool aCtiveBomb READ getVisibel NOTIFY PosChanged)
    Q_PROPERTY(bool StateQml READ getTerroristDetonates NOTIFY PosChanged)

public:
    explicit BombTerrorist(QObject *parent = 0);
    ~BombTerrorist();

    double getX();
    double getY();
    bool getVisibel();
    bool getTerroristDetonates();

    double x;
    double y;



signals:
    void PosChanged();

    void detonates(); // Explodiert
    void bottomReached(); //Unterer Rand erreicht
    void deathMan(QObject*);      // Gestorben

public slots:
    void timerSlot();   // Spielzeit Runde
    void shotedCheck(double, double);   // Wurde getroffen

private:


    // Für Bewegung
    double speed;       // Bewegungsgeschwindikeit
    char bewegungsform;

    //Für Bombe
    int bombTime;

    // Gibt an ob Terrorist lebt oder Tot ist.
    bool liveLevel;
    bool visibel;        //lässt Terroristen blicken wenn tot;

    double visableTime; // Timer für Dauer des strobo.


};

#endif // BOMBTERRORIST_H
