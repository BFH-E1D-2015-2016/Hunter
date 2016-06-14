import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2


ApplicationWindow {

    title: qsTr("Qt / QML introduction")
    width: 640
    height: 480
    //width: Screen.width;
    //height: Screen.height;
    visible: true


    Startbildschirm{
        id: startScreen
        visible: true;
    }

    Spielbildschirm{
        id: gameScreen
        visible: false
    }
    SpielBeendet{
        id: gameOverScreen
        visible: false

    }
 }
