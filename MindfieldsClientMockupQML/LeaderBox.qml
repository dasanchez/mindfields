import QtQuick 2.0

Rectangle {
    property string player_name: ""
    property color team_color: bgColor
    width: 120
    height: 30
    radius: 5
    border.width: 3
    border.color: team_color
    color: "transparent"

    Rectangle {
        width: 10
        height: 10
        radius: 2
        color: team_color
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        anchors.centerIn: parent
        text: player_name
        font.pointSize: 12
        font.family: gameFont
        color: fgColor
    }
}
