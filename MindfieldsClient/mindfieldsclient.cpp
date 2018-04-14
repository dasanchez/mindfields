#include "mindfieldsclient.h"
#include "ui_mindfieldsclient.h"

MindfieldsClient::MindfieldsClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MindfieldsClient)
{
    ui->setupUi( this );
    p1Socket = new QTcpSocket( this );
    p2Socket = new QTcpSocket( this );
    p3Socket = new QTcpSocket( this );
    p4Socket = new QTcpSocket( this );

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

    connect( p1Socket, SIGNAL( readyRead() ), this, SLOT( dataReceived() ) );
    connect( p2Socket, SIGNAL( readyRead() ), this, SLOT( dataReceived() ) );
    connect( p3Socket, SIGNAL( readyRead() ), this, SLOT( dataReceived() ) );
    connect( p4Socket, SIGNAL( readyRead() ), this, SLOT( dataReceived() ) );
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
        p1Socket->disconnectFromHost();
    else if ( senderButton == ui->p2DisconnectButton )
        p2Socket->disconnectFromHost();
    else if ( senderButton == ui->p3DisconnectButton )
        p3Socket->disconnectFromHost();
    else if ( senderButton == ui->p4DisconnectButton )
        p4Socket->disconnectFromHost();
}

void MindfieldsClient::connectSocket()
{
    QPushButton *senderButton = qobject_cast<QPushButton *>( QObject::sender() );
    if ( senderButton == ui->p1ConnectButton )
        p1Socket->connectToHost( QHostAddress::LocalHost, ui->p1PortBox->value() );
    else if ( senderButton == ui->p2ConnectButton )
        p2Socket->connectToHost( QHostAddress::LocalHost, ui->p2PortBox->value() );
    else if ( senderButton == ui->p3ConnectButton )
        p3Socket->connectToHost( QHostAddress::LocalHost, ui->p3PortBox->value() );
    else if ( senderButton == ui->p4ConnectButton )
        p4Socket->connectToHost( QHostAddress::LocalHost, ui->p4PortBox->value() );
}

void MindfieldsClient::socketConnected()
{
    QTcpSocket *senderSocket = qobject_cast<QTcpSocket *>( QObject::sender() );

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
    QTcpSocket *senderSocket = qobject_cast<QTcpSocket *>( QObject::sender() );

    if ( senderSocket == p1Socket )
        ui->p1MessageBox->appendPlainText(QString("Socket disconnected"));
    else if ( senderSocket == p2Socket )
        ui->p2MessageBox->appendPlainText( QString( "Socket disconnected") );
    else if ( senderSocket == p3Socket )
        ui->p3MessageBox->appendPlainText( QString( "Socket disconnected") );
    else if ( senderSocket == p4Socket )
        ui->p4MessageBox->appendPlainText( QString( "Socket disconnected") );
}

void MindfieldsClient::dataReceived()
{
    QTcpSocket *senderSocket = qobject_cast<QTcpSocket *>( QObject::sender() );

    if ( senderSocket == p1Socket )
    {
        while ( p1Socket->bytesAvailable() > 0 )
        {
            QByteArray data = p1Socket->readAll();
            qDebug() << "p1> " << data;
            ui->p1MessageBox->appendPlainText( QString( data ) );
        }
    }
    else if ( senderSocket == p2Socket )
    {
        while ( p2Socket->bytesAvailable() > 0 )
        {
            QByteArray data = p2Socket->readAll();
            qDebug() << "p2> " << data;
            ui->p2MessageBox->appendPlainText( QString( data ) );
        }
    }
    else if ( senderSocket == p3Socket )
    {
        while ( p3Socket->bytesAvailable() > 0 )
        {
            QByteArray data = p3Socket->readAll();
            qDebug() << "p3> " << data;
            ui->p3MessageBox->appendPlainText( QString( data ) );
        }
    }
    else if ( senderSocket == p4Socket )
    {
        while ( p4Socket->bytesAvailable() > 0 )
        {
            QByteArray data = p4Socket->readAll();
            qDebug() << "p4> " << data;
            ui->p4MessageBox->appendPlainText( QString( data ) );
        }
    }


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
        if ( p1Socket->isOpen() )
        {
            p1Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p2SendButton )
    {
        json.insert( "type", ui->p2TypeEdit->text() );
        json.insert( ui->p2Key1Edit->text(), ui->p2Value1Edit->text() );
        json.insert( ui->p2Key2Edit->text(), ui->p2Value2Edit->text() );
        QJsonDocument jsonDoc(json);
        if ( p2Socket->isOpen() )
        {
            p2Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p3SendButton )
    {
        json.insert( "type", ui->p3TypeEdit->text() );
        json.insert( ui->p3Key1Edit->text(), ui->p3Value1Edit->text() );
        json.insert( ui->p3Key2Edit->text(), ui->p3Value2Edit->text() );
        QJsonDocument jsonDoc(json);
        if ( p3Socket->isOpen() )
        {
            p3Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p4SendButton )
    {
        json.insert( "type", ui->p4TypeEdit->text() );
        json.insert( ui->p4Key1Edit->text(), ui->p4Value1Edit->text() );
        json.insert( ui->p4Key2Edit->text(), ui->p4Value2Edit->text() );
        QJsonDocument jsonDoc(json);
        if ( p4Socket->isOpen() )
        {
            p4Socket->write( jsonDoc.toJson() );
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
        if ( p1Socket->isOpen() )
        {
            p1Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p2PlayerButton )
    {
        json.insert( "name", ui->p2NameEdit->text() );
        QJsonDocument jsonDoc(json);
        if ( p2Socket->isOpen() )
        {
            p2Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p3PlayerButton )
    {
        json.insert( "name", ui->p3NameEdit->text() );
        QJsonDocument jsonDoc(json);
        if ( p3Socket->isOpen() )
        {
            p3Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p4PlayerButton )
    {
        json.insert( "name", ui->p4NameEdit->text() );
        QJsonDocument jsonDoc(json);
        if ( p4Socket->isOpen() )
        {
            p4Socket->write( jsonDoc.toJson() );
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
        if ( p1Socket->isOpen() )
        {
            p1Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p1OrangeButton )
    {
        json.insert( "team", "orange" );
        QJsonDocument jsonDoc(json);
        if ( p1Socket->isOpen() )
        {
            p1Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p2BlueButton )
    {
        json.insert( "team", "blue" );
        QJsonDocument jsonDoc(json);
        if ( p2Socket->isOpen() )
        {
            p2Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p2OrangeButton )
    {
        json.insert( "team", "orange" );
        QJsonDocument jsonDoc(json);
        if ( p2Socket->isOpen() )
        {
            p2Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p3BlueButton )
    {
        json.insert( "team", "blue" );
        QJsonDocument jsonDoc(json);
        if ( p3Socket->isOpen() )
        {
            p3Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p3OrangeButton )
    {
        json.insert( "team", "orange" );
        QJsonDocument jsonDoc(json);
        if ( p3Socket->isOpen() )
        {
            p3Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p4BlueButton )
    {
        json.insert( "team", "blue" );
        QJsonDocument jsonDoc(json);
        if ( p4Socket->isOpen() )
        {
            p4Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p4OrangeButton )
    {
        json.insert( "team", "orange" );
        QJsonDocument jsonDoc(json);
        if ( p4Socket->isOpen() )
        {
            p4Socket->write( jsonDoc.toJson() );
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
        if ( p1Socket->isOpen() )
        {
            p1Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p1MemberButton )
    {
        json.insert( "role", "member" );
        QJsonDocument jsonDoc(json);
        if ( p1Socket->isOpen() )
        {
            p1Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p2LeaderButton )
    {
        json.insert( "role", "leader" );
        QJsonDocument jsonDoc(json);
        if ( p2Socket->isOpen() )
        {
            p2Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p2MemberButton )
    {
        json.insert( "role", "member" );
        QJsonDocument jsonDoc(json);
        if ( p2Socket->isOpen() )
        {
            p2Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p3LeaderButton )
    {
        json.insert( "role", "leader" );
        QJsonDocument jsonDoc(json);
        if ( p3Socket->isOpen() )
        {
            p3Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p3MemberButton )
    {
        json.insert( "role", "member" );
        QJsonDocument jsonDoc(json);
        if ( p3Socket->isOpen() )
        {
            p3Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p4LeaderButton )
    {
        json.insert( "role", "leader" );
        QJsonDocument jsonDoc(json);
        if ( p4Socket->isOpen() )
        {
            p4Socket->write( jsonDoc.toJson() );
        }
    }
    else if ( senderButton == ui->p4MemberButton )
    {
        json.insert( "role", "member" );
        QJsonDocument jsonDoc(json);
        if ( p4Socket->isOpen() )
        {
            p4Socket->write( jsonDoc.toJson() );
        }
    }
}
