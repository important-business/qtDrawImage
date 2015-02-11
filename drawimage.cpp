#include <QApplication>
#include <QPainter>
#include <QWSServer>
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWSServer::setCursorVisible(false);

    MyWindow* fs_win = new MyWindow;
    fs_win->setWindowFlags(Qt::FramelessWindowHint);
    fs_win->resize(480, 272);
    fs_win->show();
    return app.exec();
}