import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0

Item {
    id: rootItem
    width: 800
    height: 200

    property var blurItem
    property bool blur

    Rectangle {
        id: background
        color: "black"
        anchors.fill: fastBlur
        radius: 20
        opacity: blur === true ? 1 : 0.7
    }

    FastBlur {
        id: fastBlur
        anchors.fill: parent
        radius: 40
        opacity: 0.55
        visible: blur
        source: ShaderEffectSource {
            sourceItem: blurItem
            sourceRect: Qt.rect(0, 0, fastBlur.width, fastBlur.height)
        }
    }
}
