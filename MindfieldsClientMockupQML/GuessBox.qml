import QtQuick 2.0
import QtQuick.Controls 2.2

SpinBox {
    id: guesses_box
    value: 1
    from: 1
    to: 7
    editable: false

    contentItem: TextInput {
        id: guess_text
        text: guesses_box.textFromValue(guesses_box.value, guesses_box.locale)
        font.family: gameFont
        font.pointSize: 16
        color: fgColor
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter

        readOnly: true
        validator: guesses_spinbox.validator
        inputMethodHints: Qt.ImhFormattedNumbersOnly
    }

    background: Rectangle {
        implicitWidth: 40
        color: bgColor
    }

    up.indicator: Rectangle {
        x: guesses_box.mirrored ? 0 : parent.width - width
        height: parent.height
        implicitWidth: 30
        implicitHeight: 20
        color: bgColor
        border.color: enabled ? fgColor : bgColor
        radius: 2

        Text {
            text: "+"
            font.pixelSize: guesses_box.font.pixelSize * 2
            color: fgColor
            anchors.fill: parent
            fontSizeMode: Text.Fit
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: Font.DemiBold
        }
    }

    down.indicator: Rectangle {
        x: guesses_box.mirrored ? parent.width - width : 0
        height: parent.height
        implicitWidth: 30
        implicitHeight: 20
        color: bgColor
        border.color: enabled ? fgColor : bgColor
        radius: 2

        Text {
            text: "-"
            font.pixelSize: guesses_box.font.pixelSize * 2
            color: fgColor
            anchors.fill: parent
            fontSizeMode: Text.Fit
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
}
