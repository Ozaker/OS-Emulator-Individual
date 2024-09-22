#pragma once
#include "Console.h"


class MainConsole : public Console {
public:
	MainConsole();

private:
	void executeCommand(const vector<string> command, ConsoleManager* manager) override;
	void executeScreenCommand(const vector<string> command, ConsoleManager* manager);
};

