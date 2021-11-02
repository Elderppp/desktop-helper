import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: main_windows
    visible: true
    width: 400
    maximumWidth: width
    minimumWidth: width
    height: 400
    maximumHeight: height
    minimumHeight: height
    title: qsTr("Hello World")
    flags: Qt.Dialog


    MouseArea {
        width: 400
        height: 400
        onClicked: {
            console.log("0x"+CommandUtil.numberToHex(main_windows.flags))
        }
    }
}
