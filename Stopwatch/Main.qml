import QtQuick

Window {
    id: window
    width: 400
    height: 400
    visible: true
    title: qsTr("StopWatch")

    Image {
        id: background
        source: background.png
        property int minSide: Math.min(window.width, window.height)
        anchors.CenterIn: parent
        scale: 1.0

        Image {
            source: bigHand.png
            id: bigHand
            anchors.centerIn: parent
            y: (background.height / 2) - 807
        }

        Image {
            source: smallHand.png
            id: smallHand
            anchors.centerIn: parent
            y: (background.height / 2) - 775
        }
    }
}
