import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    id: deckungStein

    Rectangle{
        id: rect

        width: 150
        height: 150
        color:"transparent"

        Image {
                id: deck
                source:  "Pictures/Deckung2.png"
                anchors.fill: parent;
            }

        MouseArea{
            id: mA
            anchors.fill:parent
            onClicked:{
                console.log("Deckung was shoted!");
            }


        }
    }
    GroupBox{
        Rectangle{

        }
    }
}

