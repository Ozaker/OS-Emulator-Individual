#include "ProcessManager.h"


const static string green = "\033[32m", yellow = "\033[93m", white = "\033[0m";
const static string mainHeader =
	string("   _____  _____  ____  _____  ______  _______     __\n") +
	"  / ____|/ ____|/ __ \\|  __ \\|  ____|/ ____\\ \\   / /\n" +
	" | |    | (___ | |  | | |__) | |__  | (___  \\ \\_/ / \n" +
	" | |     \\___ \\| |  | |  ___/|  __|  \\___ \\  \\   /  \n" +
	" | |____ ____) | |__| | |    | |____ ____) |  | |   \n" +
	"  \\_____|_____/ \\____/|_|    |______|_____/   |_|\n" +
	green + "Hello, Welcome to CSOPESY commandline!" + white + '\n' +
	yellow + "Type 'exit' to quit, 'clear' to clear the screen" + white + '\n';


ProcessManager::ProcessManager() 
	: initialized(false), mainConsole("main_process", mainHeader, "Enter a command: ") {}


void ProcessManager::start() {
	string input;
	string consoleName;
	vector<string> command;

	Console* curConsole = &this->mainConsole;
	bool mainInControl = true;

	curConsole->show();
	while (true) {
		curConsole->takeInput(input);

		command = Utils::parseCommand(input);

		if (mainInControl) {
			if (command[0] == "clear") {
				curConsole->content = curConsole->header;
				curConsole->show();
			}
			else if (command[0] == "exit") {
				return;
			}
			else if (command[0] == "initialize") {
				if (!this->initialized) {
					this->config.loadFromFile("config.txt");
				}
				cout << command[0] + " command recognized. Doing something.\n";
			}
			else if (command[0] == "screen") {
				cout << command[0] + " command recognized. Doing something.\n";
			}
			else if (command[0] == "scheduler-test" || command[0] == "scheduler-stop" || command[0] == "report-util") {
				cout << command[0] + " command recognized. Doing something.\n";
			}
			else {
				curConsole->print(command[0] + " command does not exist.\n");
			}
		}
		else {
			if (command[0] == "process-smi") {
				curConsole->print("Placeholder.\n");
			}
			else if (command[0] == "exit") {
				curConsole = &this->mainConsole;
				mainInControl = false;
				curConsole->show();
			}
			else {
				curConsole->print(command[0] + " command does not exist.\n");
			}
		}
	}
}


void ProcessManager::spawnConsole(const string name) {
	string curDateTime = Utils::getCurDateTimeAsString();
	this->consoles.insert(
		{ name, Console(
			name,
			"Process: " + name + '\n' + "Current instruction line : 0\n" + "Screen created at " + curDateTime + '\n',
			"root:\\> ")
		}
	);
}