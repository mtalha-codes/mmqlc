#ifndef TRIGONOMETRY_HPP
#define TRIGONOMETRY_HPP
#include "boost_fwd.hpp"

namespace mmqli::core::trigonometry {
    // these are pretty small functions so i inlined them so that compiler won't spend time inlining these....

    inline float1000 cotangent(const float1000 &arg) {
        const float1000 tangent = tan(arg);
        float1000 cot = constants::ONE / tangent;
        return cot;
    }

    inline float1000 secant(const float1000 &arg) {
        const float1000 cosine = cos(arg);
        float1000 SEC = 1 / cosine;
        return SEC;
    }

    inline float1000 cosecant(const float1000 &arg) {
        const float1000 sine = sin(arg);
        float1000 CSC = 1 / sine;
        return CSC;
    }

    inline float1000 inverse_cotangent(const float1000 &arg) {
        const float1000 normalized_arg(1 / arg);
        float1000 acotngt = atan(normalized_arg);
        return acotngt;
    }

    inline float1000 inverse_secant(const float1000 &arg) {
        const float1000 suitable_arg(1 / arg);
        float1000 asecnt = acos(suitable_arg);
        return asecnt;
    }

    inline float1000 inverse_cosecant(const float1000 &arg) {
        const float1000 suitable_arg(1 / arg);
        float1000 cscnt = asin(suitable_arg);
        return cscnt;
    }

    inline float1000 cotangent_hyperbolic(const float1000 &arg) {
        const float1000 tangh = tanh(arg);
        float1000 coTh = 1 / tangh;
        return coTh;
    }

    inline float1000 secant_hyperbolic(const float1000 &arg) {
        const float1000 COSh = cosh(arg);
        float1000 SECh = 1 / COSh;
        return SECh;
    }

    inline float1000 cosecant_hyperbolic(const float1000 &arg) {
        const float1000 SINh = sinh(arg);
        float1000 CSCh = 1 / SINh;
        return CSCh;
    }

    inline float1000 inverse_cotangent_hyperbolic(const float1000 &arg) {
        const float1000 suitable_arg(1 / arg);
        float1000 acotngth = atanh(suitable_arg);
        return acotngth;
    }

    inline float1000 inverse_secant_hyperbolic(const float1000 &arg) {
        const float1000 suitable_arg(1 / arg);
        float1000 asecnth = acosh(suitable_arg);
        return asecnth;
    }

    inline float1000 inverse_cosecant_hyperbolic(const float1000 &arg) {
        const float1000 suitable_arg(1 / arg);
        float1000 cscnth = asinh(suitable_arg);
        return cscnth;
    }
}// mmqli::core::trigonometry
#endif