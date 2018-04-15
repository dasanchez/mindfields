#ifndef MINDFIELDSCLIENT_H
#define MINDFIELDSCLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QUrl>
#include <QtWebSockets/QWebSocketServer>
#include <QtWebSockets/QWebSocket>
#include <QHostAddress>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

namespace Ui {
class MindfieldsClient;
}

class MindfieldsClient : public QWidget
{
    Q_OBJECT

public:
    explicit MindfieldsClient(QWidget *parent = 0);
    ~MindfieldsClient();

public slots:
    void connectSocket();
    void disconnectSocket();
    void socketConnected();
    void socketDisconnected();
    void sendData( );
    void dataReceived( QString );
    void sendPlayerRequest();
    void sendTeamRequest( );
    void sendRoleRequest( );

private:
    Ui::MindfieldsClient *ui;
//    QTcpSocket *p1Socket = nullptr;
//    QTcpSocket *p2Socket = nullptr;
//    QTcpSocket *p3Socket = nullptr;
//    QTcpSocket *p4Socket = nullptr;
    QWebSocket *p1Socket;
    QWebSocket *p2Socket;
    QWebSocket *p3Socket;
    QWebSocket *p4Socket;


};

#endif // MINDFIELDSCLIENT_H
