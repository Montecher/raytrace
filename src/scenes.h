#ifndef RAYTRACE_SCENES_H
#define RAYTRACE_SCENES_H

#include <string>
#include "Cam.h"
#include "Object.h"

/**
 * \class Scene
 * \brief scene manager.
 */
class Scene {
private:
    Cam* _cam;  ///< Cam used in the scene.
    Object* _scene;  ///< scene used currently.

public:
    /**
     * \brief Scene constructor.
     * @param cam Cam used.
     * @param scene scene currently in use.
     */
    Scene(Cam* cam, Object* scene);

    /**
     * \brief Scene destructor.
     */
    ~Scene();

    /**
     * \brief Cam getter.
     * @return Cam currently in use.
     */
    inline Cam* cam() const { return _cam; }

    /**
     * \brief scene getter.
     * @return scene currently in use.
     */
    inline Object* scene() const { return _scene; }

    /**
     * \brief list of all the available scenes.
     * @return map of all the scenes.
     */
    static std::map<std::string, Scene*>* getScenes();

    /**
     * \brief scene getter.
     * @return scene specified from getScenes().
     */
    static Scene* getScene(std::string);
};

#endif //RAYTRACE_SCENES_H
