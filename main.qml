import QtQuick 2.4
import Cute.Quack 1.0

Item {
    TrText {
        id: loremIpsum
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 25
        wrapMode: Text.Wrap
        font.pointSize: 16
        trText: "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
                + "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
                + "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris "
                + "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in "
                + "reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla "
                + "pariatur. Excepteur sint occaecat cupidatat non proident, sunt in "
                + "culpa qui officia deserunt mollit anim id est laborum."
    }

    TrButton {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.margins: loremIpsum.anchors.margins
        property string trText: QT_TR_NOOP("Toggle quack")
        onClicked: Quack.on = !Quack.on
    }
}
