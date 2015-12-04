#include "CommandManager.h"
#include <string>
CommandManager::CommandManager(){}

CommandManager::~CommandManager(){}

void CommandManager::execute(Command* cmd) {
	cmd->execute();
	undoCmds.push(cmd);

	// cleanup and release redoable commands
	while (!redoCmds.empty()) {
		Command* c = redoCmds.top();
		redoCmds.pop();
		delete c;
	}
}

void CommandManager::redo() {
	if (redoCmds.size() == 0){
		throw std::string("Can't Redo!");
	}

	Command* c = redoCmds.top();
	redoCmds.pop();
	c->execute(); // redo the command
	undoCmds.push(c);
}

void CommandManager::undo() {
	if (undoCmds.size() == 0){
		throw std::string("Can't Undo!");
	}

	Command* c = undoCmds.top();
	undoCmds.pop();
	c->unexecute(); // undo the command
	redoCmds.push(c);
}