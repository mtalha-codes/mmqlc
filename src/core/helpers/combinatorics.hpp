#ifndef COMBINATORICS_HPP
#define COMBINATORICS_HPP

#include "boost_fwd.hpp"
#include "constants.hpp"

namespace mmqli::core::combinatorics {
    inline float1000 factorial(const float1000 &param) {
        return float1000{ tgamma(param + constants::real_one) };
    }

    inline float1000 permutation(const float1000 &n, const float1000 &r) {
        const float1000 n_factorial{ factorial(n) };
        const float1000 n_minus_r_factorial{factorial(n - r)};
        return float1000{ n_factorial / n_minus_r_factorial };
    }

    inline float1000 combination(const float1000 &n, const float1000 &r) {
        const float1000 r_factorial{ constants::real_one / factorial(r)};
        return float1000{r_factorial * permutation(n, r)};
    }
} // namespace mmqli::core::combinatorics
#endif //COMBINATORICS_HPP