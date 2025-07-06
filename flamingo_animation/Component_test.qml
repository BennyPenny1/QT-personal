import QtQuick          2.11
import QtQuick.Controls 2.4
import QtQuick.Dialogs  1.3
import QtQuick.Layouts  1.11
import QtQuick.Window   2.11


Window {
    id: window
    width: 1000
    height: 1000
    visible: true
    color: "green"
    MouseArea {
        anchors.fill: parent
        cursorShape: QT.ArrowCursor
        onClicked: console.log("nomnom")
    }
    Popup {
        id: activeVehicleParamsLoadingScreen
        visible: true
        width: parent.width
        height: parent.height
        modal: true
        focus: true
        dim: false

        background: Rectangle {
            color: "black"
            opacity: .85
        }

        Rectangle {
            color: "transparent"
            height: (parent.height > parent.width) ? (parent.width) * .25 : (parent.height) * .25
            width: height * 1.8/3
            x: (parent.width) / 2 - (width / 2)
            y: (parent.height / 2) - (height / 2)

            FlamingoAnimation {}
        }
    }


}
