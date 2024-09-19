#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::string, std::cout, std::cin, std::vector;

class Console {
public:
	const string creationDateTimeAsString;
	const string name;
	const string header;
	const string prompt;
	string content;

	Console(const string name, const string header, const string prompt);
		
	void show(); // clears screen and displays the screen state from when the screen was last attached
	void takeInput(string& buffer); // takes user input and stores in buffer then updates content accordingly
	void print(string str); // prints to stdout while updating content
};