import QtQuick 2.15

Item {
    id: container
    height: (parent.height > parent.width) ? parent.width : parent.height
    width: ((height * 1.8) / 3)
    x: (parent.width / 2) - (width / 2)
    y: (parent.height / 2) - (height / 2)


    // range must be divisable by 2
    // range must be divisable by the translation
    // (range / 2) must be divisable by 3
    // (range / translation) * (fastInterval * 2) must not exceed (FrameInterval * 9) / 2

    property int frameInterval: 220 // how fast you want the bird to change frames (220 is recomended)
    property int range: 72 // how many pixels you want the bird to bob up and down
    property int fastInterval: 11 // how fast each translation happens
    property int translation: 2 // how far you want the bird to move up or down every interval

    // for bird to start at bottom: upDownMovement: range / 2; goingUp: true frameIndex: 6
    // for bird start at top: upDownMovement: -(range / 2); goingUp: false; frameIndex: 0

    property int upDownMovement: -(range / 2)
    property bool goingUp: false
    property int frameIndex: 0


    Image {
        id: image

        x: (parent.width / 2) - (width / 2)
        y: (parent.height / 2) - (height / 2) + upDownMovement

        height: parent.height
        width: parent.width


        source: "qrc:/images/images/AnimationFrame" + (parent.frameIndex + 1) + ".png"

        Timer {
            id: frameTimer
            interval: container.frameInterval; repeat: true; running: true;

            onTriggered: {
                container.frameIndex = (container.frameIndex + 1) % 9
            }
        }
        Timer {
            id: fastTimer
            interval: container.fastInterval; repeat: true; running: false;
            onTriggered: {
                //console.log("fast: " + container.upDownMovement)
                if (container.goingUp == true) {
                   // if  fast hits medium boundary
                   if (container.upDownMovement == -(container.range / 2) / 3) {
                       container.upDownMovement -= container.translation
                       fastTimer.stop()
                       mediumTimer.start()
                   }

                   // if indice is still within medium
                   else {
                       container.upDownMovement -= container.translation
                   }
                }

                else {
                    // if  fast hits medium boundary
                    if (container.upDownMovement == (container.range / 2) / 3) {
                        container.upDownMovement += container.translation
                        fastTimer.stop()
                        mediumTimer.start()
                    }

                    // if indice is still within fast
                    else {
                        container.upDownMovement += container.translation
                    }
                }
            }
        }
        Timer {
            id: mediumTimer
            interval: container.fastInterval * 2; repeat: true; running: false;
            onTriggered: {
                //console.log("medium: " + container.upDownMovement)

                if (container.goingUp == true) {
                   // if  medium hits slow boundary
                   if (container.upDownMovement == -((container.range / 2) / 3) * 2) {
                       container.upDownMovement -= container.translation
                       mediumTimer.stop()
                       slowTimer.start()
                   }

                   // if medium hits fast boundary
                   else if (container.upDownMovement == (container.range / 2) / 3) {
                       container.upDownMovement -= container.translation
                       mediumTimer.stop()
                       fastTimer.start()
                   }

                   // if indice is still within medium
                   else {
                       container.upDownMovement -= container.translation
                   }
                }

                else {
                    // if  medium hits slow boundary
                    if (container.upDownMovement == ((container.range / 2) / 3) * 2) {
                        container.upDownMovement += container.translation
                        mediumTimer.stop()
                        slowTimer.start()
                    }

                    // if medium hits fast boundary
                    else if (container.upDownMovement == -(container.range / 2) / 3) {
                        container.upDownMovement += container.translation
                        mediumTimer.stop()
                        fastTimer.start()
                    }

                    // if indice is still within medium
                    else {
                        container.upDownMovement += container.translation
                    }
                }
            }
        }
        Timer {
            id: slowTimer
            interval: container.fastInterval * 3; repeat: true; running: container.goingUp;
            onTriggered: {
                //console.log("slow: " + container.upDownMovement)

                if (container.goingUp == true) {
                   // if slow timer hits sync boundary
                   if (container.upDownMovement == -(container.range / 2)) {
                       slowTimer.stop()
                       syncTimer.start()
                   }

                   // if slow timer hits medium boundary
                   else if (container.upDownMovement == ((container.range / 2) / 3) * 2) {
                       container.upDownMovement -= container.translation
                       slowTimer.stop()
                       mediumTimer.start()
                   }

                   // if indice is still within slow
                   else {
                       container.upDownMovement -= container.translation
                   }
                }
                else {
                    // if slow timer hits pause boundary
                    if (container.upDownMovement == container.range / 2) {
                        slowTimer.stop()
                        pauseTimer.start()
                    }

                    // if movement hits slow boundary
                    else if (container.upDownMovement == -((container.range / 2) / 3) * 2) {
                        container.upDownMovement += container.translation
                        slowTimer.stop()
                        mediumTimer.start()
                    }

                    // if indice is still within slow boundary
                    else {
                        container.upDownMovement += container.translation
                    }
                }
            }
        }
        Timer {
            id: pauseTimer
            interval: (container.frameInterval * 9) / 2 - (container.range / container.translation) * (container.fastInterval * 2); repeat: true; running: false;
            onTriggered: {
                //console.log("pause: " + container.upDownMovement)

                container.goingUp = true
                container.upDownMovement -= container.translation
                pauseTimer.stop()
                slowTimer.start()
            }
        }
        Timer {
            id: syncTimer
            interval: 10; repeat: true; running: !container.goingUp;
            onTriggered: {
                //console.log("sync: " + container.upDownMovement)
                if (container.frameIndex == 1) {
                   container.goingUp = false
                   container.upDownMovement += container.translation
                   syncTimer.stop()
                   slowTimer.start()
                }
            }
        }
    }
}


