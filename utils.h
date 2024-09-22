#pragma once
#include <string>
#include <vector>

using std::string, std::vector;

namespace Utils {
	string getCurDateTimeAsString();

	// splits a string containing a user command and its arguments into an array of strings
	vector<string> parseCommand(const string input);
}
