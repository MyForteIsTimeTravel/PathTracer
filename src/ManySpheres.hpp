/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  ManySpheres.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef ManySpheres_hpp
#define ManySpheres_hpp

#include "Scene.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
struct ManySpheres : public Scene
    {
        ManySpheres ()
            {
            const float groundY = -1.f;
            const float roofY = 1.0;
            
            const float leftWallX = -10.f;
            const float rightWallX = 10.f;
            
            const float backWallZ = -10.8;
            const float frontWallZ = -0.01f;
            
            const Linear::vec3 groundColour = Linear::vec3(1.0, 1.0, 1.0);
            Triangle ground1;
            ground1.vertices [0] = Linear::vec3(leftWallX, groundY, backWallZ);
            ground1.vertices [1] = Linear::vec3(leftWallX, groundY, frontWallZ);
            ground1.vertices [2] = Linear::vec3(rightWallX, groundY, frontWallZ);
            ground1.normals  [0] = Linear::vec3::up;
            ground1.normals  [1] = Linear::vec3::up;
            ground1.normals  [2] = Linear::vec3::up;
            ground1.material.colour = groundColour;
            ground1.material.extinction = 0.4f;
            geometry.push_back(ground1);
            
            Triangle ground2;
            ground2.vertices [0] = Linear::vec3(leftWallX, groundY, backWallZ);
            ground2.vertices [1] = Linear::vec3(rightWallX, groundY, frontWallZ);
            ground2.vertices [2] = Linear::vec3(rightWallX, groundY, backWallZ);
            ground2.normals  [0] = Linear::vec3::up;
            ground2.normals  [1] = Linear::vec3::up;
            ground2.normals  [2] = Linear::vec3::up;
            ground2.material.colour = groundColour;
            ground2.material.extinction = 0.4f;
            geometry.push_back(ground2);

            Sphere sph;
            sph.position = Linear::vec3(-0.4, -0.7, -2.75);
            sph.radius = 0.3f;
            sph.material.colour = Linear::vec3(1.0, 0.0, 1.0);
            sph.material.extinction = 0.99f;
            sph.material.scattersImpulse = false;
            spheres.push_back(sph);

            sph.position = Linear::vec3(-1.05, -0.7, -2.75);
            sph.radius = 0.3f;
            sph.material.colour = Linear::vec3(0.32, 0.32, 0.32);
            sph.material.extinction = 0.99f;
            sph.material.scattersImpulse = false;
            spheres.push_back(sph);

            sph.position = Linear::vec3(0.8, -0.7, -3);
            sph.radius = 0.3f;
            sph.material.colour = Linear::vec3(1.0, 1.0, 0.0);
            sph.material.extinction = 0.99f;
            sph.material.scattersImpulse = false;
            spheres.push_back(sph);

            sph.position = Linear::vec3(0.4, -0.7, -2.5);
            sph.radius = 0.3f;
            sph.material.colour = Linear::vec3(0.0, 1.0, 0.0);
            sph.material.extinction = 0.99f;
            sph.material.scattersImpulse = false;
            spheres.push_back(sph);
            
            sph.position = Linear::vec3(1.5, -0.3, -4.2);
            sph.radius = 0.7f;
            sph.material.colour = Linear::vec3(1.0, 0.0, 0.0);
            sph.material.extinction = 0.99f;
            sph.material.scattersImpulse = false;
            spheres.push_back(sph);

            sph.position = Linear::vec3(-1.5, -0.3, -4.2);
            sph.radius = 0.7f;
            sph.material.colour = Linear::vec3(0.0, 0.0, 1.0);
            sph.material.extinction = 0.99f;
            sph.material.scattersImpulse = false;
            spheres.push_back(sph);

            PointLight light;
            light.position = Linear::vec3(0.0, 2.f, -2.75f);
            light.colour   = Linear::vec3(1.0, 1.0, 1.0);
            light.power    = Linear::vec3(0.5, 0.5, 0.5);
            pLighting.push_back(light);

            AreaLight alight (Linear::vec3(0, 0.975f, -1.375), 0.5, 0.25, Linear::vec3(1.0, 1.0, 1.0), Linear::vec3(0.5, 0.5, 0.5));
            std::vector<Triangle> mesh = alight.mesh();
            aLighting.push_back(alight);
            //geometry.insert(geometry.end(), mesh.begin(), mesh.end());

            std::sort(spheres.begin(), spheres.end(), 
                [] (const Sphere& a, const Sphere& b) -> bool 
                    { return a.position.z < b.position.z; });
            }
        };

#endif /* ManySpheres_h */
