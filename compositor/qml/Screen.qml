import QtQuick 2.0
import QtWayland.Compositor 1.0
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.VirtualKeyboard 2.1

WaylandOutput {
    id: rootOutput
    sizeFollowsWindow: true

    signal newWindowRectCreated(var rect);
    signal toggle();

    property alias stack: stackView

    window: Window {
        width: 1024
        height: 768
        visible: true

        ColumnLayout {
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.bottom: inputPanel.top
            spacing: 2

            TopPanel {
                Layout.preferredWidth: parent.width
                Layout.preferredHeight: 50

                onHomeRequested: {
                    stackView.pop();
                }
            }

            StackView {
                id: stackView
                Layout.preferredWidth: parent.width
                Layout.fillHeight: true
                Layout.preferredHeight: 50
                initialItem: HomeScreen {
                    width: 300
                    height: 400
                }
            }
        }

        InputPanel {
            id: inputPanel
            y: Qt.inputMethod.visible ? parent.height - inputPanel.height : parent.height
            anchors.left: parent.left
            anchors.right: parent.right
        }
    }
}
