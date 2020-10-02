#ifndef RAYTRACE_OBJECT_H
#define RAYTRACE_OBJECT_H

#include <iostream>
#include <vector>
#include "Vec3.h"


// CAN'T BE VIRTUAL BUT NO TOUCH
class Object {
public:
    virtual ~Object() {};
    virtual double distance_to(const Vec3&) const = 0;
    virtual Vec3 normal_at(const Vec3&) const;
};



class Intersection: public Object {
protected:
    const Object* obj1;
    const Object* obj2;

public:
//    Intersection(const Object...);
    ~Intersection();
    Intersection(const Object*, const Object*);
    Intersection(const Object*, const Object*, const Object*);
    Intersection(const Object*, const Object*, const Object*, const Object*);

    virtual double distance_to(const Vec3&) const;
};

class Union: public Object {
protected:
    const Object* obj1;
    const Object* obj2;

public:
//    Union(const Object...);
    ~Union();
    Union(const Object*, const Object*);
    Union(const Object*, const Object*, const Object*);
    Union(const Object*, const Object*, const Object*, const Object*);

    virtual double distance_to(const Vec3&) const;
};

class Negation: public Object {
protected:
    const Object* obj;

public:
    ~Negation();
    Negation(const Object*);

    virtual double distance_to(const Vec3&) const;
};

class Exclusion: public Object {
protected:
    const Object* obj1;
    const Object* obj2;

public:
    ~Exclusion();
    Exclusion(const Object*, const Object*);

    virtual double distance_to(const Vec3&) const;
};


#endif //RAYTRACE_OBJECT_H
