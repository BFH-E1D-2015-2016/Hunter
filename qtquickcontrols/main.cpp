#include <QApplication>

#include "maingame.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainGame* mainGame = new MainGame(&app);    //Create a new MainGame and make it a child of app.

   return app.exec();
}
