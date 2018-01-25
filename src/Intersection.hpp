/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Intersection.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Intersection_hpp
#define Intersection_hpp

#include "Linear/vec3.hpp"
#include "Scene.hpp"
#include "Ray.hpp"

/**
 *  testTriangles
 *
 *  ray     - the ray throught the scene
 *  scene   - the scene with .geometry holding all the triangles
 *  out     - reference to the surface element pointer
 */
static void testTriangles (const Ray& ray, const Scene& scene, SurfaceElement*& out)
    {
    for (const Triangle& t : scene.geometry)
        { // test for intersections against the world
        const Linear::vec3& u = t.vertices[1] - t.vertices[0];
        const Linear::vec3& v = t.vertices[2] - t.vertices[0];
        const Linear::vec3& n = Linear::cross(ray.direction(), v);
        const float a = Linear::dot(u, n);
        const Linear::vec3& s = ray.origin() - t.vertices[0];
        const Linear::vec3& r = Linear::cross(s, u);
        float weight[3];
        weight[1] = Linear::dot(s, n) / a;
        weight[2] = Linear::dot(ray.direction(), r) / a;
        weight[0] = 1.0f - (weight[1] + weight[2]);
        const float d = Linear::dot(v, r) / a;
        static const float eps1 = 1e-7f;
        static const float eps2 = 1e-10;
        if (!((a <= eps1) || (weight[0] < -eps2) || (weight[1] < -eps2) || (weight[2] < -eps2) || (d <= 0.1f)))
            { // we hit a triangle
            const Linear::vec3& pos =
                ray.origin() + (ray.direction() * d);
            const Linear::vec3& norm =
                (weight[0] * t.normals[0]) +
                (weight[1] * t.normals[1]) +
                (weight[2] * t.normals[2]);
            delete out;
            out = new SurfaceElement(pos, pos, norm, norm);
            out->material = t.material;
            } // we hit a triangle
        } // test for intersections against the world
    }

/**
 *  testSpheres
 *
 *  ray     - the ray throught the scene
 *  scene   - the scene with .geometry holding all the triangles
 *  out     - reference to the surface element pointer
 */
static void testSpheres (const Ray& ray, const Scene& scene, SurfaceElement*& out)
    {
    for (const Sphere& sph : scene.spheres)
        { // test for intersections against the world
        Linear::vec3 u = ray.origin() - sph.position;
        float a = Linear::dot(ray.direction(), ray.direction());
        float b = 2 * Linear::dot(u, ray.direction());
        float c = Linear::dot(u, u) - pow (sph.radius, 2);
        float d = pow (b, 2) - 4 * a * c;
            
        if (d >= 0)
            { // we hit a sphere
            float t = (-b) + sqrt(d) / 2 * a;
            Linear::vec3 p =
                ray.origin() + (ray.direction() * t);
            Linear::vec3 n =
                Linear::normalise(sph.position - p);
            
            delete out;
            out = new SurfaceElement(p, p, n, n);
            out->material = sph.material;
            } // we hit a sphere
        } // test for intersections against the world
    }

/**
 *  intersect
 *
 *  ray     - the ray throught the scene
 *  scene   - the scene with .geometry holding all the triangles
 */
static SurfaceElement* intersect (const Ray& ray, const Scene& scene)
    {
    SurfaceElement* out = NULL;
    float distance = Linear::infinity;
    testTriangles (ray, scene, out);
    testSpheres   (ray, scene, out);
    return out;
    }

/**
 *  visible
 *
 *  ray     - the ray throught the scene
 *  scene   - the scene with .geometry holding all the triangles
 */
static bool visible (const Ray& ray, const Scene& scene)
    {
    SurfaceElement* surface = intersect(ray, scene);
    bool result = (surface == NULL);
    delete surface;
    return result;
    }

#endif /* Intersection_h */
