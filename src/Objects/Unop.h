#ifndef __OBJECTS_UNOP_H
#define __OBJECTS_UNOP_H
#include "Object.h"

/**
 * \class Unop
 * \brief Abstract class handling unary operators for 3D objects.
 *
 * Simplifies construction and destruction of unary operators.
 */
class Unop : public Object {
public:
    /**
     * Unop destructor
     */
    virtual ~Unop() {
        delete this->obj;
    };

    /**
     * \brief Constructor base
     */
    Unop(const Object* obj) {
        this->obj = obj;
    };

protected:
    const Object* obj;  ///< Object affected by operation.
};

#endif
