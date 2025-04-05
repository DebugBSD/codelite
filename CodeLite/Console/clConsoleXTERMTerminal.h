#ifndef CLCONSOLEXTERMTERMINAL_H
#define CLCONSOLEXTERMTERMINAL_H

#include "clConsoleGnomeTerminal.h"
#include "codelite_exports.h"

class WXDLLIMPEXP_CL clConsoleXTERMTerminal : public clConsoleGnomeTerminal
{
public:
    clConsoleXTERMTerminal();
    virtual ~clConsoleXTERMTerminal();
};

#endif // CLCONSOLELXTERMINAL_H
