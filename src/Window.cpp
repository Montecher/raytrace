#include "Window.hh"
#include "scenes.h"
#include "Image.h"
#include "constants.h"

Window::Window() : QWidget() {
    scene = (Scene*) 0;
    renderer = new RendererThread;

    QHBoxLayout *layout = new QHBoxLayout;
    QGridLayout *leftPane = new QGridLayout;
    layout->addLayout(leftPane);

    QLabel *title = new QLabel("Select a scene:");
    title->setFixedHeight(50);
    leftPane->addWidget(title, 0, 0);
    sceneSelect = new QComboBox();
    for(auto it = Scene::getScenes()->begin(); it!=Scene::getScenes()->end(); ++it) {
        sceneSelect->addItem(QString::fromStdString(std::string(it->first)));
    }
    sceneSelect->setCurrentIndex(-1);
    leftPane->addWidget(sceneSelect, 1, 0);


    toggleRealistic = new QPushButton("toggle realistic view");
    toggleRealistic->setCheckable(true);
    leftPane->addWidget(toggleRealistic, 2, 0);

    image = new QImage(WIDTH, HEIGHT, QImage::Format_RGB888);
    label = new QLabel();
    label->setPixmap(QPixmap::fromImage(*image));
    layout->addWidget(label);

    setLayout(layout);

    connect(sceneSelect, SIGNAL(activated(int)), this, SLOT(loadScene(int)));
    connect(toggleRealistic, SIGNAL(toggled(bool)), this, SLOT(createImage()));
    connect(this, SIGNAL(showImage(QPixmap)), label, SLOT(setPixmap(QPixmap)));
    connect(renderer, SIGNAL(image(Image)), this, SLOT(setImage(Image)));
}

void Window::createImage() {
    if(!scene) return;
    if (!toggleRealistic->isChecked()) {
        renderer->render_shaded(scene->scene(), scene->cam(), WIDTH, HEIGHT);
    } else {
        renderer->render_realistic(scene->scene(), scene->cam(), WIDTH, HEIGHT, RPP, DEPTH);
    }
}

void Window::setImage(Image img) {
    qDebug() << "setImage";
    image->loadFromData(QByteArray::fromStdString(img.to_bmp()), "BMP");
    emit showImage(QPixmap::fromImage(*image));
}

void Window::loadScene(int sceneNb) {
    scene = Scene::getScenes()->at(std::string(sceneSelect->itemText(sceneNb).toUtf8().constData()));
    createImage();
}
