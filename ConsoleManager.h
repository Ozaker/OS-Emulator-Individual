#pragma once
#include <unordered_map>
#include "Config.h"
#include "globals.h"
#include "utils.h"
#include "Console.h"


using std::unordered_map, std::pair, std::make_pair, std::shared_ptr, std::make_shared;

class ConsoleManager {
	friend class MainConsole;
	friend class ProcessConsole;

private:
	bool initialized;
	Config* config;

	bool running;
	unordered_map<string, shared_ptr<Console>> consoles;
	shared_ptr<Console> attachedConsole;

public:
	ConsoleManager(Config* config);
	void start();

private:
	void switchScreen(const string name);
	void addProcessConsole(const string name);
};
