#ifndef DELETECOMMAND_H_INCLUDED
#define DELETECOMMAND_H_INCLUDED

#include "Command.h"
class Model;
class DeleteCommand : public Command{
public:
    DeleteCommand(Model* model, int order);
    ~DeleteCommand();
    void execute();
    void unexecute();
private:
    Model* m;
    int order;
};

#endif // DELETECOMMAND_H_INCLUDED
