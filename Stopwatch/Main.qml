import QtQuick

Window {
    id: window
    width: 400
    height: 400
    visible: true
    title: qsTr("StopWatch")
    Rectangle {
        id: frame
        color: "grey"
        width: 400
        height: 400

        Rectangle {
            color: "lightblue"
            width: 300
            height: 150
            x: 50; y: 50

            Rectangle {
                width: 50
                height: 50
                x: 50
                y: 50
                color: "white"
            }
        }
        Rectangle {
            color: "green"
            width: 300
            height: 150
            x: 50; y: 200

            Rectangle {
                width: 150
                height: 50
                x: 100; y: 50
                color: "blue"
            }
        }
    }
}
