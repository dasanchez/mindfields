#ifndef MINDFIELDSCLIENT_H
#define MINDFIELDSCLIENT_H

#include <QWidget>
#include <QTcpSocket>
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
    void connectToServer();
    void dataReceived();
    void socketDisconnected();
    void socketConnected();
    void sendData();
    void sendPlayerRequest();
    void sendTeamRequest();
    void sendRoleRequest();
    void disconnectSocket();

private:
    Ui::MindfieldsClient *ui;
    QTcpSocket *tcpSocket = nullptr;

};

#endif // MINDFIELDSCLIENT_H
