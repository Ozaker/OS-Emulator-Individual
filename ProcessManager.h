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

public:
	ProcessManager();

	void start();
	bool mainLoopInner(bool& mainInControl);

private:
	// returns a pointer to the newly inserted element (if any) and a boolean signifying whether a console with name=name already existed 
	pair<Console*, bool> tryAddConsole(const string name);
};
