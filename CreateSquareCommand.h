#ifndef CREATESQUARECOMMAND_H_INCLUDED
#define CREATESQUARECOMMAND_H_INCLUDED

#include "Command.h"
class Model;

class CreateSqaureCommand : public Command{
public:
    CreateSqaureCommand(Model* model, int x, int y, int length);
    ~CreateSqaureCommand();
    void execute();
    void unexecute();
private:
    Model* m;
    int x, y, l;
};

#endif // SQUARECOMMAND_H_INCLUDED
