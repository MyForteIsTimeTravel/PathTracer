/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PointLight.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef PointLight_hpp
#define PointLight_hpp

#include "Linear/vec3.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * *
 *  PointLight
 *
 *  Simple representation of a point light
 * * * * * * * * * * * * * * * * * * * * * * * */
struct PointLight
    {
    Linear::vec3 position;
    Linear::vec3 colour;
    Linear::vec3 power;
    };

#endif /* PointLight_h */
