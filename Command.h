#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

class Command{
public:
    Command();
    virtual ~Command();
    virtual void execute();
    virtual void unexecute();
};

#endif // COMMAND_H_INCLUDED
