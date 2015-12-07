#include "GroupCommand.h"
#include "Model.h"
GroupCommand::GroupCommand(Model* model, vector<string> descriptions):
    m(model), vecDes(descriptions){}

GroupCommand::~GroupCommand(){}

void GroupCommand::execute(){
    m->groupGraphis(vecDes);
}

void GroupCommand::unexecute(){

}
