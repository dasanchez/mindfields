#include "mindfieldsclientsim.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MindfieldsClientSim w;
    w.show();

    return a.exec();
}
