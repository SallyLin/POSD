#include "MoveLowerLayerCommand.h"
#include "Model.h"

MoveLowerLayerCommand::MoveLowerLayerCommand(Model* model, Graphics* group, Graphics* groupChild):
    m(model), group(group), groupChild(groupChild){}

MoveLowerLayerCommand::~MoveLowerLayerCommand(){}

void MoveLowerLayerCommand::execute(){
    m->graphicsMoveLowerLayer(group, groupChild);
}

void MoveLowerLayerCommand::unexecute(){
    m->graphicsMoveUpperLayer(group, groupChild);
}
