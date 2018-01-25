/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  vec3.hpp
 *  LinearAlgebra
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef vec3_hpp
#define vec3_hpp

#include "Linear.hpp"
#include <string>
#include <cmath>

namespace Linear {
    struct vec3 {
        real x; real& r = x; real& one   = x;
        real y; real& g = y; real& two   = y;
        real z; real& b = z; real& three = z;
        vec3 (real _x, real _y, real _z): x(_x), y(_y), z(_z) {}
        vec3 (const vec3& v): x(v.x), y(v.y), z(v.z) {}
        vec3 (real _v): x(_v), y(_v), z(_v) {}
        vec3 (): x(0.0), y(0.0), z(0.0) {}
        static const vec3 up;
        static const vec3 down;
        static const vec3 left;
        static const vec3 right;
        static const vec3 forward;
        static const vec3 origin;
        static const vec3 zero;
        inline void operator = (vec3 rhs) { x  = rhs.x; y  = rhs.y; z  = rhs.z; }
        inline void operator+= (vec3 rhs) { x += rhs.x; y += rhs.y; z += rhs.z; }
        inline void operator-= (vec3 rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; }
        inline void operator/= (vec3 rhs) { x /= rhs.x; y /= rhs.y; z /= rhs.z; }
        inline void operator*= (vec3 rhs) { x *= rhs.x; y *= rhs.y; z *= rhs.z; }
        inline std::string string () const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")"; }
        inline std::string shapeString () const { return std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z) + "\n"; }
    };
    
    const vec3 vec3::up      = vec3(0.0, 1.0, 0.0);
    const vec3 vec3::down    = vec3(0.0, -1.0, 0.0);
    const vec3 vec3::left    = vec3(1.0, 0.0, 0.0);
    const vec3 vec3::right   = vec3(-1.0, 0.0, 0.0);
    const vec3 vec3::forward = vec3(0.0, 0.0, -1.0);
    const vec3 vec3::origin  = vec3(0.0);
    const vec3 vec3::zero    = vec3(0.0);

    inline vec3 operator + (vec3 lhs, vec3 rhs)
        { return vec3(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z); }
    inline vec3 operator - (vec3 lhs, vec3 rhs)
        { return vec3(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }
    inline vec3 operator / (vec3 lhs, vec3 rhs)
        { return vec3(lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z); }
    inline vec3 operator / (vec3 lhs, real rhs)
        { return vec3(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs); }
    inline vec3 operator * (vec3 lhs, vec3 rhs)
        { return vec3(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z); }
    inline vec3 operator * (vec3 lhs, real rhs)
        { return vec3(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs); }
    inline vec3 operator * (real lhs, vec3 rhs)
        { return vec3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z); }
    inline bool operator== (vec3 lhs, vec3 rhs)
        { return (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z); }
    inline bool operator!= (vec3 lhs, vec3 rhs)
        { return !(lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z); }
    inline real dot (vec3 lhs, vec3 rhs)
        { return (lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z); }
    inline vec3 cross (vec3 lhs, vec3 rhs)
        { return vec3(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x); }
    inline vec3 inverse (vec3 vec)
        { return vec * -1; }
    inline real magnitude (vec3 vec)
        { return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)); }
    inline vec3 normalise (vec3 vec)
        { return vec / magnitude(vec); }
    inline real distance (vec3 lhs, vec3 rhs)
        { return Linear::magnitude(lhs - rhs); }
    inline vec3 operator -(vec3 vec)
        { return inverse(vec); }
    real sum (vec3 vec)
        { return vec.x + vec.y + vec.z; }
    real average (vec3 vec)
        { return vec.x + vec.y + vec.z / 3; }
    inline vec3 reflect (vec3 i, vec3 n)
        { return i - 2.0 * dot(n, i) * n; }
    inline vec3 vabs (vec3 v)
        { return vec3(fabs(v.x), fabs(v.y), fabs(v.z)); }
    
    inline Linear::vec3 tangent1 (Linear::vec3 v)
        {
        Linear::vec3 result = (fabs(v.x) < 0.9f) ?
            Linear::vec3(1.0, 0.0, 0.0):
            Linear::vec3(0.0, 1.0, 0.0);
        return Linear::normalise(result - (v * Linear::dot(v, result)));
        }
    
    inline Linear::vec3 tangent2 (Linear::vec3 v)
        { return Linear::cross(v, tangent1(v)); }
}

#endif /* vec3_h */

