#ifndef CREATECIRCLECOMMAND_H_INCLUDED
#define CREATECIRCLECOMMAND_H_INCLUDED

#include "Command.h"

class Model;
class CreateCircleCommand : public Command{
public:
    CreateCircleCommand(Model* model, int x, int y, int radius);
    ~CreateCircleCommand();
    void execute();
    void unexecute();
private:
    Model* m;
    int x, y, r;
};

#endif // CREATECIRCLECOMMAND_H_INCLUDED
