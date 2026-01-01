#ifndef BOOST_FWD_HPP
#define BOOST_FWD_HPP

#include <complex>
#include <concepts>
#include <boost/multiprecision/mpfr.hpp>


using float1000 = boost::multiprecision::mpfr_float_1000;
using complex1000 = std::complex<float1000>;

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
#endif