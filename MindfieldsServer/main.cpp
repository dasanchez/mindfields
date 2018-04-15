#include <QCoreApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include "mindfieldsserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication app( argc, argv );

    unsigned int port = 8888;

    QCommandLineParser parser;
    QCommandLineOption portOption( "p" ,
                                   QCoreApplication::translate("main", "Listen on <port>."),
                                   QCoreApplication::translate("main", "port"));
    parser.addOption( portOption );
    parser.process( app );

    // set port if command line argument is present
    if ( parser.isSet( portOption ) )
    {
        QString portStr = parser.value( portOption );
        qDebug() << "Server will listen to port " << portStr;
        port = portStr.toInt();
    }

    MindfieldsServer mServer( 0, port );

    return app.exec();
}
