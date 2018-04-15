#include "mindfieldsclient.h"
#include "ui_mindfieldsclient.h"

MindfieldsClient::MindfieldsClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MindfieldsClient)
{
    ui->setupUi( this );
    //    p1Socket = new QTcpSocket( this );
    //    p2Socket = new QTcpSocket( this );
    //    p3Socket = new QTcpSocket( this );
    //    p4Socket = new QTcpSocket( this );
    p1Socket = new QWebSocket;
    p2Socket = new QWebSocket;
    p3Socket = new QWebSocket;
    p4Socket = new QWebSocket;

    connect( ui->p1ConnectButton, SIGNAL( clicked( bool ) ), this, SLOT( connectSocket() ) );
    connect( ui->p2ConnectButton, SIGNAL( clicked( bool ) ), this, SLOT( connectSocket() ) );
    connect( ui->p3ConnectButton, SIGNAL( clicked( bool ) ), this, SLOT( connectSocket() ) );
    connect( ui->p4ConnectButton, SIGNAL( clicked( bool ) ), this, SLOT( connectSocket() ) );
    connect( ui->p1DisconnectButton, SIGNAL( clicked( bool ) ), this, SLOT( disconnectSocket() ) );
    connect( ui->p2DisconnectButton, SIGNAL( clicked( bool ) ), this, SLOT( disconnectSocket() ) );
    connect( ui->p3DisconnectButton, SIGNAL( clicked( bool ) ), this, SLOT( disconnectSocket() ) );
    connect( ui->p4DisconnectButton, SIGNAL( clicked( bool ) ), this, SLOT( disconnectSocket() ) );
    connect( ui->p1SendButton, SIGNAL( clicked( bool ) ), this, SLOT( sendData() ) );
    connect( ui->p2SendButton, SIGNAL( clicked( bool ) ), this, SLOT( sendData() ) );
    connect( ui->p3SendButton, SIGNAL( clicked( bool ) ), this, SLOT( sendData() ) );
    connect( ui->p4SendButton, SIGNAL( clicked( bool ) ), this, SLOT( sendData() ) );
    connect( ui->p1PlayerButton, SIGNAL( clicked( bool )), this, SLOT( sendPlayerRequest() ) );
    connect( ui->p2PlayerButton, SIGNAL( clicked( bool )), this, SLOT( sendPlayerRequest() ) );
    connect( ui->p3PlayerButton, SIGNAL( clicked( bool )), this, SLOT( sendPlayerRequest() ) );
    connect( ui->p4PlayerButton, SIGNAL( clicked( bool )), this, SLOT( sendPlayerRequest() ) );
    connect( ui->p1BlueButton, SIGNAL( clicked( bool ) ), this, SLOT(sendTeamRequest( )));
    connect( ui->p2BlueButton, SIGNAL( clicked( bool ) ), this, SLOT(sendTeamRequest( )));
    connect( ui->p3BlueButton, SIGNAL( clicked( bool ) ), this, SLOT(sendTeamRequest( )));
    connect( ui->p4BlueButton, SIGNAL( clicked( bool ) ), this, SLOT(sendTeamRequest( )));
    connect( ui->p1OrangeButton, SIGNAL( clicked( bool ) ), this, SLOT(sendTeamRequest( )));
    connect( ui->p2OrangeButton, SIGNAL( clicked( bool ) ), this, SLOT(sendTeamRequest( )));
    connect( ui->p3OrangeButton, SIGNAL( clicked( bool ) ), this, SLOT(sendTeamRequest( )));
    connect( ui->p4OrangeButton, SIGNAL( clicked( bool ) ), this, SLOT(sendTeamRequest( )));
    connect( ui->p1LeaderButton, SIGNAL(clicked(bool)), this, SLOT( sendRoleRequest( ) ) );
    connect( ui->p2LeaderButton, SIGNAL(clicked(bool)), this, SLOT( sendRoleRequest( ) ) );
    connect( ui->p3LeaderButton, SIGNAL(clicked(bool)), this, SLOT( sendRoleRequest( ) ) );
    connect( ui->p4LeaderButton, SIGNAL(clicked(bool)), this, SLOT( sendRoleRequest( ) ) );
    connect( ui->p1MemberButton, SIGNAL(clicked(bool)), this, SLOT( sendRoleRequest( ) ) );
    connect( ui->p2MemberButton, SIGNAL(clicked(bool)), this, SLOT( sendRoleRequest( ) ) );
    connect( ui->p3MemberButton, SIGNAL(clicked(bool)), this, SLOT( sendRoleRequest( ) ) );
    connect( ui->p4MemberButton, SIGNAL(clicked(bool)), this, SLOT( sendRoleRequest( ) ) );

    //    connect( p1Socket, SIGNAL( readyRead() ), this, SLOT( dataReceived() ) );
    //    connect( p2Socket, SIGNAL( readyRead() ), this, SLOT( dataReceived() ) );
    //    connect( p3Socket, SIGNAL( readyRead() ), this, SLOT( dataReceived() ) );
    //    connect( p4Socket, SIGNAL( readyRead() ), this, SLOT( dataReceived() ) );
    connect( p1Socket, SIGNAL( textMessageReceived( QString ) ) , this, SLOT( dataReceived( QString ) ) );
    connect( p2Socket, SIGNAL( textMessageReceived( QString ) ) , this, SLOT( dataReceived( QString ) ) );
    connect( p3Socket, SIGNAL( textMessageReceived( QString ) ) , this, SLOT( dataReceived( QString ) ) );
    connect( p4Socket, SIGNAL( textMessageReceived( QString ) ) , this, SLOT( dataReceived( QString ) ) );
    connect( p1Socket, SIGNAL( connected() ), this, SLOT( socketConnected() ) );
    connect( p2Socket, SIGNAL( connected() ), this, SLOT( socketConnected() ) );
    connect( p3Socket, SIGNAL( connected() ), this, SLOT( socketConnected() ) );
    connect( p4Socket, SIGNAL( connected() ), this, SLOT( socketConnected() ) );
    connect( p1Socket, SIGNAL( disconnected() ), this, SLOT( socketDisconnected() ) );
    connect( p2Socket, SIGNAL( disconnected() ), this, SLOT( socketDisconnected() ) );
    connect( p3Socket, SIGNAL( disconnected() ), this, SLOT( socketDisconnected() ) );
    connect( p4Socket, SIGNAL( disconnected() ), this, SLOT( socketDisconnected() ) );
}

MindfieldsClient::~MindfieldsClient()
{
    delete ui;
}

void MindfieldsClient::disconnectSocket()
{
    QPushButton *senderButton = qobject_cast<QPushButton *>( QObject::sender() );

    if ( senderButton == ui->p1DisconnectButton )
        p1Socket->close();
    else if ( senderButton == ui->p2DisconnectButton )
        p2Socket->close();
    else if ( senderButton == ui->p3DisconnectButton )
        p3Socket->close();
    else if ( senderButton == ui->p4DisconnectButton )
        p4Socket->close();
}

void MindfieldsClient::connectSocket()
{
    QPushButton *senderButton = qobject_cast<QPushButton *>( QObject::sender() );
    // build Url
    QString urlStr;
    urlStr.append("ws://localhost:");

    if ( senderButton == ui->p1ConnectButton )
    {
        urlStr.append(QString("%1").arg(ui->p1PortBox->value()));
        QUrl url(urlStr);
        p1Socket->open(url);
    }
    else if ( senderButton == ui->p2ConnectButton )
    {
        // build Url
        urlStr.append(QString("%1").arg(ui->p2PortBox->value()));
        QUrl url(urlStr);
        p2Socket->open(url);
    }
    else if ( senderButton == ui->p3ConnectButton )
    {
        // build Url
        urlStr.append(QString("%1").arg(ui->p3PortBox->value()));
        QUrl url(urlStr);
        p3Socket->open(url);
    }
    else if ( senderButton == ui->p4ConnectButton )
    {
        // build Url
        urlStr.append(QString("%1").arg(ui->p4PortBox->value()));
        QUrl url(urlStr);
        p4Socket->open(url);
    }
}

void MindfieldsClient::socketConnected()
{
    QWebSocket *senderSocket = qobject_cast<QWebSocket *>( QObject::sender() );

    if ( senderSocket == p1Socket )
        ui->p1MessageBox->appendPlainText(QString("Socket connected"));
    else if ( senderSocket == p2Socket )
        ui->p2MessageBox->appendPlainText( QString( "Socket connected") );
    else if ( senderSocket == p3Socket )
        ui->p3MessageBox->appendPlainText( QString( "Socket connected") );
    else if ( senderSocket == p4Socket )
        ui->p4MessageBox->appendPlainText( QString( "Socket connected") );
}

void MindfieldsClient::socketDisconnected()
{
    QWebSocket *senderSocket = qobject_cast<QWebSocket *>( QObject::sender() );

    if ( senderSocket == p1Socket )
        ui->p1MessageBox->appendPlainText(QString("Socket disconnected"));
    else if ( senderSocket == p2Socket )
        ui->p2MessageBox->appendPlainText( QString( "Socket disconnected") );
    else if ( senderSocket == p3Socket )
        ui->p3MessageBox->appendPlainText( QString( "Socket disconnected") );
    else if ( senderSocket == p4Socket )
        ui->p4MessageBox->appendPlainText( QString( "Socket disconnected") );
}

void MindfieldsClient::dataReceived( QString dataIn )
{
    QWebSocket *senderSocket = qobject_cast<QWebSocket *>( QObject::sender() );

    if ( senderSocket == p1Socket )
        ui->p1MessageBox->appendPlainText( dataIn );
    else if ( senderSocket == p2Socket )
        ui->p2MessageBox->appendPlainText( dataIn );
    else if ( senderSocket == p3Socket )
        ui->p3MessageBox->appendPlainText( dataIn );
    else if ( senderSocket == p4Socket )
        ui->p4MessageBox->appendPlainText( dataIn );
}

void MindfieldsClient::sendData()
{
    QPushButton *senderButton = qobject_cast<QPushButton *>( QObject::sender() );
    QJsonObject json;

    if ( senderButton == ui->p1SendButton )
    {
        json.insert( "type", ui->p1TypeEdit->text() );
        json.insert( ui->p1Key1Edit->text(), ui->p1Value1Edit->text() );
        json.insert( ui->p1Key2Edit->text(), ui->p1Value2Edit->text() );
        QJsonDocument jsonDoc(json);
        if ( p1Socket->isValid() )
        {
            p1Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p2SendButton )
    {
        json.insert( "type", ui->p2TypeEdit->text() );
        json.insert( ui->p2Key1Edit->text(), ui->p2Value1Edit->text() );
        json.insert( ui->p2Key2Edit->text(), ui->p2Value2Edit->text() );
        QJsonDocument jsonDoc(json);
        if ( p2Socket->isValid() )
        {
            p2Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p3SendButton )
    {
        json.insert( "type", ui->p3TypeEdit->text() );
        json.insert( ui->p3Key1Edit->text(), ui->p3Value1Edit->text() );
        json.insert( ui->p3Key2Edit->text(), ui->p3Value2Edit->text() );
        QJsonDocument jsonDoc(json);
        if ( p3Socket->isValid() )
        {
            p3Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p4SendButton )
    {
        json.insert( "type", ui->p4TypeEdit->text() );
        json.insert( ui->p4Key1Edit->text(), ui->p4Value1Edit->text() );
        json.insert( ui->p4Key2Edit->text(), ui->p4Value2Edit->text() );
        QJsonDocument jsonDoc(json);
        if ( p4Socket->isValid() )
        {
            p4Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
}

void MindfieldsClient::sendPlayerRequest()
{
    QPushButton *senderButton = qobject_cast<QPushButton *>( QObject::sender() );
    QJsonObject json;
    json.insert( "type", "newplayerrequest" );

    if ( senderButton == ui->p1PlayerButton )
    {
        json.insert( "name", ui->p1NameEdit->text() );
        QJsonDocument jsonDoc(json);
        if ( p1Socket->isValid() )
        {
            p1Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p2PlayerButton )
    {
        json.insert( "name", ui->p2NameEdit->text() );
        QJsonDocument jsonDoc(json);
        if ( p2Socket->isValid() )
        {
            p2Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p3PlayerButton )
    {
        json.insert( "name", ui->p3NameEdit->text() );
        QJsonDocument jsonDoc(json);
        if ( p3Socket->isValid() )
        {
            p3Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p4PlayerButton )
    {
        json.insert( "name", ui->p4NameEdit->text() );
        QJsonDocument jsonDoc(json);
        if ( p4Socket->isValid() )
        {
            p4Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
}

void MindfieldsClient::sendTeamRequest( )
{
    QJsonObject json;
    json.insert( "type", "teamrequest" );

    QPushButton *senderButton = qobject_cast<QPushButton *>( QObject::sender() );

    if ( senderButton == ui->p1BlueButton )
    {
        json.insert( "team", "blue" );
        QJsonDocument jsonDoc(json);
        if ( p1Socket->isValid() )
        {
            p1Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p1OrangeButton )
    {
        json.insert( "team", "orange" );
        QJsonDocument jsonDoc(json);
        if ( p1Socket->isValid() )
        {
            p1Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p2BlueButton )
    {
        json.insert( "team", "blue" );
        QJsonDocument jsonDoc(json);
        if ( p2Socket->isValid() )
        {
            p2Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p2OrangeButton )
    {
        json.insert( "team", "orange" );
        QJsonDocument jsonDoc(json);
        if ( p2Socket->isValid() )
        {
            p2Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p3BlueButton )
    {
        json.insert( "team", "blue" );
        QJsonDocument jsonDoc(json);
        if ( p3Socket->isValid() )
        {
            p3Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p3OrangeButton )
    {
        json.insert( "team", "orange" );
        QJsonDocument jsonDoc(json);
        if ( p3Socket->isValid() )
        {
            p3Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p4BlueButton )
    {
        json.insert( "team", "blue" );
        QJsonDocument jsonDoc(json);
        if ( p4Socket->isValid() )
        {
            p4Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p4OrangeButton )
    {
        json.insert( "team", "orange" );
        QJsonDocument jsonDoc(json);
        if ( p4Socket->isValid() )
        {
            p4Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
}

void MindfieldsClient::sendRoleRequest( )
{
    QJsonObject json;
    json.insert( "type", "rolerequest" );

    QPushButton *senderButton = qobject_cast<QPushButton *>( QObject::sender() );

    if ( senderButton == ui->p1LeaderButton )
    {
        json.insert( "role", "leader" );
        QJsonDocument jsonDoc(json);
        if ( p1Socket->isValid() )
        {
            p1Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p1MemberButton )
    {
        json.insert( "role", "member" );
        QJsonDocument jsonDoc(json);
        if ( p1Socket->isValid() )
        {
            p1Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p2LeaderButton )
    {
        json.insert( "role", "leader" );
        QJsonDocument jsonDoc(json);
        if ( p2Socket->isValid() )
        {
            p2Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p2MemberButton )
    {
        json.insert( "role", "member" );
        QJsonDocument jsonDoc(json);
        if ( p2Socket->isValid() )
        {
            p2Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p3LeaderButton )
    {
        json.insert( "role", "leader" );
        QJsonDocument jsonDoc(json);
        if ( p3Socket->isValid() )
        {
            p3Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p3MemberButton )
    {
        json.insert( "role", "member" );
        QJsonDocument jsonDoc(json);
        if ( p3Socket->isValid() )
        {
            p3Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p4LeaderButton )
    {
        json.insert( "role", "leader" );
        QJsonDocument jsonDoc(json);
        if ( p4Socket->isValid() )
        {
            p4Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
    else if ( senderButton == ui->p4MemberButton )
    {
        json.insert( "role", "member" );
        QJsonDocument jsonDoc(json);
        if ( p4Socket->isValid() )
        {
            p4Socket->sendTextMessage( QString( jsonDoc.toJson() ) );
        }
    }
}
