#ifndef MINDFIELDSCLIENTSIM_H
#define MINDFIELDSCLIENTSIM_H

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
class MindfieldsClientSim;
}

class MindfieldsClientSim : public QWidget
{
    Q_OBJECT

public:
    explicit MindfieldsClientSim(QWidget *parent = 0);
    ~MindfieldsClientSim();

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
    Ui::MindfieldsClientSim *ui;
//    QTcpSocket *p1Socket = nullptr;
//    QTcpSocket *p2Socket = nullptr;
//    QTcpSocket *p3Socket = nullptr;
//    QTcpSocket *p4Socket = nullptr;
    QWebSocket *p1Socket;
    QWebSocket *p2Socket;
    QWebSocket *p3Socket;
    QWebSocket *p4Socket;


};

#endif // MINDFIELDSCLIENTSIM_H
