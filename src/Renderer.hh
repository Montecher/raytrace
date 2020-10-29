#ifndef __RENDERER_H
#define __RENDERER_H

#include <QObject>
#include <QThread>
#include "Image.h"
#include "Cam.h"
#include "Object.h"

class Renderer: public QObject {
	Q_OBJECT

public:
	Renderer() {};
	~Renderer() {};

signals:
	void image(Image);

public slots:
	void render_shaded(Object*, Cam*, int, int);
	void render_realistic(Object*, Cam*, int, int, int, int);
};

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
