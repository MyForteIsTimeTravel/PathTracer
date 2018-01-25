/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  vec2.hpp
 *  LinearAlgebra
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef vec2_hpp
#define vec2_hpp

#include "Linear.hpp"
#include <string>
#include <cmath>

namespace Linear {
    struct vec2 {
        real x; real& u = x; real& one = x;
        real y; real& v = y; real& two = y;
        vec2 (real _x, real _y): x(_x), y(_y) {}
        vec2 (const vec2& v): x(v.x), y(v.y) {}
        vec2 (real _v): x(_v), y(_v) {}
        vec2 (): x(0.0), y(0.0) {}
        inline static vec2 up     () { return vec2(0.0,  1.0); }
        inline static vec2 down   () { return vec2(0.0, -1.0); }
        inline static vec2 left   () { return vec2(1.0,  0.0); }
        inline static vec2 right  () { return vec2(-1.0, 0.0); }
        inline static vec2 origin () { return vec2(0.0); }
        inline static vec2 zero   () { return vec2(0.0); }
        inline void operator = (vec2 rhs) { x  = rhs.x; y  = rhs.y; }
        inline void operator+= (vec3 rhs) { x += rhs.x; y += rhs.y; }
        inline void operator-= (vec3 rhs) { x -= rhs.x; y -= rhs.y; }
        inline void operator/= (vec3 rhs) { x /= rhs.x; y /= rhs.y; }
        inline void operator*= (vec3 rhs) { x *= rhs.x; y *= rhs.y; }
        inline std::string string () { return "("+std::to_string(x)+", "+std::to_string(y)+")"; }
        inline std::string shapeString () { return std::to_string(x) + " " + std::to_string(y) + "\n"; }
    };
    
    inline vec2 operator + (vec2 lhs, vec2 rhs)
        { return vec2(lhs.x + rhs.x, lhs.y + rhs.y); }
    inline vec2 operator - (vec2 lhs, vec2 rhs)
        { return vec2(lhs.x - rhs.x, lhs.y - rhs.y); }
    inline vec2 operator / (vec2 lhs, vec2 rhs)
        { return vec2(lhs.x / rhs.x, lhs.y / rhs.y); }
    inline vec2 operator / (vec2 lhs, real rhs)
        { return vec2(lhs.x / rhs, lhs.y / rhs); }
    inline vec2 operator * (vec2 lhs, vec2 rhs)
        { return vec2(lhs.x * rhs.x, lhs.y * rhs.y); }
    inline vec2 operator * (vec2 lhs, real rhs)
        { return vec2(lhs.x * rhs, lhs.y * rhs); }
    inline vec2 operator * (real lhs, vec2 rhs)
        { return vec2(lhs * rhs.x, lhs * rhs.y); }
    inline bool operator== (vec2 lhs, vec2 rhs)
        { return (lhs.x == rhs.x && lhs.y == rhs.y); }
    inline bool operator!= (vec2 lhs, vec2 rhs)
        { return !(lhs.x == rhs.x && lhs.y == rhs.y); }
    inline void operator+= (vec2 lhs, vec2 rhs)
        { lhs.x += rhs.x; lhs.y += rhs.y; }
    inline void operator-= (vec2 lhs, vec2 rhs)
        { lhs.x -= rhs.x; lhs.y -= rhs.y; }
    inline void operator/= (vec2 lhs, vec2 rhs)
        { lhs.x /= rhs.x; lhs.y /= rhs.y; }
    inline void operator*= (vec2 lhs, vec2 rhs)
        { lhs.x *= rhs.x; lhs.y *= rhs.y; }
    inline real dot (vec2 lhs, vec2 rhs)
        { return (lhs.x * rhs.x + lhs.y * rhs.y); }
    inline vec2 inverse (vec2 vec)
        { return vec * -1; }
    inline real magnitude (vec2 vec)
        { return sqrt(pow(vec.x, 2) + pow(vec.y, 2)); }
    inline vec2 normalise (vec2 vec)
        { return vec / magnitude(vec); }
    inline vec2 operator -(vec2 vec)
        { return inverse(vec); }
}

#endif /* vec2_h */

