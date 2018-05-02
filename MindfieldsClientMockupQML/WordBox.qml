import QtQuick 2.0

/*
* properties required:
* boxColor
* teamColor
* wordText
* textColor
*/

Rectangle {
    color: boxColor
    border.width: 2
    border.color: teamColor
    radius: 3

    Text {
        anchors.centerIn: parent
        text: wordText
        font.pointSize: 16
        font.family: gameFont
        color: textColor
        font.weight: Font.DemiBold
    }
}
