import QtQuick 2.0

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
                source:  "qrc:/Pictures/Ak-Terrorist2.png"
            }

            MouseArea{
                id: mA
                anchors.fill:parent
                onEntered:{
                    mainGame.hit(xOrdinate,yOrdinate)
                    //console.log("AkTerrorist was shoted!" + xOrdinate + yOrdinate);
                }


            }
        }
}

