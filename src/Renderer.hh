#ifndef __RENDERER_H
#define __RENDERER_H

#include <QObject>
#include <QThread>
#include "Image.h"
#include "Cam.h"
#include "Object.h"

/**
 * \class Renderer
 * \brief class responsible for the rendering of the Image with the data given
 */
class Renderer: public QObject {
	Q_OBJECT

public:
    /** \const */
	Renderer() {};
	~Renderer() {};
	/** \endconst */

signals:
    /**
     * \brief signal emitted when the image is rendered
     * The Renderer emits this signal once the rendering is done, giving the Image as the signal info
     */
	void image(Image);

public slots:
    /**
     * \brief slot that is called to do the shaded render of the scene.
     *
     * Once the render is done, it will send an image() signal containing the rendered Image.
     *
     * @param scene scene to be rendered.
     * @param cam Cam to be used.
     * @param width Image width.
     * @param height Image height.
     */
	void render_shaded(Object* scene, Cam* cam, int width, int height);

	/**
     * \brief slot that is called to do the realistic render of the scene.
     *
     * Once the render is done, it will send an image() signal containing the rendered Image.
     *
     * @param scene scene to be rendered.
     * @param cam Cam to be used.
     * @param width Image width.
     * @param height Image height.
	 * @param rpp number of Ray per pixel.
     * @param depth max number of bounces per Ray.
	 */
	void render_realistic(Object* scene, Cam* cam, int width, int height, int rpp, int depth);
};

/**
 * \class RendererThread.
 * \brief manages the multithreading for the render.
 */
class RendererThread: public QObject {
	Q_OBJECT

private:
	QThread _thread;
	Renderer* _renderer;

public:
	RendererThread();
	~RendererThread();

signals:
	void image(Image);
	void _render_shaded(Object*, Cam*, int, int);
	void _render_realistic(Object*, Cam*, int, int, int, int);

public slots:
	void render_shaded(Object*, Cam*, int, int);
	void render_realistic(Object*, Cam*, int, int, int, int);
};

#endif
