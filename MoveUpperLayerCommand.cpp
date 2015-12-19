#include "MoveUpperLayerCommand.h"
#include "Model.h"

MoveUpperLayerCommand::MoveUpperLayerCommand(Model* model, Graphics* group, Graphics* groupChild):
    m(model), group(group), groupChild(groupChild){}

MoveUpperLayerCommand::~MoveUpperLayerCommand(){}

void MoveUpperLayerCommand::execute(){
    m->graphicsMoveUpperLayer(group, groupChild);
}

void MoveUpperLayerCommand::unexecute(){
    m->graphicsMoveLowerLayer(group, groupChild);
}
