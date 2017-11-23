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
        id: rootWindow
        width: 1024
        height: 768
        visible: true

        Item {
            id: container
            state: "notification_hidden"
            anchors.fill: parent
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
                    } // HomeScreen
                } // StackView
            } // ColumnLayout

            InputPanel {
                id: inputPanel
                y: Qt.inputMethod.visible ? parent.height - inputPanel.height : parent.height
                anchors.left: parent.left
                anchors.right: parent.right
            }

            Notifications {
                id: notificationItem
                width: parent.width - 200
                height: 200
                anchors.horizontalCenter: parent.horizontalCenter
                blurItem: container
                blur: false
            }

            Connections {
                target: controller
                onNotification: {
                    console.debug("Notification");
                    container.state = "notification_shown"
                }
                onCloseNotification: {
                    container.state = "notification_hidden"
                }
            }

            states: [ 
                State {
                    name: "notification_shown"
                    AnchorChanges { target: notificationItem; anchors.top: container.top; anchors.bottom: undefined }
                }, 
                State {
                    name: "notification_hidden"
                    AnchorChanges { target: notificationItem; anchors.bottom: container.top }
                }
            ]
            transitions: Transition {
            // smoothly reanchor myRect and move into new position
                AnchorAnimation { duration: 300 }
            }
        } // Item { container }
    } // Window
}
