#include "ConsoleManager.h"
#include "MainConsole.h"
#include "ProcessConsole.h"


ConsoleManager::ConsoleManager(Config* config) 
	: initialized(false), config(config), running(false) {
	this->consoles.insert(make_pair(MAIN_CONSOLE_NAME, make_shared<MainConsole>()));
	this->attachedConsole = this->consoles.at(MAIN_CONSOLE_NAME);
}


void ConsoleManager::start() {
	this->running = true;
	this->attachedConsole->onAttach();
	while (this->running) {
		string input;
		this->attachedConsole->takeInput(input);
		vector<string> command = Utils::parseCommand(input);

		this->attachedConsole->executeCommand(command, this);
	}
}


void ConsoleManager::switchScreen(const string name) {
	this->attachedConsole = this->consoles.at(name);
	this->attachedConsole->onAttach();
}


void ConsoleManager::addProcessConsole(const string name) {
	this->consoles.insert(make_pair(name, make_shared<ProcessConsole>(name)));
}