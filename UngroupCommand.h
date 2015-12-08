#ifndef UNGROUPCOMMAND_H_INCLUDED
#define UNGROUPCOMMAND_H_INCLUDED
#include "Command.h"
#include <string>
class Model;
class UngroupCommand : public Command{
public:
    UngroupCommand(Model* model, std::string description, int childNum);
    ~UngroupCommand();
    void execute();
    void unexecute();
private:
    Model* m;
    int childNum;
    std::string des;
};

#endif // UNGROUPCOMMAND_H_INCLUDED
