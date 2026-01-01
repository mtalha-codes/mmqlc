#ifndef MMQLI_CORE_HPP
#define MMQLI_CORE_HPP

#include <type_traits>
#include <stdexcept>
#include "../parser/Parser.hpp"

template<typename T>
concept RealComplex = Real<T> || Complex<T>; // either real number or complex number.

namespace mmqli::core {

    using ParsedRealQuery = std::tuple<std::string, float1000, float1000>;
    using ParsedRealQueries = std::vector<ParsedRealQuery>;
    using ParsedComplexQuery = std::tuple<std::string, complex1000, complex1000>;
    using ParsedComplexQueries = std::vector<ParsedComplexQuery>;

class Core {
    ParsedRealQueries parsed_reals;
    ParsedComplexQueries parsed_complex;
    std::vector<std::string> results;
    std::vector<std::string> errors;

    static std::string to_str(const complex1000 &complex);
    static std::string to_str(const float1000 &real);

    /**
     * This function build the answer string from the components. This is a templated function and by ODR, it is defined and implemented here.
     * @param q The query string
     * @param f The first operand
     * @param s The second operand
     * @param r The result after evaluation.
     * @return The answer string in the form @code query f,s = r @endcode
     */
    std::string build_output(const std::string &q, const RealComplex auto& f, const RealComplex auto& s, const RealComplex auto& r) {
        return q + " " + to_str(f) + "," + to_str(s) + " = " + to_str(r) + "\n";
    }
    /**
     * This function build the answer string from the components. This is a templated function and by ODR, it is defined and implemented here.
     * @param q The query string
     * @param f The first operand
     * @param r The result after evaluation.
     * @return The answer string in the form @code query f = r @endcode
     */
    std::string build_output(const std::string &q, const RealComplex auto& f, const RealComplex auto& r) {
        return q + " " + to_str(f) + " = " + to_str(r) + "\n";
    }

    void attach_error(const std::string &err);
    std::string get_string_errors();

public:
    Core(const ParsedRealQueries &parsedReal, const ParsedComplexQueries &parsedComplex);
    std::vector<std::string> evaluate_all();
};
} //namespace mmqli::core
#endif