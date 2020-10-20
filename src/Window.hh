#ifndef RAYTRACE_WINDOW_HH
#define RAYTRACE_WINDOW_HH

#include <QApplication>
#include <QtWidgets>
#include "Cam.h"
#include "Renderer.hh"

class Window : public QWidget {
    Q_OBJECT

private:
    QImage *image;
    QLabel *label;
    QPushButton *toggleRealistic;

    Cam *camera;
    Object *scene;
    RendererThread *renderer;


public:
    Window();

private slots:
    void loadSCene(int);
    void test(int);
    void createImage();
    void setImage(Image);

signals:
    void showImage(QPixmap);
};

#endif //RAYTRACE_WINDOW_HH
