//
//  quaternion.hpp
//  Linear
//
//  Created by laptop on 17/11/2017.
//  Copyright © 2017 RyanNeedham. All rights reserved.
//

#ifndef quaternion_hpp
#define quaternion_hpp

#include "Linear.hpp"
#include "mat4.hpp"
#include "vec3.hpp"

namespace Linear {
    struct quaternion {
        vec4 v;
        
        quaternion (real _x, real _y, real _z, real _w): v (_x, _y, _z, _w) {}
        quaternion (const quaternion& _): v(_.v) {}
        quaternion (vec4 _v) : v (_v) {}
        quaternion (): v (0, 0, 0, 1) {}
        
        static quaternion fromVtoV (vec3 v1, vec3 v2) {
            quaternion q;
            vec3 a = cross (v1, v2);
            q.v.x = a.x;
            q.v.y = a.y;
            q.v.z = a.z;
            q.v.w = sqrt(pow(Linear::magnitude(v1), 2) * pow(Linear::magnitude(v2), 2)) + dot (v1, v2);
            return normalize(q);
        }
        
        static inline quaternion conj (quaternion q)
            { return quaternion (-q.v.x, -q.v.y, -q.v.z, q.v.w); }
        static inline real magnitude (quaternion q)
            { return sqrt(pow(q.v.w, 2) + pow(q.v.x, 2) + pow(q.v.y, 2) + pow(q.v.z, 2)); }
        static inline quaternion normalize (quaternion q)
            { return q.v * ( 1.0f/sqrt(q.v.x * q.v.x + q.v.y * q.v.y + q.v.z * q.v.z + q.v.w * q.v.w)); }
        
        std::string string ()
            { return "(" + std::to_string(v.w) + " [" + std::to_string(v.x) + ", " + std::to_string(v.y) + ", " + std::to_string(v.z) + "])"; }
    };
    
    quaternion product (quaternion lhs, quaternion rhs) {
        return quaternion (
            (lhs.v.w * rhs.v.w) - (lhs.v.x * rhs.v.x) - (lhs.v.y * rhs.v.y) - (lhs.v.z * rhs.v.z),
            (lhs.v.w * rhs.v.x) + (lhs.v.x * rhs.v.w) + (lhs.v.y * rhs.v.z) - (lhs.v.z * rhs.v.y),
            (lhs.v.w * rhs.v.y) - (lhs.v.x * rhs.v.z) + (lhs.v.y * rhs.v.w) + (lhs.v.z * rhs.v.x),
            (lhs.v.w * rhs.v.z) + (lhs.v.x * rhs.v.y) - (lhs.v.y * rhs.v.x) + (lhs.v.z * rhs.v.w)
        );
    }
    
    mat4 matrix (quaternion q) {
        return mat4(
            vec4(1.0f - 2.0f * q.v.y * q.v.y - 2.0f * q.v.z * q.v.z, 2.0f * q.v.x * q.v.y - 2.0f * q.v.z * q.v.w, 2.0f * q.v.x * q.v.z + 2.0f * q.v.y * q.v.w, 0.0f),
            vec4(2.0f * q.v.x * q.v.y + 2.0f * q.v.z * q.v.w, 1.0f - 2.0f * q.v.x * q.v.x - 2.0f * q.v.z * q.v.z, 2.0f * q.v.y * q.v.z - 2.0f * q.v.x * q.v.w, 0.0f),
            vec4(2.0f * q.v.x * q.v.z - 2.0f * q.v.y * q.v.w, 2.0f * q.v.y * q.v.z + 2.0f * q.v.x * q.v.w, 1.0f - 2.0f * q.v.x * q.v.x - 2.0f * q.v.y * q.v.y, 0.0f),
            vec4(0.0f, 0.0f, 0.0f, 1.0f)
        );
    }
    
    inline quaternion operator * (quaternion lhs, quaternion rhs)
        { return product (lhs, rhs); }
    inline quaternion operator * (quaternion lhs, real rhs)
        { return quaternion(lhs.v * rhs); }
    inline quaternion operator * (real lhs, quaternion rhs)
        { return quaternion(lhs * rhs.v); }
    inline bool operator== (quaternion lhs, quaternion rhs)
        { return fequal(lhs.v.w, rhs.v.w) && fequal(lhs.v.x, rhs.v.x) && fequal(lhs.v.y, rhs.v.y) && fequal(lhs.v.z, rhs.v.z); }
}

#endif /* quaternion_h */


/**/
