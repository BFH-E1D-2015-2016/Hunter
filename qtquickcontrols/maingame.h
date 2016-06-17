#ifndef MAINGAME_H
#define MAINGAME_H

#define Anfangsleben           10

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "akterrorist.h"
#include "bombterrorist.h"


class MainGame : public QObject
{
    Q_OBJECT
public:
    explicit MainGame(QObject *parent = 0);



signals:
    void livesChanged();
    void playDetonatsSound();
    void playGunSound();
    void playBottomReachedSound();
    void setlabeltext(QString text);
    void treffer(double, double);
    void gameOver();

public slots:
    void hit(double x,double y);

    void shotedDown();
    void detonatedDown();
    void terroristAtBottom();

    void roundElapsed();
    void infoUpdate();
    void startGame();

    void populateAkEnemies();

    void removeAkEnemy(QObject* akEnemy);
    void removeBombEnemy(QObject* akEnemy);

private:
QQmlApplicationEngine* engine;
QTimer* roundTimer;
QTimer* bewegungsTimer;
//bool gameOverSended;

//Test Variabeln:::
qint32 roundCounter;
qint8 i;

//Level Steuerung
qint8 level;
qint32 levelTimer;

//für for Schleife
QObject* testObject;

//Score and live
qint32 score;
qint32 live;
QString infoString;

//Trefferpositon
double trefferX;
double trefferY;

QString TestS1;
QList<QObject*> AkEnemis;
QList<QObject*> BombEnemis;

};

#endif // MAINGAME_H
