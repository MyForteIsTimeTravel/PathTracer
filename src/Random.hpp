/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Random.hpp
 *  Path Tracer
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Random_hpp
#define Random_hpp

#include "Linear/mat4.hpp"
#include "Linear/vec3.hpp"
#include "Linear/vec2.hpp"
#include <cstdlib>

/* * * * * * * * * * * * * * * * * * * * * * * *
 *  Random
 *
 *  static random number generator. wrapper on 
 *  standard C Rand, nothing fancy
 * * * * * * * * * * * * * * * * * * * * * * * */
struct Random
    {
    static void init ()
        { srand((int)time(NULL)); }

    static void init (int seed)
        { srand(seed); }

    /** 
     *  random integer 0 to RAND_MAX
     */ 
    static int value ()
        { return rand(); }

    /** 
     *  random float 0.0f to 1.0f
     */ 
    static float normalised ()
        { return value () / (float) RAND_MAX; }
    
    /** 
     *  random float min to max
     */ 
    static float value (float min, float max)
        { return (normalised () * (max - min)) + min; }

    /** 
     *  random float min to max
     */ 
    static Linear::vec2 monteCarloDirection2D ()
        {
        while (true)
            {
            Linear::vec2 vec;
            vec.x = value(-1.0, 1.0);
            vec.y = value(-1.0, 1.0);
            float mag = Linear::magnitude(vec);
            if (mag <= 1.0f) return Linear::normalise(vec);
            }
        return Linear::vec2(0.0, 0.0);
        }
    
    /**
     *  cosine distributed hemisphere vector
     */
    static Linear::vec3 cosHemisphereVector ()
        {
        float theta = value (0.0, 2 * M_PI);
        float s     = value (0.0, 1.0);
        float y     = sqrt (s);
        float r     = sqrt (1 - pow(y, 2));
        return Linear::vec3 (r * cos(theta), y, r * sin(theta));
        }
    
    /**
     *  uniform distributed hemisphere vector
     */
    static Linear::vec3 uniHemisphereVector ()
        {
        float y = 1 / (2 * M_PI);
        float u = normalised();
        float v = normalised();
        float r = sqrt(1 - pow (y, 2));
        return Linear::vec3 (r * cos(2 * M_PI * u), y, r * sin (2 * M_PI * u));
        }
    };

#endif /* Random_h */
