#include "maingame.h"

MainGame::MainGame(QObject *parent) : QObject(parent)
{
    TestVar1 = 0;
    score = 0;
    live = 10;

    //Level Steuerung
    level = 1;          // In
    levelTimer = 1000;  // In 10ms

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
    engine->load(QUrl(QStringLiteral("main.qml")));
}

void MainGame::startGame(){
    qDebug() << " Game started. ";
    roundTimer->start();
    bewegungsTimer->start();
}

void MainGame::hit(double x,double y){
    qDebug() << "hit"<< x << y;
    score=score+1000;

    trefferX = x;
    trefferY = y;

    emit treffer(trefferX,trefferY);

}

void MainGame::roundElapsed(){

    if (live>0){
        TestVar1++;
        infoString= QStringLiteral("Zeit:%1 ").arg(TestVar1);
        infoString += QStringLiteral("Leben:%1 ").arg(live);
        infoString += QStringLiteral("Score%1 ").arg(score);
        emit setlabeltext(infoString);
        qDebug() << " 1 sek elapsed " << TestVar1;

        populateAkEnemies();
        engine->rootContext()->setContextProperty("akEnemy", QVariant::fromValue(AkEnemis));
        engine->rootContext()->setContextProperty("bombEnemy", QVariant::fromValue(BombEnemis));
    }
    else{
        live =20;
        infoString= QStringLiteral("Game over");
        emit setlabeltext(infoString);
    }
    }


void MainGame::shotedDown(){
    score=score-10;
    emit playGunSound();
    live--;
}

void MainGame::detonatedDown(){
    score=score-10;
    emit playDetonatsSound();
    live--;
}

void MainGame::populateAkEnemies(){
char AmoutOfEnemies = AkEnemis.size()+BombEnemis.size();
char Random = (int) qrand() % (int) 2; //Zufallszahl zwischen 0 und 1.
if((AmoutOfEnemies<9)&&(Random==1)){
        AkTerrorist * akEnemy = new AkTerrorist(this);

        connect(bewegungsTimer,SIGNAL(timeout()),akEnemy,SLOT(timerSlot()));
        connect(akEnemy,SIGNAL(fireAShot()),this,SLOT(shotedDown()));
        connect(this,SIGNAL(treffer(double,double)),akEnemy,SLOT(shotedCheck(double, double)));
        connect(akEnemy,SIGNAL(deathMan(QObject*)),this,SLOT(removeAkEnemy(QObject*)));

        AkEnemis.append(akEnemy);
}
if((AmoutOfEnemies<9)&&(Random==0)){
        BombTerrorist * bombEnemy = new BombTerrorist(this);

        connect(bewegungsTimer,SIGNAL(timeout()),bombEnemy,SLOT(timerSlot()));
        connect(bombEnemy,SIGNAL(detonates()),this,SLOT(detonatedDown()));
        connect(this,SIGNAL(treffer(double,double)),bombEnemy,SLOT(shotedCheck(double, double)));
        connect(bombEnemy,SIGNAL(deathMan(QObject*)),this,SLOT(removeBombEnemy(QObject*)));

        BombEnemis.append(bombEnemy);
}

}

void MainGame::removeAkEnemy(QObject* akEnemy){
    qDebug() << " remove enemy now: " << akEnemy;
    AkEnemis.removeOne(akEnemy);
    engine->rootContext()->setContextProperty("akEnemy", QVariant::fromValue(AkEnemis));
    akEnemy->deleteLater();

}

void MainGame::removeBombEnemy(QObject* bombEnemy){
    qDebug() << " remove enemy now: " << bombEnemy;
    BombEnemis.removeOne(bombEnemy);
    engine->rootContext()->setContextProperty("bombEnemy", QVariant::fromValue(BombEnemis));
    bombEnemy->deleteLater();

}
