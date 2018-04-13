#include <QCoreApplication>
#include "mindfieldsserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MindfieldsServer mServer;

    return a.exec();
}
