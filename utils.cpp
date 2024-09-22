#include <regex>
#include <ctime>
#include "utils.h"
#include "globals.h"


string Utils::getCurDateTimeAsString() {
	char buffer[24];
	time_t creationDateTime;
	time(&creationDateTime);

	tm dateTimeStruct;
	localtime_s(&dateTimeStruct, &creationDateTime);
	strftime(buffer, 24, "%m/%d/%Y, %I:%M:%S %p", &dateTimeStruct);
	return buffer;
}


vector<string> Utils::parseCommand(const string input) {
	// remove trailing, leading, extra spaces from input
	string inputNoExtraSpaces = std::regex_replace(input, std::regex("^ +| +$|( ) +"), "$1");

	vector<string> temp;
	temp.reserve(MAX_COMMAND_LENGTH);

	// split input by space 
	int idxPrevSpace = -1, i = 0;
	for (; i <= inputNoExtraSpaces.length(); i++) {
		if (inputNoExtraSpaces[i] == ' ' || i == inputNoExtraSpaces.length()) {
			temp.push_back(inputNoExtraSpaces.substr(idxPrevSpace + 1, i - idxPrevSpace - 1));
			idxPrevSpace = i;
		}
	}

	while (temp.size() < MAX_COMMAND_LENGTH) {
		temp.push_back("");
	}
	return temp;
}