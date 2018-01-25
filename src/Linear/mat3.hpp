/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  mat3.hpp
 *  LinearAlgebra
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef mat3_hpp
#define mat3_hpp

#include "Linear.hpp"
#include "vec3.hpp"
#include <cmath>

namespace Linear {
    struct mat3 {
        /** values stored in rows */
        vec3 a, b, c;
        
        /** compute collumns when needed */
        vec3 x () { return vec3(a.x, b.x, c.x); }
        vec3 y () { return vec3(a.y, b.y, c.y); }
        vec3 z () { return vec3(a.z, b.z, c.z); }
        
        mat3 (vec3 _a, vec3 _b, vec3 _c):
            a (_a), b (_b), c (_c) {}
        mat3 ():
            a (1.0, 0.0, 0.0),
            b (0.0, 1.0, 0.0),
            c (0.0, 0.0, 1.0) {}
        
        static mat3 identity ()
            { return mat3 (); }
        
        static mat3 product (mat3 lhs, mat3 rhs) {
            mat3 result;
            result.a.x = Linear::dot(lhs.a, rhs.x());
            result.a.y = Linear::dot(lhs.a, rhs.y());
            result.a.z = Linear::dot(lhs.a, rhs.z());
            result.b.x = Linear::dot(lhs.b, rhs.x());
            result.b.y = Linear::dot(lhs.b, rhs.y());
            result.b.z = Linear::dot(lhs.b, rhs.z());
            result.c.x = Linear::dot(lhs.c, rhs.x());
            result.c.y = Linear::dot(lhs.c, rhs.y());
            result.c.z = Linear::dot(lhs.c, rhs.z());
            return result;
        }
        
        static mat3 product (real lhs, mat3 rhs) {
            rhs.a.x *= lhs; rhs.a.y *= lhs; rhs.a.z *= lhs;
            rhs.b.x *= lhs; rhs.b.y *= lhs; rhs.b.z *= lhs;
            rhs.c.x *= lhs; rhs.c.y *= lhs; rhs.c.z *= lhs;
            return rhs;
        }
        
        std::string string ()
            { return a.string() + "\n" + b.string() + "\n" + c.string() + "\n"; }
        std::string shapeString ()
            { return string(); }
    };
    
    inline bool operator== (mat3 lhs, mat3 rhs)
        { return lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c; }

    mat3 operator * (mat3 lhs, mat3 rhs)
        { return mat3::product (lhs, rhs); }
    mat3 operator * (real lhs, mat3 rhs)
        { return mat3::product (lhs, rhs); }
    mat3 operator * (mat3 lhs, real rhs)
        { return mat3::product (rhs, lhs); }
}

#endif /* mat3_h */
