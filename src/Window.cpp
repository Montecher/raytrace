#include "Window.hh"
#include "scenes.h"
#include "Image.h"
#include "constants.h"




Window::Window() : QWidget() {
    QHBoxLayout *layout = new QHBoxLayout;
    QGridLayout *leftPane = new QGridLayout;
    layout->addLayout(leftPane);

    QLabel *title = new QLabel("Select a scene:");
    title->setFixedHeight(50);
    leftPane->addWidget(title, 0, 0);
    QComboBox *sceneSelect = new QComboBox();
    sceneSelect->addItem("scene 1");
    sceneSelect->addItem("scene 2");
    sceneSelect->setCurrentIndex(-1);
    leftPane->addWidget(sceneSelect, 1, 0);


    toggleRealistic = new QPushButton("toggle realistic view");
    toggleRealistic->setCheckable(true);
    leftPane->addWidget(toggleRealistic, 2, 0);

    camera = Cam(Vec3::Y, Vec3::X, Vec3::Y, 1, 1);
    image = new QImage(WIDTH, HEIGHT, QImage::Format_RGB888);
    label = new QLabel();
    label->setPixmap(QPixmap::fromImage(*image));
    layout->addWidget(label);

    setLayout(layout);

    connect(sceneSelect, SIGNAL(activated(int)), this, SLOT(test(int)));
    connect(sceneSelect, SIGNAL(activated(int)), this, SLOT(loadSCene(int)));
    connect(toggleRealistic, SIGNAL(toggled(bool)), this, SLOT(createImage()));
    connect(this, SIGNAL(showImage(QPixmap)), label, SLOT(setPixmap(QPixmap)));
}

void Window::createImage() {
    if (!toggleRealistic->isChecked()) {
        image->loadFromData(QByteArray::fromStdString(camera.render(scene, WIDTH, HEIGHT).to_bmp()), "BMP");
    } else {
        // image->loadFromData(QByteArray::fromStdString(camera.render_realistic(scene, WIDTH, HEIGHT).to_bmp()), "BMP");
        image = new QImage(WIDTH, HEIGHT, QImage::Format_RGB888);
        image->fill(QColor("red")); // temp placeholder until the real function is here
    }
    emit showImage(QPixmap::fromImage(*image));
}

void Window::test(int input) {
    qDebug() << input;
}

void Window::loadSCene(int sceneNb) {
    switch (sceneNb) {
        case 0:
            scene = SCENE::scene1();
            break;
        case 1:
            scene = SCENE::scene2();
            break;
    }
    camera = Cam(Vec3::Y, Vec3::X, Vec3::Y, 1, 1);
    createImage();
}
