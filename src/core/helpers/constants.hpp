#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include "boost_fwd.hpp"

namespace mmqli::core::constants {
    const float1000 arbitrary_precise_pi(3.141592653589793238462643383279);
    const float1000 real_one(1);
    const float1000 real_zero(0);
    const complex1000 complex_one(real_one, real_zero);
    const complex1000 complex_zero(real_zero, real_zero);
}
#endif
