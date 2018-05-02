// Colors
var orangeColor = "#FFAF22";
var blueColor = "#3288CA";
var fgColor = "#888888";

// Word grid objects
var dynamicObject;
var boxArray = new Array(16)
var wordBox;
var words = [ "APPLE", "BEER", "CINNAMON", "DICE",
             "ELEPHANT", "FARM", "GRANDMA", "HABIT",
             "INDIA", "JEEP", "KARMA", "LIME",
             "MEXICO", "NAAN", "OWL", "PERISCOPE" ];
var colors = [ orangeColor, orangeColor, fgColor, fgColor,
              blueColor, blueColor, orangeColor, orangeColor,
              orangeColor, fgColor, blueColor, blueColor,
              orangeColor, blueColor, orangeColor, blueColor];

function cycleState() {
    if ( root.state === 'name_entry' )
    {
        root.state = 'team_entry';
    }
    else if ( root.state === 'team_entry' )
    {
        root.state = 'role_entry';
    }
    else if ( root.state === 'role_entry' )
    {
        root.state = 'prompt_start';
    }
    else if ( root.state === 'prompt_start' )
    {
        root.state = 'wait_start';
    }
    else if ( root.state === 'wait_start')
    {
        root.state = 'display_words';
    }
    else if (root.state === 'display_words' )
    {
        root.state = 'hint_entry';
    }
    else if ( root.state === 'hint_entry' )
    {
        root.state = 'wait_approval';
    }
    else if ( root.state === 'wait_approval' )
    {
        root.state = 'wait_orange_guess';
        msg_box.append("<font color=\"#FFAF22\">BOB ></font> india and mexico obvs<br/>")
    }
    else if ( root.state === 'wait_orange_guess' )
    {
        root.state = 'guess_submitted';

        // Toggle element 8 in wordListModel
        wordListModel.get(8).boxColor = orangeColor;
        wordListModel.get(8).textColor = "black";
        wordListModel.get(8).activated = true;
    }
    else if ( root.state === 'guess_submitted' )
    {
        root.state = 'guess2_submitted';
        top_guess_text.text = "MEXICO";
        timer_text.text = ":39"
        wordListModel.get(12).boxColor = orangeColor;
        wordListModel.get(12).textColor = "black";
        wordListModel.get(12).activated = true;
    }
    else if ( root.state === 'guess2_submitted' )
    {
        root.state = 'wait_hint';
    }
    else if ( root.state === 'wait_hint' )
    {
        root.state = 'hint_approval';
    }
    else if ( root.state === 'hint_approval' )
    {
        root.state = 'wait_blue_guess';
        top_hint_text.text = incoming_hint_text.text;
        timer_text.text = ":59"
        msg_box.append("<font color=\"#3288CA\">Cindy ></font> naan for sure<br/>")
    }
    else if ( root.state === 'wait_blue_guess' )
    {
        root.state = 'guess3_submitted';
        top_guess_text.text = "NAAN";
        timer_text.text = ":52";
        wordListModel.get(13).boxColor = blueColor;
        wordListModel.get(13).textColor = "black";
        wordListModel.get(13).activated = true

    }
    else if ( root.state === 'guess3_submitted' )
    {
        root.state = 'hint2_entry';
        hint_input.text = "";
    }
    else if ( root.state === 'hint2_entry' )
    {
        root.state = 'guess4_submitted';
        top_guess_text.text = "HABIT";
        timer_text.text = ":22";

        msg_box.append("<font color=\"#3288CA\">Cindy ></font> are you kidding me<br/>")
        wordListModel.get(0).boxColor = orangeColor;
        wordListModel.get(0).textColor = "black";
        wordListModel.get(0).activated = true

        wordListModel.get(1).boxColor = orangeColor;
        wordListModel.get(1).textColor = "black";
        wordListModel.get(1).activated = true

        wordListModel.get(6).boxColor = orangeColor;
        wordListModel.get(6).textColor = "black";
        wordListModel.get(6).activated = true

        wordListModel.get(14).boxColor = orangeColor;
        wordListModel.get(14).textColor = "black";
        wordListModel.get(14).activated = true

        wordListModel.get(7).boxColor = orangeColor;
        wordListModel.get(7).textColor = "black";
        wordListModel.get(7).activated = true
    }
    else if ( root.state === 'guess4_submitted' )
    {
        root.state = 'name_entry';
    }
    console.log( "New state: " + root.state )
}

function populateWordGrid() {
    var i;
    for ( i = 0; i < words.length ; i++ )
    {
        wordListModel.append(
                    {
                        "wordText": words[i],
                        "boxColor": "transparent",
                        "textColor": "white",
                        "activated": false,
                        "teamColor": colors[i]
                    }
                    );
    }
}

//function createWordObject() {
//    dynamicObject = Qt.createComponent( 'WordBox.qml' );

//    if ( dynamicObject.status === Component.Ready)
//        finishCreation();
//    else
//        dynamicObject.statusChanged.connect(finishCreation)
//}

//function finishCreation() {
//    if ( dynamicObject.status === Component.Ready )
//    {
//        var wordId = 'word' + wordIndex;

//        wordBox = dynamicObject.createObject( word_grid_layout,
//                                             {
//                                                 "Layout.preferredHeight": 35,
//                                                 "Layout.preferredWidth": wordBoxWidth,
//                                                 "wordText": words[wordIndex],
//                                                 "teamColor": colors[wordIndex],
//                                                 "id": wordId
//                                             } );
//        console.log("wordBox has text " + wordBox.wordText );
//        objectsModel.append( {"obj": wordBox} );

//        wordIndex++;
//    }
//}
