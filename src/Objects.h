#ifndef __OBJECTS
#define __OBJECTS

// base classes
#include "Object.h"
#include "Objects/Unop.h"
#include "Objects/Binop.h"

// primitives
#include "Objects/Box.h"
#include "Objects/Plane.h"
#include "Objects/Sphere.h"

// unary operators
#include "Objects/Scaling.h"
#include "Objects/Negation.h"
#include "Objects/Translation.h"
#include "Objects/WithMaterial.h"

// binary operators
#include "Objects/Union.h"
#include "Objects/Intersection.h"
#include "Objects/Exclusion.h"
#include "Objects/SmoothUnion.h"

#endif
