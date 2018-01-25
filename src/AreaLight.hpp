/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  AreaLight.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef AreaLight_hpp
#define AreaLight_hpp

#include "SurfaceElement.hpp"
#include "Linear/vec3.hpp"
#include "Triangle.hpp"
#include "Random.hpp"
#include <vector>

/* * * * * * * * * * * * * * * * * * * * * * * *
 *  AreaLight
 *
 *  Assumed to lie flat on the Z axis
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
struct AreaLight
    {
    Linear::vec3 position; // center of the light
    Linear::vec3 a;        // top left vertex
    Linear::vec3 b;        // top right vertex
    Linear::vec3 c;        // bottom right vertex
    Linear::vec3 d;        // bottom left vertex
    float height;          // size across the Z axis
    float width;           // size across the X axis
    Linear::vec3 colour;
    Linear::vec3 power;
        
    /** 
     *  constructed with a position, size and colour arguments
     */
    AreaLight (Linear::vec3 pos, float _width, float _height, Linear::vec3 col, Linear::vec3 pow):
        position (pos), colour (col), power (pow), width (_width), height (_height)
        {
        a = position + Linear::vec3(-(width/2), 0,  (height/2));
        b = position + Linear::vec3( (width/2), 0,  (height/2));
        c = position + Linear::vec3( (width/2), 0, -(height/2));
        d = position + Linear::vec3(-(width/2), 0, -(height/2));
        }
        
    /** 
     *  samples the light area for a point and returns a 
     *  surface element at that point
     */
    SurfaceElement samplePoint () const
        {
        Linear::vec2 sample = Random::monteCarloDirection2D();
        Linear::vec3 point = Linear::vec3(position.x * sample.x, position.y, position.z * sample.y);
        SurfaceElement surface (point, point, Linear::vec3::down, Linear::vec3::down);
        return surface;
        }

    /** 
     *  returns a mesh representing the light
     */   
    std::vector<Triangle> mesh ()
        {
        std::vector<Triangle> tris;
        tris.push_back(Triangle());
        tris.push_back(Triangle());
        tris.push_back(Triangle());
        tris.push_back(Triangle());
        tris[0].vertices[0]     = c;
        tris[0].vertices[1]     = a;
        tris[0].vertices[2]     = b;
        tris[1].vertices[0]     = c;
        tris[1].vertices[1]     = d;
        tris[1].vertices[2]     = a;
        tris[0].normals[0]      = Linear::vec3::down;
        tris[0].normals[1]      = Linear::vec3::down;
        tris[0].normals[2]      = Linear::vec3::down;
        tris[1].normals[0]      = Linear::vec3::down;
        tris[1].normals[1]      = Linear::vec3::down;
        tris[1].normals[2]      = Linear::vec3::down;
        tris[2].vertices[0]     = a;
        tris[2].vertices[1]     = c;
        tris[2].vertices[2]     = b;
        tris[3].vertices[0]     = d;
        tris[3].vertices[1]     = c;
        tris[3].vertices[2]     = a;
        tris[2].normals[0]      = Linear::vec3::down;
        tris[2].normals[1]      = Linear::vec3::down;
        tris[2].normals[2]      = Linear::vec3::down;
        tris[3].normals[0]      = Linear::vec3::down;
        tris[3].normals[1]      = Linear::vec3::down;
        tris[3].normals[2]      = Linear::vec3::down;
        tris[0].material.colour = colour;
        tris[1].material.colour = colour;
        tris[2].material.colour = colour;
        tris[3].material.colour = colour;
        tris[0].material.emission = colour;
        tris[1].material.emission = colour;
        tris[2].material.emission = colour;
        tris[3].material.emission = colour;
        tris[0].material.emits = true;
        tris[1].material.emits = true;
        tris[2].material.emits = true;
        tris[3].material.emits = true;
        tris[0].material.extinction = 0.9f;
        tris[1].material.extinction = 0.9f;
        tris[2].material.extinction = 0.9f;
        tris[3].material.extinction = 0.9f;
            
        return tris;
        }
    };

#endif /* AreaLight_h */
