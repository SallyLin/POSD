#include "MoveCommand.h"
#include "Model.h"

MoveCommand::MoveCommand(Model* model, Graphics* graphics, int del_x, int del_y):
    m(model), g(graphics), del_x(del_x), del_y(del_y){}

MoveCommand::~MoveCommand(){}

void MoveCommand::execute(){
    m->graphicMove(g, del_x, del_y);
}

void MoveCommand::unexecute(){
    m->graphicMove(g, (-del_x), (-del_y));
}
