import QtQuick 2.0
import QtQuick.Controls 1.2

Button {
    property string trText
    property QtObject textRequest: translator.translate(trText)
    text: textRequest.value
}
