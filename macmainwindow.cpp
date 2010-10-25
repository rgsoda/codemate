#include <QtGui>
#include "macmainwindow.h"

#ifdef Q_WS_MAC

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    MacMainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}

#else
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QLabel label;
    label.resize(300, 200);
    label.setText(" This demo requires Mac OS X.");
    label.show();
    return app.exec();
}

#endif
