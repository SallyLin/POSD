#include "CreateCircleCommand.h"
#include "Model.h"
#include "SimpleGraphics.h"
#include "Circle.h"
CreateCircleCommand::CreateCircleCommand(Model* model, int x, int y, int radius):
    m(model), x(x), y(y), r(radius){}

CreateCircleCommand::~CreateCircleCommand(){}

void CreateCircleCommand::execute(){
    SimpleGraphics* sg = new SimpleGraphics(new Circle(x, y, r));
    m->addGraphices(sg);
}

void CreateCircleCommand::unexecute(){
    m->deleteLastGraphics();
}
