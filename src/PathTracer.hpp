/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  PathTracer.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef PathTracer_hpp
#define PathTracer_hpp

#include "SurfaceElement.hpp"
#include "CornellScene.hpp"
#include "EmptyCornell.hpp"
#include "Intersection.hpp"
#include "Linear/vec3.hpp"
#include "Linear/vec2.hpp"
#include "ShadowScene.hpp"
#include "SphereScene.hpp"
#include "ManySpheres.hpp"
#include "TestScene.hpp"
#include "Triangle.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Image.hpp"
#include "Ray.hpp"

#include <thread>

/* * * * * * * * * * * * * * * * * * * * * * * *
 *  Path Tracer
 *
 *  static methods for rendering an image
 *
 * * * * * * * * * * * * * * * * * * * * * * * */
namespace PathTracer
    {
    static void worker                            (Image* img, const Scene* scene, const Camera* camera, int x, int y, int samples);
    static void render                            (int width, int height, int nSamples);
    static Ray eyeRay                             (float x, float y, int width, int height, const Camera& camera);
    static Linear::vec3 trace                     (const Ray& ray, const Scene& scene, bool isEyeRay);
    static Linear::vec3 estimateDirectAreaLight   (SurfaceElement* surface, const Ray& ray, const Scene& scene);
    static Linear::vec3 estimateDirectPointLight  (SurfaceElement* surface, const Ray& ray, const Scene& scene);
    static Linear::vec3 estimateIndirectLight     (SurfaceElement* surface, const Ray& ray, const Scene& scene, bool isEyeRay);
    static Linear::vec3 estimateImpulseScattering (SurfaceElement* surface, const Ray& ray, const Scene& scene, bool isEyeRay);

    static void worker (Image& img, const Scene& scene, Camera& camera, int x, int y, int samples)
        {
        Linear::vec3 radiance (0.0, 0.0, 0.0);
        const Ray& ray = PathTracer::eyeRay (x + 0.5f, y + 0.5f, img.width, img.height, camera);
        for (int n = 0; n < samples; ++n)
            radiance += PathTracer::trace (ray, scene, true) / (float)samples;
        img.setPixel(x, y, radiance);
        }
        
    /**
     *  render
     *
     *  width       - horizontal size
     *  height      - vertical size
     *  nSamples    - the number of traces to average each pixel over
     */
    static void render (int width, int height, int nSamples)
        {
        Image img (width, height, Linear::vec3(0.006, 0.006, 0.006));
        const Scene& scene = EmptyCornell ();
        const Camera& camera = Camera();
        Random::init();

        std::vector<std::thread> pool;
            
        int x0 = 0, x1 = img.width;
        int y0 = 0, y1 = img.height;

/*
        for (int y = y0; y < y1; ++y)
            for (int x = x0; x < x1; ++x)
                pool.push_back(std::thread(
                    worker,
                    &img,
                    scene,
                    camera,
                    x, y, nSamples
                ));
*/

        for (int y = y0; y < y1; ++y)
            for (int x = x0; x < x1; ++x)
                { // for each pixel of the output image, cast into the scene and sample it
                Linear::vec3 radiance (0.0, 0.0, 0.0);
                const Ray& ray = eyeRay (x + 0.5f, y + 0.5f, img.width, img.height, camera);
                for (int n = 0; n < nSamples; ++n)
                    radiance += trace (ray, scene, true) / (float)nSamples;
                img.setPixel(x, y, radiance);
                } // for each pixel of the output image, cast into the scene and sample it


        img.writePixels (
            std::to_string(width)  + "x" +
            std::to_string(height) + "_" +
            std::to_string(nSamples), 64 );
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
        return Ray (origin, Linear::normalise(origin));
        }
        
    /**
     *  trace
     *
     *  probes the given scene for intersections with the given ray
     *  and calculates the colour value based on surface information
     *  taken from whatever it intersected with
     *
     *  ray         - the ray into the scene
     *  scene       - the geometry and lighting information
     *  isEyeRay    - true if this is the prime ray, false otherwise
     */
     static Linear::vec3 trace (const Ray& ray, const Scene& scene, bool isEyeRay)
        {
        Linear::vec3 output (0.0, 0.0, 0.0);
        SurfaceElement* surface;
        if ((surface = intersect(ray, scene)))
            { // if we hit something...
            if ((isEyeRay) && surface->material.emits)
                { // if eye ray hits a light, add emission
                output += surface->material.emission;
                } // if eye ray hits a light, add emission
            if ((!isEyeRay) || surface->material.reflectsDirect)
                { // compute direct illumination from point & area lights
                output += PathTracer::estimateDirectPointLight  (surface, ray, scene);
                output += PathTracer::estimateDirectAreaLight   (surface, ray, scene);
                } // compute direct illumination from point & area lights
            if ((!isEyeRay) ||  surface->material.scattersImpulse)
                { // compute impulse scattering
                //output += estimateImpulseScattering (surface, ray, scene, isEyeRay);
                } // compute impulse scattering
            if (!(isEyeRay) || surface->material.reflectsIndirect)
                { // finally, add in indirect illumination
                output += PathTracer::estimateIndirectLight     (surface, ray, scene, isEyeRay);
                } // finally, add in indirect illumination
            } // if we hit something...
        delete surface;
        return output;
        }
        
    /**
     *  estimateDirectPointLight
     *
     *  calculate the direct influence from point lights on the given surface 
     *
     *  surface     - surface information on the intersected geometry
     *  ray         - the ray into the scene
     *  scene       - the geometry and lighting information
     */
    static Linear::vec3 estimateDirectPointLight (SurfaceElement* surface, const Ray& ray, const Scene& scene)
        {
        Linear::vec3 output;
        for (const PointLight& light : scene.pLighting)
            { // for each point light in the scene
            Ray probe (surface->geometric.position, light.position);
            if (visible (probe, scene))
                { // if not in shadow
                // compute the incoming vector
                Linear::vec3 w_i = light.position - surface->shading.position;
                float distance = Linear::magnitude(w_i);
                // compute inverse square attenuation
                Linear::vec3 E_i = light.colour / (4 * M_PI * distance * distance);
                // use BSDF to convert to light output
                output += surface->evaluateBSDFfinite (w_i, -ray.direction()) *
                    E_i * fmax(0, Linear::dot(w_i, surface->shading.normal));
                } // if not in shadow
            } // for each point light in the scene
        return output;
        }
        
    /**
     *  estimateDirectAreaLight
     *
     *  calculate the direct influence from area lights on the given surface, taking 
     *  multiple samples for each light
     *
     *  surface     - surface information on the intersected geometry
     *  ray         - the ray into the scene
     *  scene       - the geometry and lighting information
     */
    static Linear::vec3 estimateDirectAreaLight (SurfaceElement* surface, const Ray& ray, const Scene& scene)
        {
        Linear::vec3 output;
        int nSamples = 64;
        for (const AreaLight& light : scene.aLighting)
            { // for each area light in the scene
            for (int i = 0; i < nSamples; ++i)
                { // sample the light n times
                // generate a random point on the surface of the light
                SurfaceElement lightSurface = light.samplePoint();
                Ray probe (surface->geometric.position, lightSurface.geometric.position);
                // cast shadow ray to determine visibility
                if (visible (probe, scene))
                    { // if not in shadow
                    // compute the incoming vector
                    Linear::vec3 w_i = lightSurface.geometric.position - surface->shading.position;
                    float distance = Linear::magnitude (w_i);
                    // inverse square
                    Linear::vec3 E_i = light.colour / (4 * M_PI * distance * distance);
                    // use BSDF to convert to light output
                    output += surface->evaluateBSDFfinite (w_i, -ray.direction()) *
                        E_i * fmax(0, Linear::dot(w_i, surface->shading.normal));
                    } // if not in shadow
                } // sample the light n times
            } // for each area light in the scene
        return output / (float)nSamples;
        }
        
    /**
     *  estimateImpulseScattering
     *
     *  trace impulses from this surface
     *
     *  surface     - surface information on the intersected geometry
     *  ray         - the ray into the scene
     *  scene       - the geometry and lighting information
     *  isEyeRay    - true if this is the prime ray, false otherwise
     */
    static Linear::vec3 estimateImpulseScattering(SurfaceElement* surface, const Ray& ray, const Scene& scene, bool isEyeRay)
        {
        Linear::vec3 impulseDirection = surface->getImpulseScatterDirection(-ray.direction());
        const Ray& secondaryRay = Ray (surface->geometric.position, impulseDirection);
        return PathTracer::trace (secondaryRay, scene, isEyeRay) * Linear::magnitude(surface->impulse);
        }
    
    /**
     *  estimateIndirectLight
     *
     *  back trace the photons path to determine influence from surfaces elsewhere in the scene
     *
     *  surface     - surface information on the intersected geometry
     *  ray         - the ray into the scene
     *  scene       - the geometry and lighting information
     *  isEyeRay    - true if this is the prime ray, false otherwise
     */
    static Linear::vec3 estimateIndirectLight (SurfaceElement* surface, const Ray& ray, const Scene& scene, bool isEyeRay)
        {
        if (Random::normalised() > surface->extinction ())
            { // the photon was extinguighed, return no light
            return Linear::vec3(0.0f, 0.0f, 0.0f);
            } // the photon was extinguished, return no light
        else
            { // the photon was not extinguished, bounce it and recurse
            Linear::vec3 bounce = Linear::reflect (-ray.direction(), surface->geometric.normal);
            Ray bounceRay (surface->geometric.position, bounce);
            return PathTracer::trace (bounceRay, scene, false);
            } // the photon was not extinguished, bounce it and recurse
        }
    };

#endif /* PathTracer_hpp */
