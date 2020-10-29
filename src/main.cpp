#include <QApplication>
#include <QMetaType>
#include "Window.hh"
#include "Image.h"

/*
#include <fstream>
#include "Cam.h"
#include "scenes.h"

#undef RPP
#undef DEPTH
#define SIZE 480
#define RPP 500
#define DEPTH 10

void render(std::string name, Scene* scene) {
    std::fstream fs;
    fs.open("out/"+name+".bmp", std::fstream::out);
    fs << scene->cam()->render_realistic(scene->scene(), SIZE, SIZE, RPP, DEPTH).to_bmp();
    fs.close();
    std::cout << "rendered " << name << std::endl;
}

void justRender(std::string name) {
    render(name, Scene::getScene(name));
}

int main() {
    justRender("scene A");
    for(auto it=Scene::getScenes()->begin(); it!=Scene::getScenes()->end(); ++it) render(it->first, it->second);
    return 0;
}
//*/


//*
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qRegisterMetaType<Image>();

    Window window;
    window.show();

    return app.exec();
}
//*/
