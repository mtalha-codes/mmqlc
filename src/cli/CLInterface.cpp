module CLInterface;
#include "../vresolver/VResolver.hpp"
#include "fmt/color.h"

#if WIN32
#include <windows.h>

/**
 * @name enable_virtual_terminal_processing
 * @brief This function is responsible for virtual terminal processing to support ascii escape sequences for colors on Windows.
 * @note This function is only compiled on Windows.
 */
inline void enable_virtual_terminal_processing() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;

    if (hOut == INVALID_HANDLE_VALUE)
        return;

    // Enable ANSI escape code support
    if (GetConsoleMode(hOut, &dwMode)) {
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
    }
}
#endif

/**
 * @breif This function is called when the mmqlc is invoked with an unknown flag.
 */
void mmqli::cli::CLInterface::unknown_flag_error() noexcept {
    fmt::print(fg(fmt::color::white) | fmt::emphasis::bold, "mmqlc: ");
    fmt::print(fg(fmt::color::red), "error: ");
    fmt::print("mmqlc invoked with unrecognised command-line option\nfailed to initialize interpreter.\n");
}

/**
 * @brief This function prints the copyright notice when the interpreter is initiated.
 */
void mmqli::cli::CLInterface::print_copyright_notice() noexcept {
    fmt::println("mmqlc (mtalha-codes) 3.0\nCopyright (C) 2026-27\nLicensed under AGPL v3.0-or-later.");
}

/**
 * @brief This show the help screen of mmqlc.
 */
void mmqli::cli::CLInterface::show_help_message() {
    fmt::println("Usage: mmqlc <[OPTION]> (binary can be started without any options)");
    fmt::println("Options:\n{} {}\n{} {}",
                 "--help",
                 "show this screen",
                 "--version",
                 "show version and copyright details"
    );
    exit(EXIT_SUCCESS);
}

/**
 * @brief  This clears the console screen of mmqlc. It is a platform-agnostic function, if you are on Windows,
 * it'll use the `cls` command otherwise if you are on unix like systems, it'll use the `clear` command.
 */
void mmqli::cli::CLInterface::clear_screen_platform_agnostic() {
#if WIN32
    system("cls");
#else
    system("clear");
#endif
}

/**
 * @short It is bread and butter of this whole class, this function process the queries, parses it, evaluate it via the API and the print it to the console.
 * @brief This function print some messages and after that it takes input of the query, it runs some checks to determine whether the query is
 * 1. a comment
 * 2. an empty line
 * 3. or a variable declaration line
 *
 * after that it tokenize the query, parse the query and pass it to the core class, and then it returns the result and print the calculated result.
 */
void mmqli::cli::CLInterface::start_interpreter() {
    constexpr auto help = "help";
    print_copyright_notice();
    fmt::print("\n");
    fmt::print(fg(fmt::color::white) | fmt::emphasis::bold, "mmqlc: ");
    fmt::print(fg(fmt::color::green), "real-time query interpreter started!\n");
    fmt::print("type '{}' to show session-specific commands. \n\n",
               fmt::format(fg(fmt::color::white) | fmt::emphasis::italic, help)
    );
    std::string query;
    std::unordered_map<std::string, std::string> variables_hashtable;
    auto empty_line = [](const std::string &q) { return q.empty(); };
    auto commented_line = [](const std::string &q) {
        return q.rfind("%%", 0) == 0;
    };
    auto var_declaration_line = [](const std::string &q) {
        return q.rfind("set", 0) == 0;
    };
    while (true) {
        fmt::print(fg(fmt::color::cyan), ">>> ");
        std::getline(std::cin, query);
        if (empty_line(query) || commented_line(query))
            continue;
        if (constexpr auto clear = "clear"; query == clear) {
            clear_screen_platform_agnostic();
            continue;
        }
        if (constexpr auto quit = "quit"; query == quit)
            break;
        if (constexpr auto flushmem = "flushmem"; query == flushmem) {
            variables_hashtable.clear();
            clear_screen_platform_agnostic();
            continue;
        }
        if (var_declaration_line(query)) {
            for (auto kp = find_and_resolve_vars({query}, variables_hashtable);
                 const auto &[varName, varValue]: kp)
                // this loop will always have one pass
                variables_hashtable[varName] = varValue;
            continue;
        }
        if (query == help) {
            fmt::println("{}\t{}\n{}\t{}\n{}\t{}",
                         "clear", "Clear the console screen",
                         "flushmem", "Erase session memory",
                         "quit", "Exit Session"
            );
            continue;
        }
        const auto answer = [&]() {
            const auto token = tokenize({query}, variables_hashtable);
            const auto parse_ptr = std::make_unique<Parser>(token);
            const auto ansPTR = std::make_unique<Core>(
                parse_ptr->parse_RealNums(), parse_ptr->parse_cmplxNums());
            return ansPTR->calculateAnswers()[0];
        }();
        fmt::print(fg(fmt::color::white) | fmt::emphasis::bold, "{}\n",
                   answer.substr(answer.find('=') + 2)); // Skip "= "
    }
}

/**
 * @brief as the name suggest what it does.
 */
void mmqli::cli::CLInterface::show_version_plus_copyright() {
    fmt::println("mmqlc (mtalha-codes) v3.0\nCopyright (C) 2026-27\nLicensed under AGPL v3.0-or-later.");
    exit(EXIT_SUCCESS);
}

mmqli::cli::CLInterface::CLInterface(const int argsC, char **argvA) {
    this->argument_count = argsC;
    this->argument_vector = argvA;
}

/**
 * This function just emulates the mmqlc cli.
 * At first, it checks whether the cli was invoked command line arguments or not,
 * if so then it checks which flags was it called with, if an unknown flag then it print error message, otherwise it calls the attached functions
 * and if no command line arguments then it starts the interpreter.
 */
void mmqli::cli::CLInterface::start_cli() {
    if (argument_count == 1) {
#if WIN32
        enable_virtual_terminal_processing();
#endif
        start_interpreter();
    }
    if (argument_count == 2) {
        if (std::string_view(argument_vector[1]) == "--help")
            show_help_message();
        if (std::string_view(argument_vector[1]) == "--version")
            show_version_plus_copyright();
        unknown_flag_error();
    }
}