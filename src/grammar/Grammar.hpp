/*
* Filename: mmqlc.regex.hpp
 * Author: Muhammad Talha
 * Github: MTalha-Codes
 * Repository: mmqlc
 * Copyright(C) - 2024
 * */


#ifndef MMQLC_REGEX_HPP
#define MMQLC_REGEX_HPP
#include <regex>

namespace regex::queries {
    const std::regex realQueryS(R"((?!\d)(\w+)\s(-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?))"); // single arg real query
    const std::regex realQueryD(
        R"((?!\d)(\w+)\s(-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?),\s*(-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?))");
    // double arg real query
    const std::regex complexQueryS(
        R"((?!\d)(\w+)\s((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)))");
    // single arg complex query
    const std::regex complexQueryD(
        R"((?!\d)(\w+)\s((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)),\s*((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)))");
    // double arg complex query
    const std::regex var_get(R"((GET)\s(?!\d)(\w+))"); // query used to get the value from mmqlc's memory
    const std::regex QuerySV(R"((?!\d)(\w+)\s(\w+))"); // works for both complex and real numbers
    const std::regex QueryDV(R"((?!\d)(\w+)\s(\w+),\s*(\w+))"); // works for both complex and real numbers
}

namespace regex::queries::internal {
    const std::regex var_get_internalReal(R"(GET\s(?!\d)(\w+)\s*=\s*(-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?))");
    // that's what the parser will do to get query [REAL NUMBERS] ;
    const std::regex var_get_internalComplex(
        R"(GET\s(?!\d)(\w+)\s*=\s*((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)))");
    // that's what the parser will do to get query [COMPLEX NUMBERS] ;
}

namespace regex::numbers {
    const std::regex complexNum(
        R"(((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)))");
    // regex for complex number
    const std::regex realNum(R"((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?))"); // regex  for real number
}

namespace regex::variables {
    const std::regex realVar(R"(SET\s(?!\d)(\w+)\s*=\s*(-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?))");
    const std::regex realVarS(R"(SET\s(?!\d)(\w+)\s*=\s*(\w+\s-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?))");
    const std::regex realVarD(
        R"(SET\s(?!\d)(\w+)\s*=\s*(\w+\s-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?,-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?))");
    const std::regex complexVar(
        R"(SET\s(?!\d)(\w+)\s*=\s*((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)))");
    const std::regex complexVarS(
        R"(SET\s(?!\d)(\w+)\s*=\s*(\w+\s(-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i)))");
    const std::regex complexVarD(
        R"(SET\s(?!\d)(\w+)\s*=\s*(\w+\s(-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i),((-?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)?(([-+]?\d+(\.\d+)?([Ee][+-]\d+(\.\d+)?)?)i))))");
    const std::regex QueryVarD(R"(SET\s(?!\d)(\w+)\s*=\s*(\w+\s\w+,\w+))");
    const std::regex QueryVarS(R"(SET\s(?!\d)(\w+)\s*=\s*(\w+\s\w+))");
}
#endif //MMQLC_REGEX_HPP
