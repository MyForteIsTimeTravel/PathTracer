/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  SurfaceElement.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef SurfaceElement_hpp
#define SurfaceElement_hpp

#include "Linear/vec3.hpp"
#include "Geometric.hpp"
#include "Material.hpp"
#include "Shading.hpp"
#include "Random.hpp"
#include "BSDF.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * *
 *  SurfaceElement
 *
 *  represents the surface at a ray intersection
 * * * * * * * * * * * * * * * * * * * * * * * */
struct SurfaceElement
    {

    /** 
     *
     */ 
    SurfaceElement (Linear::vec3 _position, Linear::vec3 _normal, Linear::vec3 _lambertian, Linear::vec3 _glossy, float _specular):
        bsdf(_lambertian, _glossy, _specular)
        {
        geometric.position = _position;
        geometric.normal   = _normal;
        }
    
    /** 
     *
     */ 
    SurfaceElement (Linear::vec3 geom_position, Linear::vec3 shading_position, Linear::vec3 geom_normal, Linear::vec3 shading_normal):
        bsdf(Linear::vec3(1.0, 1.0, 1.0), Linear::vec3(1.0, 1.0, 1.0), 20.0f)
        {
        geometric.position = geom_position;
        shading.position   = shading_position;
        geometric.normal   = geom_normal;
        shading.normal     = shading_normal;
        impulse = Linear::vec3(0.25, 0.25, 0.25);
        }
    
    /** 
     *
     */ 
    SurfaceElement ():
        bsdf(Linear::vec3(1.0, 0.0, 1.0), Linear::vec3(1.0, 0.0, 1.0), 20.0f)
        {}

    /** 
     *
     */     
   ~SurfaceElement ()
        {}
        
    Geometric geometric;
        
    Material material;
    Shading shading;
        
    BSDF bsdf;
        
    Linear::vec3 impulse;
        
    float extinction ()
        { return material.extinction; }
        
    Linear::vec3 evaluateBSDFfinite (Linear::vec3 w_i, Linear::vec3 w_o)
        { return material.colour * bsdf.evaluateFiniteScatteringDensity(w_i, w_o, geometric.normal); }
        
    /**
     *  if opaque, reflect.
     *  if transparent, refract.
     */
    Linear::vec3 getImpulseScatterDirection (const Linear::vec3& incoming)
        { return Random::cosHemisphereVector(); }
               // { return Linear::normalise(2 * (Linear::dot(incoming, geometric.normal)) * geometric.normal); }
    };

#endif /* SurfaceElement_h */
