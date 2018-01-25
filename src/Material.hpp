/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Material.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Material_hpp
#define Material_hpp

#include "Linear/vec3.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * *
 *  Material
 *
 *  holds information about a given surface
 * * * * * * * * * * * * * * * * * * * * * * * */
struct Material
    {

    /** 
     *
     */ 
    Material ():
        scattersImpulse  (true),
        reflectsIndirect (true),
        reflectsDirect   (true),
        emits            (false)
        {}
        
    Linear::vec3 emission;
    Linear::vec3 colour;
    float extinction;

    bool scattersImpulse;
    bool reflectsIndirect;
    bool reflectsDirect;
    bool emits;
    };

#endif /* Material_hpp */
