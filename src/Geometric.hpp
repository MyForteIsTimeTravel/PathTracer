/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Geometric.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Geometric_hpp
#define Geometric_hpp

/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Geometric
 *
 *  represents a geometric position and surface normal
 * * * * * * * * * * * * * * * * * * * * * * * * * * * */
struct Geometric
    {
    Linear::vec3 position;
    Linear::vec3 normal;
    };    

#endif