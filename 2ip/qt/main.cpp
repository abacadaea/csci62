#include "examplewindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExampleWindow w;
    w.show();
    return a.exec();
}
