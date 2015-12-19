#ifndef MOVEUPPERLAYERCOMMAND_H_INCLUDED
#define MOVEUPPERLAYERCOMMAND_H_INCLUDED
#include "Command.h"
#include "Graphics.h"
class Model;
class MoveUpperLayerCommand : public Command{
public:
    MoveUpperLayerCommand(Model* model, Graphics* group, Graphics* groupChild);
    ~MoveUpperLayerCommand();
    void execute();
    void unexecute();

private:
    Model* m;
    Graphics* group;
    Graphics* groupChild;
};

#endif // MOVEUPPERLAYERCOMMAND_H_INCLUDED
