/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Shading.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Shading_hpp
#define Shading_hpp

#include "Linear/vec3.hpp"
#include "Linear/vec2.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * *
 *  Shading
 *  
 *  interpolated geometry data
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
struct Shading
    {
    Linear::vec3 position;
    Linear::vec3 normal; // surface normal at p
    Linear::vec2 tcs;    // texture coordinates at p
    };

#endif /* Shading_hpp */
