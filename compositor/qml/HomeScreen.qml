import QtQuick 2.0
import ahs.Compositor.ApplicationManager 1.0

Item {
    width: 800
    height: 600

    ListModel {
        id: appModel
        ListElement { 
            name: "HelloGL"; 
            icon: "pics/AudioPlayer_48.png" 
            exec: "animation"
            dir: "/home/bata/qt5-examples/quick/animation"
        }
    }

    ApplicationManager {
        id: appManager
    }

    GridView {
        anchors.fill: parent
        cellWidth: 300; cellHeight: 300
        focus: true
        model: appModel

        highlight: Rectangle { width: 80; height: 80; color: "lightsteelblue" }

        delegate: Item {
            width: 300; height: 300

            Image {
                id: myIcon
                y: 20; anchors.horizontalCenter: parent.horizontalCenter
                source: icon
            }
            Text {
                anchors { top: myIcon.bottom; horizontalCenter: parent.horizontalCenter }
                text: name
            }
            MouseArea {
                anchors.fill: parent
                onClicked: { 
                    parent.GridView.view.currentIndex = index;

                    appManager.launchApplication(exec, dir);
                }
            }
        }
    }
}

