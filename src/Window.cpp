#include "Window.hh"
#include "scenes.h"
#include "Image.h"
#include "constants.h"

Window::Window() : QWidget() {
    scene = (Object*) 0;
    camera = new Cam();
    camera->setPos(Vec3::Z*3. - Vec3::X*5.);
    camera->setPointing(Vec3::O);
    renderer = new RendererThread;

    QHBoxLayout *layout = new QHBoxLayout;
    QGridLayout *leftPane = new QGridLayout;
    layout->addLayout(leftPane);

    QLabel *title = new QLabel("Select a scene:");
    title->setFixedHeight(50);
    leftPane->addWidget(title, 0, 0);
    QComboBox *sceneSelect = new QComboBox();
    sceneSelect->addItem("scene 1");
    sceneSelect->addItem("scene 2");
    sceneSelect->addItem("scene 3");
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

    connect(sceneSelect, SIGNAL(activated(int)), this, SLOT(test(int)));
    connect(sceneSelect, SIGNAL(activated(int)), this, SLOT(loadSCene(int)));
    connect(toggleRealistic, SIGNAL(toggled(bool)), this, SLOT(createImage()));
    connect(this, SIGNAL(showImage(QPixmap)), label, SLOT(setPixmap(QPixmap)));
    connect(renderer, SIGNAL(image(Image)), this, SLOT(setImage(Image)));
}

void Window::createImage() {
    if(!scene) return;
    if (!toggleRealistic->isChecked()) {
        renderer->render_shaded(scene, camera, WIDTH, HEIGHT);
    } else {
        renderer->render_realistic(scene, camera, WIDTH, HEIGHT, RPP);
    }
}

void Window::setImage(Image img) {
    qDebug() << "setImage";
    image->loadFromData(QByteArray::fromStdString(img.to_bmp()), "BMP");
    emit showImage(QPixmap::fromImage(*image));
}

void Window::test(int input) {
    qDebug() << input;
}

void Window::loadSCene(int sceneNb) {
    if(scene) {
        delete scene;
        scene = (Object*) 0;
    }
    switch (sceneNb) {
        case 0:
            scene = SCENE::scene1();
            break;
        case 1:
            scene = SCENE::scene2();
            break;
        case 2:
            scene = SCENE::scene3();
            break;
        default:
            return;
    }
    createImage();
}
