import QtQuick 2.3
import QtQuick.Controls 1.2


Rectangle {
    visible: true
    width: 640
    height: 480
    //title: qsTr("Rönu.exe")

    // The background image
    Image {
        id: hingergrund
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        source:  "Pictures/Menuebild.jpg"
        anchors.fill: parent;

        Rectangle {
            id: startButon
            x: 245
            y: 60
            color: "transparent"
            width: 174
            height: 63

            MouseArea {
                anchors.fill: parent
                onClicked: { console.log("Game will be start!");}
            }
        }

        Rectangle {
            id: quitButon
            x: 245
            y: 125
            color: "transparent"
            width: 174
            height: 30
            MouseArea {
                        anchors.fill: parent
                        onClicked: { console.log("Show Score Screen!");Qt.quit(); }
            }

        }
        Rectangle {
            id: scoreButon
            x: 245
            y: 165
            color: "transparent"
            width: 174
            height: 30
                MouseArea {
                        anchors.fill: parent
                        onClicked: { console.log("Show Score Screen!"); }
            }

        }
   }





   /* menuBar: MenuBar {
        Menu {
            title: qsTr("Dini Familie")
            MenuItem {
                text: qsTr("&Dinu")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Dini Vater")
                onTriggered: Qt.quit();
            }
            MenuItem {
                text: qsTr("Dini Mutter")
                onTriggered: Qt.quit();
            }
        }
    }

    Label {
        id: tkjllwrekuth
        text: qsTr("Alla")
        verticalAlignment: Text.AlignBottom
        anchors.centerIn: parent
    }*/
}
