import QtQuick 2.3
import QtQuick.Controls 1.2
import QtMultimedia 5.5
import "BasicLogic.js" as BasicLogic

Rectangle {
    //id: gameOverScreen
    width: 640
    height: 480


    // The background image
    Image {
        id: hingergrund2
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        source:  "Pictures/Hintergrund.jpg"
        anchors.fill: parent;
     }
    Text {
        id: loser
        x: 146
        y: 198
        text: qsTr("Game Over");
        font.pixelSize: 70
        color: "green";
    }
    Rectangle{
           id: statusBar
           x: 270
           y: 299
           radius: 5
           color: "transparent"
           width: 100
           height: 30*1;

           Text {
               id: name
               x: -28
               y: 3
               text: qsTr("Your Score: XXXX");
               font.pixelSize:  20*1
               color: "green"
               Connections {                        // Mittels Connections verbinden wir das Signal mit dem Qml "Slot"
                                  target: mainGame   // myclassdata wurde als ContextProperty in main.cpp definiert
                                  onSetlabeltext: {     // ganz wichtig !!! hier muss ein Großbuchstabe stehen sonst funktionierts nicht
                                    name.text=text // das Label wo Hallo World stand enthält nun den Text von C++
                                  }}

           }

   }
    MouseArea{
        anchors.fill:parent
        onClicked: {
            BasicLogic.showStartScreen();}
    }
 }


