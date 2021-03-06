#ifndef RAYTRACE_WINDOW_HH
#define RAYTRACE_WINDOW_HH

#include <QApplication>
#include <QtWidgets>
#include "Cam.h"
#include "Renderer.hh"
#include "scenes.h"


/**
 * @class Window
 * @brief Window containing the renders.
 *
 * This is the Window that the user will be able to use to control the camera, render type and the scene to render.
*/
class Window : public QWidget {
    Q_OBJECT

private:
    QImage *image; ///< Object storing the rendered image.
    QLabel *label; ///< Container of the image in the window.
    QPushButton *toggleRealistic; ///< Button used to swap between the shaded and realistic view.
    QComboBox *sceneSelect; ///< Combobox used to select the scene.

    Scene *scene; ///< Scene currently loaded in the window.
    RendererThread *renderer; ///< Renderer thread to free up GUI thread.


public:
    /**
     * \brief Constructor for the gui window
     */
    Window();

private slots:
    /**
     * @brief Loads the scene.
     *
     * Loads the asked scene, then resets the camera and calls the image renderer.
     *
     * @param sceneNb id of the selected value in the combobox with all the scenes listed.
     */
    void loadScene(int sceneNb);

    /**
     * @brief Image renderer
     *
     * Creates the image with the scene and camera stored in the window object attributes with the render mode selected.
     */
    void createImage();

    /**
     * \brief changes the Image that is selected.
     * @param image new Image used.
     */
    void setImage(Image image);

signals:
    /**
     * @brief Signal used to tell the window to refresh the image inside the label.
     */
    void showImage(QPixmap);
};

#endif //RAYTRACE_WINDOW_HH
