#ifndef RAYTRACE_SCENES_H
#define RAYTRACE_SCENES_H

#include <string>
#include "Cam.h"
#include "Object.h"

class Scene {
private:
    Cam* _cam;
    Object* _scene;

public:
    Scene(Cam*, Object*);
    ~Scene();

    inline Cam* cam() const { return _cam; }
    inline Object* scene() const { return _scene; }

    static std::map<std::string, Scene*>* getScenes();
};

#endif //RAYTRACE_SCENES_H
