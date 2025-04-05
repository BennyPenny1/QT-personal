import QtQuick

Window {
    id: window
    width: 400
    height: 400
    visible: true
    title: qsTr("StopWatch2")
    property int rotationAng1: 0
    property int rotationAng2: 0
    property int minSide: Math.min(window.width, window.height)
    
    Image {
        id: background
        source: "qrc:/imgs/images/background.png"
        anchors.centerIn: parent
        width: minSide
        height: minSide
        scale: 1.0

        Rectangle {
            id: centerBtn
            width: background.width * 0.185
            height: background.height * 0.1
            x: (background.width) / 2 - (width / 2)
            y: background.height * 0.02

        }
        Rectangle {
            id: leftBtn
            width: background.width * 0.185
            height: background.height * 0.1
            x: (background.width) * .25 - (width / 2)
            y: background.height * 0.2

            transform: Rotation {
                origin.x: legtBtn.width / 2
                origin.y: leftBtn.height / 2
                angle: 45
            }

        }
        Rectangle {
            id: rightBtn
            width: background.width * 0.185
            height: background.height * 0.1
            x: (background.width) * .75 - (width / 2)
            y: background.height * 0.2

            transform: Rotation {
                origin.x: rightBtn.width / 2
                origin.y: rightBtn.height / 2
                angle: 315
            }

        }

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
                angle: 44 + rotationAng1
            }
            Timer {
                interval: 1000
                running: true
                repeat: true
                onTriggered: {
                    rotationAng1 = (rotationAng1 + 6) % 360
                }
            }
        }

        Image {
            source: "qrc:/imgs/images/smallHand.png"
            id: smallHand

            width: background.width * 0.3
            height: background.height * 0.3
            x: background.width / 2 - (width * 0.72)
            y: background.height / 2 - (height * 0.6)



            transform: Rotation {
                origin.x: smallHand.width * 0.7164
                origin.y: smallHand.height * 0.7296
                angle: 44 + rotationAng2
            }
        }
        Timer {
            interval: 60000
            running: true
            repeat: true
            onTriggered: {
                rotationAng2 = (rotationAng2 + 6) % 360
            }
        }
    }
}
