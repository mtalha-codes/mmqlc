/*
 * Filename: mmqlc.functions.hpp
 * Author: Muhammad Talha
 * Github: MTalha-Codes
 * Repository: mmqlc
 * Copyright(C) - 2024
 * */

#ifndef MMQLC_FUNCTIONS_HPP
#define MMQLC_FUNCTIONS_HPP

#include "constants.hpp"
#include <cmath>
#include "boost_fwd.hpp"


namespace math::functions::realTrig {
    inline float1000 cot(const float1000 &arg) {
        const float1000 tang = tan(arg);
        float1000 coT = 1 / tang;
        return coT;
    }

    inline float1000 sec(const float1000 &arg) {
        const float1000 COS = cos(arg);
        float1000 SEC = 1 / COS;
        return SEC;
    }

    inline float1000 csc(const float1000 &arg) {
        const float1000 SIN = sin(arg);
        float1000 CSC = 1 / SIN;
        return CSC;
    }

    inline float1000 acot(const float1000 &arg) {
        const float1000 suitable_arg(1 / arg);
        float1000 acotngt = atan(suitable_arg);
        return acotngt;
    }

    inline float1000 asec(const float1000 &arg) {
        const float1000 suitable_arg(1 / arg);
        float1000 asecnt = acos(suitable_arg);
        return asecnt;
    }

    inline float1000 acsc(const float1000 &arg) {
        const float1000 suitable_arg(1 / arg);
        float1000 cscnt = asin(suitable_arg);
        return cscnt;
    }

    inline float1000 coth(const float1000 &arg) {
        const float1000 tangh = tanh(arg);
        float1000 coTh = 1 / tangh;
        return coTh;
    }

    inline float1000 sech(const float1000 &arg) {
        const float1000 COSh = cosh(arg);
        float1000 SECh = 1 / COSh;
        return SECh;
    }

    inline float1000 csch(const float1000 &arg) {
        const float1000 SINh = sinh(arg);
        float1000 CSCh = 1 / SINh;
        return CSCh;
    }

    inline float1000 acoth(const float1000 &arg) {
        const float1000 suitable_arg(1 / arg);
        float1000 acotngth = atanh(suitable_arg);
        return acotngth;
    }

    inline float1000 asech(const float1000 &arg) {
        const float1000 suitable_arg(1 / arg);
        float1000 asecnth = acosh(suitable_arg);
        return asecnth;
    }

    inline float1000 acsch(const float1000 &arg) {
        const float1000 suitable_arg(1 / arg);
        float1000 cscnth = asinh(suitable_arg);
        return cscnth;
    }
}

namespace math::functions::complexTrig {
    inline complex_float1000 cot(const complex_float1000 &arg) {
        const complex_float1000 tang = std::tan(arg);
        complex_float1000 coT = one / tang;
        return coT;
    }

    inline complex_float1000 sec(const complex_float1000 &arg) {
        const complex_float1000 COS = std::cos(arg);
        const
                complex_float1000 SEC = one / COS;
        return SEC;
    }

    inline complex_float1000 csc(const complex_float1000 &arg) {
        const complex_float1000 SIN = std::sin(arg);
        complex_float1000 CSC = one / SIN;
        return CSC;
    }

    inline complex_float1000 acot(const complex_float1000 &arg) {
        const complex_float1000 suitable_arg(one / arg);
        complex_float1000 acotngt = std::atan(suitable_arg);
        return acotngt;
    }

    inline complex_float1000 asec(const complex_float1000 &arg) {
        const complex_float1000 suitable_arg(one / arg);
        complex_float1000 asecnt = std::acos(suitable_arg);
        return asecnt;
    }


    inline complex_float1000 acsc(const complex_float1000 &arg) {
        const complex_float1000 suitable_arg(one / arg);
        complex_float1000 cscnt = std::asin(suitable_arg);
        return cscnt;
    }

    inline complex_float1000 coth(const complex_float1000 &arg) {
        const complex_float1000 tangh = std::tanh(arg);
        complex_float1000 coTh = one / tangh;
        return coTh;
    }

    inline complex_float1000 sech(const complex_float1000 &arg) {
        const complex_float1000 COSh = std::cosh(arg);
        complex_float1000 SECh = one / COSh;
        return SECh;
    }

    inline complex_float1000 csch(const complex_float1000 &arg) {
        const complex_float1000 SINh = std::sinh(arg);
        complex_float1000 CSCh = one / SINh;
        return CSCh;
    }

    inline complex_float1000 acoth(const complex_float1000 &arg) {
        const complex_float1000 suitable_arg(one / arg);
        complex_float1000 acotngth = std::atanh(suitable_arg);
        return acotngth;
    }

    inline complex_float1000 asech(const complex_float1000 &arg) {
        const complex_float1000 suitable_arg(one / arg);
        complex_float1000 asecnth = std::acosh(suitable_arg);
        return asecnth;
    }

    inline complex_float1000 acsch(const complex_float1000 &arg) {
        const complex_float1000 suitable_arg(one / arg);
        complex_float1000 cscnth = std::asinh(suitable_arg);
        return cscnth;
    }
}

namespace math::functions::helperFunctions {
    inline float1000 degrees_to_radians(const float1000 &degs) {
        float1000 rads(degs * Pi);
        rads /= 180;
        return rads;
    }

    inline float1000 radians_to_degrees(const float1000 &rads) {
        float1000 degs(rads * 180);
        degs /= Pi;
        return degs;
    }

    inline float1000 factorial(const float1000 &param) {
        float1000 fact(tgamma(param + ONE));
        return fact;
    }

    inline float1000 nPr(const float1000 &n, const float1000 &r) {
        const float1000 numerator(factorial(n));
        const float1000 denominator(factorial(n - r));
        float1000 perm(numerator);
        perm /= denominator;
        return perm;
    }

    inline float1000 nCr(const float1000 &n, const float1000 &r) {
        float1000 rFact = ONE;
        rFact /= factorial(r);
        float1000 comb(rFact * nPr(n, r));
        return comb;
    }
}
#endif //MMQLC_FUNCTIONS_HPP
