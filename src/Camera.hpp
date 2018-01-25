/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Camera.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Camera_hpp
#define Camera_hpp

#include <cmath>

/* * * * * * * * * * * * * * * * * * * * * * * *
 *  Camera
 *
 *  representation of a camera/eye/viewpoint in
 *  a scene
 * * * * * * * * * * * * * * * * * * * * * * * */
struct Camera
    {

    /** 
     *  constructed with a default set of values
     */ 
    Camera (): 
        near (-0.1f),
        far  (-100.0f),
        fov  (M_PI / 2.0f)
        {}
        
    float near; // near plane
    float far;  // far plane
    float fov;  // field of view
    };

#endif /* Camera_h */
