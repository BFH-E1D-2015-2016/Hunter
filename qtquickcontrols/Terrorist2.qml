import QtQuick 2.0
import QtMultimedia 5.5

Item {


        id: terroristBomb
        property int xPos: 0;
        property int yPos: 0;
        property int listAdress: 0;
        signal buttonClick()
        //signal hit(int x,int y);


        Rectangle{
            id: rect
            width:70
            height:85
            color: "transparent"
            x:terroristBomb.xPos
            y:terroristBomb.yPos

            Image{
                width:50
                height:85
                source:  "Pictures/Kaboom2.png"
            }
            /*SoundEffect{
                id: GunShotTerrorist
                source:"Audio/GunshotPlayer.wav"
                if(StateQml === true)
                {
                    GunShotTerrorist.play()
                }
            }*/
            MouseArea{
                id: mA
                anchors.fill:parent
                propagateComposedEvents: true
                onClicked:{

                    mainGame.hit(xOrdinateBomb,yOrdinateBomb)
                    //console.log("AkTerrorist was shoted!" + xOrdinate + yOrdinate);
                    mouse.accepted = false
                }
            }

        }
}
