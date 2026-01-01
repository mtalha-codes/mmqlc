#include "Core.hpp"
#include "helpers/trigonometry.hpp"
#include "helpers/combinatorics.hpp"

std::string mmqli::core::Core::to_str(const complex1000& complex) {
    const std::string real_part { complex.real().str() };
    std::string imaginary_part { complex.imag().str() + "i" };
    if (imaginary_part[0] != '-') // check if there is no negative sign then insert positive sign
        imaginary_part.insert(0, 1, '+');
    return std::string{ real_part + imaginary_part };
}

std::string mmqli::core::Core::to_str(const float1000& real) {
    return real.str();
}

void mmqli::core::Core::attach_error(const std::string& err) {
    errors.emplace_back(err);
}

std::string mmqli::core::Core::get_string_errors() {
    std::ranges::sort(errors);
    auto l = std::ranges::unique(errors);
    errors.erase(l.begin(), errors.end());
    std::string allErrors;
    for (const auto &err: errors) {
        allErrors.append(err);
        allErrors.append("\n");
    }
    return allErrors;
}

mmqli::core::Core::Core(const ParsedRealQueries &parsedReal, const ParsedComplexQueries &parsedComplex) {
    parsed_reals = parsedReal;
    parsed_complex = parsedComplex;
}

std::vector<std::string> mmqli::core::Core::evaluate_all() {
    auto doReal = [this]() {
            if (parsed_reals.empty())
                return;
            for (const auto &parsedToken: parsed_reals) {
                std::string QUERY = std::get < 0 > (parsedToken);
                if (std::smatch m; std::regex_match(QUERY, m, grammar::queries::internal::var_get_internalReal)) {
                    results.emplace_back(QUERY + "\n");
                    continue;
                }
                float1000 F_OPERAND = std::get < 1 > (parsedToken);
                float1000 S_OPERAND = std::get < 2 > (parsedToken);
                auto calculate_real_double = [this](const std::string &query, const float1000 &fOperand,
                                                    const float1000 &sOperand) {
                    if (query == "ADD") {
                        float1000 result(fOperand + sOperand);
                        results.emplace_back(build_output(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "SUBTRACT") {
                        float1000 result(fOperand - sOperand);
                        results.emplace_back(build_output(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "MULTIPLY") {
                        float1000 result(fOperand * sOperand);
                        results.emplace_back(build_output(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "DIVIDE") {
                        if (sOperand != 0) {
                            float1000 result(fOperand / sOperand);
                            results.emplace_back(build_output(query, fOperand, sOperand, result));
                            return true;
                        } else {
                            throw std::runtime_error("Cannot divide by zero");
                        }
                    } else if (query == "POWER") {
                        float1000 result(round(pow(fOperand, sOperand)));
                        results.emplace_back(build_output(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "ROOT") {
                        if (sOperand != 0) {
                            float1000 index(1);
                            index /= sOperand;
                            float1000 result(round(pow(fOperand, index)));
                            results.emplace_back(build_output(query, fOperand, sOperand, result));
                            return true;
                        } else {
                            throw std::runtime_error("Zeroth root does not exist");
                        }
                    } else if (query == "LOGARITHM") {
                        // using change of base formula
                        float1000 n(log10(fOperand));
                        float1000 d(log10(sOperand));
                        float1000 log_result(n);
                        log_result /= d;
                        results.emplace_back(build_output(query, fOperand, sOperand, log_result));
                        return true;
                    } else if (query == "PERMUTATION") {
                        float1000 result(hf::nPr(fOperand, sOperand));
                        results.emplace_back(build_output(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "COMBINATION") {
                        float1000 result(hf::nCr(fOperand, sOperand));
                        results.emplace_back(build_output(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "MOD") {
                        if (sOperand != 0) {
                            float1000 result = fmod(fOperand, sOperand);
                            results.emplace_back(build_output(query, fOperand, sOperand, result));
                            return true;
                        } else {
                            throw std::runtime_error("Cannot divide by zero");
                        }
                    } else
                        return false;
                };
                auto calculate_real_single = [this](const std::string &query, const float1000 &fOperand) {
                    if (query == "FACTORIAL") {
                        float1000 result(hf::factorial(fOperand));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "ABSOLUTE") {
                        float1000 result(fabs(fOperand));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "FLOOR") {
                        float1000 result(floor(fOperand));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "CEILING") {
                        float1000 result(ceil(fOperand));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "SINE") {
                        float1000 rads(hf::degrees_to_radians(fOperand));
                        float1000 result(sin(rads));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "COSINE") {
                        float1000 rads(hf::degrees_to_radians(fOperand));
                        float1000 result(cos(rads));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "TANGENT") {
                        if (fOperand == 90) {
                            results.emplace_back(build_output(query, fOperand, infinity));
                            return true;
                        } else {
                            float1000 rads(hf::degrees_to_radians(fOperand));
                            float1000 result(tan(rads));
                            results.emplace_back(build_output(query, fOperand, result));
                            return true;
                        }
                    } else if (query == "COTANGENT") {
                        if (fOperand == 90) {
                            results.emplace_back(build_output(query, fOperand, ZERO));
                            return true;
                        } else if (fOperand == 0) {
                            results.emplace_back(build_output(query, fOperand, infinity));
                            return true;
                        } else {
                            float1000 rads(hf::degrees_to_radians(fOperand));
                            float1000 result(rt::cotangent(rads));
                            results.emplace_back(build_output(query, fOperand, result));
                            return true;
                        }
                    } else if (query == "COSECANT") {
                        if (fOperand == 0) {
                            results.emplace_back(build_output(query, fOperand, infinity));
                            return true;
                        } else {
                            float1000 rads(hf::degrees_to_radians(fOperand));
                            float1000 result(rt::cosecant(rads));
                            results.emplace_back(build_output(query, fOperand, result));
                            return true;
                        }
                    } else if (query == "SECANT") {
                        if (fOperand == 90) {
                            results.emplace_back(build_output(query, fOperand, infinity));
                            return true;
                        } else {
                            float1000 rads(hf::degrees_to_radians(fOperand));
                            float1000 result(rt::secant(rads));
                            results.emplace_back(build_output(query, fOperand, result));
                            return true;
                        }
                    } else if (query == "INVERSE_SINE") {
                        float1000 rads(asin(fOperand));
                        float1000 result(hf::radians_to_degrees(rads));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_COSINE") {
                        float1000 rads(acos(fOperand));
                        float1000 result(hf::radians_to_degrees(rads));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_TANGENT") {
                        float1000 rads(atan(fOperand));
                        float1000 result(hf::radians_to_degrees(rads));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_COTANGENT") {
                        float1000 rads(rt::inverse_cotangent(fOperand));
                        float1000 result(hf::radians_to_degrees(rads));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_COSECANT") {
                        float1000 rads(rt::inverse_cosecant(fOperand));
                        float1000 result(hf::radians_to_degrees(rads));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_SECANT") {
                        float1000 rads(rt::inverse_secant(fOperand));
                        float1000 result(hf::radians_to_degrees(rads));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "HYP_SINE") {
                        float1000 result(sinh(fOperand));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "HYP_COSINE") {
                        float1000 result(cosh(fOperand));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "HYP_TANGENT") {
                        float1000 result(tanh(fOperand));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "HYP_COTANGENT") {
                        float1000 result_val(rt::cotangent_hyperbolic(fOperand));
                        results.emplace_back(build_output(query, fOperand, result_val));
                        return true;
                    } else if (query == "HYP_COSECANT") {
                        float1000 result_val(rt::cosecant_hyperbolic(fOperand));
                        results.emplace_back(build_output(query, fOperand, result_val));
                        return true;
                    } else if (query == "HYP_SECANT") {
                        float1000 result_val(rt::secant_hyperbolic(fOperand));
                        results.emplace_back(build_output(query, fOperand, result_val));
                        return true;
                    } else if (query == "INVERSE_HYP_TANGENT") {
                        float1000 result(atanh(fOperand));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_HYP_SINE") {
                        float1000 result(asinh(fOperand));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_HYP_COSINE") {
                        float1000 result(acosh(fOperand));
                        results.emplace_back(build_output(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_HYP_COTANGENT") {
                        float1000 result_val(rt::inverse_cotangent_hyperbolic(fOperand));
                        results.emplace_back(build_output(query, fOperand, result_val));
                        return true;
                    } else if (query == "INVERSE_HYP_COSECANT") {
                        float1000 result_val(rt::inverse_cosecant_hyperbolic(fOperand));
                        results.emplace_back(build_output(query, fOperand, result_val));
                        return true;
                    } else if (query == "INVERSE_HYP_SECANT") {
                        float1000 result_val(rt::inverse_secant_hyperbolic(fOperand));
                        results.emplace_back(build_output(query, fOperand, result_val));
                        return true;
                    } else if (query == "NATURAL_LOGARITHM") {
                        float1000 res(log(fOperand));
                        results.emplace_back(build_output(query, fOperand, res));
                        return true;
                    } else if (query == "BINARY_LOGARITHM") {
                        float1000 res(log2(fOperand));
                        results.emplace_back(build_output(query, fOperand, res));
                        return true;
                    } else if (query == "COMMON_LOGARITHM") {
                        float1000 res(log10(fOperand));
                        results.emplace_back(build_output(query, fOperand, res));
                        return true;
                    } else {
                        return false;
                    }
                };
                if (calculate_real_single(QUERY, F_OPERAND) ||
                    calculate_real_double(QUERY, F_OPERAND, S_OPERAND))
                    continue;
                else {
                    std::string current_error = "Syntax Fault: MmQLC failed to process " + QUERY;
                    attach_error(current_error);
                }
            }
        };
        auto doComplex = [this]() {
            if (parsed_complex.empty())
                return;
            for (const auto &parsedToken: parsed_complex) {
                std::string QUERY = std::get < 0 > (parsedToken);
                if (std::smatch m; std::regex_match(QUERY, m, grammar::queries::internal::var_get_internalComplex)) {
                    results.emplace_back(QUERY + "\n");
                    continue;
                }
                auto F_OPERAND = std::get < 1 > (parsedToken);
                auto S_OPERAND = std::get < 2 > (parsedToken);
                auto calculate_complex_double = [this](const std::string &query, const complex1000 &fOperand,
                                                       const complex1000 &sOperand) {
                    if (query == "ADD") {
                        auto result = fOperand + sOperand;
                        results.emplace_back(build_output(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "SUBTRACT") {
                        auto result = fOperand - sOperand;
                        results.emplace_back(build_output(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "MULTIPLY") {
                        auto result = fOperand * sOperand;
                        results.emplace_back(build_output(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "DIVIDE") {
                        if (sOperand == zero) {
                            throw std::runtime_error("Cannot divide complex number by zero !");
                        }
                        const auto result = fOperand / sOperand;
                        results.emplace_back(build_output(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "POWER") {
                        auto result = std::pow(fOperand, sOperand);
                        results.emplace_back(build_output(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "ROOT") {
                        if (sOperand == zero) {
                            throw std::runtime_error("Zeroth root of complex number is undefined !");
                        }
                        const auto ind = one / sOperand;
                        const auto result = std::pow(fOperand, ind);
                        results.emplace_back(build_output(query, fOperand, sOperand, result));
                        return true;
                    } else {
                        return false;
                    }
                };
                auto calculate_complex_single = [this](const std::string &query, const complex1000 &fOperand) {
                    if (query == "MODULUS") {
                        float1000 MOD(std::abs(fOperand));
                        results.emplace_back(build_output(query, fOperand, MOD));
                        return true;
                    } else if (query == "ARGUMENT") {
                        float1000 rads(std::arg(fOperand));
                        float1000 degs(hf::radians_to_degrees(rads));
                        results.emplace_back(build_output(query, fOperand, degs));
                        return true;
                    } else if (query == "SINE") {
                        auto sine = std::sin(fOperand);
                        results.emplace_back(build_output(query, fOperand, sine));
                        return true;
                    } else if (query == "COSINE") {
                        auto cosine = std::cos(fOperand);
                        results.emplace_back(build_output(query, fOperand, cosine));
                        return true;
                    } else if (query == "TANGENT") {
                        auto tang = std::tan(fOperand);
                        results.emplace_back(build_output(query, fOperand, tang));
                        return true;
                    } else if (query == "COTANGENT") {
                        auto cotangent = ct::cot(fOperand);
                        results.emplace_back(build_output(query, fOperand, cotangent));
                        return true;
                    } else if (query == "SECANT") {
                        auto secant = ct::sec(fOperand);
                        results.emplace_back(build_output(query, fOperand, secant));
                        return true;
                    } else if (query == "COSECANT") {
                        auto cosecant = ct::csc(fOperand);
                        results.emplace_back(build_output(query, fOperand, cosecant));
                        return true;
                    } else if (query == "INVERSE_SINE") {
                        auto inverseSine = std::asin(fOperand);
                        results.emplace_back(build_output(query, fOperand, inverseSine));
                        return true;
                    } else if (query == "INVERSE_COSINE") {
                        auto inverseCosine = std::acos(fOperand);
                        results.emplace_back(build_output(query, fOperand, inverseCosine));
                        return true;
                    } else if (query == "INVERSE_TANGENT") {
                        auto inverseTangent = std::atan(fOperand);
                        results.emplace_back(build_output(query, fOperand, inverseTangent));
                        return true;
                    } else if (query == "INVERSE_COTANGENT") {
                        auto inverseCot = ct::acot(fOperand);
                        results.emplace_back(build_output(query, fOperand, inverseCot));
                        return true;
                    } else if (query == "INVERSE_SECANT") {
                        auto inverseSec = ct::asec(fOperand);
                        results.emplace_back(build_output(query, fOperand, inverseSec));
                        return true;
                    } else if (query == "INVERSE_COSECANT") {
                        auto inverseCsc = ct::acsc(fOperand);
                        results.emplace_back(build_output(query, fOperand, inverseCsc));
                        return true;
                    } else if (query == "HYP_SINE") {
                        auto hyperSine = std::sinh(fOperand);
                        results.emplace_back(build_output(query, fOperand, hyperSine));
                        return true;
                    } else if (query == "HYP_COSINE") {
                        auto hyperCosine = std::cosh(fOperand);
                        results.emplace_back(build_output(query, fOperand, hyperCosine));
                        return true;
                    } else if (query == "HYP_TANGENT") {
                        auto hyperTangent = std::tanh(fOperand);
                        results.emplace_back(build_output(query, fOperand, hyperTangent));
                        return true;
                    } else if (query == "HYP_COTANGENT") {
                        auto Cothan = ct::coth(fOperand);
                        results.emplace_back(build_output(query, fOperand, Cothan));
                        return true;
                    } else if (query == "HYP_SECANT") {
                        auto Shek = ct::sech(fOperand);
                        results.emplace_back(build_output(query, fOperand, Shek));
                        return true;
                    } else if (query == "HYP_COSECANT") {
                        auto CoShek = ct::csch(fOperand);
                        results.emplace_back(build_output(query, fOperand, CoShek));
                        return true;
                    } else if (query == "INVERSE_HYP_SINE") {
                        auto inverseHypSine = std::asinh(fOperand);
                        results.emplace_back(build_output(query, fOperand, inverseHypSine));
                        return true;
                    } else if (query == "INVERSE_HYP_COSINE") {
                        auto inverseHypCosine = std::acosh(fOperand);
                        results.emplace_back(build_output(query, fOperand, inverseHypCosine));
                        return true;
                    } else if (query == "INVERSE_HYP_TANGENT") {
                        auto inverseHypTangent = std::atanh(fOperand);
                        results.emplace_back(build_output(query, fOperand, inverseHypTangent));
                        return true;
                    } else if (query == "INVERSE_HYP_COTANGENT") {
                        auto InvCOTH = ct::acoth(fOperand);
                        results.emplace_back(build_output(query, fOperand, InvCOTH));
                        return true;
                    } else if (query == "INVERSE_HYP_SECANT") {
                        auto InvSheck = ct::asech(fOperand);
                        results.emplace_back(build_output(query, fOperand, InvSheck));
                        return true;
                    } else if (query == "INVERSE_HYP_COSECANT") {
                        auto INV_CSCH = ct::acsch(fOperand);
                        results.emplace_back(build_output(query, fOperand, INV_CSCH));
                        return true;
                    } else if (query == "NATURAL_LOGARITHM") {
                        if (fOperand == zero) {
                            throw std::runtime_error("Cannot take log of zero !");
                        }
                        auto ln = std::log(fOperand);
                        results.emplace_back(build_output(query, fOperand, ln));
                        return true;
                    } else if (query == "POWER_E") {
                        auto expo = std::exp(fOperand);
                        results.emplace_back(build_output(query, fOperand, expo));
                        return true;
                    } else if (query == "CONJUGATE") {
                        auto conjg = std::conj(fOperand);
                        results.emplace_back(build_output(query, fOperand, conjg));
                        return true;
                    } else {
                        return false;
                    }
                };
                if (calculate_complex_single(QUERY, F_OPERAND) ||
                    calculate_complex_double(QUERY, F_OPERAND, S_OPERAND)) { continue; } else {
                    std::string current_error = "Syntax Fault: MmQLC failed to process " + QUERY;
                    attach_error(current_error);
                }
            }
        };
        doReal();
        doComplex();
        if (!errors.empty())
            throw std::runtime_error(get_string_errors());
        return results;
}
