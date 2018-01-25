/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  SphereScene.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef SphereScene_hpp
#define SphereScene_hpp

#include "Scene.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
struct SphereScene : public Scene
    {
        SphereScene ()
            {
            const float groundY = -0.5f;
            const float roofY = 10.0;
            
            const float leftWallX = -16.f;
            const float rightWallX = 16.f;
            
            const float backWallZ = -10;
            const float frontWallZ = -0.01f;
            
            const Linear::vec3 groundColour = Linear::vec3(1, 1, 1);
            Triangle ground1;
            ground1.vertices [0] = Linear::vec3(leftWallX, groundY, backWallZ);
            ground1.vertices [1] = Linear::vec3(leftWallX, groundY, frontWallZ);
            ground1.vertices [2] = Linear::vec3(rightWallX, groundY, frontWallZ);
            ground1.normals  [0] = Linear::vec3::up;
            ground1.normals  [1] = Linear::vec3::up;
            ground1.normals  [2] = Linear::vec3::up;
            ground1.material.colour = groundColour;
            ground1.material.extinction = 0.99f;
            geometry.push_back(ground1);
            
            Triangle ground2;
            ground2.vertices [0] = Linear::vec3(leftWallX, groundY, backWallZ);
            ground2.vertices [1] = Linear::vec3(rightWallX, groundY, frontWallZ);
            ground2.vertices [2] = Linear::vec3(rightWallX, groundY, backWallZ);
            ground2.normals  [0] = Linear::vec3::up;
            ground2.normals  [1] = Linear::vec3::up;
            ground2.normals  [2] = Linear::vec3::up;
            ground2.material.colour = groundColour;
            ground2.material.extinction = 0.99f;
            geometry.push_back(ground2);
            
            const Linear::vec3 backWallColour = Linear::vec3(0.862745, 0.8823529, 0.96470588);
            Triangle backWall1;
            backWall1.vertices [0] = Linear::vec3(leftWallX, roofY, backWallZ);
            backWall1.vertices [1] = Linear::vec3(leftWallX, groundY, backWallZ);
            backWall1.vertices [2] = Linear::vec3(rightWallX, groundY, backWallZ);
            backWall1.normals  [0] = Linear::vec3::forward;
            backWall1.normals  [1] = Linear::vec3::forward;
            backWall1.normals  [2] = Linear::vec3::forward;
            backWall1.material.colour = backWallColour;
            backWall1.material.extinction = 0.8f;
            geometry.push_back(backWall1);
            
            Triangle backWall2;
            backWall2.vertices [0] = Linear::vec3(leftWallX, roofY, backWallZ);
            backWall2.vertices [1] = Linear::vec3(rightWallX, groundY, backWallZ);
            backWall2.vertices [2] = Linear::vec3(rightWallX, roofY, backWallZ);
            backWall2.normals  [0] = Linear::vec3::forward;
            backWall2.normals  [1] = Linear::vec3::forward;
            backWall2.normals  [2] = Linear::vec3::forward;
            backWall2.material.colour = backWallColour;
            backWall2.material.extinction = 0.8f;
            geometry.push_back(backWall2);
            
            Sphere sph;
            sph.position = Linear::vec3(0.0, 0.1, -1.5);
            sph.radius = 0.6f;
            sph.material.colour = Linear::vec3(1.0, 0.545098, 0.462745);
            sph.material.extinction = 0.99f;
            sph.material.scattersImpulse = false;
            spheres.push_back(sph);

            sph.position = Linear::vec3(-0.4, -0.4, -0.8);
            sph.radius = 0.1f;
            sph.material.colour = Linear::vec3(0.9686274, 0.9764705, 0.6431372);
            sph.material.extinction = 0.99f;
            sph.material.scattersImpulse = false;
            spheres.push_back(sph);
            
            // PINK
            sph.position = Linear::vec3(2, 0.4, -1.75);
            sph.radius = 0.9f;
            sph.material.colour = Linear::vec3(1.0, 0.666666, 0.91764705);
            sph.material.extinction = 0.99f;
            sph.material.scattersImpulse = false;
            spheres.push_back(sph);

            sph.position = Linear::vec3(1.8, -0.7, -1.0);
            sph.radius = 0.3f;
            sph.material.colour = Linear::vec3(1.0, 0.585098, 0.492745);
            sph.material.extinction = 0.99f;
            sph.material.scattersImpulse = false;
            spheres.push_back(sph);
            
            PointLight light;
            light.position = Linear::vec3(-1.f, 0.9f, -0.6f);
            light.colour   = Linear::vec3(0.8, 0.8, 0.8);
            light.power    = Linear::vec3(12, 12, 12);
            pLighting.push_back(light);

            AreaLight alight (Linear::vec3(0, 1.2f, -1), 0.5, 0.25, Linear::vec3(1.0, 1.0, 1.0), Linear::vec3(255, 255, 255));
            std::vector<Triangle> mesh = alight.mesh();
            //aLighting.push_back(alight);
           // geometry.insert(geometry.end(), mesh.begin(), mesh.end());

            std::sort(spheres.begin(), spheres.end(), 
                [] (const Sphere& a, const Sphere& b) -> bool 
                    { return a.position.z < b.position.z; });
            }
        };

#endif /* SphereScene_h */
