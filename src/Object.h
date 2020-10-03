#ifndef RAYTRACE_OBJECT_H
#define RAYTRACE_OBJECT_H

#include <iostream>
#include <vector>
#include "Vec3.h"


class Object {
public:
    virtual ~Object() {};
    virtual double distance_to(const Vec3&) const = 0;
    virtual Vec3 normal_at(const Vec3&) const;
    virtual const Object* get_intersecting(const Vec3&) const;
};



class Intersection: public Object {
protected:
    const Object* obj1;
    const Object* obj2;

public:
    ~Intersection();
    Intersection(const Object*, const Object*);
    Intersection(const Object*, const Object*, const Object*);
    Intersection(const Object*, const Object*, const Object*, const Object*);

    virtual double distance_to(const Vec3&) const;
    virtual const Object* get_intersecting(const Vec3&) const;
};

class Union: public Object {
protected:
    const Object* obj1;
    const Object* obj2;

public:
    ~Union();
    Union(const Object*, const Object*);
    Union(const Object*, const Object*, const Object*);
    Union(const Object*, const Object*, const Object*, const Object*);

    virtual double distance_to(const Vec3&) const;
    virtual const Object* get_intersecting(const Vec3&) const;
};

class Negation: public Object {
protected:
    const Object* obj;

public:
    ~Negation();
    Negation(const Object*);

    virtual double distance_to(const Vec3&) const;
    virtual const Object* get_intersecting(const Vec3&) const;
};

class Exclusion: public Object {
protected:
    const Object* obj1;
    const Object* obj2;

public:
    ~Exclusion();
    Exclusion(const Object*, const Object*);

    virtual double distance_to(const Vec3&) const;
    virtual const Object* get_intersecting(const Vec3&) const;
};

class Translation: public Object {
protected:
    const Object* obj;
    Vec3 translate;

public:
    ~Translation();
    Translation(const Object*, const Vec3);

    virtual double distance_to(const Vec3&) const;
    virtual const Object* get_intersecting(const Vec3&) const;
};

class Scaling: public Object {
protected:
    const Object* obj;
    Vec3 center;
    double factor;

public:
    ~Scaling();
    Scaling(const Object*, const Vec3&, const double);

    virtual double distance_to(const Vec3&) const;
    virtual const Object* get_intersecting(const Vec3&) const;
};


#endif //RAYTRACE_OBJECT_H
