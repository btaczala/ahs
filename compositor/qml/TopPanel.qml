import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls 2.2

Rectangle {
    id: rectangle
    width: 800
    height: 100

    color: "black"

    signal homeRequested()

    Image {
        id: image
        source: "images/home.png"
        fillMode: Image.PreserveAspectFit
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        height: parent.height - 10

        MouseArea {
            id: mouseArea
            anchors.fill: parent

            onClicked: {
                homeRequested()
            }
        }
    }

    Button {
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        text: "Close"

        onClicked: {
            controller.sendDummyNotification();
        }
    }
}
