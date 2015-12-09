#ifndef MOVECOMMAND_H_INCLUDED
#define MOVECOMMAND_H_INCLUDED

#include "Command.h"
#include <string>
#include "Graphics.h"

class Model;
class MoveCommand : public Command{
public:
    MoveCommand(Model* model, Graphics* graphics, int del_x, int del_y);
    ~MoveCommand();
    void execute();
    void unexecute();
private:
    Model* m;
    Graphics* g;
    int del_x, del_y;
};

#endif // MOVECOMMAND_H_INCLUDED
