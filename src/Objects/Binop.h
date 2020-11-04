#ifndef __OBJECTS_BINOP_H
#define __OBJECTS_BINOP_H
#include "Object.h"

/**
 * \class Binop
 * \brief Abstract class handling binary operators for 3D objects.
 *
 * Simplifies construction and destruction of binary operators.
 */
class Binop : public Object {
public:
    /**
     * Binop destructor
     */
    virtual ~Binop() {
        delete this->obj1;
        delete this->obj2;
    };

    /**
     * \brief Constructor base
     */
    Binop(const Object* obj1, const Object* obj2) {
        this->obj1 = obj1;
        this->obj2 = obj2;
    };

protected:
    const Object* obj1;  ///< first Object of the operation.
    const Object* obj2;  ///< second Object of the operation.
};

#endif
