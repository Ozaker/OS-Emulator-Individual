#pragma once
#include "Console.h"
#include "utils.h"


class ProcessConsole : public Console {
public: 
	ProcessConsole(string name);

private:
	void executeCommand(const vector<string> command, ConsoleManager* manager) override;
};

