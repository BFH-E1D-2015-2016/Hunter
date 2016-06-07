#ifndef MAINGAME_H
#define MAINGAME_H

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
    void setlabeltext(QString text);
    void treffer(double, double);

public slots:
    void hit(double x,double y);

    void shotedDown();

    void roundElapsed();
    void startGame();

    void populateAkEnemies();

    void removeAkEnemy(QObject* akEnemy);

private:
QQmlApplicationEngine* engine;
QTimer* roundTimer;
QTimer* bewegungsTimer;

//Test Variabeln:::
qint32 TestVar1;
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

};

#endif // MAINGAME_H
