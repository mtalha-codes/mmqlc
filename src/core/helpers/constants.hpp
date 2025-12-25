#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP
#include "boost_fwd.hpp"

namespace mmqli::core::constants {
    const float1000 Pi("3.141592653589793238462643383279");
    const float1000 ONE("1");
    const float1000 ZERO("0");
    const complex1000 one(ONE, ZERO);
    const complex1000 zero(ZERO, ZERO);
}

#endif