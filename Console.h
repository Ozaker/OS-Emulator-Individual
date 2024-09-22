#pragma once
#include <iostream>
#include <string>
#include <vector>


using std::string, std::cout, std::cin, std::vector;

class ConsoleManager; // forward declaration to avoid circular dependency

class Console {
protected:
	const string creationDateTimeAsString;
	const string name;
	const string header;
	const string prompt;
	string content;

public:
	Console(const string name, const string header, const string prompt);
	void onAttach();
	void takeInput(string& buffer);		// takes user input and stores it in buffer then updates content accordingly
	void print(const string str);		// prints to stdout while updating content
	virtual void executeCommand(const vector<string> command, ConsoleManager* manager) = 0;
	void warnInvalidCommand(string command);
};