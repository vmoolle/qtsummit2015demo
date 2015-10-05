import QtQuick 2.0
import QtQuick.Controls 1.2

Button {
    property string trText: QT_TR_NOOP("Toggle quack")
    property QtObject textRequest: translator.translate(trText)
    text: textRequest.value
}
