#pragma once
#include <unordered_map>
#include "Config.h"
#include "Console.h"
#include "utils.h"


using std::unordered_map;

class ProcessManager {
private:
	bool initialized;
	Config config;
	Console mainConsole;
	unordered_map<string, Console> consoles;

public:
	ProcessManager();

	void start();

private:
	void spawnConsole(const string name);
};
