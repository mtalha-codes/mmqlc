/*
 * Filename: mmqlc.calculator.hpp
 * Author: Muhammad Talha
 * Github: MTalha-Codes
 * Repository: mmqlc
 * Copyright(C) - 2024
 * */

#ifndef MMQLC_CALCULATOR_HPP
#define MMQLC_CALCULATOR_HPP

#include <type_traits>
#include <stdexcept>
#include "../headers/Parser.hpp"
#include "../headers/functions.hpp"

namespace rt = math::functions::realTrig; // namespace alias for realTrig;
namespace ct = math::functions::complexTrig; // namespace alias for complexTrig;
namespace hf = math::functions::helperFunctions; // namespace alias for helperFunctions;

class mmqlc_calculator {
    std::vector<std::tuple<std::string, float1000, float1000> > realNums_parsed;
    std::vector<std::tuple<std::string, complex_float1000, complex_float1000> > cmplxNums_parsed;
    std::vector<std::string> answerStrings;
    std::vector<std::string> error_messages;

    static std::string stringConvert(const complex_float1000 &complexArg) {
        const std::string realStr = complexArg.real().str();
        std::string imagStr = complexArg.imag().str() + "i";
        if (imagStr[0] != '-')
            imagStr.insert(0, 1, '+');
        std::string complexStr = realStr + imagStr;
        return complexStr;
    }

    static std::string stringConvert(const float1000 &darg) {
        return darg.str();
    }

    template<typename T, typename U, typename R>
    std::enable_if_t<(std::is_same_v<T, float1000> || std::is_same_v<T, complex_float1000>) &&
                     (std::is_same_v<U, float1000> || std::is_same_v<U, complex_float1000>) &&
                     (std::is_same_v<R, float1000> || std::is_same_v<R, complex_float1000>), std::string>
    constructAnswer(const std::string &q, const T &f, const U &s, const R &r) {
        return q + " " + stringConvert(f) + "," + stringConvert(s) + " = " + stringConvert(r) + "\n";
    }

    template<typename T, typename R>
    std::enable_if_t<(std::is_same_v<T, float1000> || std::is_same_v<T, complex_float1000>) &&
                     (std::is_same_v<R, float1000> || std::is_same_v<R, complex_float1000>), std::string>
    constructAnswer(const std::string &q, const T &f, const R &r) {
        return q + " " + stringConvert(f) + " = " + stringConvert(r) + "\n";
    }

    void appendError(const std::string &err) {
        error_messages.emplace_back(err);
    }

    std::string get_string_errors() {
        std::ranges::sort(error_messages);
        auto l = std::ranges::unique(error_messages);
        error_messages.erase(l.begin(), error_messages.end());
        std::string allErrors;
        for (const auto &err: error_messages) {
            allErrors.append("\n");
            allErrors.append(err);
            allErrors.append("\n");
        }
        return allErrors;
    }

public:
    mmqlc_calculator(std::vector<std::tuple<std::string, float1000, float1000> > const &parsedReal,
                     std::vector<std::tuple<std::string, complex_float1000, complex_float1000> > const &parsedComplex) {
        realNums_parsed = parsedReal;
        cmplxNums_parsed = parsedComplex;
    }

    std::vector<std::string> calculateAnswers() {
        auto doReal = [this]() {
            if (realNums_parsed.empty())
                return;
            for (const auto &parsedToken: realNums_parsed) {
                std::string QUERY = std::get<0>(parsedToken);
                if (std::smatch m; std::regex_match(QUERY, m, regex::queries::internal::var_get_internalReal)) {
                    answerStrings.emplace_back(QUERY + "\n");
                    continue;
                }
                float1000 F_OPERAND = std::get<1>(parsedToken);
                float1000 S_OPERAND = std::get<2>(parsedToken);
                auto calculate_real_double = [this](const std::string &query, const float1000 &fOperand,
                                                    const float1000 &sOperand) {
                    if (query == "ADD") {
                        float1000 result(fOperand + sOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "SUBTRACT") {
                        float1000 result(fOperand - sOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "MULTIPLY") {
                        float1000 result(fOperand * sOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "DIVIDE") {
                        if (sOperand != 0) {
                            float1000 result(fOperand / sOperand);
                            answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                            return true;
                        } else {
                            throw std::runtime_error("Cannot divide by zero");
                        }
                    } else if (query == "POWER") {
                        float1000 result(round(pow(fOperand, sOperand)));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "ROOT") {
                        if (sOperand != 0) {
                            float1000 index(1);
                            index /= sOperand;
                            float1000 result(round(pow(fOperand, index)));
                            answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
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
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, log_result));
                        return true;
                    } else if (query == "PERMUTATION") {
                        float1000 result(hf::nPr(fOperand, sOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "COMBINATION") {
                        float1000 result(hf::nCr(fOperand, sOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "MOD") {
                        if (sOperand != 0) {
                            float1000 result = fmod(fOperand, sOperand);
                            answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
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
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "ABSOLUTE") {
                        float1000 result(fabs(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "FLOOR") {
                        float1000 result(floor(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "CEILING") {
                        float1000 result(ceil(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "SINE") {
                        float1000 rads(hf::degrees_to_radians(fOperand));
                        float1000 result(sin(rads));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "COSINE") {
                        float1000 rads(hf::degrees_to_radians(fOperand));
                        float1000 result(cos(rads));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "TANGENT") {
                        if (fOperand == 90) {
                            answerStrings.emplace_back(constructAnswer(query, fOperand, infinity));
                            return true;
                        } else {
                            float1000 rads(hf::degrees_to_radians(fOperand));
                            float1000 result(tan(rads));
                            answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                            return true;
                        }
                    } else if (query == "COTANGENT") {
                        if (fOperand == 90) {
                            answerStrings.emplace_back(constructAnswer(query, fOperand, ZERO));
                            return true;
                        } else if (fOperand == 0) {
                            answerStrings.emplace_back(constructAnswer(query, fOperand, infinity));
                            return true;
                        } else {
                            float1000 rads(hf::degrees_to_radians(fOperand));
                            float1000 result(rt::cot(rads));
                            answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                            return true;
                        }
                    } else if (query == "COSECANT") {
                        if (fOperand == 0) {
                            answerStrings.emplace_back(constructAnswer(query, fOperand, infinity));
                            return true;
                        } else {
                            float1000 rads(hf::degrees_to_radians(fOperand));
                            float1000 result(rt::csc(rads));
                            answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                            return true;
                        }
                    } else if (query == "SECANT") {
                        if (fOperand == 90) {
                            answerStrings.emplace_back(constructAnswer(query, fOperand, infinity));
                            return true;
                        } else {
                            float1000 rads(hf::degrees_to_radians(fOperand));
                            float1000 result(rt::sec(rads));
                            answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                            return true;
                        }
                    } else if (query == "INVERSE_SINE") {
                        float1000 rads(asin(fOperand));
                        float1000 result(hf::radians_to_degrees(rads));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_COSINE") {
                        float1000 rads(acos(fOperand));
                        float1000 result(hf::radians_to_degrees(rads));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_TANGENT") {
                        float1000 rads(atan(fOperand));
                        float1000 result(hf::radians_to_degrees(rads));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_COTANGENT") {
                        float1000 rads(rt::acot(fOperand));
                        float1000 result(hf::radians_to_degrees(rads));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_COSECANT") {
                        float1000 rads(rt::acsc(fOperand));
                        float1000 result(hf::radians_to_degrees(rads));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_SECANT") {
                        float1000 rads(rt::asec(fOperand));
                        float1000 result(hf::radians_to_degrees(rads));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "HYP_SINE") {
                        float1000 result(sinh(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "HYP_COSINE") {
                        float1000 result(cosh(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "HYP_TANGENT") {
                        float1000 result(tanh(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "HYP_COTANGENT") {
                        float1000 result_val(rt::coth(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result_val));
                        return true;
                    } else if (query == "HYP_COSECANT") {
                        float1000 result_val(rt::csch(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result_val));
                        return true;
                    } else if (query == "HYP_SECANT") {
                        float1000 result_val(rt::sech(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result_val));
                        return true;
                    } else if (query == "INVERSE_HYP_TANGENT") {
                        float1000 result(atanh(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_HYP_SINE") {
                        float1000 result(asinh(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_HYP_COSINE") {
                        float1000 result(acosh(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result));
                        return true;
                    } else if (query == "INVERSE_HYP_COTANGENT") {
                        float1000 result_val(rt::acoth(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result_val));
                        return true;
                    } else if (query == "INVERSE_HYP_COSECANT") {
                        float1000 result_val(rt::acsch(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result_val));
                        return true;
                    } else if (query == "INVERSE_HYP_SECANT") {
                        float1000 result_val(rt::asech(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, result_val));
                        return true;
                    } else if (query == "NATURAL_LOGARITHM") {
                        float1000 res(log(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, res));
                        return true;
                    } else if (query == "BINARY_LOGARITHM") {
                        float1000 res(log2(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, res));
                        return true;
                    } else if (query == "COMMON_LOGARITHM") {
                        float1000 res(log10(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, res));
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
                    appendError(current_error);
                }
            }
        };
        auto doComplex = [this]() {
            if (cmplxNums_parsed.empty())
                return;
            for (const auto &parsedToken: cmplxNums_parsed) {
                std::string QUERY = std::get<0>(parsedToken);
                if (std::smatch m; std::regex_match(QUERY, m, regex::queries::internal::var_get_internalComplex)) {
                    answerStrings.emplace_back(QUERY + "\n");
                    continue;
                }
                auto F_OPERAND = std::get<1>(parsedToken);
                auto S_OPERAND = std::get<2>(parsedToken);
                auto calculate_complex_double = [this](const std::string &query, const complex_float1000 &fOperand,
                                                       const complex_float1000 &sOperand) {
                    if (query == "ADD") {
                        auto result = fOperand + sOperand;
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "SUBTRACT") {
                        auto result = fOperand - sOperand;
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "MULTIPLY") {
                        auto result = fOperand * sOperand;
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "DIVIDE") {
                        if (sOperand == zero) {
                            throw std::runtime_error("Cannot divide complex number by zero !");
                        }
                        const auto result = fOperand / sOperand;
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "POWER") {
                        auto result = std::pow(fOperand, sOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else if (query == "ROOT") {
                        if (sOperand == zero) {
                            throw std::runtime_error("Zeroth root of complex number is undefined !");
                        }
                        const auto ind = one / sOperand;
                        const auto result = std::pow(fOperand, ind);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sOperand, result));
                        return true;
                    } else {
                        return false;
                    }
                };
                auto calculate_complex_single = [this](const std::string &query, const complex_float1000 &fOperand) {
                    if (query == "MODULUS") {
                        float1000 MOD(std::abs(fOperand));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, MOD));
                        return true;
                    } else if (query == "ARGUMENT") {
                        float1000 rads(std::arg(fOperand));
                        float1000 degs(hf::radians_to_degrees(rads));
                        answerStrings.emplace_back(constructAnswer(query, fOperand, degs));
                        return true;
                    } else if (query == "SINE") {
                        auto sine = std::sin(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, sine));
                        return true;
                    } else if (query == "COSINE") {
                        auto cosine = std::cos(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, cosine));
                        return true;
                    } else if (query == "TANGENT") {
                        auto tang = std::tan(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, tang));
                        return true;
                    } else if (query == "COTANGENT") {
                        auto cotangent = ct::cot(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, cotangent));
                        return true;
                    } else if (query == "SECANT") {
                        auto secant = ct::sec(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, secant));
                        return true;
                    } else if (query == "COSECANT") {
                        auto cosecant = ct::csc(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, cosecant));
                        return true;
                    } else if (query == "INVERSE_SINE") {
                        auto inverseSine = std::asin(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, inverseSine));
                        return true;
                    } else if (query == "INVERSE_COSINE") {
                        auto inverseCosine = std::acos(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, inverseCosine));
                        return true;
                    } else if (query == "INVERSE_TANGENT") {
                        auto inverseTangent = std::atan(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, inverseTangent));
                        return true;
                    } else if (query == "INVERSE_COTANGENT") {
                        auto inverseCot = ct::acot(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, inverseCot));
                        return true;
                    } else if (query == "INVERSE_SECANT") {
                        auto inverseSec = ct::asec(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, inverseSec));
                        return true;
                    } else if (query == "INVERSE_COSECANT") {
                        auto inverseCsc = ct::acsc(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, inverseCsc));
                        return true;
                    } else if (query == "HYP_SINE") {
                        auto hyperSine = std::sinh(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, hyperSine));
                        return true;
                    } else if (query == "HYP_COSINE") {
                        auto hyperCosine = std::cosh(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, hyperCosine));
                        return true;
                    } else if (query == "HYP_TANGENT") {
                        auto hyperTangent = std::tanh(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, hyperTangent));
                        return true;
                    } else if (query == "HYP_COTANGENT") {
                        auto Cothan = ct::coth(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, Cothan));
                        return true;
                    } else if (query == "HYP_SECANT") {
                        auto Shek = ct::sech(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, Shek));
                        return true;
                    } else if (query == "HYP_COSECANT") {
                        auto CoShek = ct::csch(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, CoShek));
                        return true;
                    } else if (query == "INVERSE_HYP_SINE") {
                        auto inverseHypSine = std::asinh(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, inverseHypSine));
                        return true;
                    } else if (query == "INVERSE_HYP_COSINE") {
                        auto inverseHypCosine = std::acosh(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, inverseHypCosine));
                        return true;
                    } else if (query == "INVERSE_HYP_TANGENT") {
                        auto inverseHypTangent = std::atanh(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, inverseHypTangent));
                        return true;
                    } else if (query == "INVERSE_HYP_COTANGENT") {
                        auto InvCOTH = ct::acoth(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, InvCOTH));
                        return true;
                    } else if (query == "INVERSE_HYP_SECANT") {
                        auto InvSheck = ct::asech(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, InvSheck));
                        return true;
                    } else if (query == "INVERSE_HYP_COSECANT") {
                        auto INV_CSCH = ct::acsch(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, INV_CSCH));
                        return true;
                    } else if (query == "NATURAL_LOGARITHM") {
                        if (fOperand == zero) {
                            throw std::runtime_error("Cannot take log of zero !");
                        }
                        auto ln = std::log(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, ln));
                        return true;
                    } else if (query == "POWER_E") {
                        auto expo = std::exp(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, expo));
                        return true;
                    } else if (query == "CONJUGATE") {
                        auto conjg = std::conj(fOperand);
                        answerStrings.emplace_back(constructAnswer(query, fOperand, conjg));
                        return true;
                    } else {
                        return false;
                    }
                };
                if (calculate_complex_single(QUERY, F_OPERAND) ||
                    calculate_complex_double(QUERY, F_OPERAND, S_OPERAND)) { continue; } else {
                    std::string current_error = "Syntax Fault: MmQLC failed to process " + QUERY;
                    appendError(current_error);
                }
            }
        };
        doReal();
        doComplex();
        if (!error_messages.empty())
            throw std::runtime_error(get_string_errors());
        return answerStrings;
    }
};

#endif
