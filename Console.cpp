#include "utils.h"
#include "globals.h"
#include "Console.h"


Console::Console(const string name, const string header, const string prompt)
	: creationDateTimeAsString(Utils::getCurDateTimeAsString()), name(name), header(header), prompt(prompt), content(header) {}


void Console::takeInput(string& buffer) {
	cout << this->prompt;
	getline(cin, buffer);
	this->content.append(this->prompt + buffer + '\n');
}


void Console::onAttach() {	
	system("cls");
	cout << this->content;
}


void Console::print(const string str) {
	cout << str;
	this->content.append(str);
}


void Console::warnInvalidCommand(string command) {
	print(command + " command does not exist.\n");
}