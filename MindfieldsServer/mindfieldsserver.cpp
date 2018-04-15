#include "mindfieldsserver.h"

MindfieldsServer::MindfieldsServer( QObject *parent, unsigned int port ) : QObject(parent)
{
    debugMode = true;

    // seed qrand()
    QDateTime cd = QDateTime::currentDateTime();
    qsrand(cd.toTime_t());

    // set up timer
    gameTimer = new QTimer(this);
    connect( gameTimer, SIGNAL( timeout()) , this, SLOT( serviceTimer() ) );

    // start TCP server
    newSession( port );
    connect( tcpServer, SIGNAL( newConnection() ), this, SLOT( processConnection() ) );
}

// when a client disconnects, remove them from the player list
// if they are a leader, assign the next player in the list
// update all remaining players of the updated roster
void MindfieldsServer::clientDisconnected()
{
    QTcpSocket *sourceClient = static_cast<QTcpSocket *>( sender() );
    Team playerTeam;
    bool wasLeader = false;

    qDebug() << "There are " << gamePlayers.size() << " players";

    for ( int i = 0; i < gamePlayers.size() ; ++i)
    {
        if ( gamePlayers[ i ].socket == sourceClient )
        {
            playerTeam = gamePlayers[ i ].team;
            if ( gamePlayers[ i ].role == LEADER )
                wasLeader = true;

            qDebug() << gamePlayers[i].name << " has left";
            qDebug() << "There are " << gamePlayers.size()-1 << " players";
            gamePlayers.removeAt( i );
            break;
        }
    }

    // reassign leadership
    if ( wasLeader )
    {
        for ( int i = 0; i< gamePlayers.size() ; ++i )
        {
            if ( gamePlayers[ i ].team == playerTeam )
            {
                gamePlayers[ i ].role = LEADER;
                break;
            }
        }
    }

    // update players with new roster
    printPlayers();
    notifyAllPlayers( generatePlayerList() );

    sourceClient->deleteLater();
}

QJsonDocument MindfieldsServer::generatePlayerList()
{
    QJsonObject jsonPlayers;
    QJsonArray bluePlayers;
    QJsonArray orangePlayers;
    QJsonArray neutralPlayers;

    jsonPlayers.insert( "type", "playerlist");

    for ( int i = 0; i < gamePlayers.size() ; ++i )
    {
        if ( gamePlayers[ i ].team == BLUE )
        {
            bluePlayers.append( gamePlayers[ i ].name );
            if ( gamePlayers[ i ].role == LEADER )
                jsonPlayers.insert( "blueleader", gamePlayers[ i ].name );
        }
        else if ( gamePlayers[ i ].team == ORANGE )
        {
            orangePlayers.append( gamePlayers[ i ].name );
            if ( gamePlayers[ i ].role == LEADER )
                jsonPlayers.insert( "orangeleader", gamePlayers[ i ].name );
        }
        else // players without a team
        {
            neutralPlayers.append( gamePlayers[ i ].name );
        }
    }

    jsonPlayers.insert( "blueteam", bluePlayers );
    jsonPlayers.insert( "orangeteam", orangePlayers );
    jsonPlayers.insert( "neutral", neutralPlayers );
    QJsonDocument jsonDoc( jsonPlayers );
    return jsonDoc;
}

// pull random words from dictionary
void MindfieldsServer::generateWordList(quint8 cardsRequired)
{
    if ( debugMode )
        qDebug() << "Pulling " << cardsRequired << " from dictionary of " << dictionary.size() << " words.";

    for ( int i = 0 ; i < cardsRequired; i++)
    {
        int randomDraw = qrand() % dictionary.size();
        wordList.append( dictionary.at( randomDraw ));
        if ( debugMode )
            qDebug() << "Pull word #" << randomDraw <<  ": " << dictionary.at ( randomDraw );
        dictionary.remove( randomDraw );
    }
}

QString MindfieldsServer::getPlayerName( QTcpSocket * socket )
{
    QString name;
    foreach ( Player player, gamePlayers)
    {
        if ( socket == player.socket )
        {
            name = player.name;
            break;
        }
    }
    return name;
}

// hint was either approved or rejected
bool MindfieldsServer::hintResponse( QString hintResponse, QTcpSocket *socket)
{
    for ( int i = 0; i < gamePlayers.size() ; ++i )
    {
        if ( gamePlayers[ i ].socket == socket && gamePlayers[ i ].role == LEADER )
        {
            // is it this leader's place to respond to hints?
            if ( gamePlayers[ i ].team != currentTurn )
            {
                // evaluate response
                if ( hintResponse == QString( "accepted" ) ) // hint approved
                    return true;
                else // hint rejected
                {
                    for ( int j = 0 ; j < gamePlayers.size() ; j++ )
                    {
                        if ( gamePlayers.at( j ).role == LEADER && gamePlayers.at( j ).name != gamePlayers[ i ].name )
                        {
                            QJsonObject jsonResponse;
                            jsonResponse.insert( "type", "hintresponse");
                            jsonResponse.insert("response", "rejected");
                            QJsonDocument responseDoc( jsonResponse );
                            gamePlayers.at( j ).socket->write( responseDoc.toJson() );
                            return false;
                        }
                    }
                } // hint rejected
            } // responding player is in the opposite team
        } // responding player is a leader
    } // look for player in gamePlayers
    return false;
}

// process a new hint issued by a player
void MindfieldsServer::hintReceived( QString hint, QTcpSocket *socket )
{
    gameTimer->stop();
    bool isLeader = false;
    // make sure that the sender is a leader
    for ( int i = 0 ; i < gamePlayers.size() ; ++i)
    {
        if ( gamePlayers[ i ].socket == socket && gamePlayers[ i ].role == LEADER )
        {
            // is it the current team's turn to issue hints?
            if ( gamePlayers[ i ].team == currentTurn ) // yes
                isLeader = true;
            else return; // no
        }
    }
    if ( isLeader )
    {
        proposedHint = hint;

        // send hint to other leader for approval
        for ( int i = 0 ; i < gamePlayers.size() ; ++i)
        {
            if ( gamePlayers[ i ].role == LEADER && gamePlayers[ i ].team != currentTurn )
            {
                QJsonObject jsonResponse;
                jsonResponse.insert("type", "newhint");
                jsonResponse.insert("hint", proposedHint);
                QJsonDocument responseDoc( jsonResponse );
                gamePlayers[ i ].socket->write( responseDoc.toJson() );
                break;
            }
        }
    }
}

bool MindfieldsServer::isPlayer( QTcpSocket * socket )
{
    bool isPlayer = false;

    foreach ( Player player, gamePlayers )
    {
        if ( socket == player.socket )
        {
            isPlayer = true;
            break;
        }
    }

    return isPlayer;
}

bool MindfieldsServer::isLeader( QTcpSocket * socket )
{
    bool leader = false;
    foreach ( Player player, gamePlayers)
    {
        if ( socket == player.socket )
        {
            if ( player.role == LEADER )
                leader = true;
            break;
        }
    }
    return leader;
}

bool MindfieldsServer::isNameTaken( QString requestedName )
{
    if ( !gamePlayers.isEmpty() )
        foreach ( Player player, gamePlayers)
        {
            if ( player.name == requestedName )
                return true;
        }
    return false;
}

// assign incoming connection to a new Player object
void MindfieldsServer::makeNewPlayer(QString name, QTcpSocket *socket)
{
    Player newPlayer;
    newPlayer.name = name;
    newPlayer.socket = socket;
    newPlayer.team = NEUTRAL;
    newPlayer.role = MEMBER;

    gamePlayers.append( newPlayer );
}

// start TCP server
void MindfieldsServer::newSession( unsigned int listenPort )
{
    tcpServer = new QTcpServer(this);
    if ( !tcpServer->listen(QHostAddress::LocalHost, listenPort )) {
        qDebug() << QString("Unable to start the server: %1.").arg(tcpServer->errorString());
        return;
    }

    QString ipAddress;
    ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    qDebug() << QString("The server is running on IP: %1, port: %2.").arg(ipAddress).arg(tcpServer->serverPort());
    qDebug() << QString("Run the client now.");
}

void MindfieldsServer::notifyAllPlayers(QJsonDocument jsonDoc)
{
    if ( !gamePlayers.isEmpty() )
        foreach ( Player player, gamePlayers )
        {
            if ( player.socket->isOpen() )
            {
                player.socket->write( jsonDoc.toJson() );
            }
        }
}

void MindfieldsServer::notifyTeamLeaders(QJsonDocument jsonDoc)
{
    if ( !gamePlayers.isEmpty() )
        foreach ( Player player, gamePlayers )
        {
            if ( player.role == LEADER && player.socket->isOpen() )
            {
                player.socket->write( jsonDoc.toJson() );
            }
        }
}

void MindfieldsServer::printPlayers()
{
    if ( !gamePlayers.isEmpty() )
        foreach ( Player player, gamePlayers )
        {
            QString playerInfo;
            playerInfo.append( "Player: " );
            playerInfo.append( player.name );
            playerInfo.append( " | Team: " );
            switch ( player.team )
            {
            case NEUTRAL:
                playerInfo.append( "neutral" );
                break;
            case BLUE:
                playerInfo.append( "blue" );
                break;
            case ORANGE:
                playerInfo.append( "orange" );
                break;
            default:
                break;
            }

            playerInfo.append( " | Role: ");
            playerInfo.append( (player.role == LEADER ? "leader" : "member" ) );

            qDebug() << playerInfo;
        }
}

// process data from any connection
void MindfieldsServer::processClientData()
{
    QTcpSocket *sourceClient = static_cast< QTcpSocket *>( sender() );
    QByteArray clientData;

    // read all available bytes from client socket
    while ( sourceClient->bytesAvailable() )
    {
        clientData.append( sourceClient->readAll() );
        //  if ( debugMode )
        //      qDebug() << sourceClient->readAll();
    }

    // extract JSON from raw data
    QJsonDocument jsonDoc = QJsonDocument::fromJson(clientData);
    QJsonObject json = jsonDoc.object();

    if ( debugMode )
        qDebug() << "Received" << json.value("type") << "request";

    switch ( gameState )
    {
    case LOBBY:
        if ( json.value( "type" ) == QString( "newplayerrequest" ) ) // new player request
            processNewPlayer( json.value( "name" ).toString(), sourceClient );
        else if ( json.value( "type" ) == QString("teamrequest") )  // team request
            processTeamRequest( json.value( "team" ).toString(), sourceClient );
        else if ( json.value( "type") == QString("rolerequest") )  // role request
            processRoleRequest( json.value( "role" ).toString(), sourceClient );
        else if ( json.value( "type" ) == QString( "startgame" ) ) // start game request
        {
            if ( processStartRequest( sourceClient ) )  // returns true if both leaders are ready
                setupFirstTurn();
        }
        break;
    case AWAITING_HINT:
        if ( json.value( "type" ) == QString( "hint") )
        {
            // hint has been submitted
            guessCount = json.value( "count" ).toInt();
            hintReceived( json.value( "hint" ).toString(), sourceClient );
        }
        else if ( json.value( "type") == QString( "hintresponse" ) )
        {
            if ( hintResponse( json.value( "response" ).toString(), sourceClient ) )
            {
                // hint has been approved
                gameState = AWAITING_GUESS;
                publishHint( proposedHint );

                QJsonObject jsonBroadcast;
                jsonBroadcast.insert("type", "timerstart");
                jsonBroadcast.insert("time", turnTime / 1000 );
                QJsonDocument broadcastDoc( jsonBroadcast );
                notifyAllPlayers( broadcastDoc );

                if ( debugMode )
                    qDebug() << "Timer started: " << turnTime / 1000 << " seconds.";

                gameTimer->start( turnTime );
            }
        }
        else if ( json.value( "type" ) == QString( "message" ))
        {
            // incoming message from a player
            if ( !isLeader( sourceClient ) ) // team member, OK
            {
                QJsonObject jsonBroadcast;
                jsonBroadcast.insert("type", "message");
                jsonBroadcast.insert("msg", json.value("msg").toString());
                jsonBroadcast.insert("name", getPlayerName(sourceClient));
                QJsonDocument broadcastDoc( jsonBroadcast );
                notifyAllPlayers( broadcastDoc );
            }
        }
        break;
    case AWAITING_GUESS:
        if ( json.value( "type" ) == QString( "guess" ) )
        {
            // reveal guess
            if ( processGuess( json.value( "guess" ).toString(), sourceClient ) ) // returns true if the word is in play
            {
                gameState = GUESS_REVEALED;
                timeLeft = gameTimer->remainingTime();
                gameTimer->stop();

                QJsonObject jsonBroadcast;
                jsonBroadcast.insert("type", "timerstart");
                jsonBroadcast.insert("time", msgTime / 1000 );
                QJsonDocument broadcastDoc( jsonBroadcast );
                notifyAllPlayers( broadcastDoc );

                if ( debugMode )
                    qDebug() << "Timer started: " << msgTime / 1000 << " seconds.";

                gameTimer->start( msgTime );
            }
        }
        else if ( json.value( "type" ) == QString( "message" ))
        {
            // incoming message from a player
            if ( !isLeader( sourceClient ) ) // team member, OK
            {
                QJsonObject jsonBroadcast;
                jsonBroadcast.insert("type", "message");
                jsonBroadcast.insert("msg", json.value("msg").toString());
                jsonBroadcast.insert("name", getPlayerName(sourceClient));
                QJsonDocument broadcastDoc( jsonBroadcast );
                notifyAllPlayers( broadcastDoc );
            }
        }
        break;
    case GAME_OVER:
        if ( json.value( "type" ) == QString( "restart") )
        {
            // player is ready to play again
            bool playersReady = true;
            foreach ( Player player, gamePlayers )
            {
                if ( player.socket == sourceClient )
                {
                    player.ready = true;
                }
                else
                {
                    if ( !player.ready )
                        playersReady = false;
                }
            }
            if ( playersReady )
            {
                gameState = LOBBY;
                QJsonObject jsonRestart;
                jsonRestart.insert( "type", "statechange" );
                jsonRestart.insert("newstate", "lobby" );
                QJsonDocument restartDoc( jsonRestart );
                notifyAllPlayers( restartDoc );
                notifyAllPlayers( generatePlayerList() );
                blueLeaderReady = false;
                orangeLeaderReady = false;
            }
        }
        break;
    default:
        break;
    }
}

// handle incoming client connections
void MindfieldsServer::processConnection()
{
    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();

    connect( clientConnection, SIGNAL( disconnected()), this, SLOT(clientDisconnected()) );
    connect(clientConnection, SIGNAL( readyRead() ), this, SLOT( processClientData() ) );
}

// return true if word is valid (regardless of whether it is correct)
bool MindfieldsServer::processGuess( QString guess, QTcpSocket *socket )
{
    QJsonObject jsonGuess;
    Team guessTeam;

    // check if the word is in the word list
    if ( !wordList.contains( guess ) || guessedWords.contains( guess ) )
        return false;

    // check if issuing player is in the right team
    foreach ( Player player, gamePlayers )
    {
        if ( player.socket == socket ) // found the sender
        {
            if ( !( player.team == currentTurn ) )
                return false;
            else // player is allowed to guess
            {
                jsonGuess.insert( "type", "guessreveal" );
                jsonGuess.insert( "player", player.name );
                jsonGuess.insert( "guess", guess );
                guessedWords.append( guess );
                guessCount--;
                break;
            }
        }
    }

    // word is in play and the player is allowed to guess
    if ( blueTeamWords.contains( guess ) )
    {
        guessTeam = BLUE;
        jsonGuess.insert( "team", "blue" );
        blueCardsLeft--;

    }
    else if ( orangeTeamWords.contains( guess ) )
    {
        guessTeam = ORANGE;
        jsonGuess.insert( "team", "orange" );
        orangeCardsLeft--;
    }
    else
    {
        jsonGuess.insert("team", "neutral");
    }

    // publish guess evaluation to all players
    QJsonDocument jsonDoc( jsonGuess );
    notifyAllPlayers( jsonDoc );

    if ( guessTeam == currentTurn )
        correctGuess = true;
    else // incorrect guess, flag end of turn
        correctGuess = false;

    return true;
}

// accept player to game or request a different name
void MindfieldsServer::processNewPlayer( QString newPlayerName, QTcpSocket *sourceClient )
{
    if ( isNameTaken(newPlayerName) )
    {   // refuse request - name is taken
        QJsonObject jsonResponse;
        jsonResponse.insert("type", "newplayerresponse");
        jsonResponse.insert("response", "taken");
        jsonResponse.insert("name", newPlayerName);
        QJsonDocument responseDoc( jsonResponse );
        sourceClient->write( responseDoc.toJson() );
    }
    else
    { // make new player or rename existing one
        if ( isPlayer( sourceClient ) ) // sender is already a registered player
        {
            for ( int i = 0; i < gamePlayers.size(); ++i )
            {
                if ( gamePlayers.at( i ).socket == sourceClient )
                {
                    gamePlayers[ i ].name = newPlayerName; // rename
                    break;
                }
            }
        }
        else
        {
            makeNewPlayer( newPlayerName, sourceClient );
        }
        QJsonObject jsonResponse;
        jsonResponse.insert("type", "newplayerresponse");
        jsonResponse.insert("response", "accepted");
        jsonResponse.insert("name", newPlayerName );
        QJsonDocument responseDoc( jsonResponse );
        sourceClient->write( responseDoc.toJson() );
    }

    if ( debugMode )
    {
        printPlayers();
    }

    notifyAllPlayers( generatePlayerList() );
}

// assign player role
void MindfieldsServer::processRoleRequest( QString role, QTcpSocket *socket)
{
    QJsonObject jsonResponse;
    jsonResponse.insert("type", "roleresponse" );

    qDebug() << "Processing role request";

    if ( !( blueLeader && orangeLeader ) ) // if both leaders are assigned, skip assignment
    {

        // look for player issuing the request
        for ( int i = 0; i < gamePlayers.size() ; ++i )
        {
            if ( gamePlayers[ i ].socket == socket )
            {
                if ( role == QString( "leader") )
                {
                    // is this position available for player's team?
                    if ( gamePlayers[ i ].team == BLUE )
                    {
                        if ( !blueLeader )
                        {
                            blueLeader = true;
                            gamePlayers[ i ].role = LEADER;
                            jsonResponse.insert( "role", "leader" );
                        }
                        else // blue team already has a leader
                        {
                            gamePlayers[ i ].role = MEMBER;
                            jsonResponse.insert("role", "member");
                        }
                    } // blue player request
                    else if ( gamePlayers[ i ].team == ORANGE )
                    {
                        if ( !orangeLeader )
                        {
                            orangeLeader = true;
                            gamePlayers[ i ].role = LEADER;
                            jsonResponse.insert( "role", "leader");
                        }
                        else // orange team already has a leader
                        {
                            gamePlayers[ i ].role = MEMBER;
                            jsonResponse.insert( "role", "member");
                        }
                    } // orange player request
                }
                else
                {
                    gamePlayers[ i ].role = MEMBER;
                    jsonResponse.insert("role", "member");
                }

                // send response to requesting player
                QJsonDocument responseDoc( jsonResponse );
                socket->write( responseDoc.toJson() );

                if ( debugMode )
                    printPlayers();

                // Send player list to all connected players
                notifyAllPlayers( generatePlayerList() );
                break;
            }
        }
    }

    // signal all players that leaders have been assigned
    if ( blueLeader && orangeLeader )
    {
        QJsonObject readyObject;
        readyObject.insert("type", "leadersassigned");
        QJsonDocument readyDoc( readyObject );
        notifyAllPlayers( readyDoc );
    }
}

// set the leader ready flag to true
// return true if both leaders are now ready
bool MindfieldsServer::processStartRequest( QTcpSocket *socket )
{
    for ( int i = 0; i < gamePlayers.size() ; ++i )
    {
        if ( gamePlayers[ i ].socket == socket )
        {
            if ( gamePlayers[ i ].role == LEADER)
            {
                if ( gamePlayers[ i ].team == BLUE )
                    blueLeaderReady = true;
                else if ( gamePlayers[ i ].team == ORANGE )
                    orangeLeaderReady = true;
            } // player is leader
        } // player found
    }

    if ( blueLeaderReady && orangeLeaderReady )
        return true;
    else
        return false;
}

// assign player to team
void MindfieldsServer::processTeamRequest( QString team, QTcpSocket *socket)
{
    QJsonObject jsonResponse;
    jsonResponse.insert("type", "teamresponse");

    for ( int i = 0 ; i < gamePlayers.size() ; ++i )
    {
        if ( gamePlayers[ i ].socket == socket )
        {
            if ( team == QString( "blue" ) )
            {
                qDebug() << "Blue team requested";
                jsonResponse.insert("team", "blue");
                if ( blueTeamCount < 4 )
                {
                    qDebug() << "Assigning blue team";
                    gamePlayers[ i ].team = BLUE;
                    jsonResponse.insert("response", "accepted");
                    jsonResponse.insert("leader",blueLeader);
                    blueTeamCount++;
                }
                else
                    jsonResponse.insert("response", "teamfull");
            }
            else if ( team == QString( "orange" ) )
            {
                jsonResponse.insert("team", "orange");
                if ( orangeTeamCount < 4 )
                {
                    gamePlayers[ i ].team = ORANGE;
                    jsonResponse.insert("response", "accepted");
                    jsonResponse.insert("leader", orangeLeader );
                    orangeTeamCount++;
                }
                else
                    jsonResponse.insert("response", "teamfull");
            }
            QJsonDocument responseDoc( jsonResponse );
            socket->write( responseDoc.toJson() );
            break;
        }
    }
    if ( debugMode )
        printPlayers();

    // Send player list to all connected players
    notifyAllPlayers( generatePlayerList() );
}

// write the key word array to all of the players
void MindfieldsServer::publishKeyWords()
{
    QJsonObject json;
    QJsonArray jsonArrayBlue;
    QJsonArray jsonArrayOrange;

    json.insert("type", "keywordlist");

    foreach ( QString word, blueTeamWords )
    {
        jsonArrayBlue.append( word );
    }

    foreach ( QString word, orangeTeamWords )
    {
        jsonArrayOrange.append( word );
    }

    json.insert( "bluewords", jsonArrayBlue );
    json.insert( "orangewords" , jsonArrayOrange );

    QJsonDocument doc(json);
    if ( !gamePlayers.isEmpty() )
        foreach ( Player player, gamePlayers )
        {
            if ( player.role == LEADER && player.socket->isOpen() )
                player.socket->write(doc.toJson());
        }
}

// write the public word array to all of the players
void MindfieldsServer::publishPublicWords()
{
    QJsonObject json;
    QJsonArray jsonArray;
    json.insert("type", "wordlist");
    foreach ( QString word, wordList )
    {
        jsonArray.append(word);
    }
    json.insert("wordlist", jsonArray);

    QJsonDocument doc(json);

    if ( !gamePlayers.isEmpty() )
        foreach ( Player player, gamePlayers )
        {
            if ( player.socket->isOpen() )
                player.socket->write(doc.toJson());
        }
}

// send hint and state change notice to all players
void MindfieldsServer::publishHint( QString hint )
{
    QJsonObject jsonMessage;
    jsonMessage.insert( "type", "statechange");
    jsonMessage.insert( "newstate", "awaitingguess");
    jsonMessage.insert( "team", ( currentTurn == BLUE ? "blue" : "orange") );
    jsonMessage.insert( "reason", "newhint" );
    jsonMessage.insert( "hint", hint );
    jsonMessage.insert( "count", guessCount );
    QJsonDocument responseDoc( jsonMessage );

    notifyAllPlayers( responseDoc );
}

// read dict.txt
void MindfieldsServer::readDictionary()
{
    // try to open dict.txt
    QFile dictFile( "dict.txt" );
    if ( !dictFile.open( QIODevice::ReadOnly | QIODevice::Text ) )
    {
        qDebug() << "Dictionary file could not be opened\n";
        return;
    }
    while ( !dictFile.atEnd() )
    {
        QByteArray word = dictFile.readLine();
        word.chop( 1 ); // remove last byte (endline?)
        dictionary.append(QString(word).toUpper()); // uppercase all words
    }

    if ( debugMode )
        qDebug() << dictionary.size() << " words read";
}

// handle timeouts
void MindfieldsServer::serviceTimer()
{
    int newTime = turnTime;

    // stop timer
    gameTimer->stop();

    QJsonObject jsonMessage;
    jsonMessage.insert("type", "statechange");

    // what happens next depends on the current state:
    switch ( gameState )
    {
    case WORDS_PRESENTED:
        // this is where we start the very first turn.
        // tell all players the leader of the team has one minute to come up with
        // a hint
        gameState = AWAITING_HINT;
        jsonMessage.insert("newstate", "awaitinghint");
        newTime = turnTime;
        break;
    case AWAITING_HINT: // time's up for the blue leader to submit a hint.
    case AWAITING_GUESS: // time's up for blue team members to submit guesses
        // switch over to orange hint
        switchTeams();
        gameState = AWAITING_HINT;
        jsonMessage.insert("newstate", "awaitinghint");
        newTime = turnTime;
        break;
    case GUESS_REVEALED: // guess has been published to all players
        // we are out of guesses OR there was an incorrect answer
        if ( guessCount < 1 || !correctGuess )
        {
            switchTeams(); // flip currentTurn between BLUE and ORANGE
            gameState = AWAITING_HINT;
            jsonMessage.insert("newstate", "awaitinghint");
            newTime = turnTime;
        }
        else if ( blueCardsLeft < 1 || orangeCardsLeft < 1 ) // somebody just won
        {
            gameState = GAME_OVER;
            jsonMessage.insert("newstate", "gameover");
            if ( blueCardsLeft < 1 ) // BLUE WINS
            {
                jsonMessage.insert( "winner", "blue" );

            }
            else if ( orangeCardsLeft < 1 ) // ORANGE WINS
            {
                jsonMessage.insert( "winner", "orange" );
            }
        }
        else // we still have guesses left and nobody has won yet
        {
            // keep waiting
            gameState = AWAITING_GUESS;
            jsonMessage.insert("newstate", "awaitingguess");
            newTime = timeLeft;
        }
        break;
    default:
        break;
    }

    jsonMessage.insert("team", ( currentTurn == BLUE ? "blue" : "orange" ));

    // send message to players
    QJsonDocument jsonDoc( jsonMessage );
    notifyAllPlayers( jsonDoc );

    // restart timer
    switch ( gameState )
    {
    case AWAITING_HINT:
    case AWAITING_GUESS:
    {
        QJsonObject jsonBroadcast;
        jsonBroadcast.insert("type", "timerstart");
        jsonBroadcast.insert("time", newTime / 1000 );
        QJsonDocument broadcastDoc( jsonBroadcast );
        notifyAllPlayers( broadcastDoc );

        if ( debugMode )
            qDebug() << "Timer started: " << newTime / 1000 << " seconds.";
    }
        gameTimer->start( newTime );
        break;
    default:
        break;
    }
}

// generate word list and publish to all players
void MindfieldsServer::setupFirstTurn()
{
    // read dictionary
    readDictionary();

    // generate word list
    generateWordList( totalCards );

    // pick starting team: currentTurn becomes BLUE or ORANGE
    currentTurn = static_cast<Team>( qrand() % 2 );

    // assign words to teams and set amount of cards left to guess for each team
    QVector< QString > tempList = wordList;
    if ( currentTurn == BLUE ) // blue team goes first and gets more cards
    {
        while ( blueTeamWords.size() < cardsFirstTeam )
        {
            const int randomDraw = qrand() % tempList.size();
            blueTeamWords.append( tempList.at( randomDraw ) );
            tempList.remove( randomDraw );
        }

        while ( orangeTeamWords.size() < cardsSecondTeam )
        {
            const int randomDraw = qrand() % tempList.size();
            orangeTeamWords.append( tempList.at( randomDraw ) );
            tempList.remove( randomDraw );
        }
        blueCardsLeft = cardsFirstTeam;
        orangeCardsLeft = cardsSecondTeam;
    }
    else // orange team goes first and gets more cards
    {
        while ( orangeTeamWords.size() < cardsFirstTeam )
        {
            const int randomDraw = qrand() % tempList.size();
            orangeTeamWords.append( tempList.at( randomDraw ) );
            tempList.remove( randomDraw );
        }

        while ( blueTeamWords.size() < cardsSecondTeam )
        {
            const int randomDraw = qrand() % tempList.size();
            blueTeamWords.append( tempList.at( randomDraw ) );
            tempList.remove( randomDraw );
        }
        orangeCardsLeft = cardsFirstTeam;
        blueCardsLeft = cardsSecondTeam;
    }

    // print game words
    foreach ( QString word, wordList )
    {
        QString output;
        output.append(word);
        if ( blueTeamWords.contains( word ) )
        {
            output.append( " [BLUE]" );
        }
        else if ( orangeTeamWords.contains( word ) )
        {
            output.append(" [ORANGE]");
        }
        qDebug () << output;
    }

    // distribute public words
    publishPublicWords();

    // distribute key words
    publishKeyWords();

    // set WORDS_PRESENTED state
    gameState = WORDS_PRESENTED;

    QJsonObject jsonState;
    jsonState.insert( "type", "statechange" );
    jsonState.insert( "newstate", "wordsdisplayed" );
    QJsonDocument stateDoc( jsonState );
    notifyAllPlayers( stateDoc );

    // start timer
    QJsonObject jsonBroadcast;
    jsonBroadcast.insert( "type", "timerstart" );
    jsonBroadcast.insert( "time", turnTime / 1000 );
    QJsonDocument broadcastDoc( jsonBroadcast );
    notifyAllPlayers( broadcastDoc );

    if ( debugMode )
        qDebug() << "Timer started: " << turnTime / 1000 << " seconds.";

    gameTimer->start( turnTime );
}

// toggle currentTurn
void MindfieldsServer::switchTeams()
{
    if ( currentTurn == BLUE )
        currentTurn = ORANGE;
    else if (currentTurn == ORANGE )
        currentTurn = BLUE;
}
