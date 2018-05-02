import QtQuick 2.0

Rectangle {
    property string player_name: ""
    property color team_color: bgColor
    width: 120
    height: 30
    radius: 5
    border.color: team_color
    border.width: 3
    color: "transparent"

    Text {
        anchors.centerIn: parent
        text: player_name
        font.pointSize: 12
        font.family: gameFont
        color: fgColor
    }
}
