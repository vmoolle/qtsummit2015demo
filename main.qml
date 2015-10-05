import QtQuick 2.4
//import Cute.Quack 1.0 as CC
import Cute.Quack 1.0

Item {
    function tr(text) {
//        return CC.quackTranslator.translate(text).value
        return QuackTranslator.translate(text).value
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
            QuackTranslator.emulateLanguageChange()
        }
    }

    Component.onCompleted: {
//        console.log("quackTranslator: " + quackTranslator)
//        console.log("CC: " + CC)
//        console.log("CC.quackTranslator: " + CC.quackTranslator)
        console.log("QuackTranslator: " + QuackTranslator)
//        console.log("CC.quackTranslator.quackTranslator: " + CC.quackTranslator.quackTranslator)
    }
}
