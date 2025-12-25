#ifndef PARSER_HPP
#define PARSER_HPP

#include "../lexer/Lexer.hpp"
#include "../core/helpers/constants.hpp"
#include "../core/helpers/boost_fwd.hpp"
#include <complex>
#include <utility>

class Parser {
    std::vector<std::tuple<std::string, std::string, std::string> > raw_tokens;
    std::vector<std::tuple<std::string, float1000, float1000> > realNum_parsed;
    std::vector<std::tuple<std::string, complex1000, complex1000> > complexNums_parsed;

    static float1000 STOD(const std::string &num) {
        if (std::smatch matches; std::regex_match(num, matches, grammar::numbers::realNum))
            return float1000(matches[1].str());
        else if (num.empty())
            return {0};
        else
            throw std::invalid_argument("No Number ??");
    }

    static complex1000 convert_to_complex(const std::string &cmplx_num) {
        if (std::smatch matches; std::regex_match(cmplx_num, matches, grammar::numbers::complexNum)) {
            const float1000 realPart(matches[2].str());
            const float1000 imagPart(matches[7].str());
            complex1000 complex1(realPart, imagPart);
            return complex1;
        } else if (cmplx_num.empty()) {
            return {float1000(0), float1000(0)};
        } else
            throw std::invalid_argument("No Complex Number ??");
    }

public:
    explicit Parser(const std::vector<std::string> &queries,
                    const std::unordered_map<std::string, std::string> &varMap = {}) {
        raw_tokens = tokenize(queries, varMap);
    }

    explicit Parser(const std::vector<std::tuple<std::string, std::string, std::string> > &token) {
        raw_tokens = token;
    }

    std::vector<std::tuple<std::string, float1000, float1000> > parse_RealNums() {
        for (const auto &raw_token: raw_tokens) {
            [[maybe_unused]]
                    float1000 fOperand(0);
            [[maybe_unused]]
                    float1000 sOperand(0);
            std::string queryToken = std::get < 0 > (raw_token);
            if (queryToken == "GET") {
                std::string full = "GET " + std::get < 1 > (raw_token) + " = ";
                try {
                    auto s = STOD(std::get < 2 > (raw_token));
                    full += std::get < 2 > (raw_token);
                } catch (...) {
                    continue;
                }
                realNum_parsed.emplace_back(full, ZERO, ZERO);
                continue;
            }
            try {
                fOperand = STOD(std::get < 1 > (raw_token));
                sOperand = STOD(std::get < 2 > (raw_token));
            } catch (...) {
                continue;
            }
            if (queryToken == "ERROR") {
                realNum_parsed.emplace_back(queryToken, ZERO, ZERO);
            }
            if (std::get < 2 > (raw_token).empty()) {
                realNum_parsed.emplace_back(queryToken, fOperand, ZERO);
            } else {
                realNum_parsed.emplace_back(queryToken, fOperand, sOperand);
            }
        }
        return realNum_parsed;
    }

    std::vector<std::tuple<std::string, complex1000, complex1000> > parse_cmplxNums() {
        for (const auto &raw_token: raw_tokens) {
            complex1000 fOperand(float1000(0), float1000(0));
            complex1000 sOperand(float1000(0), float1000(0));
            std::string queryToken = std::get < 0 > (raw_token);
            if (queryToken == "GET") {
                std::string full = "GET " + std::get < 1 > (raw_token) + " = ";
                try {
                    auto s = convert_to_complex(std::get < 2 > (raw_token));
                    full += std::get < 2 > (raw_token);
                } catch (...) {
                    continue;
                }
                complexNums_parsed.emplace_back(full, zero, zero);
                continue;
            }
            try {
                fOperand = convert_to_complex(std::get < 1 > (raw_token));
                sOperand = convert_to_complex(std::get < 2 > (raw_token));
            } catch (...) {
                continue;
            }
            if (queryToken == "ERROR") {
                complexNums_parsed.emplace_back(queryToken, zero, zero);
            }
            if (std::get < 2 > (raw_token).empty()) {
                complexNums_parsed.emplace_back(queryToken, fOperand, zero);
            } else {
                complexNums_parsed.emplace_back(queryToken, fOperand, sOperand);
            }
        }
        return complexNums_parsed;
    }
};

#endif