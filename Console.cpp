#include "Console.h"
#include "utils.h"


Console::Console(const string name, const string header, const string prompt)
	: creationDateTimeAsString(Utils::getCurDateTimeAsString()), name(name), header(header), prompt(prompt), content(header) {}


void Console::takeInput(string& buffer) {
	cout << this->prompt;
	getline(cin, buffer);
	this->content.append(this->prompt + buffer + '\n');
}


void Console::show() {	
	system("CLS");
	cout << this->content;
}


void Console::print(const string str) {
	cout << str;
	this->content.append(str);
}


void Console::clear() {
	this->content = this->header;
	show();
}