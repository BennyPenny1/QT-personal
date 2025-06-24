import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    id: window
    width: 500
    height: 750
    visible: true
    title: qsTr("Animated Flamingo")
    color: "black"


    Image {
        id: image

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


        x: (parent.width / 2) - (image.width / 2)
        y: 75 + upDownMovement


        source: "qrc:/images/images/frame" + (image.frameIndex + 1) + "transp.png"

        Timer {
            id: frameTimer
            interval: image.frameInterval; repeat: true; running: true;

            onTriggered: {
                image.frameIndex = (image.frameIndex + 1) % 9
            }
        }
        Timer {
            id: fastTimer
            interval: image.fastInterval; repeat: true; running: false;
            onTriggered: {
                console.log("fast: " + image.upDownMovement)
                if (image.goingUp == true) {
                   // if  fast hits medium boundary
                   if (image.upDownMovement == -(image.range / 2) / 3) {
                       image.upDownMovement -= image.translation
                       fastTimer.stop()
                       mediumTimer.start()
                   }

                   // if indice is still within medium
                   else {
                       image.upDownMovement -= image.translation
                   }
                }

                else {
                    // if  fast hits medium boundary
                    if (image.upDownMovement == (image.range / 2) / 3) {
                        image.upDownMovement += image.translation
                        fastTimer.stop()
                        mediumTimer.start()
                    }

                    // if indice is still within fast
                    else {
                        image.upDownMovement += image.translation
                    }
                }
            }
        }
        Timer {
            id: mediumTimer
            interval: image.fastInterval * 2; repeat: true; running: false;
            onTriggered: {
                console.log("medium: " + image.upDownMovement)

                if (image.goingUp == true) {
                   // if  medium hits slow boundary
                   if (image.upDownMovement == -((image.range / 2) / 3) * 2) {
                       image.upDownMovement -= image.translation
                       mediumTimer.stop()
                       slowTimer.start()
                   }

                   // if medium hits fast boundary
                   else if (image.upDownMovement == (image.range / 2) / 3) {
                       image.upDownMovement -= image.translation
                       mediumTimer.stop()
                       fastTimer.start()
                   }

                   // if indice is still within medium
                   else {
                       image.upDownMovement -= image.translation
                   }
                }

                else {
                    // if  medium hits slow boundary
                    if (image.upDownMovement == ((image.range / 2) / 3) * 2) {
                        image.upDownMovement += image.translation
                        mediumTimer.stop()
                        slowTimer.start()
                    }

                    // if medium hits fast boundary
                    else if (image.upDownMovement == -(image.range / 2) / 3) {
                        image.upDownMovement += image.translation
                        mediumTimer.stop()
                        fastTimer.start()
                    }

                    // if indice is still within medium
                    else {
                        image.upDownMovement += image.translation
                    }
                }
            }
        }
        Timer {
            id: slowTimer
            interval: image.fastInterval * 3; repeat: true; running: image.goingUp;
            onTriggered: {
                console.log("slow: " + image.upDownMovement)

                if (image.goingUp == true) {
                   // if slow timer hits sync boundary
                   if (image.upDownMovement == -(image.range / 2)) {
                       slowTimer.stop()
                       syncTimer.start()
                   }

                   // if slow timer hits medium boundary
                   else if (image.upDownMovement == ((image.range / 2) / 3) * 2) {
                       image.upDownMovement -= image.translation
                       slowTimer.stop()
                       mediumTimer.start()
                   }

                   // if indice is still within slow
                   else {
                       image.upDownMovement -= image.translation
                   }
                }
                else {
                    // if slow timer hits pause boundary
                    if (image.upDownMovement == image.range / 2) {
                        slowTimer.stop()
                        pauseTimer.start()
                    }

                    // if movement hits slow boundary
                    else if (image.upDownMovement == -((image.range / 2) / 3) * 2) {
                        image.upDownMovement += image.translation
                        slowTimer.stop()
                        mediumTimer.start()
                    }

                    // if indice is still within slow boundary
                    else {
                        image.upDownMovement += image.translation
                    }
                }
            }
        }
        Timer {
            id: pauseTimer
            interval: (image.frameInterval * 9) / 2 - (image.range / image.translation) * (image.fastInterval * 2); repeat: true; running: false;
            onTriggered: {
                console.log("pause: " + image.upDownMovement)

                image.goingUp = true
                image.upDownMovement -= image.translation
                pauseTimer.stop()
                slowTimer.start()
            }
        }
        Timer {
            id: syncTimer
            interval: 10; repeat: true; running: !image.goingUp;
            onTriggered: {
                console.log("sync: " + image.upDownMovement)
                if (image.frameIndex == 1) {
                   image.goingUp = false
                   image.upDownMovement += image.translation
                   syncTimer.stop()
                   slowTimer.start()
                }
            }
        }
    }
}
