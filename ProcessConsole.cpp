#include "ProcessConsole.h"
#include "ConsoleManager.h"


ProcessConsole::ProcessConsole(string name) 
	: Console(
		name,
		"Process: " + name + '\n' + "Current instruction line : 0\n" + "Screen created at " + Utils::getCurDateTimeAsString() + '\n',
		"root:\\> "
	) {}


void ProcessConsole::executeCommand(const vector<string> command, ConsoleManager* manager) {
	if (command[0] == "process-smi") {
		print("Placeholder.\n");
	}
	else if (command[0] == "exit") {
		manager->switchScreen(MAIN_CONSOLE_NAME);
	}
	else if (!command[0].empty()) {
		warnInvalidCommand(command[0]);
	}
}