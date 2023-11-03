#pragma once

#if defined(_WIN32) || defined(_WIN64)
    #define QUILL_WINDOWS
#elif defined(__APPLE__) || defined(__linux__)
    #define QUILL_UNIX
#else
    #error "Unsupported platform"
#endif