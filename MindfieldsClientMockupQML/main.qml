import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import "state_logic.js" as Logic

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Mindfields Mockup")

    property string rootColor: "#444444"
    property string bgColor: "#222222"
    property string fgColor: "#BBBBBB"
    property string orangeColor: "#FFAF22"
    property string blueColor: "#3288CA"
    property string gameFont: "Open Sans"
    property int wordBoxWidth: 120

    //    onActiveFocusItemChanged: print("activeFocusItem", activeFocusItem)

    ListModel {
        id: wordListModel
    }

    Rectangle {
        id: root
        anchors.fill: parent
        color: rootColor
        state: "name_entry"

        RowLayout {
            id: lobby_layout
            anchors.fill: parent
            spacing: 10

            // Two areas: left for the player to input data,
            // right for the list of players waiting for the game to start.
            Rectangle {
                id: title_player_rec
                Layout.minimumWidth: 480
                Layout.preferredWidth: 480
                Layout.fillHeight: true
                color: rootColor

                ColumnLayout {
                    id: title_player
                    anchors.fill: parent
                    spacing: 2

                    Rectangle {
                        id: title_rec
                        color: bgColor
                        Layout.fillWidth: true
                        Layout.preferredHeight: 200
                        Layout.minimumHeight: 200

                        Text {
                            anchors.centerIn: parent
                            //                            text: "TITLE: " + parent.width + 'x' + parent.height
                            text: "MINDFIELDS"
                            font.pointSize: 48
                            color: fgColor
                            font.family: gameFont
                        }
                    }

                    Rectangle {
                        id: name_entry_area
                        color: bgColor
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        Rectangle {
                            id: player_name_entry
                            anchors.fill: parent
                            color: bgColor
                            visible: true

                            Text {
                                id: name_label
                                anchors.top: parent.top
                                anchors.topMargin: 10
                                anchors.horizontalCenter: parent.horizontalCenter
                                height: 12
                                text: "- Enter your name -"
                                font.pointSize: 12
                                color: fgColor
                                font.family: gameFont
                            }

                            TextInput {
                                id: name_entry
                                anchors.top: player_name_entry.top
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.topMargin: 30
                                text: ""
                                font.pointSize: 24
                                focus: true
                                color: fgColor
                                font.family: gameFont
                            }
                        }
                    }

                    Rectangle {
                        id: team_entry_area
                        color: rootColor
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        visible: false;

                        Rectangle {
                            id: name_display_area
                            anchors.fill: parent
                            color: bgColor
                            Text {
                                id: name_display
                                anchors.top: parent.top
                                anchors.topMargin: 30
                                anchors.horizontalCenter: parent.horizontalCenter
                                color: fgColor
                                text: name_entry.text
                                font.pointSize: 24
                                font.family: gameFont
                            }

                            Text {
                                id: team_label
                                text: qsTr("- Select a team -")
                                anchors.top: name_display.bottom
                                anchors.topMargin: 10
                                anchors.horizontalCenter: parent.horizontalCenter
                                font.pointSize: 12
                                height: 12
                                color: fgColor
                                font.family: gameFont
                            }

                            Row {
                                id: team_buttons_row
                                anchors.top: name_display.bottom
                                anchors.topMargin: 40
                                anchors.horizontalCenter: parent.horizontalCenter
                                width: 100
                                height: 40
                                spacing: 20

                                Rectangle {
                                    id: orange_button
                                    width: 40
                                    height: parent.height
                                    border.color: orangeColor
                                    border.width: 3
                                    color: "transparent"
                                    radius: 10
                                }

                                Rectangle {
                                    id: blue_button
                                    width: 40
                                    height: parent.height
                                    border.color: blueColor
                                    border.width: 3
                                    color: "transparent"
                                    radius: 10
                                }

                            }

                            Rectangle {
                                id: ready_rec
                                anchors.top: team_buttons_row.bottom
                                anchors.topMargin: 40
                                anchors.horizontalCenter: parent.horizontalCenter
                                width: 80
                                height: 40
                                color: "transparent"
                                border.color: fgColor
                                border.width: 3
                                visible: false
                                radius: 5

                                Text {
                                    id: ready_text
                                    anchors.centerIn: parent
                                    text: "Ready?"
                                    color: fgColor
                                    font.pointSize: 16
                                    font.family: gameFont
                                }
                            }

                            Text {
                                id: wait_start_label
                                anchors.top: ready_rec.bottom
                                anchors.topMargin: 10
                                anchors.horizontalCenter: parent.horizontalCenter
                                text: "- Waiting for the other team -"
                                font.pointSize: 12
                                height: 12
                                color: fgColor
                                font.family: gameFont
                                visible: false
                            }

                        }

                    }

                }

                // This MouseArea will prevent spin boxes from getting focus!
                MouseArea {
                    id: playerMouseArea
                    anchors.fill: parent
                    onClicked: Logic.cycleState();
                }
            }

            Rectangle {
                id: player_list
                color: bgColor
                Layout.fillWidth: true
                Layout.fillHeight: true

                Column {
                    anchors.fill: parent
                    anchors.topMargin: 20
                    spacing: 20

                    PlayerBox {
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.topMargin: 10
                        team_color: orangeColor
                        player_name: "BOB"
                    }

                    PlayerBox {
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.topMargin: 10
                        team_color: blueColor
                        player_name: "Cindy"
                    }

                    LeaderBox {
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.topMargin: 10
                        team_color: blueColor
                        player_name: "donald"
                    }

                }

            }

        }

        ColumnLayout {
            id: game_layout
            anchors.fill: parent
            spacing: 5
            visible: false

            // Four areas:
            // 1. Instructions / current state of the game, and a timer display
            // 2. Words laid out in a grid
            // 3. Messaging window
            // 4. Player interactions: hint handling for leaders, chat for members
            Rectangle {
                id: top_bar_rect
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                color: rootColor

                RowLayout {
                    id: top_bar_layout
                    anchors.fill: parent
                    spacing: 5

                    Rectangle {
                        id: status_rect
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        color: bgColor

                        Text {
                            id: status_text
                            text: "- Study the words -"
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.left: parent.left
                            anchors.leftMargin: 20
                            font.pointSize: 16
                            font.family: gameFont
                            color: fgColor
                        }
                    }

                    Rectangle {
                        id: top_hint_rec
                        Layout.fillHeight: true
                        Layout.preferredWidth: 250
                        color: bgColor
                        visible: false

                        Text {
                            id: top_hint_label
                            text: "Hint:"
                            anchors.left: parent.left
                            anchors.leftMargin: 5
                            anchors.verticalCenter: parent.verticalCenter
                            color: fgColor
                            font.pointSize: 16
                            font.family: gameFont
                        }

                        Text {
                            id: top_hint_text
                            text: "country"
                            anchors.left: top_hint_label.right
                            anchors.leftMargin: 5
                            anchors.right: hint_divider_rec.left
                            anchors.rightMargin: 5
                            anchors.verticalCenter: parent.verticalCenter
                            color: fgColor
                            font.pointSize: 24
                            font.family: gameFont
                            horizontalAlignment: Text.AlignHCenter
                        }

                        Rectangle {
                            id: hint_divider_rec
                            anchors.right: top_guess_count.left
                            anchors.leftMargin: 5
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            width: 2
                            color: rootColor
                        }

                        Text {
                            id: top_guess_count
                            text: guesses_box.value.toString()
                            width: 30
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.right: parent.right
                            font.family: gameFont
                            font.pointSize: 24
                            color: fgColor
                            horizontalAlignment: Text.AlignHCenter
                        }
                    }

                    Rectangle {
                        id: top_guess_rec
                        Layout.fillHeight: true
                        Layout.preferredWidth: 240
                        color: bgColor
                        visible: false

                        Text {
                            id: top_guess_text
                            text: "INDIA"
                            anchors.centerIn: parent
                            color: "white"
                            font.pointSize: 24
                            font.family: gameFont
                            horizontalAlignment: Text.AlignHCenter
                        }
                    }

                    Rectangle {
                        id: timer_rect
                        Layout.fillHeight: true
                        Layout.preferredWidth: 80
                        color: bgColor

                        Text {
                            id: timer_text
                            text: ":47"
                            anchors.centerIn: parent
                            font.family: gameFont
                            font.pointSize: 24
                            color: fgColor
                        }

                    }

                }

                // This MouseArea will prevent spin boxes from getting focus!
                MouseArea {
                    id: topBarMouseArea
                    anchors.fill: parent
                    onClicked: Logic.cycleState();
                }

            }

            Rectangle {
                id: word_grid_rect
                Layout.fillWidth: true
                Layout.preferredHeight: 270
                color: bgColor

                GridLayout {

                    id: gridView
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    anchors.margins: 10
                    rows: 4
                    columns: 4
                    rowSpacing: 25
                    columnSpacing: 25

                    Repeater {
                        model: wordListModel

                        WordBox {
                            property bool activated: false
                            Layout.preferredHeight: 40
                            Layout.preferredWidth: 120
                        }

                    }

                    Component.onCompleted: Logic.populateWordGrid();
                }
            }

            Rectangle {
                id: msg_rect
                Layout.fillWidth: true
                Layout.fillHeight: true
                color: bgColor

                Rectangle {
                    id: msg_box_border
                    anchors.fill: parent
                    anchors.margins: 5
                    color: "transparent"
                    border.color: fgColor
                    border.width: 1
                    radius: 2
                }

                ScrollView {
                    anchors.fill: parent
                    anchors.margins: 10

                    TextArea {
                        id: msg_box
                        //                        anchors.fill: parent
                        font.family: gameFont
                        font.pointSize: 12
                        textFormat: TextEdit.RichText
                        text: "<font color=\"#FFAF22\">BOB ></font> blue is going dooooown!<br/>"
                        color: "white"
                        verticalAlignment: TextEdit.AlignBottom
                        wrapMode: TextEdit.WordWrap
                        readOnly: true
                        cursorPosition: msg_box.length
                    }
                }

            }

            Rectangle {
                id: leader_status_rec
                Layout.fillWidth: true
                Layout.preferredHeight: 50
                color: bgColor

                RowLayout {
                    id: leader_bar_layout
                    anchors.fill: parent
                    anchors.topMargin: 5
                    anchors.bottomMargin: 5
                    anchors.leftMargin: 5

                    LeaderBox {
                        Layout.fillHeight: true
                        Layout.preferredWidth: 120
                        player_name: name_entry.text
                        team_color: orangeColor
                    }

                    Rectangle {
                        id: leader_input_rec
                        Layout.fillHeight: true
                        Layout.fillWidth: true
                        color: bgColor
                        visible: false

                        Rectangle {
                            id: hint_label_rec
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.bottom: parent.bottom
                            width: 45
                            color: bgColor

                            Text {
                                id: hint_label_text
                                anchors.centerIn: parent
                                text: "Hint:"
                                font.family: gameFont
                                font.pointSize: 12
                                color: fgColor
                            }
                        }

                        TextInput {
                            id: hint_input
                            anchors.left: hint_label_rec.right
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            width: 200
                            color: fgColor
                            font.family: gameFont
                            focus: false
                            font.pointSize: 24
                            horizontalAlignment: TextInput.AlignHCenter
                            maximumLength: 16
                        }

                        Rectangle {
                            id: guesses_label_rec
                            anchors.top: parent.top
                            anchors.left: hint_input.right
                            anchors.bottom: parent.bottom
                            width: 60
                            color: bgColor

                            Text {
                                id: guesses_label_text
                                anchors.centerIn: parent
                                text: "Guesses:"
                                font.family: gameFont
                                font.pointSize: 12
                                color: fgColor
                            }
                        }

                        GuessBox {
                            id: guesses_box
                            anchors.left: guesses_label_rec.right
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            anchors.topMargin: 5
                            anchors.bottomMargin: 5
                        }

                        Rectangle {
                            id: send_hint_rec
                            anchors.left: guesses_box.right
                            anchors.right: parent.right
                            anchors.verticalCenter: parent.verticalCenter
                            anchors.leftMargin: 5
                            anchors.rightMargin: 5
                            height: 30
                            color: "transparent"
                            border.width: 1
                            border.color: fgColor
                            radius: 2

                            Text {
                                id: send_hint_text
                                anchors.centerIn: parent
                                text: "Send"
                                font.pointSize: 16
                                font.family: gameFont
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: incoming_hint_rec
                            anchors.left: hint_label_rec.right
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            width: 240
                            color: bgColor
                            visible: false

                            Text {
                                id: incoming_hint_text
                                anchors.centerIn: parent
                                text: "indian"
                                font.family: gameFont
                                font.pointSize: 24
                                color: fgColor
                            }
                        }

                        Rectangle {
                            id: approve_hint_rec
                            anchors.left: incoming_hint_rec.right
                            anchors.leftMargin: 10
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            anchors.topMargin: 5
                            anchors.bottomMargin: anchors.topMargin
                            height: 40
                            width: 100
                            color: "transparent"
                            border.width: 1
                            border.color: fgColor
                            radius: 2
                            visible: false

                            Text {
                                id: approve_hint_text
                                anchors.centerIn: parent
                                text: "Approve"
                                font.pointSize: 16
                                font.family: gameFont
                                color: "white"
                            }
                        }

                        Rectangle {
                            id: reject_hint_rec
                            anchors.left: approve_hint_rec.right
                            anchors.leftMargin: 10
                            anchors.top: parent.top
                            anchors.bottom: parent.bottom
                            anchors.topMargin: 5
                            anchors.bottomMargin: anchors.topMargin
                            height: 40
                            width: 100
                            color: "transparent"
                            border.width: 1
                            border.color: fgColor
                            radius: 2
                            visible: false

                            Text {
                                id: reject_hint_text
                                anchors.centerIn: parent
                                text: "Reject"
                                font.pointSize: 16
                                font.family: gameFont
                                color: "white"
                            }

                        }

                    }

                }
            }

        }

        Rectangle {
            id: game_over_rec
            anchors.centerIn: parent
            width: 400
            height: 160
            color: bgColor
            border.color: orangeColor
            border.width: 2
            radius: 5
            visible: false

            Text {
                id: game_over_text
                anchors.top: parent.top
                anchors.topMargin: 20
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Orange Wins!"
                color: "white"
                font.pointSize: 36
                font.family: gameFont
            }

            Rectangle {
                id: play_again_rect
                anchors.top: game_over_text.bottom
                anchors.topMargin: 20
                anchors.leftMargin: 80
                anchors.rightMargin: 80
                anchors.left: parent.left
                anchors.right: parent.right
                height: 50
                color: "transparent"
                border.color: fgColor
                border.width: 2
                radius: 2

                Text {
                    text: "Play again?"
                    color: "white"
                    anchors.centerIn: parent
                    font.family: gameFont
                    font.pointSize: 24
                }
            }
        }


        states: [

            State {
                id: guess4_submitted_state
                name: "guess4_submitted"
                PropertyChanges {
                    target: lobby_layout
                    visible: false
                }
                PropertyChanges {
                    target: game_layout
                    visible: true
                }
                PropertyChanges {
                    target: status_text
                    text: "- BOB guessed: -"
                }
                PropertyChanges {
                    target: name_entry
                    focus: false
                }
                PropertyChanges {
                    target: top_guess_rec
                    visible: true
                }
                PropertyChanges {
                    target: game_over_rec
                    visible: true
                }
            },
            State {
                id: hint2_entry_state
                name: "hint2_entry"
                PropertyChanges {
                    target: lobby_layout
                    visible: false
                }
                PropertyChanges {
                    target: game_layout
                    visible: true
                }
                PropertyChanges {
                    target: name_entry
                    focus: false
                }
                PropertyChanges {
                    target: leader_input_rec
                    visible: true
                }
                PropertyChanges {
                    target: status_text
                    text: " - Enter a hint and number of related words -"
                }
                PropertyChanges {
                    target: hint_input
                    focus: true
                }
                PropertyChanges {
                    target: hint_input
                    visible: true
                }
                PropertyChanges {
                    target: guesses_box
                    visible: true
                }
                PropertyChanges {
                    target: send_hint_rec
                    visible: true
                }
            },
            State {
                id: guess3_submitted_state
                name: "guess3_submitted"
                PropertyChanges {
                    target: lobby_layout
                    visible: false
                }
                PropertyChanges {
                    target: game_layout
                    visible: true
                }
                PropertyChanges {
                    target: status_text
                    text: "- Cindy guessed: -"
                }
                PropertyChanges {
                    target: name_entry
                    focus: false
                }
                PropertyChanges {
                    target: top_guess_rec
                    visible: true
                }
            },
            State {
                id: wait_blue_guess_state
                name: "wait_blue_guess"
                PropertyChanges {
                    target: lobby_layout
                    visible: false
                }
                PropertyChanges {
                    target: game_layout
                    visible: true
                }
                PropertyChanges {
                    target: status_text
                    text: "- Waiting for blue guesses -"
                }
                PropertyChanges {
                    target: name_entry
                    focus: false
                }
                PropertyChanges {
                    target: top_hint_rec
                    visible: true
                }
            },
            State {
                id: hint_approval_state
                name: "hint_approval"
                PropertyChanges {
                    target: lobby_layout
                    visible: false
                }
                PropertyChanges {
                    target: game_layout
                    visible: true
                }
                PropertyChanges {
                    target: status_text
                    text: "- Respond to hint request -"
                }
                PropertyChanges {
                    target: name_entry
                    focus: false
                }
                PropertyChanges {
                    target: leader_input_rec
                    visible: true
                }
                PropertyChanges {
                    target: hint_input
                    visible: false
                }
                PropertyChanges {
                    target: guesses_label_rec
                    visible: false
                }
                PropertyChanges {
                    target: guesses_box
                    visible: false
                }
                PropertyChanges {
                    target: send_hint_rec
                    visible: false
                }
                PropertyChanges {
                    target: incoming_hint_rec
                    visible: true
                }
                PropertyChanges {
                    target: approve_hint_rec
                    visible: true
                }
                PropertyChanges {
                    target: reject_hint_rec
                    visible: true
                }
            },
            State {
                id: wait_hint_state
                name: "wait_hint"
                PropertyChanges {
                    target: lobby_layout
                    visible: false
                }
                PropertyChanges {
                    target: game_layout
                    visible: true
                }
                PropertyChanges {
                    target: status_text
                    text: "- Waiting for hint -"
                }
                PropertyChanges {
                    target: name_entry
                    focus: false
                }
            },
            State {
                id: guess2_submitted_state
                name: "guess2_submitted"
                PropertyChanges {
                    target: lobby_layout
                    visible: false
                }
                PropertyChanges {
                    target: game_layout
                    visible: true
                }
                PropertyChanges {
                    target: status_text
                    text: "- BOB guessed: -"
                }
                PropertyChanges {
                    target: name_entry
                    focus: false
                }
                PropertyChanges {
                    target: top_guess_rec
                    visible: true
                }
            },
            State {
                id: guess_submitted_state
                name: "guess_submitted"
                PropertyChanges {
                    target: lobby_layout
                    visible: false
                }
                PropertyChanges {
                    target: game_layout
                    visible: true
                }
                PropertyChanges {
                    target: status_text
                    text: "- BOB guessed: -"
                }
                PropertyChanges {
                    target: name_entry
                    focus: false
                }
                PropertyChanges {
                    target: top_guess_rec
                    visible: true
                }
            },
            State {
                id: wait_orange_guess_state
                name: "wait_orange_guess"
                PropertyChanges {
                    target: lobby_layout
                    visible: false
                }
                PropertyChanges {
                    target: game_layout
                    visible: true
                }
                PropertyChanges {
                    target: status_text
                    text: "- Waiting for orange guesses -"
                }
                PropertyChanges {
                    target: name_entry
                    focus: false
                }
                PropertyChanges {
                    target: top_hint_rec
                    visible: true
                }
            },
            State {
                id: wait_approval_state
                name: "wait_approval"
                PropertyChanges {
                    target: lobby_layout
                    visible: false
                }
                PropertyChanges {
                    target: game_layout
                    visible: true
                }
                PropertyChanges {
                    target: status_text
                    text: "- Waiting for hint approval -"
                }
                PropertyChanges {
                    target: name_entry
                    focus: false
                }
            },
            State {
                id: hint_entry_state
                name: "hint_entry"
                PropertyChanges {
                    target: lobby_layout
                    visible: false
                }
                PropertyChanges {
                    target: game_layout
                    visible: true
                }
                PropertyChanges {
                    target: name_entry
                    focus: false
                }
                PropertyChanges {
                    target: leader_input_rec
                    visible: true
                }
                PropertyChanges {
                    target: status_text
                    text: " - Enter a hint and number of related words -"
                }
                PropertyChanges {
                    target: hint_input
                    focus: true
                }
            },
            State {
                id: display_words_state
                name: "display_words"
                PropertyChanges {
                    target: lobby_layout
                    visible: false
                }
                PropertyChanges {
                    target: game_layout
                    visible: true
                }
                PropertyChanges {
                    target: name_entry
                    focus: false
                }
            },
            State {
                id: wait_start_state
                name: "wait_start"
                PropertyChanges {
                    target: orange_button
                    color: orangeColor
                }
                PropertyChanges {
                    target: blue_button
                    visible: false
                }
                PropertyChanges {
                    target: name_entry_area
                    visible: false
                }
                PropertyChanges {
                    target: team_entry_area
                    visible: true
                }
                PropertyChanges {
                    target: team_buttons_row
                    width: 40
                }
                PropertyChanges {
                    target: team_label
                    visible: false
                }
                PropertyChanges {
                    target: ready_rec
                    visible: true
                }
                PropertyChanges {
                    target: ready_rec
                    color: fgColor
                }
                PropertyChanges {
                    target: ready_text
                    color: "black"
                }
                PropertyChanges {
                    target: ready_text
                    text: "Ready"
                }
                PropertyChanges {
                    target: wait_start_label
                    visible: true
                }
            },
            State {
                id: prompt_start_state
                name: "prompt_start"
                PropertyChanges {
                    target: orange_button
                    color: orangeColor
                }
                PropertyChanges {
                    target: blue_button
                    visible: false
                }
                PropertyChanges {
                    target: name_entry_area
                    visible: false
                }
                PropertyChanges {
                    target: team_entry_area
                    visible: true
                }
                PropertyChanges {
                    target: team_buttons_row
                    width: 40
                }
                PropertyChanges {
                    target: team_label
                    visible: false
                }
                PropertyChanges {
                    target: ready_rec
                    visible: true
                }
            },
            State {
                id: role_entry_state
                name: "role_entry"
                PropertyChanges {
                    target: blue_button
                    visible: false
                }
                PropertyChanges {
                    target: name_entry_area
                    visible: false
                }
                PropertyChanges {
                    target: team_entry_area
                    visible: true
                }
                PropertyChanges {
                    target: team_buttons_row
                    width: 40
                }
                PropertyChanges {
                    target: team_label
                    text: " - Play as leader? -"
                }
            },
            State {
                id: team_entry_state
                name: "team_entry"
                PropertyChanges {
                    target: name_entry_area
                    visible: false
                }
                PropertyChanges {
                    target: team_entry_area
                    visible: true

                }
            },
            State {
                id: name_entry_state
                name: "name_entry"
                PropertyChanges {
                    target: name_entry_area
                    visible: true
                }
                PropertyChanges {
                    target: team_entry_area
                    visible: false

                }
            }

        ]

    }

}
