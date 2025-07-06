import QtQuick

Window {
    id: window
    width: 400
    height: 400
    visible: true
    title: qsTr("StopWatch2")
    property int minSide: Math.min(window.width, window.height)
    property int rotationAng1: 0
    property int rotationAng2: 0

    Item {
        id: container
        width: minSide
        height: minSide
        anchors.centerIn: parent
        scale: 1.0

        Image {
            id: background
            source: "qrc:/imgs/images/background.png"
            x: container.width / 2 - this.width / 2
            y: 0
            width: container.width * 0.75
            height: container.height * 0.75
            scale: 1.0

            Rectangle {
                id: centerBtn
                color: "black"
                width: background.width * 0.185
                height: background.height * 0.1
                x: (background.width) / 2 - (this.width / 2)
                y: background.height * 0.02

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHand
                }

            }
            Rectangle {
                id: leftBtn
                color: "black"
                width: background.width * 0.065
                height: background.height * 0.06
                x: (background.width) * .28 - (this.width / 2)
                y: background.height * 0.158

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHand
                }

                transform: Rotation {
                    origin.x: leftBtn.width / 2
                    origin.y: leftBtn.height / 2
                    angle: 329
                }

            }
            Rectangle {
                id: rightBtn
                color: "black"
                width: background.width * 0.067
                height: background.height * 0.06
                x: (background.width) * .725 - (this.width / 2)
                y: background.height * 0.16

                signal buttonPressed()

                MouseArea {
                    anchors.fill: parent
                    cursorShape: Qt.PointingHand
                }

                transform: Rotation {
                    origin.x: rightBtn.width / 2
                    origin.y: rightBtn.height / 2
                    angle: 31
                }
            }

            Image {
                source: "qrc:/imgs/images/bigHand.png"
                id: bigHand
                width: background.width * 0.3
                height: background.height * 0.3
                x: background.width / 2 - (this.width * 0.69)
                y: background.height / 2 - (this.height * 0.6)

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
                x: background.width / 2 - (this.width * 0.72)
                y: background.height / 2 - (this.height * 0.6)



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

        Rectangle {
            color: "blue"
            width: container.width * 0.95
            height: container.height * 0.225
            x: container.width / 2 - this.width / 2
            y: container.height * 0.75
        }
    }
}
