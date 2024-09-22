#include "MainConsole.h"
#include "ConsoleManager.h"


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


MainConsole::MainConsole() 
	: Console(MAIN_CONSOLE_NAME, mainHeader, "Enter a command: ") {}


void MainConsole::executeCommand(const vector<string> command, ConsoleManager* manager) {
	if (command[0] == "clear") {
		this->content = this->header;
		onAttach();
	}
	else if (command[0] == "exit") {
		manager->running = false;
	}
	else if (command[0] == "initialize") {
		if (!manager->initialized) {
			manager->config->loadFromFile("config.txt");
		}
		print(command[0] + " command recognized. Doing something.\n");
	}
	else if (command[0] == "screen") {
		executeScreenCommand(command, manager);
	}
	else if (command[0] == "scheduler-test" || command[0] == "scheduler-stop" || command[0] == "report-util") {
		print(command[0] + " command recognized. Doing something.\n");
	}
	else if (!command[0].empty()) {
		warnInvalidCommand(command[0]);
	}
}


void MainConsole::executeScreenCommand(const vector<string> command, ConsoleManager* manager) {
	if (command[1] == "-s") {
		if (command[2].empty()) {
			print("Provide a name.\n");
		}
		else if (manager->consoles.contains(command[2])) {
			print("A screen with the same name already exists. Choose a unique name.\n");
		}
		else {
			manager->addProcessConsole(command[2]);
			manager->switchScreen(command[2]);
		}
	}
	else if (command[1] == "-r") {
		if (!manager->consoles.contains(command[2])) { 
			print("No screen with name " + command[2] + " exists.\n");
		}
		else {
			manager->switchScreen(command[2]);
		}
	}
	else if (command[1] == "-ls") {
		for (const auto& [name, console] : manager->consoles) {
			manager->attachedConsole->print("Process: " + name + '\n');
		}
	}
	else {
		print("Invalid arguments for screen command.\n");
	}
}