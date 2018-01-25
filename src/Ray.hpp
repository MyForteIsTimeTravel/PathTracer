/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Ray.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Ray_hpp
#define Ray_hpp

#include "Linear/vec3.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * *
 *  Ray
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
struct Ray
    {
    Linear::vec3 q; // origin position
    Linear::vec3 w; // direction vector

    /** Construct a ray with the given origin and direction */
    Ray (Linear::vec3 from, Linear::vec3 to):
        q (from), w (Linear::normalise(to - from)) {}
    /** return direction of the ray */
    Linear::vec3 origin () const
        { return q; }
    /** return origin of the ray */
    Linear::vec3 direction () const 
        { return w; }
    };

#endif /* Ray_h */
