#include "Core.hpp"
#include "helpers/trigonometry.hpp"
#include "helpers/combinatorics.hpp"

#define OPERATION_SUCCESS true
#define OPERATION_FAILURE false

namespace RealTrig = mmqli::core::trigonometry::real;
namespace AngleConv = mmqli::core::trigonometry::real::converters;
namespace ComplexTrig = mmqli::core::trigonometry::complex;
namespace Combinatorics = mmqli::core::combinatorics;

std::string mmqli::core::Core::to_str(const complex1000& complex) {
    const std::string real_part{complex.real().str()};
    std::string imaginary_part{complex.imag().str() + "i"};
    if (imaginary_part[0] != '-') // check if there is no negative sign then insert positive sign
        imaginary_part.insert(0, 1, '+');
    return std::string{real_part + imaginary_part};
}

std::string mmqli::core::Core::to_str(const float1000& real) {
    return real.str();
}

bool mmqli::core::Core::calculate_real_queries_double_operands(const std::string& query, const float1000& first_operand,
    const float1000& second_operand) {
                if (query == "ADD") {
                    results.emplace_back(
                        build_output(
                            query,
                            first_operand,
                            second_operand,
                            float1000{first_operand + second_operand}
                        )
                    );
                    return OPERATION_SUCCESS;
                }
                if (query == "SUBTRACT") {
                    results.emplace_back(
                        build_output(
                            query,
                            first_operand,
                            second_operand,
                            float1000{first_operand - second_operand}
                        )
                    );
                    return OPERATION_SUCCESS;
                }
                if (query == "MULTIPLY") {
                    results.emplace_back(
                        build_output(
                            query,
                            first_operand,
                            second_operand,
                            float1000{first_operand * second_operand}
                        )
                    );
                    return OPERATION_SUCCESS;
                }
                if (query == "DIVIDE") {
                    if (second_operand == 0) throw std::runtime_error("Division by zero is undefined !");
                    results.emplace_back(
                        build_output(
                            query,
                            first_operand,
                            second_operand,
                            float1000{first_operand / second_operand}
                        )
                    );
                    return OPERATION_SUCCESS;
                }
                if (query == "POWER") {
                    results.emplace_back(
                        build_output(
                            query,
                            first_operand,
                            second_operand,
                            float1000{pow(first_operand, second_operand)}
                        )
                    );
                    return OPERATION_SUCCESS;
                }
                if (query == "ROOT") {
                    if (second_operand == 0) throw std::runtime_error("Zeroeth root is undefined !");
                    if (second_operand == 1) {
                        results.emplace_back(
                            build_output(
                                query,
                                first_operand,
                                second_operand,
                                first_operand
                            )
                        );
                        return OPERATION_SUCCESS;
                    }
                    if (second_operand == 2) {
                        results.emplace_back(
                            build_output(
                                query,
                                first_operand,
                                second_operand,
                                float1000{sqrt(first_operand)}
                            )
                        );
                        return OPERATION_SUCCESS;
                    }
                    if (second_operand == 3) {
                        results.emplace_back(
                            build_output(
                                query,
                                first_operand,
                                second_operand,
                                float1000{cbrt(first_operand)}
                            )
                        );
                        return OPERATION_SUCCESS;
                    }
                    results.emplace_back(
                        build_output(
                            query,
                            first_operand,
                            second_operand,
                            float1000{pow(first_operand, float1000{constants::real_one / second_operand})}
                        )
                    );
                    return OPERATION_SUCCESS;
                }
                if (query == "LOGARITHM") {
                    // using change of base formula
                    results.emplace_back(
                        build_output(
                            query,
                            first_operand,
                            second_operand,
                            float1000{ float1000{log10(first_operand) } / float1000{log10(second_operand)} }
                        )
                    );
                    return OPERATION_SUCCESS;
                }
                if (query == "PERMUTATION") {
                    results.emplace_back(
                        build_output(
                            query,
                            first_operand,
                            second_operand,
                            float1000{Combinatorics::permutation(first_operand, second_operand)}
                        )
                    );
                    return true;
                }
                if (query == "COMBINATION") {
                    results.emplace_back(
                        build_output(
                            query,
                            first_operand,
                            second_operand,
                            float1000{Combinatorics::combination(first_operand, second_operand)}
                        )
                    );
                    return OPERATION_SUCCESS;
                }
                 if (query == "MOD") {
                    if (second_operand == 0) throw std::runtime_error("Cannot divide by zero");
                    results.emplace_back(
                        build_output(
                            query,
                            first_operand,
                            second_operand,
                            float1000{fmod(first_operand, second_operand)}
                        )
                    );
                    return OPERATION_SUCCESS;
                }
                return OPERATION_FAILURE;   // because unmatched operation request.
}

bool mmqli::core::Core::
calculate_real_queries_single_operand(const std::string& query, const float1000& operand) {
     if (query == "FACTORIAL") {
                    results.emplace_back(
                        build_output(
                            query,
                            operand,
                            float1000{Combinatorics::factorial(operand)}
                        )
                    );
                    return OPERATION_SUCCESS;
                }
                if (query == "ABSOLUTE") {
                    float1000 result(fabs(operand));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "FLOOR") {
                    float1000 result(floor(operand));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "CEILING") {
                    float1000 result(ceil(operand));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "SINE") {
                    float1000 rads(hf::degrees_to_radians(operand));
                    float1000 result(sin(rads));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "COSINE") {
                    float1000 rads(hf::degrees_to_radians(operand));
                    float1000 result(cos(rads));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "TANGENT") {
                    if (operand == 90) {
                        results.emplace_back(build_output(query, operand, infinity));
                        return true;
                    }
                    else {
                        float1000 rads(hf::degrees_to_radians(operand));
                        float1000 result(tan(rads));
                        results.emplace_back(build_output(query, operand, result));
                        return true;
                    }
                }
                else if (query == "COTANGENT") {
                    if (operand == 90) {
                        results.emplace_back(build_output(query, operand, ZERO));
                        return true;
                    }
                    else if (operand == 0) {
                        results.emplace_back(build_output(query, operand, infinity));
                        return true;
                    }
                    else {
                        float1000 rads(hf::degrees_to_radians(operand));
                        float1000 result(rt::cotangent(rads));
                        results.emplace_back(build_output(query, operand, result));
                        return true;
                    }
                }
                else if (query == "COSECANT") {
                    if (operand == 0) {
                        results.emplace_back(build_output(query, operand, infinity));
                        return true;
                    }
                    else {
                        float1000 rads(hf::degrees_to_radians(operand));
                        float1000 result(rt::cosecant(rads));
                        results.emplace_back(build_output(query, operand, result));
                        return true;
                    }
                }
                else if (query == "SECANT") {
                    if (operand == 90) {
                        results.emplace_back(build_output(query, operand, infinity));
                        return true;
                    }
                    else {
                        float1000 rads(hf::degrees_to_radians(operand));
                        float1000 result(rt::secant(rads));
                        results.emplace_back(build_output(query, operand, result));
                        return true;
                    }
                }
                else if (query == "INVERSE_SINE") {
                    float1000 rads(asin(operand));
                    float1000 result(hf::radians_to_degrees(rads));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "INVERSE_COSINE") {
                    float1000 rads(acos(operand));
                    float1000 result(hf::radians_to_degrees(rads));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "INVERSE_TANGENT") {
                    float1000 rads(atan(operand));
                    float1000 result(hf::radians_to_degrees(rads));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "INVERSE_COTANGENT") {
                    float1000 rads(rt::inverse_cotangent(operand));
                    float1000 result(hf::radians_to_degrees(rads));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "INVERSE_COSECANT") {
                    float1000 rads(rt::inverse_cosecant(operand));
                    float1000 result(hf::radians_to_degrees(rads));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "INVERSE_SECANT") {
                    float1000 rads(rt::inverse_secant(operand));
                    float1000 result(hf::radians_to_degrees(rads));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "HYP_SINE") {
                    float1000 result(sinh(operand));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "HYP_COSINE") {
                    float1000 result(cosh(operand));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "HYP_TANGENT") {
                    float1000 result(tanh(operand));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "HYP_COTANGENT") {
                    float1000 result_val(rt::cotangent_hyperbolic(operand));
                    results.emplace_back(build_output(query, operand, result_val));
                    return true;
                }
                else if (query == "HYP_COSECANT") {
                    float1000 result_val(rt::cosecant_hyperbolic(operand));
                    results.emplace_back(build_output(query, operand, result_val));
                    return true;
                }
                else if (query == "HYP_SECANT") {
                    float1000 result_val(rt::secant_hyperbolic(operand));
                    results.emplace_back(build_output(query, operand, result_val));
                    return true;
                }
                else if (query == "INVERSE_HYP_TANGENT") {
                    float1000 result(atanh(operand));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "INVERSE_HYP_SINE") {
                    float1000 result(asinh(operand));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "INVERSE_HYP_COSINE") {
                    float1000 result(acosh(operand));
                    results.emplace_back(build_output(query, operand, result));
                    return true;
                }
                else if (query == "INVERSE_HYP_COTANGENT") {
                    float1000 result_val(rt::inverse_cotangent_hyperbolic(operand));
                    results.emplace_back(build_output(query, operand, result_val));
                    return true;
                }
                else if (query == "INVERSE_HYP_COSECANT") {
                    float1000 result_val(rt::inverse_cosecant_hyperbolic(operand));
                    results.emplace_back(build_output(query, operand, result_val));
                    return true;
                }
                else if (query == "INVERSE_HYP_SECANT") {
                    float1000 result_val(rt::inverse_secant_hyperbolic(operand));
                    results.emplace_back(build_output(query, operand, result_val));
                    return true;
                }
                else if (query == "NATURAL_LOGARITHM") {
                    float1000 res(log(operand));
                    results.emplace_back(build_output(query, operand, res));
                    return true;
                }
                else if (query == "BINARY_LOGARITHM") {
                    float1000 res(log2(operand));
                    results.emplace_back(build_output(query, operand, res));
                    return true;
                }
                else if (query == "COMMON_LOGARITHM") {
                    float1000 res(log10(operand));
                    results.emplace_back(build_output(query, operand, res));
                    return true;
                }
                else {
                    return false;
                }
}

void mmqli::core::Core::process_real_queries() {
    if (parsed_reals.empty())
        return;
    for (const auto& parsedToken : parsed_reals) {
        std::string QUERY = std::get<0>(parsedToken);
        if (std::smatch m; std::regex_match(QUERY, m, grammar::queries::internal::var_get_internalReal)) {
            results.emplace_back(QUERY + "\n");
            continue;
        }
        const float1000 F_OPERAND = std::get<1>(parsedToken);
        // ReSharper disable once CppTooWideScopeInitStatement
        const float1000 S_OPERAND = std::get<2>(parsedToken);
        if (calculate_real_queries_single_operand(QUERY, F_OPERAND) ||
            calculate_real_queries_double_operands(QUERY, F_OPERAND, S_OPERAND)) {continue;}
        std::string current_error = "Syntax Fault: MmQLC failed to process " + QUERY;
        attach_error(current_error);
    }
}

bool mmqli::core::Core::calculate_complex_queries_double_operands(const std::string& query,
    const complex1000& first_operand, const complex1000& second_operand) {
    if (query == "ADD") {
                    auto result = first_operand + second_operand;
                    results.emplace_back(build_output(query, first_operand, second_operand, result));
                    return true;
                }
                else if (query == "SUBTRACT") {
                    auto result = first_operand - second_operand;
                    results.emplace_back(build_output(query, first_operand, second_operand, result));
                    return true;
                }
                else if (query == "MULTIPLY") {
                    auto result = first_operand * second_operand;
                    results.emplace_back(build_output(query, first_operand, second_operand, result));
                    return true;
                }
                else if (query == "DIVIDE") {
                    if (second_operand == zero) {
                        throw std::runtime_error("Cannot divide complex number by zero !");
                    }
                    const auto result = first_operand / second_operand;
                    results.emplace_back(build_output(query, first_operand, second_operand, result));
                    return true;
                }
                else if (query == "POWER") {
                    auto result = std::pow(first_operand, second_operand);
                    results.emplace_back(build_output(query, first_operand, second_operand, result));
                    return true;
                }
                else if (query == "ROOT") {
                    if (second_operand == zero) {
                        throw std::runtime_error("Zeroth root of complex number is undefined !");
                    }
                    const auto ind = one / second_operand;
                    const auto result = std::pow(first_operand, ind);
                    results.emplace_back(build_output(query, first_operand, second_operand, result));
                    return true;
                }
                else {
                    return false;
                }
}

bool mmqli::core::Core::
calculate_complex_queries_single_operand(const std::string& query, const complex1000& operand) {

                if (query == "MODULUS") {
                    float1000 MOD(std::abs(operand));
                    results.emplace_back(build_output(query, operand, MOD));
                    return true;
                }
                else if (query == "ARGUMENT") {
                    float1000 rads(std::arg(operand));
                    float1000 degs(hf::radians_to_degrees(rads));
                    results.emplace_back(build_output(query, operand, degs));
                    return true;
                }
                else if (query == "SINE") {
                    auto sine = std::sin(operand);
                    results.emplace_back(build_output(query, operand, sine));
                    return true;
                }
                else if (query == "COSINE") {
                    auto cosine = std::cos(operand);
                    results.emplace_back(build_output(query, operand, cosine));
                    return true;
                }
                else if (query == "TANGENT") {
                    auto tang = std::tan(operand);
                    results.emplace_back(build_output(query, operand, tang));
                    return true;
                }
                else if (query == "COTANGENT") {
                    auto cotangent = ct::cot(operand);
                    results.emplace_back(build_output(query, operand, cotangent));
                    return true;
                }
                else if (query == "SECANT") {
                    auto secant = ct::sec(operand);
                    results.emplace_back(build_output(query, operand, secant));
                    return true;
                }
                else if (query == "COSECANT") {
                    auto cosecant = ct::csc(operand);
                    results.emplace_back(build_output(query, operand, cosecant));
                    return true;
                }
                else if (query == "INVERSE_SINE") {
                    auto inverseSine = std::asin(operand);
                    results.emplace_back(build_output(query, operand, inverseSine));
                    return true;
                }
                else if (query == "INVERSE_COSINE") {
                    auto inverseCosine = std::acos(operand);
                    results.emplace_back(build_output(query, operand, inverseCosine));
                    return true;
                }
                else if (query == "INVERSE_TANGENT") {
                    auto inverseTangent = std::atan(operand);
                    results.emplace_back(build_output(query, operand, inverseTangent));
                    return true;
                }
                else if (query == "INVERSE_COTANGENT") {
                    auto inverseCot = ct::acot(operand);
                    results.emplace_back(build_output(query, operand, inverseCot));
                    return true;
                }
                else if (query == "INVERSE_SECANT") {
                    auto inverseSec = ct::asec(operand);
                    results.emplace_back(build_output(query, operand, inverseSec));
                    return true;
                }
                else if (query == "INVERSE_COSECANT") {
                    auto inverseCsc = ct::acsc(operand);
                    results.emplace_back(build_output(query, operand, inverseCsc));
                    return true;
                }
                else if (query == "HYP_SINE") {
                    auto hyperSine = std::sinh(operand);
                    results.emplace_back(build_output(query, operand, hyperSine));
                    return true;
                }
                else if (query == "HYP_COSINE") {
                    auto hyperCosine = std::cosh(operand);
                    results.emplace_back(build_output(query, operand, hyperCosine));
                    return true;
                }
                else if (query == "HYP_TANGENT") {
                    auto hyperTangent = std::tanh(operand);
                    results.emplace_back(build_output(query, operand, hyperTangent));
                    return true;
                }
                else if (query == "HYP_COTANGENT") {
                    auto Cothan = ct::coth(operand);
                    results.emplace_back(build_output(query, operand, Cothan));
                    return true;
                }
                else if (query == "HYP_SECANT") {
                    auto Shek = ct::sech(operand);
                    results.emplace_back(build_output(query, operand, Shek));
                    return true;
                }
                else if (query == "HYP_COSECANT") {
                    auto CoShek = ct::csch(operand);
                    results.emplace_back(build_output(query, operand, CoShek));
                    return true;
                }
                else if (query == "INVERSE_HYP_SINE") {
                    auto inverseHypSine = std::asinh(operand);
                    results.emplace_back(build_output(query, operand, inverseHypSine));
                    return true;
                }
                else if (query == "INVERSE_HYP_COSINE") {
                    auto inverseHypCosine = std::acosh(operand);
                    results.emplace_back(build_output(query, operand, inverseHypCosine));
                    return true;
                }
                else if (query == "INVERSE_HYP_TANGENT") {
                    auto inverseHypTangent = std::atanh(operand);
                    results.emplace_back(build_output(query, operand, inverseHypTangent));
                    return true;
                }
                else if (query == "INVERSE_HYP_COTANGENT") {
                    auto InvCOTH = ct::acoth(operand);
                    results.emplace_back(build_output(query, operand, InvCOTH));
                    return true;
                }
                else if (query == "INVERSE_HYP_SECANT") {
                    auto InvSheck = ct::asech(operand);
                    results.emplace_back(build_output(query, operand, InvSheck));
                    return true;
                }
                else if (query == "INVERSE_HYP_COSECANT") {
                    auto INV_CSCH = ct::acsch(operand);
                    results.emplace_back(build_output(query, operand, INV_CSCH));
                    return true;
                }
                else if (query == "NATURAL_LOGARITHM") {
                    if (operand == zero) {
                        throw std::runtime_error("Cannot take log of zero !");
                    }
                    auto ln = std::log(operand);
                    results.emplace_back(build_output(query, operand, ln));
                    return true;
                }
                else if (query == "POWER_E") {
                    auto expo = std::exp(operand);
                    results.emplace_back(build_output(query, operand, expo));
                    return true;
                }
                else if (query == "CONJUGATE") {
                    auto conjg = std::conj(operand);
                    results.emplace_back(build_output(query, operand, conjg));
                    return true;
                }
                else {
                    return false;
                }
}

void mmqli::core::Core::process_complex_queries() {
    if (parsed_complex.empty()) // if there is no complex query...... !
        return;
    for (const auto& parsedToken : parsed_complex) {
        std::string QUERY = std::get<0>(parsedToken);
        if (std::smatch m; std::regex_match(QUERY, m, grammar::queries::internal::var_get_internalComplex)) {
            results.emplace_back(QUERY + "\n");
            continue;
        }
        const complex1000 F_OPERAND = std::get<1>(parsedToken);
        // ReSharper disable once CppTooWideScopeInitStatement
        const complex1000 S_OPERAND = std::get<2>(parsedToken);

        if (calculate_complex_queries_single_operand(QUERY, F_OPERAND) ||
            calculate_complex_queries_double_operands(QUERY, F_OPERAND, S_OPERAND)) { continue; }
        std::string current_error = "mmqli failed to evaluate " + QUERY;
        attach_error(current_error);
    }
}

void mmqli::core::Core::attach_error(const std::string& err) {
    errors.emplace_back(err);
}

std::string mmqli::core::Core::get_string_errors() {
    std::ranges::sort(errors);
    auto l = std::ranges::unique(errors);
    errors.erase(l.begin(), errors.end());
    std::string allErrors;
    for (const auto& err : errors) {
        allErrors.append(err);
        allErrors.append("\n");
    }
    return allErrors;
}

mmqli::core::Core::Core(const ParsedRealQueries& parsedReal, const ParsedComplexQueries& parsedComplex) {
    parsed_reals = parsedReal;
    parsed_complex = parsedComplex;
}

std::vector<std::string> mmqli::core::Core::evaluate_all() {
    process_real_queries();
    process_complex_queries();
    if (!errors.empty())
        throw std::runtime_error(get_string_errors());
    return results;
}
