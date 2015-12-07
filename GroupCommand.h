#ifndef GROUPCOMMAND_H_INCLUDED
#define GROUPCOMMAND_H_INCLUDED

#include "Command.h"
#include <vector>
#include <string>
using namespace std;
class Model;
class GroupCommand : public Command{
public:
    GroupCommand(Model* model, vector<string> descriptions);
    ~GroupCommand();
    void execute();
    void unexecute();
private:
    vector<string> vecDes;
    Model* m;
};

#endif // GROUPCOMMAND_H_INCLUDED
