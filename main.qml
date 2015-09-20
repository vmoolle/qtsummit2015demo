import QtQuick 2.4

Item {
    function tr(text) {
        return translator.translate(text).value
    }

//    Text {
//        anchors.centerIn: parent
//        font.pointSize: 16
////        text: translator.translate(qsTr("Hey")).value
////        text: translator.translate(QT_TR_NOOP("Hey")).value
//        text: tr(QT_TR_NOOP("Hey"))
//    }

    TrText {
        anchors.centerIn: parent
        font.pointSize: 16
        trText: QT_TR_NOOP("Hey")
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            translator.emulateLanguageChange()
        }
    }
}
