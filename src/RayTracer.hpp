/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  RayTracer.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef RayTracer_hpp
#define RayTracer_hpp

#include "Linear/vec3.hpp"
#include "Linear/vec2.hpp"
#include "ShadowScene.hpp"
#include "SphereScene.hpp"
#include "CornellScene.hpp"
#include "TestScene.hpp"
#include "Triangle.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Image.hpp"
#include "Ray.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * *
 *
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
struct RayTracer
    {
        
    /**
     *  render
     */
    static void render (int width, int height)
        {
        Image img = Image (width, height, Linear::vec3(0.006, 0.006, 0.006));
        CornellScene scene;
        const Camera camera;
        int x0 = 0, x1 = img.width;
        int y0 = 0, y1 = img.height;
        for (int y = y0; y < y1; ++y)
            for (int x = x0; x < x1; ++x)
                { // for each pixel of the output image
                    
                /** calculate the eye ray and set up radiance & distance variables */
                const Ray& r = eyeRay (x + 0.5f, y + 0.5f, img.width, img.height, camera);
                float dist = Linear::infinity;
                Linear::vec3 outgoingLight;
                    
                /** iterate through the scenes geometry and rasterize accordingly */
                for (Triangle& t : scene.geometry)
                    if (sample(scene, x, y, r, t, outgoingLight, img))
                        {
                        img.setPixel(x, y, outgoingLight);
                        //img.setDepth(x, y, dist);
                        }
                } // for each pixel of the output image
            
        img.writePixels("ray_frag_cornell", 4);
        img.writeDepth("ray_depth_cornell", 4);
        }
        
    /**
     *  sample
     *
     *  scene       -
     *  x           -
     *  y           -
     *  ray         -
     *  tri         -
     *  radiance    -
     *  distance    -
     */
    static bool sample (const Scene& scene, int x, int y, const Ray& ray, const Triangle& tri, Linear::vec3& radiance, Image& img)
        {
        float weight[3];
        const float d = intersect (ray, tri, weight);
        if (d >= img.getDepth(x, y)) return false;
        img.setDepth(x, y, d);
        const Linear::vec3& p = ray.origin() + ray.direction() * d;
        const Linear::vec3& n = Linear::normalise(
            tri.normals[0] * weight[0] +
            tri.normals[1] * weight[1] +
            tri.normals[2] * weight[2]
        );
        Linear::vec3 w_o = ray.direction() * -1;
        //shade (scene, tri.bsdf, p, n, w_o, radiance);
            
        /** debug radiances*/
        //radiance = Linear::vec3(0.1, 0.1, 0.1) * d; // white on any intersect
        radiance = Linear::vec3(weight[0], weight[1], weight[2]); // barycentrics
        return true;
        }
        
    /**
     *  eyeRay
     *
     *  x           -
     *  y           -
     *  width       -
     *  height      -
     *  camera      -
     */
    static Ray eyeRay (float x, float y, int width, int height, const Camera& camera)
        {
        const float aspect = float(height) / width;
        const float s = -2.0f * tan(camera.fov * 0.5);
        Linear::vec3 origin ((x / width - 0.5f) * s, -(y / height - 0.5f) * s * aspect, 1.0f);
        origin *= camera.near;
        return Ray(origin, Linear::normalise(origin));
        }
    
    /**
     *  intersect
     *
     *  ray         -
     *  tri         -
     *  weight      -
     */
    static float intersect (const Ray& ray, const Triangle& tri, float weight[3])
        {
        const Linear::vec3& u = tri.vertices[1] - tri.vertices[0];
        const Linear::vec3& v = tri.vertices[2] - tri.vertices[0];
        const Linear::vec3& n = Linear::cross(ray.direction(), v);
        const float a = Linear::dot(u, n);
        const Linear::vec3& s = ray.origin() - tri.vertices[0];
        const Linear::vec3& r = Linear::cross(s, u);
        weight[1] = Linear::dot(s, n) / a;
        weight[2] = Linear::dot(ray.direction(), r) / a;
        weight[0] = 1.0f - (weight[1] + weight[2]);
        const float dist = Linear::dot(v, r) / a;
        static const float eps1 = 1e-7f;
        static const float eps2 = 1e-10;
        if ((a <= eps1) || (weight[0] < -eps2) || (weight[1] < -eps2) || (weight[2] < -eps2) || (dist <= 0.0f))
            return Linear::infinity;
        else return dist;
        }
    
    static float intersect (const Ray& ray, const Sphere& sph)
        {
        const Linear::vec3& u = ray.origin() - sph.position;
        const Linear::vec3& v = ray.direction();
        const float a = Linear::dot(v, v);
        const float b = 2 * Linear::dot(u, v);
        const float c = Linear::dot(u, u) - pow(sph.radius, 2);
        return (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
        }
    
    /**
     *  shade
     *
     *  scene       -
     *  tri         -
     *  p           -
     *  n           -
     *  w_o         -
     *  l_o         -
     */
    static void shade (const Scene& scene, const BSDF& bsdf, const Linear::vec3& p, const Linear::vec3& n, const Linear::vec3& w_o, Linear::vec3& l_o)
        {
        l_o = Linear::vec3::zero;
        
        for (const PointLight& light : scene.pLighting)
            { // for each point light in the scene
            const Linear::vec3 offset = light.position - p;
            const float dist = Linear::magnitude(offset);
            const Linear::vec3 w_i = offset / dist;
                
            if (visible (p, w_i, dist, scene))
                {
                const Linear::vec3& l_i = light.power / (4 * M_PI * pow(dist, 2));
                l_o += l_i * bsdf.evaluateFiniteScatteringDensity(w_i, w_o, n) * fmax(0.0, Linear::dot(w_i, n));
                }
            } // for each point light in the scene
        }
        
    /**
     *  visible
     *
     *  p           -
     *  direction   -
     *  dist        -
     *  scene       -
     */
    static bool visible (const Linear::vec3& p, const Linear::vec3& direction, float dist, const Scene& scene)
        {
        static const float bumpEps = 1e-4;
        const Ray probe (p + direction * bumpEps, direction);
        dist -= bumpEps;
        float ignore[3];
        for (const Triangle& tri : scene.geometry)
            if (intersect(probe, tri, ignore) < dist) return false;
        return true;
        }
    };

#endif /* RayTracer_h */
