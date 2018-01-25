/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  CornellScene.hpp
 *  Path Tracer
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef CornellScene_hpp
#define CornellScene_hpp

#include "Scene.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
struct CornellScene : public Scene
    {
    CornellScene ()
        {
        const float groundY = -1.f;
        const float roofY = 1.0;
            
        const float leftWallX = -1.f;
        const float rightWallX = 1.f;
            
        const float backWallZ = -2.5;
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
        geometry.push_back(ground1);
        
        Triangle ground2;
        ground2.vertices [0] = Linear::vec3(leftWallX, groundY, backWallZ);
        ground2.vertices [1] = Linear::vec3(rightWallX, groundY, frontWallZ);
        ground2.vertices [2] = Linear::vec3(rightWallX, groundY, backWallZ);
        ground2.normals  [0] = Linear::vec3::up;
        ground2.normals  [1] = Linear::vec3::up;
        ground2.normals  [2] = Linear::vec3::up;
        ground2.material.colour = groundColour;
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
        geometry.push_back(roof1);
        
        Triangle roof2;
        roof2.vertices [0] = Linear::vec3(leftWallX, roofY, backWallZ);
        roof2.vertices [1] = Linear::vec3(rightWallX, roofY, frontWallZ);
        roof2.vertices [2] = Linear::vec3(leftWallX, roofY, frontWallZ);
        roof2.normals  [0] = Linear::vec3::down;
        roof2.normals  [1] = Linear::vec3::down;
        roof2.normals  [2] = Linear::vec3::down;
        roof2.material.colour = roofColour;
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
        geometry.push_back(leftWall1);
    
        Triangle leftWall3;
        leftWall3.vertices [0] = Linear::vec3(leftWallX, groundY, backWallZ);
        leftWall3.vertices [1] = Linear::vec3(leftWallX, groundY, frontWallZ);
        leftWall3.vertices [2] = Linear::vec3(leftWallX, roofY, backWallZ);
        leftWall3.normals  [0] = Linear::vec3::left;
        leftWall3.normals  [1] = Linear::vec3::left;
        leftWall3.normals  [2] = Linear::vec3::left;
        leftWall3.material.colour = leftWallColour;
        geometry.push_back(leftWall3);
        
        Triangle leftWall2;
        leftWall2.vertices [0] = Linear::vec3(leftWallX, roofY, frontWallZ);
        leftWall2.vertices [1] = Linear::vec3(leftWallX, groundY, frontWallZ);
        leftWall2.vertices [2] = Linear::vec3(leftWallX, roofY, backWallZ);
        leftWall2.normals  [0] = Linear::vec3::left;
        leftWall2.normals  [1] = Linear::vec3::left;
        leftWall2.normals  [2] = Linear::vec3::left;
        leftWall2.material.colour = leftWallColour;
        geometry.push_back(leftWall2);
            
        Triangle leftWall4;
        leftWall4.vertices [0] = Linear::vec3(leftWallX, groundY, frontWallZ);
        leftWall4.vertices [1] = Linear::vec3(leftWallX, roofY, frontWallZ);
        leftWall4.vertices [2] = Linear::vec3(leftWallX, roofY, backWallZ);
        leftWall4.normals  [0] = Linear::vec3::left;
        leftWall4.normals  [1] = Linear::vec3::left;
        leftWall4.normals  [2] = Linear::vec3::left;
        leftWall4.material.colour = leftWallColour;
        geometry.push_back(leftWall4);
        
        const Linear::vec3 rightWallColour = Linear::vec3(0.5, 1, 1);
        Triangle rightWall1;
        rightWall1.vertices [0] = Linear::vec3(rightWallX,  roofY, backWallZ);
        rightWall1.vertices [1] = Linear::vec3(rightWallX, groundY, backWallZ);
        rightWall1.vertices [2] = Linear::vec3(rightWallX, groundY, frontWallZ);
        rightWall1.normals  [0] = Linear::vec3::right;
        rightWall1.normals  [1] = Linear::vec3::right;
        rightWall1.normals  [2] = Linear::vec3::right;
        rightWall1.material.colour = rightWallColour;
        geometry.push_back(rightWall1);
        
        Triangle rightWall2;
        rightWall2.vertices [0] = Linear::vec3(rightWallX, roofY, backWallZ);
        rightWall2.vertices [1] = Linear::vec3(rightWallX, groundY, frontWallZ);
        rightWall2.vertices [2] = Linear::vec3(rightWallX, roofY, frontWallZ);
        rightWall2.normals  [0] = Linear::vec3::right;
        rightWall2.normals  [1] = Linear::vec3::right;
        rightWall2.normals  [2] = Linear::vec3::right;
        rightWall2.material.colour = rightWallColour;
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
        geometry.push_back(backWall1);
        
        Triangle backWall2;
        backWall2.vertices [0] = Linear::vec3(leftWallX, roofY, backWallZ);
        backWall2.vertices [1] = Linear::vec3(rightWallX, groundY, backWallZ);
        backWall2.vertices [2] = Linear::vec3(rightWallX, roofY, backWallZ);
        backWall2.normals  [0] = Linear::vec3::forward;
        backWall2.normals  [1] = Linear::vec3::forward;
        backWall2.normals  [2] = Linear::vec3::forward;
        backWall2.material.colour = backWallColour;
        geometry.push_back(backWall2);
            
        Triangle tri1;
        tri1.vertices [0] = Linear::vec3(0.2, 0.25, -1);
        tri1.vertices [1] = Linear::vec3(-0.5, -0.65, -1);
        tri1.vertices [2] = Linear::vec3(0.6, -0.5, -1);
        tri1.normals  [0] = Linear::normalise(Linear::vec3( 0.0f,  0.6f, 1.0f));
        tri1.normals  [1] = Linear::normalise(Linear::vec3(-0.4f, -0.4f, 1.0f));
        tri1.normals  [2] = Linear::normalise(Linear::vec3( 0.4f, -0.4f, 1.0f));
        tri1.material.colour = Linear::vec3(1.0, 0.0, 1.0);
        geometry.push_back(tri1);
        
        Triangle tri2;
        tri2.vertices [0] = Linear::vec3(-0.5, -0.65, -1);
        tri2.vertices [1] = Linear::vec3(0.2, 0.25, -1);
        tri2.vertices [2] = Linear::vec3(0.6, -0.5, -1);
        tri2.normals  [0] = Linear::normalise(Linear::vec3(-0.4f, -0.4f, 1.0f));
        tri2.normals  [1] = Linear::normalise(Linear::vec3( 0.0f,  0.6f, 1.0f));
        tri2.normals  [2] = Linear::normalise(Linear::vec3( 0.4f, -0.4f, 1.0f));
        tri2.material.colour = Linear::vec3(1.0, 0.0, 1.0);
        geometry.push_back(tri2);
            
        PointLight light;
        light.position = Linear::vec3(0.0, 0.95f, 2.f);
        light.colour   = Linear::vec3(1.0, 1.0, 1.0);
        light.power    = Linear::vec3(12, 12, 12);
        //pLighting.push_back(light);
            
            
        AreaLight alight (Linear::vec3(0, 0.9f, -1.35), 0.5, 0.5, Linear::vec3(1.0, 1.0, 1.0), Linear::vec3(128, 128, 128));
        std::vector<Triangle> mesh = alight.mesh();
        aLighting.push_back(alight);
        geometry.insert(geometry.end(), mesh.begin(), mesh.end());
        }
    };

#endif /* CornellScene_h */
