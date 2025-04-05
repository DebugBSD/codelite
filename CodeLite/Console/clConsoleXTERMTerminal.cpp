#include "clConsoleXTERMTerminal.h"

#include "Platform/Platform.hpp"
#include "StdToWX.h"

clConsoleXTERMTerminal::clConsoleXTERMTerminal()
{
    wxString executable = "xterm";
    const wxArrayString commands = StdToWX::ToArrayString({"xterm", "xterm", "xterm"});
    ThePlatform->AnyWhich(commands, &executable);

    SetTerminalCommand(executable + " -e %COMMAND%");
    SetEmptyTerminalCommand(executable + " -cd %WD%");
}

clConsoleXTERMTerminal::~clConsoleXTERMTerminal() {}
