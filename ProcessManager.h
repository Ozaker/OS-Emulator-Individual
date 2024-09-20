#pragma once
#include <map>
#include "Config.h"
#include "Console.h"
#include "utils.h"


using std::map, std::pair, std::make_pair;

class ProcessManager {
private:
	bool initialized;
	Config config;

	Console mainConsole;
	map<string, Console> consoles;

	Console* attachedConsole;
	bool mainAttached;

public:
	ProcessManager();

	void start();
	bool mainLoopInner();

private:
	void executeScreenCommand(const vector<string> command);
	void executeSubscreenCommand(const vector<string> command); // returns whether the command was a valid subscreen command

	// returns a pointer to the newly inserted element (if any) and a boolean signifying whether a console with name=name already existed 
	pair<Console*, bool> tryAddConsole(const string name);
};
