module;
#include <complex>
#include <concepts>
#include <boost/multiprecision/mpfr.hpp>
export module helpers.boost_fwd;

export using float1000 = boost::multiprecision::mpfr_float_1000;
export typedef std::complex<float1000> complex1000;

template<typename T>
   concept Real = requires(T p)
{
    {p.str()} -> std::same_as<std::string>;
};

template<typename T>
concept Complex = requires(T p)
{
    {p.real()} -> std::same_as<float1000>;
    {p.imag()} -> std::same_as<float1000>;
};
