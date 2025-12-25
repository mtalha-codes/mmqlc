namespace mmqli::cli {
    class CLInterface {
        int argument_count;
        char **argument_vector;

        static void unknown_flag_error() noexcept;

        static void print_copyright_notice() noexcept;

        static void show_help_message();

        static void clear_screen_platform_agnostic();

        static void start_interpreter();

        static void show_version_plus_copyright();

    public:
        CLInterface(int argsC, char **argvA);

        void start_cli();
    };
} // mmqli::cli