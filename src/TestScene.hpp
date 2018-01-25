/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  TestScene.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef TestScene_hpp
#define TestScene_hpp

#include "Scene.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
struct TestScene : public Scene
    {
    TestScene ()
        {
        Triangle tri;
        tri.vertices [0] = Linear::vec3(0, 1, -2);
        tri.vertices [1] = Linear::vec3(-1.9, -1, -2);
        tri.vertices [2] = Linear::vec3(1.6, -0.5, -2);
        tri.normals  [0] = Linear::normalise(Linear::vec3( 0.0f,  0.6f, 1.0f));
        tri.normals  [1] = Linear::normalise(Linear::vec3(-0.4f, -0.4f, 1.0f));
        tri.normals  [2] = Linear::normalise(Linear::vec3( 0.4f, -0.4f, 1.0f));
        //tri.bsdf.k_l     = Linear::vec3(1, 0, 1);
        //tri.bsdf.k_g     = Linear::vec3(0.1f, 0.1f, 0.1f);
        //tri.bsdf.s       = 20.0f;
        geometry.push_back(tri);
        
        PointLight light;
        light.position = Linear::vec3(1.0f, 3.0f, 1.0f);
        light.colour   = Linear::vec3(1.0, 0.0, 1.0);
        light.power    = Linear::vec3(10, 10, 10);
        pLighting.push_back(light);
        }
    };

#endif /* TestScene_h */
