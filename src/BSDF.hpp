/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  BSDF.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef BSDF_hpp
#define BSDF_hpp

#include "Linear/vec3.hpp"
#include <cmath>

/* * * * * * * * * * * * * * * * * * * * * * * *
 *  
 *
 *  
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
struct BSDF
    {
    BSDF (Linear::vec3 _lambertian, Linear::vec3 _glossy, float _specular):
        lambertian (_lambertian), 
        glossy     (_glossy), 
        specular   (_specular)
        {}
        
    Linear::vec3 lambertian; // lambertian reflectance
    Linear::vec3 glossy;     // glossy reflectance
    float        specular;   // specular factor
        
    /**
     *  evaluate finite scattering density
     *  (scaled so that the outgoing radiance never exceeds the incoming radiance)
     */
    Linear::vec3 evaluateFiniteScatteringDensity (const Linear::vec3& w_i, const Linear::vec3& w_o, const Linear::vec3& norm) const
        {
        const Linear::vec3& w_h = Linear::normalise (w_i + w_o);
        return 
            (lambertian + glossy * ((specular + 8.0f) * 
            powf(std::fmax(0.0f, Linear::dot(w_h, norm)), specular) / 8.0f)) / 
            M_PI;
        }
    };

#endif /* BSDF_h */
