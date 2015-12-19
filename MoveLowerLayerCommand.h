#ifndef MOVELOWERLAYERCOMMAND_H_INCLUDED
#define MOVELOWERLAYERCOMMAND_H_INCLUDED

#include "Command.h"
#include "Graphics.h"
class Model;
class MoveLowerLayerCommand : public Command{
public:
    MoveLowerLayerCommand(Model* model, Graphics* group, Graphics* groupChild);
    ~MoveLowerLayerCommand();
    void execute();
    void unexecute();
private:
    Model* m;
    Graphics* group;
    Graphics* groupChild;

};

#endif // MOVELOWERLAYERCOMMAND_H_INCLUDED
