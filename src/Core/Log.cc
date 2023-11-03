#include "Log.hh"
#include "Platform.hh"

namespace Quill
{
    namespace Logger
    { 
        void Init()
        {
        #if defined(QUILL_WINDOWS)
            HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

            if (outputHandle == INVALID_HANDLE_VALUE)
                return;

            DWORD consoleMode = 0;
            if (!GetConsoleMode(outputHandle, &consoleMode))
                return;

            consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            if (!SetConsoleMode(outputHandle, consoleMode))
                return;
        #endif
        }
    }
}
