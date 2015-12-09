#ifndef COMMANDMANAGER_H_INCLUDED
#define COMMANDMANAGER_H_INCLUDED

#include <stack>
#include "Command.h"
using namespace std;

class CommandManager{
public:
    CommandManager();
    ~CommandManager();
    void execute(Command* cmd);
    void redo();
    void undo();
    bool isUndoEmpty();
    bool isRedoEmpty();
private:
    stack<Command*>undoCmds;
    stack<Command*>redoCmds;
};


#endif // COMMANDMANAGER_H_INCLUDED
