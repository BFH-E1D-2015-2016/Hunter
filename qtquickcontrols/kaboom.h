#ifndef KABOOM_H
#define KABOOM_H

#include <QObject>
#include <QTimer>


class KaBoom : public QObject
{
    Q_OBJECT

public:
    KaBoom(QObject *parent = 0);
    ~KaBoom();  //Dekunstroktor

signals:
    void explosed();      // Explodiert
    void deathMan();      // Gestorben

public slots:
    void timerSlot();   // Spielzeit Runde
    void hitByShot();   // Wurde getroffen

private:
    double liveLevel;   // Leben
    double ExploTimer;  // Zeit bis er in die  Luft geht
};

#endif // KABOOM_H
