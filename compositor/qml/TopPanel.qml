import QtQuick 2.0

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
}
