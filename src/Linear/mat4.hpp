/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  mat4.hpp
 *  LinearAlgebra
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef mat4_hpp
#define mat4_hpp

#include "Linear.hpp"
#include "vec4.hpp"
#include <cmath>

namespace Linear {
    struct mat4 {
        /** values stored in rows */
        vec4 a, b, c, d;
        
        /** compute collumns when needed */
        vec4 x () { return vec4(a.x, b.x, c.x, d.x); }
        vec4 y () { return vec4(a.y, b.y, c.y, d.y); }
        vec4 z () { return vec4(a.z, b.z, c.z, d.z); }
        vec4 w () { return vec4(a.w, b.w, c.w, d.w); }
        
        mat4 (vec4 _a, vec4 _b, vec4 _c, vec4 _d):
            a (_a), b (_b), c (_c), d (_d) {}
        mat4 ():
            a (1.0, 0.0, 0.0, 0.0),
            b (0.0, 1.0, 0.0, 0.0),
            c (0.0, 0.0, 1.0, 0.0),
            d (0.0, 0.0, 0.0, 1.0) {}
        
        static mat4 identity ()
            { return mat4 (); }
        
        static mat4 product (mat4 lhs, mat4 rhs) {
            mat4 result;
            result.a.x = Linear::dot(lhs.a, rhs.x());
            result.a.y = Linear::dot(lhs.a, rhs.y());
            result.a.z = Linear::dot(lhs.a, rhs.z());
            result.a.w = Linear::dot(lhs.a, rhs.w());
            result.b.x = Linear::dot(lhs.b, rhs.x());
            result.b.y = Linear::dot(lhs.b, rhs.y());
            result.b.z = Linear::dot(lhs.b, rhs.z());
            result.b.w = Linear::dot(lhs.b, rhs.w());
            result.c.x = Linear::dot(lhs.c, rhs.x());
            result.c.y = Linear::dot(lhs.c, rhs.y());
            result.c.z = Linear::dot(lhs.c, rhs.z());
            result.c.w = Linear::dot(lhs.c, rhs.w());
            result.d.x = Linear::dot(lhs.d, rhs.x());
            result.d.y = Linear::dot(lhs.d, rhs.y());
            result.d.z = Linear::dot(lhs.d, rhs.z());
            result.d.w = Linear::dot(lhs.d, rhs.w());
            return result;
        }
        
        static mat4 product (real lhs, mat4 rhs) {
            rhs.a.x *= lhs; rhs.a.y *= lhs; rhs.a.z *= lhs; rhs.a.w *= lhs;
            rhs.b.x *= lhs; rhs.b.y *= lhs; rhs.b.z *= lhs; rhs.b.w *= lhs;
            rhs.c.x *= lhs; rhs.c.y *= lhs; rhs.c.z *= lhs; rhs.c.w *= lhs;
            rhs.d.x *= lhs; rhs.d.y *= lhs; rhs.d.z *= lhs; rhs.d.w *= lhs;
            return rhs;
        }
        
        static vec4 product (vec4 lhs, mat4 rhs) {
            return vec4 (
                rhs.a.x * lhs.x + rhs.a.y * lhs.y + rhs.a.z * lhs.z + rhs.a.w * lhs.w,
                rhs.b.x * lhs.x + rhs.b.y * lhs.y + rhs.b.z * lhs.z + rhs.b.w * lhs.w,
                rhs.c.x * lhs.x + rhs.c.y * lhs.y + rhs.c.z * lhs.z + rhs.c.w * lhs.w,
                rhs.d.x * lhs.x + rhs.d.y * lhs.y + rhs.d.z * lhs.z + rhs.d.w * lhs.w
            );
        }
        
        static mat4 translate (real _x, real _y, real _z) {
            mat4 result;
            result.a.w = _x;
            result.b.w = _y;
            result.c.w = _z;
            return result;
        }
        
        static mat4 scale (real _x, real _y, real _z) {
            mat4 result;
            result.a.x = _x;
            result.b.y = _y;
            result.c.z = _z;
            return result;
        }
        
        static mat4 rotateZ (real th) {
            mat4 result;
            result.a.x =  cos(th); result.a.y =  sin(th);
            result.b.x = -sin(th); result.b.y =  cos(th);
            return result;
        }
        
        static mat4 rotateX (real th) {
            mat4 result;
            result.b.y =  cos(th); result.b.z =  sin(th);
            result.c.y = -sin(th); result.c.z =  cos(th);
            return result;
        }
        
        static mat4 rotateY (real th) {
            mat4 result;
            result.a.x =  cos(th); result.a.z = -sin(th);
            result.c.x =  sin(th); result.c.z =  cos(th);
            return result;
        }
        
        static mat4 rotateEuler (real _x, real _y, real _z) {
            mat4 z = rotateZ(_z);
            mat4 x = rotateX(_x);
            mat4 y = rotateY(_y);
            return product(z, product(x, y));
        }
        
        std::string string ()
            { return a.string() + "\n" + b.string() + "\n" + c.string() + "\n" + d.string(); }
        std::string shapeString ()
            { return string(); }
    };
    
    inline bool operator== (mat4 lhs, mat4 rhs)
        { return lhs.a == rhs.a && lhs.b == rhs.b && lhs.c == rhs.c && lhs.d == rhs.d; }
    
    mat4 operator * (mat4 lhs, mat4 rhs)
        { return mat4::product (lhs, rhs); }
    mat4 operator * (real lhs, mat4 rhs)
        { return mat4::product (lhs, rhs); }
    mat4 operator * (mat4 lhs, real rhs)
        { return mat4::product (rhs, lhs); }
    vec4 operator * (vec4 lhs, mat4 rhs)
        { return mat4::product (lhs, rhs); }
    vec4 operator * (mat4 lhs, vec4 rhs)
        { return mat4::product (rhs, lhs); }
    
    static mat4 project (real fov, real aspect, real near, real far) {
        mat4 result;
        real thfov = tan(fov / 2);
        result.a.x = (real)1 / (aspect * thfov);
        result.b.y = (real)1 / thfov;
        result.c.z = -(far + near) / (far - near);
        result.c.w = (real)1;
        result.d.z = ((real)2 * far * near) / (far - near);
        return result;
    }
    
    static mat4 look (vec3 eye, vec3 center, vec3 up) {
        mat4 result;
        vec3 f = normalise(center - eye);
        vec3 s = normalise(cross(f, up));
        vec3 u = cross(s, f);
        result.a.x = s.x;
        result.b.x = s.y;
        result.c.x = s.z;
        result.a.y = u.x;
        result.b.y = u.y;
        result.c.y = u.z;
        result.a.z =-f.x;
        result.b.z =-f.y;
        result.c.z =-f.z;
        result.d.x =-dot(s, eye);
        result.d.y =-dot(u, eye);
        result.d.z = dot(f, eye);
        return result;
    }
}

#endif /* mat4_h */
