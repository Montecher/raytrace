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

void render(std::string name, Scene* scene) {
    std::fstream fs;
    fs.open("out/"+name+".bmp", std::fstream::out);
    fs << scene->cam()->render_realistic(scene->scene(), SIZE, SIZE, RPP).to_bmp();
    fs.close();
    std::cout << "rendered " << name << std::endl;
}

int main() {
    for(auto it=Scene::getScenes()->begin(); it!=Scene::getScenes()->end(); ++it) render(it->first, it->second);
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
