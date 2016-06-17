#ifndef BOMBTERRORIST_H
#define BOMBTERRORIST_H

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
    //Positonsvariablen
    double x;
    double y;

/* Signale die von AkTerrorist gesendet werden*/
signals:

    void PosChanged();              ///< Signal zum Updaten von QML
    void detonates();               ///< Signal das der Terrorist explodiert ist -> Slot: mainGame (Leben abziehen)
    void bottomReached();           ///< Unterer Rand erreicht
    void deathMan(QObject*);        ///< Signal das der Terrorist gestorben ist -> Slot: mainGame(Objekt vernichten)

/*Öffentliche Slots*/
public slots:

    void timerSlot();                   ///< Slot für Bewegungs und Selbstexplosions Timer
    void shotedCheck(double, double);   ///< mit den übergebenen Koordinaten überprüfen ob Terrorist getroffen wurde.
    void destroyTerrorist();            ///< manuelles Zestörenen des Terroristen (Wenn Spiel zuende)

private:
/* Variabeln der Klasse BombTerrorist*/

    // Für Bewegung
    double speed;       ///< Bewegungsgeschwindikeit
    char bewegungsform;

    //Für Bombe
    int bombTime;           ///< timer für die Selbstexplosion des Terroristten

    // Gibt an ob Terrorist lebt oder Tot ist.
    bool liveLevel;         ///< Gibt an ob Terrorist lebt oder tot ist
    bool visibel;           ///<lässt Terroristen blicken wenn tot;
    double visableTime;     ///< Timer für Dauer des strobo.


};

#endif // BOMBTERRORIST_H
