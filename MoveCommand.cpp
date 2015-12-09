#include "MoveCommand.h"
#include "Model.h"

MoveCommand::MoveCommand(Model* model, std::string description, int del_x, int del_y):
    m(model), des(description), del_x(del_x), del_y(del_y){}

MoveCommand::~MoveCommand(){}

void MoveCommand::execute(){
    m->graphicMove(des, del_x, del_y);
}

void MoveCommand::unexecute(){
    m->graphicMove(std::string(""), (-del_x), (-del_y));
}
