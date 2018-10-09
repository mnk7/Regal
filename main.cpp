#include "regal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Regal w;
    w.show();

    return a.exec();
}
