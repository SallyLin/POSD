#ifndef CREATERECTANGLECOMMAND_H_INCLUDED
#define CREATERECTANGLECOMMAND_H_INCLUDED

#include "Command.h"
class Model;

class CreateRectangleCommand : public Command{
public:
    CreateRectangleCommand(Model* model, int x, int y, int length, int width);
    ~CreateRectangleCommand();
    void execute();
    void unexecute();
private:
    Model* m;
    int x, y, l, w;
};

#endif // CREATERECTANGLECOMMAND_H_INCLUDED
