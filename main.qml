import QtQuick 2.4
import Cute.Quack 1.0

Item {
//    function tr(text) {
////        return CC.quackTranslator.translate(text).value
//        return translator.translate(text).value
//    }

//    property QtObject textRequest: translator.translate(QT_TR_NOOP("Hey"))
////    property string textRequest: translator.translate(QT_TR_NOOP("Hey")).value


//    Text {
//        anchors.centerIn: parent
//        font.pointSize: 16
////        text: translator.translate(qsTr("Hey")).value
////        text: translator.translate(QT_TR_NOOP("Hey")).value

////        text: tr(QT_TR_NOOP("Hey"))
//        text: textRequest.value
//    }

    TrText {
        anchors.centerIn: parent
        font.pointSize: 16
        trText: QT_TR_NOOP("Hey")// + " Quack.on: " + Quack.on
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Quack.on = !Quack.on
        }
    }

    Component.onCompleted: {
//        console.log("quackTranslator: " + quackTranslator)
//        console.log("CC: " + CC)
//        console.log("CC.quackTranslator: " + CC.quackTranslator)
//        console.log("translator: " + translator)
//        console.log("quack: " + Quack)
//        console.log("CC.quackTranslator.quackTranslator: " + CC.quackTranslator.quackTranslator)
//        textRequest = translator.translate(QT_TR_NOOP("Hey"))
    }
}
