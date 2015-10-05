import QtQuick 2.0

Text {
    horizontalAlignment: Text.AlignJustify
    property string trText
    property QtObject textRequest: translator.translate(trText)
    text: textRequest.value
}
