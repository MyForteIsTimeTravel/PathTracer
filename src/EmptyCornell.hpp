/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  EmptyCornell.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef EmptyCornell_hpp
#define EmptyCornell_hpp

#include "Scene.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
struct EmptyCornell : public Scene
    {
    EmptyCornell ()
        {
            const float groundY = -1.f;
            const float roofY = 1.0;
            
            const float leftWallX = -1.f;
            const float rightWallX = 1.f;
            
            const float backWallZ = -2;
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
            ground1.material.extinction = 0.5f;
            geometry.push_back(ground1);
            
            Triangle ground2;
            ground2.vertices [0] = Linear::vec3(leftWallX, groundY, backWallZ);
            ground2.vertices [1] = Linear::vec3(rightWallX, groundY, frontWallZ);
            ground2.vertices [2] = Linear::vec3(rightWallX, groundY, backWallZ);
            ground2.normals  [0] = Linear::vec3::up;
            ground2.normals  [1] = Linear::vec3::up;
            ground2.normals  [2] = Linear::vec3::up;
            ground2.material.colour = groundColour;
            ground2.material.extinction = 0.5f;
            geometry.push_back(ground2);
            
            
            const Linear::vec3 roofColour = Linear::vec3(1, 1, 1);
            Triangle roof1;
            roof1.vertices [0] = Linear::vec3(leftWallX, roofY, backWallZ);
            roof1.vertices [1] = Linear::vec3(rightWallX, roofY, backWallZ);
            roof1.vertices [2] = Linear::vec3(rightWallX, roofY, frontWallZ);
            roof1.normals  [0] = Linear::vec3::down;
            roof1.normals  [1] = Linear::vec3::down;
            roof1.normals  [2] = Linear::vec3::down;
            roof1.material.colour  = roofColour;
            roof1.material.extinction = 0.99f;
            //roof1.material.reflectsDirect = false;
            geometry.push_back(roof1);
            
            Triangle roof2;
            roof2.vertices [0] = Linear::vec3(leftWallX, roofY, backWallZ);
            roof2.vertices [1] = Linear::vec3(rightWallX, roofY, frontWallZ);
            roof2.vertices [2] = Linear::vec3(leftWallX, roofY, frontWallZ);
            roof2.normals  [0] = Linear::vec3::down;
            roof2.normals  [1] = Linear::vec3::down;
            roof2.normals  [2] = Linear::vec3::down;
            roof2.material.colour = roofColour;
            roof2.material.extinction = 0.99f;
            //roof2.material.reflectsDirect = false;
            geometry.push_back(roof2);
            
            
            const Linear::vec3 leftWallColour = Linear::vec3(1, 0.2, 0.2);
            Triangle leftWall1;
            leftWall1.vertices [0] = Linear::vec3(leftWallX, groundY, frontWallZ);
            leftWall1.vertices [1] = Linear::vec3(leftWallX, groundY, backWallZ);
            leftWall1.vertices [2] = Linear::vec3(leftWallX, roofY, backWallZ);
            leftWall1.normals  [0] = Linear::vec3::left;
            leftWall1.normals  [1] = Linear::vec3::left;
            leftWall1.normals  [2] = Linear::vec3::left;
            leftWall1.material.colour = leftWallColour;
            leftWall1.material.extinction = 0.99f;
            geometry.push_back(leftWall1);
            
            Triangle leftWall2;
            leftWall2.vertices [0] = Linear::vec3(leftWallX, roofY, frontWallZ);
            leftWall2.vertices [1] = Linear::vec3(leftWallX, groundY, frontWallZ);
            leftWall2.vertices [2] = Linear::vec3(leftWallX, roofY, backWallZ);
            leftWall2.normals  [0] = Linear::vec3::left;
            leftWall2.normals  [1] = Linear::vec3::left;
            leftWall2.normals  [2] = Linear::vec3::left;
            leftWall2.material.colour = leftWallColour;
            leftWall2.material.extinction = 0.99f;
            geometry.push_back(leftWall2);
            
            const Linear::vec3 rightWallColour = Linear::vec3(0.5, 1, 1);
            Triangle rightWall1;
            rightWall1.vertices [0] = Linear::vec3(rightWallX,  roofY, backWallZ);
            rightWall1.vertices [1] = Linear::vec3(rightWallX, groundY, backWallZ);
            rightWall1.vertices [2] = Linear::vec3(rightWallX, groundY, frontWallZ);
            rightWall1.normals  [0] = Linear::vec3::right;
            rightWall1.normals  [1] = Linear::vec3::right;
            rightWall1.normals  [2] = Linear::vec3::right;
            rightWall1.material.colour = rightWallColour;
            rightWall1.material.extinction = 0.99f;
            geometry.push_back(rightWall1);
            
            Triangle rightWall2;
            rightWall2.vertices [0] = Linear::vec3(rightWallX, roofY, backWallZ);
            rightWall2.vertices [1] = Linear::vec3(rightWallX, groundY, frontWallZ);
            rightWall2.vertices [2] = Linear::vec3(rightWallX, roofY, frontWallZ);
            rightWall2.normals  [0] = Linear::vec3::right;
            rightWall2.normals  [1] = Linear::vec3::right;
            rightWall2.normals  [2] = Linear::vec3::right;
            rightWall2.material.colour = rightWallColour;
            rightWall2.material.extinction = 0.99f;
            geometry.push_back(rightWall2);
            
            const Linear::vec3 backWallColour = Linear::vec3(1, 1, 1);
            Triangle backWall1;
            backWall1.vertices [0] = Linear::vec3(leftWallX, roofY, backWallZ);
            backWall1.vertices [1] = Linear::vec3(leftWallX, groundY, backWallZ);
            backWall1.vertices [2] = Linear::vec3(rightWallX, groundY, backWallZ);
            backWall1.normals  [0] = Linear::vec3::forward;
            backWall1.normals  [1] = Linear::vec3::forward;
            backWall1.normals  [2] = Linear::vec3::forward;
            backWall1.material.colour = backWallColour;
            backWall1.material.extinction = 0.1f;
            geometry.push_back(backWall1);
            
            Triangle backWall2;
            backWall2.vertices [0] = Linear::vec3(leftWallX, roofY, backWallZ);
            backWall2.vertices [1] = Linear::vec3(rightWallX, groundY, backWallZ);
            backWall2.vertices [2] = Linear::vec3(rightWallX, roofY, backWallZ);
            backWall2.normals  [0] = Linear::vec3::forward;
            backWall2.normals  [1] = Linear::vec3::forward;
            backWall2.normals  [2] = Linear::vec3::forward;
            backWall2.material.colour = backWallColour;
            backWall2.material.extinction = 0.99f;
            geometry.push_back(backWall2);

            Sphere sph;
            sph.position = Linear::vec3(0.0, -0.2, -0.75);
            sph.radius = 0.2f;
            sph.material.colour = Linear::vec3(1.0, 0.545098, 0.462745);
            sph.material.extinction = 0.99f;
            //sph.material.scattersImpulse = false;
            //spheres.push_back(sph);


            PointLight light;
            light.position = Linear::vec3(0.0, 0.0f, 0.f);
            light.colour   = Linear::vec3(1.0, 1.0, 1.0);
            light.power    = Linear::vec3(0.5, 0.5, 0.5);
            pLighting.push_back(light);
            
            AreaLight alight (Linear::vec3(0, 0.99f, -1.375), 0.5, 0.25, Linear::vec3(1.32, 1.32, 1.32), Linear::vec3(128, 128, 128));
            std::vector<Triangle> mesh = alight.mesh();
            //aLighting.push_back(alight);
            //geometry.insert(geometry.end(), mesh.begin(), mesh.end());
        }
    };

#endif /* EmptyCornell_h */
