#ifndef MOVECOMMAND_H_INCLUDED
#define MOVECOMMAND_H_INCLUDED

#include "Command.h"
#include <string>

class Model;
class MoveCommand : public Command{
public:
    MoveCommand(Model* model, std::string description, int del_x, int del_y);
    ~MoveCommand();
    void execute();
    void unexecute();
private:
    Model* m;
    std::string des;
    int del_x, del_y;
};

#endif // MOVECOMMAND_H_INCLUDED
