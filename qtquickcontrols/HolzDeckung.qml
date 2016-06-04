import QtQuick 2.0

Item {

    id: deckungHolz

    Rectangle{
        id: rect

        width: 150
        height: 150
        color:"transparent"

        Image {
                id: deck
                source:  "qrc:/Pictures/Deckung3.png"
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

}

