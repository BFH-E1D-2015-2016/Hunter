#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>
#include "maingame.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//Give working directory
    /*
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("applicationDir", QDir::currentPath());
    engine.load(QUrl(QStringLiteral("Startbildschirm.qml")));
*/
/*
    sendApplicationDir applicationDir;
    applicationDir.Path="file:///"+QDir::currentPath();
    emit sendApplicationDir(applicationDir.Path);
  */
    MainGame* mainGame = new MainGame(&app);    //Create a new MainGame and make it a child of app.

   return app.exec();
}
