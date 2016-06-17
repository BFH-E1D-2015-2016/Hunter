#include "maingame.h"

MainGame::MainGame(QObject *parent) : QObject(parent)
{
    /* Dies hier ist der Konstruktor der Klasse Main Game.
     * Hier werden die nötigen Timer erzeugt für die Bewegung und Erzeugung der Terroristen sowie die QML Engine gestartet.
     * Desweitern werden alle Variablen auf ihren Defaultwert gesetzt.
     * Der bewegungsTimer wird dabei mit der Funktion zum updaten der Informationszeile im QML verbunden ("infoUpdate")
     * und dient den Objekten der beiden Terroristen Klassen als Zeitreferenz.
     * Der roundTimer wird für das erzeugen neuer Gegner  benötigt*/
    roundCounter = 0;
    score = 0;
    live = 10;

    //Level Steuerung
    level = 1;          // Aktuell nicht implementiert
    levelTimer = 1000;  // In 10ms

    roundTimer = new QTimer(this);   // Create a new timer and make it a child of MainGame
    roundTimer->setInterval(1000);   // set interval in ms

    bewegungsTimer = new QTimer(this);   // Create a new timer and make it a child of MainGame
    bewegungsTimer->setInterval(10);   // set interval in ms

    //Slots für Nach jeder Runde Gegner neu setzen sowie Bewegung und Infos Update
    connect(roundTimer,SIGNAL(timeout()),this,SLOT(roundElapsed()));
    connect(bewegungsTimer,SIGNAL(timeout()),this,SLOT(infoUpdate()));

    //create a new QmlApplication engine and expose context properties
    engine = new QQmlApplicationEngine(this);

    //set the enemies and gifts lists as context properties, they are used as models
    engine->rootContext()->setContextProperty("mainGame",this);
    engine->load(QUrl(QStringLiteral("main.qml")));
}

void MainGame::startGame(){
    /*Wird aufgerufen, sobald auf dem StartBildschirm auff Play gedrückt wurde.
     *  Diese Funktion startet dann die für das Spiel nötigen Timer und setzt
     *  die Variablen auf ihren Anfangszusatnd.*/

    live = Anfangsleben;
    score = 0;
    roundCounter = 0;
    qDebug() << " Game started. ";
    roundTimer->start();
    bewegungsTimer->start();
}

void MainGame::hit(double x,double y){
    /*Diese funktion empfängt vom QML das Signal
     * mit den übermittelten Koordinaten des getroffenen Terroristen.
     * Diese werden dann allen Instanzen der beiden Terroritsten weitergegeben
     * Zusätzlich werden die Punkte gegeben*/

    qDebug() << "hit"<< x << y;
    score=score+10;

    trefferX = x;
    trefferY = y;

    emit treffer(trefferX,trefferY);

}

void MainGame::roundElapsed(){
    /*  Diese Funktionn ist ein Slot, der auf den Überlauf
     *  des Timers roundTimer ausgeführt wird(jede Sekunde). Dieser widerum führt
     *  die Funktion populateEnemy aus und zählt die Sekunden hoch*/

    if (live>0){
        roundCounter++;
        qDebug() << " 1 sek elapsed " << roundCounter;
        populateAkEnemies();
        engine->rootContext()->setContextProperty("akEnemy", QVariant::fromValue(AkEnemis));        //Arrray mit Instanzen von AkEnemy für QML  updaten
        engine->rootContext()->setContextProperty("bombEnemy", QVariant::fromValue(BombEnemis));    //Arrray mit Instenzen von bombEnemy für QML  updaten
    }
}

void MainGame::terroristAtBottom(){
    /* Diese Funktion übermitelt das Signal für das Abspielen der BottomReached Sound Effekt.
     * Dies geschieht über maingGame, da eine direkte Übertragung von der Klasse BombeEnemy nach
     * QML, zu Kollisonen führt, da sich das Objekt BombEnemy einen kurzen Moment später zestört.*/

    if(live>0){
       emit playBottomReachedSound();
    }

}

void MainGame::infoUpdate(){
    // Diese Funktion führt den Update der  Informationszeile oben links im QML durch wenn das Spiel läuft
    // oder gibt den erreichten Score  aus soblad das Spiel Beendet ist (GameOver).

    if (live>0){
        infoString= QStringLiteral("Zeit:%1 ").arg(roundCounter);
        infoString += QStringLiteral("Leben:%1 ").arg(live);
        infoString += QStringLiteral("Score%1 ").arg(score);
        emit setlabeltext(infoString);
    }
    else{
        infoString = QStringLiteral("Your Score: %1 ").arg(score);
        emit setlabeltext(infoString);
    }

}

void MainGame::shotedDown(){
    /*Bei dieser Funktion handelt es sich um einen SLOT, den alle AkTerrorist-Objekten aufrufen können,
     *  wenn sie ein Schuss auf den Spieler abgefeuer. Dabei wird dem Spieler ein Leben abgezogen
     *  und Punkte dem Score abgezogen.*/

    if(live>1){
        score=score-10;
        emit playGunSound();
        live--;
    }
    else{
        score=score-10;
        emit playGunSound();
        live--;
        emit gameOver();
    }
}


void MainGame::detonatedDown(){
    /*Bei dieser Funktion handelt es sich um einen SLOT, den alle BombTerrorist-Objekten aufrufen können,
     *  wenn sie explodiert sind. Dabei wird dem Spieler ein Leben abgezogen
     *  und Punkte dem Score abgezogen.*/

    if(live>0){
        score=score-10;
        emit playDetonatsSound();
        live--;
    }
    else{
        score=score-10;
        emit playDetonatsSound();
        live--;
        emit gameOver();
    }

}

void MainGame::populateAkEnemies(){
    /*Diese Funktion dient dazu einen neuen Terroristen
     * zu erzeugen. Dazu Instanziiert sie nach
     *  dem Zufallsprinzip ein Objekt aus der AkEnemy oder BombEnemy Klasse,
     *  solange von den beiden nicht mehr als 10 Instanzen insgesamt aktiv sind.
     *  Damit man den Überblick behält, welche Objekte der Terroristen aktiv sind,
     *  werden diese je nach ihrer Klasse in eine Liste eingetragen. Diese wird dann
     *  auch gebraucht, um die Gegner auf der QML Oberfläche darzustellen.*/

char AmoutOfEnemies = AkEnemis.size()+BombEnemis.size();    // Variable zählt  zusammen wieviele Terroisten gerade aktiv sind.
char Random = (int) qrand() % (int) 2; //Zufallszahl zwischen 0 und 1. 0-> AkTerrorist 1->BombTerrorist
//  Erzeuge AkTerrorist und verbinde die Signale mit den nötigen Slots
if((AmoutOfEnemies<9)&&(Random==1)){
        AkTerrorist * akEnemy = new AkTerrorist(this);

        connect(bewegungsTimer,SIGNAL(timeout()),akEnemy,SLOT(timerSlot()));
        connect(akEnemy,SIGNAL(fireAShot()),this,SLOT(shotedDown()));
        connect(this,SIGNAL(treffer(double,double)),akEnemy,SLOT(shotedCheck(double, double)));
        connect(akEnemy,SIGNAL(deathMan(QObject*)),this,SLOT(removeAkEnemy(QObject*)));
        connect(this,SIGNAL(gameOver()),akEnemy,SLOT(destroyTerrorist()));

        AkEnemis.append(akEnemy);
}
//  Erzeuge AkTerrorist und verbinde die Signale mit den nötigen Slots
if((AmoutOfEnemies<9)&&(Random==0)){
        BombTerrorist * bombEnemy = new BombTerrorist(this);

        connect(bewegungsTimer,SIGNAL(timeout()),bombEnemy,SLOT(timerSlot()));
        connect(bombEnemy,SIGNAL(detonates()),this,SLOT(detonatedDown()));
        connect(this,SIGNAL(treffer(double,double)),bombEnemy,SLOT(shotedCheck(double, double)));
        connect(bombEnemy,SIGNAL(deathMan(QObject*)),this,SLOT(removeBombEnemy(QObject*)));
        connect(bombEnemy,SIGNAL(bottomReached()),this,SLOT(terroristAtBottom()));
        connect(this,SIGNAL(gameOver()),bombEnemy,SLOT(destroyTerrorist()));

        BombEnemis.append(bombEnemy);
}

}

void MainGame::removeAkEnemy(QObject* akEnemy){
    /*Diese Funktion dient dazu einen Terroristen der AkTerrorist Klasse zu vernichten
     * und sein Eintrag aus der Liste zu löschen, nachdem dieser gestorben ist . Damit es nicht
     * zu Fehleren beim zestören kommt während gerade eine Funktion auf der betreffenden Instanz audgeführt wird,
     * wird die Funktion "deleteLater();" benutzt. */

    qDebug() << " remove enemy now: " << akEnemy;
    AkEnemis.removeOne(akEnemy);
    engine->rootContext()->setContextProperty("akEnemy", QVariant::fromValue(AkEnemis));
    akEnemy->deleteLater();

}

void MainGame::removeBombEnemy(QObject* bombEnemy){
    /*Diese Funktion dient dazu einen Terroristen der BombTerrorist Klasse zu vernichten
     * und sein Eintrag aus der Liste zu löschen, nachdem dieser gestorben ist . Damit es nicht
     * zu Fehleren beim zestören kommt während gerade eine Funktion auf der betreffenden Instanz audgeführt wird,
     * wird die Funktion "deleteLater();" benutzt. */

    qDebug() << " remove enemy now: " << bombEnemy;
    BombEnemis.removeOne(bombEnemy);
    engine->rootContext()->setContextProperty("bombEnemy", QVariant::fromValue(BombEnemis));
    bombEnemy->deleteLater();

}
