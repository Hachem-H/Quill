#pragma once

#include <stdio.h>

namespace Quill
{
    namespace Console
    {
        const char* const MODE_RESET     = "\033[0m";
        const char* const MODE_BOLD      = "\033[1m";
        const char* const MODE_UNDERLINE = "\033[4m";
        const char* const MODE_ITALIC    = "\033[3m";

        const char* const COLORS_RED       = "\033[91m";
        const char* const COLORS_GREEN     = "\033[92m";
        const char* const COLORS_YELLOW    = "\033[93m";
        const char* const COLORS_BLUE      = "\033[94m";
        const char* const COLORS_MAGENTA   = "\033[95m";
        const char* const COLORS_CYAN      = "\033[96m";
    };

    namespace Logger
    {
        void Init();
    };
};

#define QUILL_INFO(...) {                                 \
    printf("[%s%sINFO%s]: ", Quill::Console::COLORS_CYAN, \
                             Quill::Console::MODE_BOLD,   \
                             Quill::Console::MODE_RESET); \
    printf(__VA_ARGS__); printf("\n"); }

#define QUILL_DEBUG(...) {                                 \
    printf("[%s%sDEBUG%s]: ", Quill::Console::COLORS_BLUE, \
                              Quill::Console::MODE_BOLD,   \
                              Quill::Console::MODE_RESET); \
    printf(__VA_ARGS__); printf("\n");}

#define QUILL_WARN(...) {                                   \
    printf("[%s%sWARN%s]: ", Quill::Console::COLORS_YELLOW, \
                             Quill::Console::MODE_BOLD,     \
                             Quill::Console::MODE_RESET);   \
    printf(__VA_ARGS__); printf("\n"); }

#define QUILL_ERROR(...) {                                 \
    printf("[%s%sERROR%s]: ", Quill::Console::COLORS_RED,  \
                              Quill::Console::MODE_BOLD,   \
                              Quill::Console::MODE_RESET); \
    printf(__VA_ARGS__); printf("\n"); }
