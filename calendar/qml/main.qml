import QtQuick 2.0
import QtWebKit 3.0
import QtQuick.Window 2.2

Window {
    width: 300
    height: 300
    visible: true

    WebView {
        width: parent.width
        height: parent.height
        url: "https://calendar.google.com"
    }
}
