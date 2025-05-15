#include "TMainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    TMainWindow window;
    window.show();
    return application.exec();
}
