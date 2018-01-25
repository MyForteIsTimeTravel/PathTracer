/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Line.hpp
 *  RaytraceRenderer
 *
 *  small struct representing a line in its general form
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Line_hpp
#define Line_hpp

#include "vec3.hpp"

namespace Linear {
    struct Line {
        const vec3 p;
        const vec3 q;
        real a, b, c;

        Line (Linear::vec3 _p, Linear::vec3 _q):
            p (_p), q (_q), a (_p.y - _q.y), b (q.x - p.x), c (((p.x - q.x) * p.y) + ((q.y - p.y) * p.x)) {
        }
    };
    
    /** calculates the distance between the point, P, and the line, L */
    inline Linear::real distance (Linear::vec3 p, Linear::Line l)
        { return fabs((l.a * p.x) + (l.b * p.y) + l.c) / sqrt(pow(l.a, 2) + pow(l.b, 2)); }
}

#endif /* Line_h */
