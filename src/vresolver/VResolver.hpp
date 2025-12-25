#ifndef VARIABLE_RESOLVER_HPP
#define VARIABLE_RESOLVER_HPP

#include "../core/Core.hpp"

inline std::unordered_map<std::string, std::string> find_and_resolve_vars(
    const std::vector<std::string> &queries, const std::unordered_map<std::string, std::string> &varMAP = {}) {
    std::unordered_map<std::string, std::string> resolvedVarMap = varMAP;
    std::smatch matches;
    auto resolveVarS = [&](const std::string &varQuery) {
        // resolves variables with simple queries.
        const auto varToken = tokenize({varQuery});
        const auto varParse = std::make_unique<Parser>(varToken);
        const auto varResolved = std::make_unique<Core>(varParse->parse_RealNums(),
                                                        varParse->parse_cmplxNums());
        std::string res = varResolved->calculateAnswers()[0];
        if (const size_t pos = res.find('='); pos != std::string::npos) {
            res = res.substr(pos + 2);
            res.pop_back(); // remove newline character at the end !.
        }
        return res;
    };
    auto resolveVarQ = [&](const std::string &varQuery, const std::unordered_map<std::string, std::string> &varMap) {
        // resolves variables with query involving variables
        const auto varToken = tokenize({varQuery}, varMap);
        const auto varParse = std::make_unique<Parser>(varToken);
        const auto varResolved = std::make_unique<Core>(varParse->parse_RealNums(),
                                                        varParse->parse_cmplxNums());
        std::string res = varResolved->calculateAnswers()[0];
        if (const size_t pos = res.find('='); pos != std::string::npos) {
            res = res.substr(pos + 2);
            res.pop_back(); // remove newline character at the end !.
        }
        return res;
    };
    for (const auto &q: queries) {
        if (q.rfind("SET", 0) != 0)
            continue;
        if (std::regex_match(q, matches, grammar::variables::realVar) || std::regex_match(
                q, matches, grammar::variables::complexVar)) {
            resolvedVarMap[matches[1].str()] = matches[2].str();
        } else if (std::regex_match(q, matches, grammar::variables::realVarS) || std::regex_match(
                       q, matches, grammar::variables::complexVarS)) {
            const std::string varName = matches[1].str();
            const std::string varValue = resolveVarS(matches[2].str());
            resolvedVarMap[varName] = varValue;
        } else if (std::regex_match(q, matches, grammar::variables::realVarD) || std::regex_match(
                       q, matches, grammar::variables::complexVarD)) {
            const std::string varName = matches[1].str();
            const std::string varValue = resolveVarS(matches[2].str());
            resolvedVarMap[varName] = varValue;
        } else if (std::regex_match(q, matches, grammar::variables::QueryVarS) || std::regex_match(
                       q, matches, grammar::variables::QueryVarD)) {
            const std::string varName = matches[1].str();
            const std::string varValue = resolveVarQ(matches[2].str(), resolvedVarMap);
            resolvedVarMap[varName] = varValue;
        } else
            throw std::runtime_error("\nError:Variable rules violated !");
    }
    return resolvedVarMap;
}

#endif //MMQLC_VARS_HPP