#include "myqgsettings.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyQGSettings w;
    w.show();

    return a.exec();
}
