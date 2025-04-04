import QtQuick

Window {
    id: window
    width: 400
    height: 400
    visible: true
    title: qsTr("StopWatch2")
    property int minSide: Math.min(window.width, window.height)

    Image {
        id: background
        source: "qrc:/imgs/images/background.png"
        anchors.centerIn: parent
        width: minSide
        height: minSide
        scale: 1.0

        Image {
            source: "qrc:/imgs/images/bigHand.png"
            id: bigHand
            width: background.width * 0.3
            height: background.height * 0.3
            x: background.width / 2 - (width * 0.69)
            y: background.height / 2 - (height * 0.6)

            transform: Rotation {
                origin.x: bigHand.width * 0.6906
                origin.y: bigHand.height * 0.7191
                RotationAnimation on angle {
                    from: 43
                    to: 403
                    duration: 60000
                    loops: Animation.Infinite
                }
            }
        }

        Image {
            source: "qrc:/imgs/images/smallHand.png"
            id: smallHand

            width: background.width * 0.3
            height: background.height * 0.3
            x: background.width / 2 - (width * 0.72)
            y: background.y + background.height / 2 - (height * 0.6)

            transform: Rotation {
                origin.x: bigHand.width * 0.7164
                origin.y: bigHand.height * 0.7296
                angle: 44

            }
            Timer {
                    interval: 1000
                    running: true
                    repeat: true
                    onTriggered: smallHand.rotation += 12
                }
        }
    }
}
