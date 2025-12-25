find_package(Boost REQUIRED COMPONENTS math multiprecision)
find_package(fmt CONFIG REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(gmp REQUIRED IMPORTED_TARGET gmp)
pkg_check_modules(gmpxx REQUIRED IMPORTED_TARGET gmpxx)
pkg_check_modules(mpfr REQUIRED IMPORTED_TARGET mpfr)

add_executable(mmqli
        main.cpp
        grammar/Grammar.hpp
        core/Core.hpp
        core/helpers/constants.hpp
        core/helpers/functions.hpp
        lexer/Lexer.hpp
        parser/Parser.hpp
        vresolver/VResolver.hpp
        cli/CLInterface.cpp
        core/Core.cpp
        lexer/Lexer.cpp
        parser/Parser.cpp
        vresolver/VResolver.cpp
        core/helpers/trigonometry.hpp
        core/helpers/combinatorics.hpp
        cli/CLInterface.hpp
        core/helpers/boost_fwd.hpp
)
target_link_libraries(mmqli PRIVATE
        Boost::math
        Boost::multiprecision
        PkgConfig::gmp
        PkgConfig::gmpxx
        PkgConfig::mpfr
        fmt::fmt-header-only
)
