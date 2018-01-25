/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Sphere.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Sphere_hpp
#define Sphere_hpp

#include "Linear/vec3.hpp"
#include "Material.hpp"
#include "BSDF.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * *
 *  Sphere
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
struct Sphere
    {
    Linear::vec3 position;  // center of the sphere
    Linear::real radius;    // dist from center to outside
    Material material;      // how to render the surface
    };

#endif /* Sphere_h */
