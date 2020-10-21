#include <QApplication>
#include <QMetaType>
#include "Window.hh"
#include "Image.h"

/*
#include <fstream>
#include "Cam.h"
#include "scenes.h"

#define SIZE 480
#define RPP 500

void render(std::string file, Object* scene) {
    Cam* cam = new Cam();
    cam->setPos(Vec3::Z*3. - Vec3::X*5.);
    cam->setPointing(Vec3::O);

    std::fstream fs;
    fs.open(file, std::fstream::out);
    fs << cam->render_realistic(scene, SIZE, SIZE, RPP).to_bmp();
    fs.close();

    delete cam;
}

int main() {
    render("out/scene1.bmp", SCENE::scene1());
    render("out/scene2.bmp", SCENE::scene2());
    render("out/scene3.bmp", SCENE::scene3());
    return 0;
}
*/


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qRegisterMetaType<Image>();

    Window window;
    window.show();

    return app.exec();
}

