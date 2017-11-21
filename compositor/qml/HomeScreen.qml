import QtQuick 2.0
import "background"

Item {
    width: 800
    height: 600

    BackgroundSwirls {
        anchors.fill: parent
    }

    GridView {
        anchors.fill: parent
        cellWidth: 300; cellHeight: 300
        focus: true
        model: registeredApplications

        highlight: Rectangle { width: 80; height: 80; color: "lightsteelblue" }

        delegate: Item {
            width: 300; height: 300

            Image {
                id: myIcon
                anchors.horizontalCenter: parent.horizontalCenter;
                anchors.verticalCenter: parent.verticalCenter;
                source: icon
                width: 250
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

