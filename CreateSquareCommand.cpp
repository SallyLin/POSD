#include "CreateSquareCommand.h"
#include "Model.h"
#include "SimpleGraphics.h"
#include "Square.h"

CreateSqaureCommand::CreateSqaureCommand(Model* model, int x, int y, int length):
    m(model), x(x), y(y), l(length){}

CreateSqaureCommand::~CreateSqaureCommand(){}

void CreateSqaureCommand::execute(){
    SimpleGraphics* sg = new SimpleGraphics(new Square(x, y, l));
    m->addGraphices(sg);
}

void CreateSqaureCommand::unexecute(){
    m->deleteLastGraphics();
}
