import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtMultimedia 5.5
import "BasicLogic.js" as BasicLogic

Rectangle {
    //id: gameScreen
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



    Rectangle{
           id: statusBar
           radius: 5
           color: "transparent"
           width: 100
           height: 30*1;

           Text {
               id: name
               text: qsTr("Lives: ");
               font.pixelSize:  20*1
               color: "green"
               Connections {                        // Mittels Connections verbinden wir das Signal mit dem Qml "Slot"
                                  target: mainGame   // myclassdata wurde als ContextProperty in main.cpp definiert
                                  onSetlabeltext: {     // ganz wichtig !!! hier muss ein Großbuchstabe stehen sonst funktionierts nicht
                                    name.text=text // das Label wo Hallo World stand enthält nun den Text von C++
                                  }}

           }

   }

    Repeater { model: akEnemy
        Terrorist1{
               x:xOrdinateAk;
               y:yOrdinateAk;
               visible:aCtiveAk;}
        }

    Repeater { model: bombEnemy
        Terrorist2{
               x:xOrdinateBomb;
               y:yOrdinateBomb;
               visible:aCtiveBomb;}
        }



     SteinDeckung{x:450;y:100;}
     MauerDeckung{x:200;y:200;}
     HolzDeckung {x:000;y:100;}

     SoundEffect{
         id: playGunshot0
         source:"Audio/GunshotPlayer.wav"
     }
     SoundEffect{
         id: playGunshot1
         source:"Audio/GunshotPlayer.wav"
     }
     SoundEffect{
         id: playGunshotAkTerrorist
         source:"Audio/GunshotPlayer.wav"
     }
     SoundEffect{
         id: playAllahAkbar
         source:"Audio/AllahAkbar.wav"
     }
     Connections {                        // Mittels Connections verbinden wir das Signal mit dem Qml "Slot"
                        target: mainGame   // myclassdata wurde als ContextProperty in main.cpp definiert
                        onPlayDetonatsSound: {     // ganz wichtig !!! hier muss ein Großbuchstabe stehen sonst funktionierts nicht
                          playAllahAkbar.play(); // das Label wo Hallo World stand enthält nun den Text von C++
                        }}
     Connections {                        // Mittels Connections verbinden wir das Signal mit dem Qml "Slot"
                        target: mainGame   // myclassdata wurde als ContextProperty in main.cpp definiert
                        onPlayGunSound: {     // ganz wichtig !!! hier muss ein Großbuchstabe stehen sonst funktionierts nicht
                          playGunshotAkTerrorist.play(); // das Label wo Hallo World stand enthält nun den Text von C++
                        }}

     /*Rectangle {
         width: animation.width; height: animation.height + 8

         AnimatedImage { id: animation; source: "Pictures/explosion.gif" }

         Rectangle {
             property int frames: animation.frameCount

             width: 4; height: 8
             x: (animation.width - width) * animation.currentFrame / frames
             y: animation.height
             color: "red"
         }
     }*/



     property int aNumber: 0

     MouseArea{
         propagateComposedEvents: true
         anchors.fill:parent
         onClicked:{
             if (aNumber === 0)
             {
                 playGunshot0.play()
                 aNumber = 1
             }
             else
             {
                 playGunshot1.play()
                 aNumber = 0
             }
             console.log("SHOT FIRED")
             mouse.accepted = false
         }
     }


}
