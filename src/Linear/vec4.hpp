/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  vec4.hpp
 *  LinearAlgebra
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef vec4_hpp
#define vec4_hpp

#include "Linear.hpp"
#include "vec3.hpp"
#include <string>
#include <cmath>

namespace Linear {
    struct vec4 {
        real x; real& r = x; real& one   = x;
        real y; real& g = y; real& two   = y;
        real z; real& b = z; real& three = z;
        real w; real& a = w; real& four  = w;
        vec4 (real _x, real _y, real _z, real _w): x(_x), y(_y), z(_z), w(_w) {}
        vec4 (const vec4& v): x(v.x), y(v.y), z(v.z), w(v.w) {}
        vec4 (): x(0.0), y(0.0), z(0.0), w(0.0) {}
        inline vec3 xyz () { return vec3(x, y, z); }
        inline void operator = (vec4 rhs) { x  = rhs.x; y  = rhs.y; z  = rhs.z; w  = rhs.w; }
        inline void operator+= (vec4 rhs) { x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w; }
        inline void operator-= (vec4 rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; w -= rhs.w; }
        inline void operator/= (vec4 rhs) { x /= rhs.x; y /= rhs.y; z /= rhs.z; w /= rhs.w; }
        inline void operator*= (vec4 rhs) { x *= rhs.x; y *= rhs.y; z *= rhs.z; w *= rhs.w; }
        inline std::string string () { return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ")"; }
        inline std::string shapeString () { return std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + std::to_string(w) + "\n"; }
    };
    
    inline vec4 operator + (vec4 lhs, vec4 rhs)
        { return vec4(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w); }
    inline vec4 operator - (vec4 lhs, vec4 rhs)
        { return vec4(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w); }
    inline vec4 operator / (vec4 lhs, vec4 rhs)
        { return vec4(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w); }
    inline vec4 operator / (vec4 lhs, real rhs)
        { return vec4(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs); }
    inline vec4 operator * (vec4 lhs, vec4 rhs)
        { return vec4(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w); }
    inline vec4 operator * (vec4 lhs, real rhs)
        { return vec4(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs); }
    inline vec4 operator * (real lhs, vec4 rhs)
        { return vec4(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w); }
    inline bool operator== (vec4 lhs, vec4 rhs)
        { return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w); }
    inline bool operator!= (vec4 lhs, vec4 rhs)
        { return !(lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z && lhs.w == rhs.w); }
    inline real dot (vec4 lhs, vec4 rhs)
        { return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w); }
    inline vec4 inverse (vec4 vec)
        { return vec * -1; }
    inline real magnitude (vec4 vec)
        { return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2) + pow(vec.w, 2)); }
    inline vec4 normalise (vec4 vec)
        { return vec / magnitude(vec); }
    inline vec4 operator -(vec4 vec)
        { return inverse(vec); }
}

#endif /* vec4_h */

