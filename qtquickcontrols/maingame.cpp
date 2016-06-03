#include "maingame.h"

MainGame::MainGame(QObject *parent) : QObject(parent)
{
    TestVar1 = 0;
    score = 0;
    live = 10;

    roundTimer = new QTimer(this);   // Create a new timer and make it a child of MainGame
    roundTimer->setInterval(1000);   // set interval in ms

    bewegungsTimer = new QTimer(this);   // Create a new timer and make it a child of MainGame
    bewegungsTimer->setInterval(10);   // set interval in ms

    //Slots für Nach jeder Runde Gegner neu setzen
    connect(roundTimer,SIGNAL(timeout()),this,SLOT(roundElapsed()));

    //create a new QmlApplication engine and expose context properties
    engine = new QQmlApplicationEngine(this);

    //set the enemies and gifts lists as context properties, they are used as models
    engine->rootContext()->setContextProperty("mainGame",this);
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
}

void MainGame::startGame(){
    qDebug() << " Game started. ";
    roundTimer->start();
    bewegungsTimer->start();
}

void MainGame::hit(double x,double y){
    qDebug() << "hit"<< x << y;
    score=score+10;

    trefferX = x;
    trefferY = y;

    emit treffer(trefferX,trefferY);

}

void MainGame::roundElapsed(){
    TestVar1++;
    //emit livesChanged();
    //TestS1= QStringLiteral("Diese Spiel läuft seit %1. Sekunden").arg(TestVar1);
    infoString= QStringLiteral("Zeit:%1 ").arg(TestVar1);
    infoString += QStringLiteral("Leben:%1 ").arg(live);
    infoString += QStringLiteral("Score%1 ").arg(score);
    emit setlabeltext(infoString);
    qDebug() << " 1 sek elapsed " << TestVar1;

    populateAkEnemies();
    engine->rootContext()->setContextProperty("akEnemy", QVariant::fromValue(AkEnemis));
}

void MainGame::shotedDown(){
    score=score-10;
    live--;
}

void MainGame::populateAkEnemies(){

if(AkEnemis.size()<9){
        AkTerrorist * akEnemy = new AkTerrorist(this);

        connect(bewegungsTimer,SIGNAL(timeout()),akEnemy,SLOT(timerSlot()));
        connect(akEnemy,SIGNAL(fireAShot()),this,SLOT(shotedDown()));
        connect(this,SIGNAL(treffer(double,double)),akEnemy,SLOT(shotedCheck(double, double)));
        connect(akEnemy,SIGNAL(deathMan(QObject*)),this,SLOT(removeAkEnemy(QObject*)));

        AkEnemis.append(akEnemy);
        //
        //qDebug() << " akEnemi was produced: ";
}

}

void MainGame::removeAkEnemy(QObject* akEnemy){
    qDebug() << " remove enemy now: " << akEnemy;
    AkEnemis.removeOne(akEnemy);
    engine->rootContext()->setContextProperty("akEnemy", QVariant::fromValue(AkEnemis));
    akEnemy->deleteLater();

}
