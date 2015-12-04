#include "CreateRectangleCommand.h"
#include "Model.h"
#include "SimpleGraphics.h"
#include "Rectangle.h"

CreateRectangleCommand::CreateRectangleCommand
    (Model* model, int x, int y, int length, int width):
    m(model), x(x), y(y), l(length), w(width){}

CreateRectangleCommand::~CreateRectangleCommand(){}

void CreateRectangleCommand::execute(){
    SimpleGraphics* sg = new SimpleGraphics(new Rectangle(x, y, l, w));
    m->addGraphices(sg);
}

void CreateRectangleCommand::unexecute(){
    m->deleteLastGraphics();
}
