/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  ShadowScene.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef ShadowScene_hpp
#define ShadowScene_hpp

#include "SurfaceElement.hpp"
#include "Scene.hpp"
#include <vector>

/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
struct ShadowScene : public Scene
    {
    ShadowScene ()
        {
        
        PointLight light;
        light.position = Linear::vec3(1.0f, 3.0f, 1.0f);
        light.colour   = Linear::vec3(1.0, 1.0, 1.0);
        light.power    = Linear::vec3(255, 255, 255);
        pLighting.push_back(light);
            
        const float groundY = -2.0f;
        
        const Linear::vec3 groundColour = Linear::vec3(1, 1, 1);
        Triangle ground1;
        ground1.vertices [0] = Linear::vec3(-10, groundY, -10);
        ground1.vertices [1] = Linear::vec3(-10, groundY, -0.01f);
        ground1.vertices [2] = Linear::vec3( 10, groundY, -0.01f);
        ground1.normals  [0] = Linear::vec3::up;
        ground1.normals  [1] = Linear::vec3::up;
        ground1.normals  [2] = Linear::vec3::up;
        ground1.material.colour = groundColour;
        geometry.push_back(ground1);
        
        Triangle ground2;
        ground2.vertices [0] = Linear::vec3(-10, groundY, -10);
        ground2.vertices [1] = Linear::vec3( 10, groundY, -0.01f);
        ground2.vertices [2] = Linear::vec3( 10, groundY, -10);
        ground2.normals  [0] = Linear::vec3::up;
        ground2.normals  [1] = Linear::vec3::up;
        ground2.normals  [2] = Linear::vec3::up;
        ground2.material.colour = groundColour;
        geometry.push_back(ground2);
            
        Triangle tri1;
        tri1.vertices [0] = Linear::vec3(0, 1, -2);
        tri1.vertices [1] = Linear::vec3(-1.9, -1, -2);
        tri1.vertices [2] = Linear::vec3(1.6, -0.5, -2);
        tri1.normals  [0] = Linear::normalise(Linear::vec3( 0.0f,  0.6f, 1.0f));
        tri1.normals  [1] = Linear::normalise(Linear::vec3(-0.4f, -0.4f, 1.0f));
        tri1.normals  [2] = Linear::normalise(Linear::vec3( 0.4f, -0.4f, 1.0f));
        tri1.material.colour = Linear::vec3(1.0, 0.0, 0.0);
        geometry.push_back(tri1);
        
        Triangle tri2;
        tri2.vertices [0] = Linear::vec3(-1.9, -1, -2);
        tri2.vertices [1] = Linear::vec3(0, 1, -2);
        tri2.vertices [2] = Linear::vec3(1.6, -0.5, -2);
        tri2.normals  [0] = Linear::normalise(Linear::vec3(-0.4f, -0.4f, 1.0f));
        tri2.normals  [1] = Linear::normalise(Linear::vec3( 0.0f,  0.6f, 1.0f));
        tri2.normals  [2] = Linear::normalise(Linear::vec3( 0.4f, -0.4f, 1.0f));
        tri2.material.colour = Linear::vec3(1.0, 0.0, 0.0);
        geometry.push_back(tri2);
        }
    };


#endif /* ShadowScene_h */
