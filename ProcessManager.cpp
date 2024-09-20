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
	: initialized(false), mainConsole("main_process", mainHeader, "Enter a command: "), attachedConsole(&this->mainConsole), mainAttached(true) {}


void ProcessManager::start() {
	bool hasExited = false;

	this->attachedConsole->show();
	while (!hasExited) {
		hasExited = mainLoopInner();
	}	
}


bool ProcessManager::mainLoopInner() {
	string input;
	this->attachedConsole->takeInput(input);
	vector<string> command = Utils::parseCommand(input);

	if (this->mainAttached && command[0] == "clear") {
		this->attachedConsole->clear();
	}
	else if (this->mainAttached && command[0] == "exit") {
		return true;
	}
	else if (this->mainAttached && command[0] == "initialize") {
		if (!this->initialized) {
			this->config.loadFromFile("config.txt");
		}
		this->attachedConsole->print(command[0] + " command recognized. Doing something.\n");
	}
	else if (this->mainAttached && command[0] == "screen") {
		executeScreenCommand(command);
	}
	else if (this->mainAttached && command[0] == "scheduler-test" || command[0] == "scheduler-stop" || command[0] == "report-util") {
		this->attachedConsole->print(command[0] + " command recognized. Doing something.\n");
	}
	else if (!this->mainAttached && command[0] == "process-smi" || command[0] == "exit") {
		executeSubscreenCommand(command);
	}
	else if (!command[0].empty()) {
		this->attachedConsole->print(command[0] + " command does not exist.\n");
	}

	return false;
}


void ProcessManager::executeScreenCommand(vector<string> command) {
	if (command[1] == "-s") {
		auto [newConsole, exists] = tryAddConsole(command[2]);
		if (exists) {
			this->attachedConsole->print("A screen with the same name already exists. Choose a unique name.\n");
		}
		else {
			this->attachedConsole = newConsole;
			this->mainAttached = false;
			this->attachedConsole->show();
		}
	}
	else if (command[1] == "-r") {
		auto it = this->consoles.find(command[2]);
		// if does not exist
		if (it == this->consoles.end()) {
			this->attachedConsole->print("No screen with name " + command[2] + " exists.\n");
		}
		else {
			this->attachedConsole = &it->second;
			this->mainAttached = false;
			this->attachedConsole->show();
		}
	}
	else if (command[1] == "-ls") {
		for (const auto& [name, console] : this->consoles) {
			this->attachedConsole->print("Process: " + name + '\n');
		}
	}
	else {
		this->attachedConsole->print("Invalid arguments for screen command.\n");
	}
}


void ProcessManager::executeSubscreenCommand(const vector<string> command) {
	if (command[0] == "process-smi") {
		this->attachedConsole->print("Placeholder.\n");
	}
	else if (command[0] == "exit") {
		this->attachedConsole = &this->mainConsole;
		this->mainAttached = true;
		this->attachedConsole->show();
	}
}


pair<Console*, bool> ProcessManager::tryAddConsole(const string name) {
	string curDateTime = Utils::getCurDateTimeAsString();
	auto[it, succ] = this->consoles.insert(make_pair(name, Console(
		name,
		"Process: " + name + '\n' + "Current instruction line : 0\n" + "Screen created at " + curDateTime + '\n',
		"root:\\> "
	)));
	return make_pair(&it->second, !succ);
}