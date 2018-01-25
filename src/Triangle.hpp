/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Triangle.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Triangle_hpp
#define Triangle_hpp

#include "Linear/vec3.hpp"
#include "Linear/vec2.hpp"
#include "Material.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * *
 *  Triangle
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
struct Triangle
    {
    Linear::vec3 vertices [3];  // position of each point
    Linear::vec3 normals  [3];  // normal of each point
    Linear::vec3 tcs      [3];  // texture coordinates at each point
    Material material;          // how to render the surface
    };

#endif /* Triangle_h */
