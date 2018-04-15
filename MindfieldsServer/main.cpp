#include <QCoreApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include "mindfieldsserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication app( argc, argv );

    unsigned int port = 8888;
    bool webSockets = false;
    bool debug = false;

    QCommandLineParser parser;
    QCommandLineOption portOption( "p" ,
                                   QCoreApplication::translate("main", "Listen on <port>."),
                                   QCoreApplication::translate("main", "port"));
    QCommandLineOption wsOption( "w" ,
                                 QCoreApplication::translate("main", "Enable WebSockets"));

    QCommandLineOption debugOption( "d" ,
                                 QCoreApplication::translate("main", "Debug mode"));

    parser.addOption( portOption );
    parser.addOption( wsOption );
    parser.addOption( debugOption );
    parser.process( app );

    // set port if command line argument is present
    if ( parser.isSet( portOption ) )
    {
        QString portStr = parser.value( portOption );
        qDebug() << "Server will listen to port " << portStr;
        port = portStr.toInt();
    }

    if ( parser.isSet( wsOption ) )
    {
        qDebug() << "Server will use WebSockets";
        webSockets = true;
    }

    if ( parser.isSet( debugOption ) )
    {
        qDebug() << "Server will run in debug mode";
        debug = true;
    }

    MindfieldsServer mServer( 0, port, webSockets, debug );

    return app.exec();
}
