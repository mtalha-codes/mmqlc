#ifndef LEXER_HPP
#define LEXER_HPP

#include <vector>
#include <tuple>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include "../grammar/Grammar.hpp"


inline std::vector<std::tuple<std::string, std::string, std::string> >
tokenize(const std::vector<std::string> &queries,
         const std::unordered_map<std::string, std::string> &resolved_varMap = {}) {
    std::vector<std::tuple<std::string, std::string, std::string> > tokens;
    auto getVar = [&resolved_varMap](const std::string &varName) {
        auto it = resolved_varMap.find(varName);
        if (it == resolved_varMap.end())
            return std::string("");
        return it->second;
    };
    auto processReal = [&](const std::string &query) {
        const std::unordered_set<std::string> SingleOperand_Queries = {
            "FACTORIAL",
            "SINE", "COSINE", "TANGENT",
            "SECANT", "COSECANT", "COTANGENT",
            "HYP_SINE", "HYP_COSINE", "HYP_TANGENT",
            "HYP_SECANT", "HYP_COTANGENT", "HYP_COSECANT",
            "INVERSE_SINE", "INVERSE_COSINE", "INVERSE_TANGENT",
            "INVERSE_SECANT", "INVERSE_COSECANT", "INVERSE_COTANGENT",
            "INVERSE_HYP_SINE", "INVERSE_HYP_COSINE", "INVERSE_HYP_TANGENT",
            "INVERSE_HYP_SECANT", "INVERSE_HYP_COTANGENT", "INVERSE_HYP_COSECANT",
            "FLOOR", "CEILING", "ABSOLUTE", "NATURAL_LOGARITHM", "BINARY_LOGARITHM", "COMMON_LOGARITHM"
        };
        if (query.rfind("SET", 0) == 0) // if query is variable definition skip tokenization
            return true;
        if (std::smatch matches; std::regex_match(query, matches, grammar::queries::var_get)) {
            if (!resolved_varMap.contains(matches[2].str()))
                throw std::runtime_error("\nError: Attempt to access undefined variable");
            std::string keyWord = matches[1].str();
            std::string firstOperand = matches[2].str();
            std::string secondOperand = resolved_varMap.at(matches[2].str());
            tokens.emplace_back(keyWord, firstOperand, secondOperand);
            return true;
        } else if (std::regex_match(query, matches, grammar::queries::realQueryS)) {
            if (const std::string keyWord = matches[1].str(); SingleOperand_Queries.contains(keyWord)) {
                std::string firstOperand = matches[2].str();
                tokens.emplace_back(keyWord, firstOperand, "");
                return true;
            }
        } else if (std::regex_match(query, matches, grammar::queries::QuerySV)) {
            if (const std::string keyWord = matches[1].str(); SingleOperand_Queries.contains(keyWord)) {
                std::string firstOperand = getVar(matches[2].str());
                if (firstOperand.empty())
                    throw std::runtime_error("\nError: Undeclared Variable Called !");
                tokens.emplace_back(keyWord, firstOperand, "");
                return true;
            }
        } else if (std::regex_match(query, matches, grammar::queries::realQueryD)) {
            const std::string keyWord = matches[1].str();
            if (SingleOperand_Queries.contains(keyWord)) return false;
            const std::string firstOperand = matches[2].str();
            const std::string secondOperand = matches[6].str();
            tokens.emplace_back(keyWord, firstOperand, secondOperand);
            return true;
        } else if (std::regex_match(query, matches, grammar::queries::QueryDV)) {
            const std::string keyWord = matches[1].str();
            if (SingleOperand_Queries.contains(keyWord)) return false;
            const std::string firstOperand = getVar(matches[2].str());
            const std::string secondOperand = getVar(matches[3].str());
            if (firstOperand.empty() || secondOperand.empty())
                throw std::runtime_error("\nError: Undeclared Variable Called !");
            tokens.emplace_back(keyWord, firstOperand, secondOperand);
            return true;
        }
        return false;
    };
    auto processComplex = [&](const std::string &query) {
        const std::unordered_set<std::string> SingleOperand_Queries = {
            "MODULUS", "CONJUGATE", "ARGUMENT",
            "SINE", "COSINE", "TANGENT",
            "COSECANT", "SECANT", "COTANGENT",
            "INVERSE_SINE", "INVERSE_COSINE", "INVERSE_TANGENT",
            "INVERSE_SECANT", "INVERSE_COSECANT", "INVERSE_COTANGENT",
            "HYP_SINE", "HYP_COSINE", "HYP_TANGENT",
            "HYP_SECANT", "HYP_COSECANT", "HYP_COTANGENT",
            "INVERSE_HYP_SINE", "INVERSE_HYP_COSINE", "INVERSE_HYP_TANGENT",
            "INVERSE_HYP_COSECANT", "INVERSE_HYP_SECANT", "INVERSE_HYP_COTANGENT",
            "NATURAL_LOGARITHM", "POWER_E"
        };
        if (query.rfind("SET", 0) == 0) // if query is variable definition skip tokenization+parsing
            return true;
        if (std::smatch matches; std::regex_match(query, matches, grammar::queries::var_get)) {
            if (!resolved_varMap.contains(matches[2].str()))
                throw std::runtime_error("\nError: Attempt to access undefined variable");
            std::string keyWord = matches[1].str();
            std::string firstOperand = matches[2].str();
            std::string secondOperand = resolved_varMap.at(matches[2].str());
            tokens.emplace_back(keyWord, firstOperand, secondOperand);
            return true;
        } else if (std::regex_match(query, matches, grammar::queries::complexQueryS)) {
            if (const std::string keyWord = matches[1].str(); SingleOperand_Queries.contains(keyWord)) {
                const std::string firstOperand = matches[2].str();
                tokens.emplace_back(keyWord, firstOperand, "");
                return true;
            }
        } else if (std::regex_match(query, matches, grammar::queries::QuerySV)) {
            if (const std::string keyWord = matches[1].str(); SingleOperand_Queries.contains(keyWord)) {
                std::string firstOperand = getVar(matches[2].str());
                if (firstOperand.empty())
                    throw std::runtime_error("\nError: Undeclared Variable Called !");
                tokens.emplace_back(keyWord, firstOperand, "");
                return true;
            }
        } else if (std::regex_match(query, matches, grammar::queries::complexQueryD)) {
            const std::string keyWord = matches[1].str();
            if (SingleOperand_Queries.contains(keyWord)) return false;
            const std::string firstOperand = matches[2].str();
            const std::string secondOperand = matches[12].str();
            tokens.emplace_back(keyWord, firstOperand, secondOperand);
            return true;
        } else if (std::regex_match(query, matches, grammar::queries::QueryDV)) {
            const std::string keyWord = matches[1].str();
            if (SingleOperand_Queries.contains(keyWord)) return false;
            const std::string firstOperand = getVar(matches[2].str());
            const std::string secondOperand = getVar(matches[3].str());
            if (firstOperand.empty() || secondOperand.empty())
                throw std::runtime_error("\nError: Undeclared Variable Called !");
            tokens.emplace_back(keyWord, firstOperand, secondOperand);
            return true;
        }
        return false;
    };
    for (const auto &query: queries) {
        if (processReal(query) || processComplex(query))
            continue; // if correct  then goto new query and pass it to tokens
        else {
            tokens.emplace_back(query, "", "");
        }
    }
    return tokens;
}


#endif