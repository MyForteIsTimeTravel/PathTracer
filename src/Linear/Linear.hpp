/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  Linear.hpp
 *  LinearAlgebra
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef Linear_hpp
#define Linear_hpp

#include <cmath>

namespace Linear {
    typedef double real;
    typedef int bit;
    typedef int integral;
    inline real deg2rad (real d) { return d * (M_PI/180); }
    inline real rad2deg (real r) { return r * (180/M_PI); }
    const  real infinity = std::numeric_limits<real>::max();
    inline bool fequal (real a, real b) { return fabs(a - b) < 0.001; }
    inline integral cap (integral n, integral max) { return (n > max) ? max : n; }
    inline real range (real min, real max, real val) { return (val < min) ? min : (val > max) ? max : val; }
}


#endif /* Linear_h */
