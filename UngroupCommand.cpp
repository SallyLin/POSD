#include "UngroupCommand.h"
#include "Model.h"
UngroupCommand::UngroupCommand(Model* model, std::string description, int childNum):
    m(model), des(description), childNum(childNum){}

UngroupCommand::~UngroupCommand(){}

void UngroupCommand::execute(){
    m->executeUngroup(des);
}

void UngroupCommand::unexecute(){
    m->unexecuteUngroup(childNum);
}
