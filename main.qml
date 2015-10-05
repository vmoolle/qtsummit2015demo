import QtQuick 2.4
import Cute.Quack 1.0

Item {
    Column {
        anchors.centerIn: parent

        TrText {
            font.pointSize: 16
            trText: QT_TR_NOOP("Hey there...")
        }
        TrText {
            font.pointSize: 16
            trText: QT_TR_NOOP("Hey, awesome duckyduckyducky!")
        }
        TrText {
            font.pointSize: 16
            trText: QT_TR_NOOP("Hey!")
        }

    }

//    TrText {
//        anchors.centerIn: parent
//        font.pointSize: 16
//        trText: QT_TR_NOOP("Hey")
//    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Quack.on = !Quack.on
        }
    }
}
