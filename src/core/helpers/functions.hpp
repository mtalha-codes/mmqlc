#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cmath>



namespace math::functions::helperFunctions {
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