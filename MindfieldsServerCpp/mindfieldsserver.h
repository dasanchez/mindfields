#ifndef MINDFIELDSSERVER_H
#define MINDFIELDSSERVER_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QDebug>
#include <QTcpServer>
#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QWebSocket>
#include <QHostAddress>
#include <QDataStream>
#include <QTcpSocket>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDateTime>
#include <QList>
#include <QTimer>

class MindfieldsServer : public QObject
{
    Q_OBJECT
public:
    explicit MindfieldsServer( QObject *parent = nullptr,
                               unsigned int port = 8888,
                               bool webSockets = false,
                               bool debug = false );

    enum Role { LEADER, MEMBER};
    enum Team { BLUE, ORANGE, NEUTRAL };
    enum GameState { LOBBY, WORDS_PRESENTED, HINT_APPROVAL, GAME_OVER,
                     AWAITING_HINT, AWAITING_GUESS, GUESS_REVEALED };

    static const int totalCards = 16;
    static const int cardsFirstTeam = 7;
    static const int cardsSecondTeam = 6;
    static const int turnTime = 60000; // milliseconds
    static const int msgTime = 3000; // milliseconds

    class Player{
    public:
        QString     name;
        Team        team;
        Role        role;
        bool        ready;
        QTcpSocket *socket;
        QWebSocket *wSocket;
    };

private slots:
    void processConnection();
    void processClientData();
    void processWSData(QString);
    void serviceTimer();
    void clientDisconnected();

private:
    QTcpServer *tcpServer; // main server object to handle incoming connections
    QWebSocketServer *wsServer;
    QVector< QString > dictionary; // all the words pulled from dictionary
    QVector< QString > wordList; // words pulled at random from the dictionary to make up the full grid
    QVector< QString > blueTeamWords; // words belonging to blue team
    QVector< QString > orangeTeamWords; // words belonging to orange team
    QVector< QString > guessedWords; // words already guessed
    QVector< Player > gamePlayers; // list of Players- Player includes name, team, role, and socket
    QVector< QString > hints; // hint history
    bool debugMode = false; // print debug messages
    bool webSocketsMode = false; // enable websockets
    bool blueLeader = false; // has the blue leader role been assigned
    bool orangeLeader = false; // has the orange leader role been assigned
    int blueTeamCount = 0; // number of players in blue team
    int orangeTeamCount = 0; // number of players in orange team
    bool blueLeaderReady = false; // blue leader is ready to start
    bool orangeLeaderReady = false; //  orange leader is ready to start
    bool correctGuess = false;
    QString proposedHint; // hint waiting to be approved
    int guessCount;
    Team firstTurn; // BLUE or ORANGE
    Team currentTurn; // BLUE or ORANGE
    int blueCardsLeft;
    int orangeCardsLeft;

    QTimer *gameTimer;
    int timeLeft;

    GameState gameState = LOBBY; // controls server responses

    void newSession( unsigned int ); // open server port to incoming connections
    void readDictionary(); // read dict.txt file
    void generateWordList( quint8 ); // pull words from dictionary
    bool isNameTaken( QString ); // check if name is already in use
    void makeNewPlayer( QString, QTcpSocket * ); // create new Player object
    void makeNewPlayer( QString, QWebSocket * );
    void processNewPlayer( QString, QTcpSocket * ); // respond to new player request
    void processNewPlayer( QString, QWebSocket * );
    void processTeamRequest( QString, QTcpSocket * ); // assign player to a team
    void processTeamRequest( QString, QWebSocket * );
    void processRoleRequest( QString, QTcpSocket * ); // assign player role
    void processRoleRequest( QString, QWebSocket * );
    bool processStartRequest( QTcpSocket * ); // a team leader is ready to start
    bool processStartRequest( QWebSocket *);
    void setupFirstTurn(); // create word list, assign key words, and publish to all players
    void publishPublicWords(); // distribute public word list
    void publishKeyWords(); // distribute key word list
    void notifyAllPlayers( QJsonDocument ); // publish message to all connected players
    void notifyTeamLeaders( QJsonDocument ); // publish message to team leaders
    void hintReceived( QString, QTcpSocket * ); // process received hint
    void hintReceived( QString, QWebSocket * );
    bool hintResponse( QString, QTcpSocket * ); // process opposing leader response
    bool hintResponse( QString, QWebSocket * );
    void publishHint( QString ); // distribute hint to all players
    bool processGuess( QString, QTcpSocket * ); // process incoming guess
    bool processGuess( QString, QWebSocket * );
    void switchTeams(); // toggle currentTurn
    void printPlayers(); // output player list
    bool isLeader( QTcpSocket * );
    bool isLeader( QWebSocket * );
    bool isPlayer( QTcpSocket * ); // check if the sender is already in the list of players
    bool isPlayer( QWebSocket * );
    QString getPlayerName( QTcpSocket * );
    QString getPlayerName( QWebSocket * );
    QJsonDocument generatePlayerList();

signals:

public slots:
};

#endif // MINDFIELDSSERVER_H
