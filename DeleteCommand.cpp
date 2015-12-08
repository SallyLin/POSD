#include "DeleteCommand.h"
#include "Model.h"
DeleteCommand::DeleteCommand(Model* model, int order) : m(model), order(order){}

DeleteCommand::~DeleteCommand(){}

void DeleteCommand::execute(){
    m->deleteGraphic(order);
}

void DeleteCommand::unexecute(){
    m->recoverGraphic(order);
}
