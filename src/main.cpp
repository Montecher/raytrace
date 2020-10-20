#include <QApplication>
#include <QMetaType>
#include "Window.hh"
#include "Image.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qRegisterMetaType<Image>();

    Window window;
    window.show();

    return app.exec();
}
