#ifndef COMBINATORICS_HPP
#define COMBINATORICS_HPP

#include "boost_fwd.hpp"
#include "constants.hpp"

namespace mmqli::core::combinatorics {
    /**
     *  Calculates the factorial of a given parameter using the gamma function.
     * @param param The parameter for which the factorial will be calculated
     * @return The factorial of the parameter
     */
    inline float1000 factorial(const float1000 &param) {
        return float1000{ tgamma(param + constants::real_one) };
    }

    /**
     * Calculates the permutation of n and r.
     * @param n The parameter n, the number of elements from which we have to select.
     * @param r The parameter r, the number of elements to be selected uniquely from n.
     * @return The permutation of n and r.
     */
    inline float1000 permutation(const float1000 &n, const float1000 &r) {
        const float1000 n_factorial{ factorial(n) };
        const float1000 n_minus_r_factorial{factorial(n - r)};
        return float1000{ n_factorial / n_minus_r_factorial };
    }

    /**
     * Calculates the combination of n and r.
     * @param n The parameter n, the number of elements from which we have to select.
     * @param r The parameter r, the number of elements to be selected from n.
     * @return The combination of n and r.
     */
    inline float1000 combination(const float1000 &n, const float1000 &r) {
        const float1000 r_factorial{ constants::real_one / factorial(r)};
        return float1000{r_factorial * permutation(n, r)};
    }
} // namespace mmqli::core::combinatorics
#endif //COMBINATORICS_HPP