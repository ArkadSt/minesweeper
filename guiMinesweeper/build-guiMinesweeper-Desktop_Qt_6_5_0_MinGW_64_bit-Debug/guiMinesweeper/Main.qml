import QtQuick
import QtQuick.Window
import GameModel 0.1

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Minesweeper")



     TableView {
         anchors.fill: parent
         columnSpacing: 1
         rowSpacing: 1
         clip: true

         model: GameModel {}

         delegate: Rectangle {
             implicitWidth: 30
             implicitHeight: 30
             border.color: "black"
             border.width: 1

             color: "#b5b7bf"
             MouseArea {
                 anchors.fill: parent
                 //onClicked: parent.
             }
             Text {
                 text: isClicked ? revealed : hidden
                 font.pointSize: 12
                 anchors.centerIn: parent
             }
         }
     }
}
