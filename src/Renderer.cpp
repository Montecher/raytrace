#include "Renderer.hh"
#include <QtDebug>

void Renderer::render_shaded(Object* scene, Cam* cam, int width, int height) {
    qDebug() << "render_shaded";
    emit Renderer::image(cam->render_shaded(scene, width, height));
}

void Renderer::render_realistic(Object* scene, Cam* cam, int width, int height, int rpp) {
    emit Renderer::image(cam->render_realistic(scene, width, height, rpp));
}

RendererThread::RendererThread() {
    _renderer = new Renderer;
    _renderer->moveToThread(&_thread);
    _thread.start();

    connect(_renderer, &Renderer::image, this, &RendererThread::image);
    connect(this, &RendererThread::_render_shaded, _renderer, &Renderer::render_shaded);
    connect(this, &RendererThread::_render_realistic, _renderer, &Renderer::render_realistic);
}

RendererThread::~RendererThread() {
    delete _renderer;
    _thread.exit();
}

void RendererThread::render_shaded(Object* scene, Cam* cam, int width, int height) {
    qDebug() << "render_shaded thread";
    emit _render_shaded(scene, cam, width, height);
}

void RendererThread::render_realistic(Object* scene, Cam* cam, int width, int height, int rpp) {
    emit _render_realistic(scene, cam, width, height, rpp);
}
