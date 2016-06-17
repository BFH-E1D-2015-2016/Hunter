import QtQuick 2.0
import QtMultimedia 5.5

Item {


        id: terroristAk
        property int xPos: 0;
        property int yPos: 0;
        property int listAdress: 0;

        //signal hit(int x,int y);

        Rectangle{
            id: rect
            width:70
            height:85
            color: "transparent"
            x:terroristAk.xPos
            y:terroristAk.yPos
            Image{
                width:50
                height:85
                source:  "Pictures/Ak-Terrorist2.png"
            }

            Rectangle{                  // Schuss links
                visible: StateQml;
                color: "yellow";
                width: 10;
                height: 20;
                x:terroristAk.xPos;
                y:terroristAk.yPos+65;
            }

            Rectangle{                  // Schuss rechts
                visible: StateQml;
                color: "yellow";
                width: 10;
                height: 20;
                x:terroristAk.xPos+40;
                y:terroristAk.yPos+65;
            }

            MouseArea{
                id: mA
                anchors.fill:parent
                propagateComposedEvents: true
                onClicked:{
                    mainGame.hit(xOrdinateAk,yOrdinateAk)
                    mouse.accepted = false
                }
            }
        }
}

