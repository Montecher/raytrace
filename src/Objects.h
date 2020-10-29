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
#include "Objects/Cylinder.h"
#include "Objects/Waves.h"
#include "Objects/Torus.h"

// unary operators
#include "Objects/Scaling.h"
#include "Objects/Negation.h"
#include "Objects/Translation.h"
#include "Objects/WithMaterial.h"
#include "Objects/LinearTransform.h"
#include "Objects/AffineTransform.h"

// binary operators
#include "Objects/Union.h"
#include "Objects/Intersection.h"
#include "Objects/Exclusion.h"
#include "Objects/SmoothUnion.h"

#endif
