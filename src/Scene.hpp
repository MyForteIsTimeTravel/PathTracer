/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Scene.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Scene_hpp
#define Scene_hpp

#include "PointLight.hpp"
#include "AreaLight.hpp"
#include "Triangle.hpp"
#include "Sphere.hpp"
#include "Box.hpp"
#include <vector>

/* * * * * * * * * * * * * * * * * * * * * * * *
 *  Scene
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
struct Scene
    {
    std::vector<PointLight> pLighting;  // all the point lights in the scene
    std::vector<AreaLight>  aLighting;  // all the area lights in the scene
    std::vector<Triangle>   geometry;  // triangle geometry
    std::vector<Sphere>     spheres;    // sphere geometry
    };

#endif /* Scene_h */
