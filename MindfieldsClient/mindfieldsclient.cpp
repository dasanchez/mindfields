#include "mindfieldsclient.h"
#include "ui_mindfieldsclient.h"

MindfieldsClient::MindfieldsClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MindfieldsClient)
{
    ui->setupUi( this );
    tcpSocket = new QTcpSocket( this );
    connect(ui->connectButton, SIGNAL( clicked( bool ) ), this, SLOT( connectToServer() ) );
    connect(ui->disconnectButton, SIGNAL(clicked(bool)), this, SLOT(disconnectSocket()));
    connect( tcpSocket, SIGNAL( readyRead() ), this, SLOT( dataReceived() ) );
    connect( tcpSocket, SIGNAL( connected() ), this, SLOT( socketConnected() ) );
    connect( tcpSocket, SIGNAL( disconnected() ), this, SLOT( socketDisconnected() ) );
    connect( ui->sendDataButton, SIGNAL( clicked(bool) ), this, SLOT( sendData() ) );
    connect( ui->playerButton, SIGNAL(clicked(bool)), this, SLOT(sendPlayerRequest()));
    connect( ui->teamButton, SIGNAL(clicked(bool)), this, SLOT(sendTeamRequest()));
    connect( ui->roleButton, SIGNAL(clicked(bool)), this, SLOT(sendRoleRequest()));
}

MindfieldsClient::~MindfieldsClient()
{
    delete ui;
}

void MindfieldsClient::disconnectSocket()
{
    tcpSocket->disconnectFromHost();
}

void MindfieldsClient::connectToServer()
{
    tcpSocket->connectToHost( QHostAddress::LocalHost, ui->portBox->value() );
}

void MindfieldsClient::socketConnected()
{
    ui->messageBox->appendPlainText(QString("Socket connected"));
}

void MindfieldsClient::socketDisconnected()
{
    ui->messageBox->appendPlainText(QString("Socket disconnected"));
}

void MindfieldsClient::dataReceived()
{
    while ( tcpSocket->bytesAvailable() > 0 )
    {
        QByteArray data = tcpSocket->readAll();
        qDebug() << data;

        ui->messageBox->appendPlainText(QString(data));
    }
}

void MindfieldsClient::sendData()
{
    QJsonObject json;
    json.insert( "type", ui->typeEdit->text() );
    json.insert( ui->keyEdit->text(), ui->valueEdit->text() );

    QJsonDocument jsonDoc(json);

    if ( tcpSocket->isOpen() )
    {
        tcpSocket->write( jsonDoc.toJson() );
    }
}

void MindfieldsClient::sendPlayerRequest()
{
    QJsonObject json;
    json.insert( "type", "newplayerrequest" );
    json.insert( "name", "synch" );

    QJsonDocument jsonDoc(json);

    if ( tcpSocket->isOpen() )
    {
        tcpSocket->write( jsonDoc.toJson() );
    }
}

void MindfieldsClient::sendTeamRequest()
{
    QJsonObject json;
    json.insert( "type", "teamrequest" );
    json.insert( "team", "blue" );

    QJsonDocument jsonDoc(json);

    if ( tcpSocket->isOpen() )
    {
        tcpSocket->write( jsonDoc.toJson() );
    }
}

void MindfieldsClient::sendRoleRequest()
{
    QJsonObject json;
    json.insert( "type", "rolerequest" );
    json.insert( "role", "leader" );

    QJsonDocument jsonDoc(json);

    if ( tcpSocket->isOpen() )
    {
        tcpSocket->write( jsonDoc.toJson() );
    }
}
