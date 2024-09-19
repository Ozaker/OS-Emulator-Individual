#include "utils.h"


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
	string inputNoExtraSpaces = regex_replace(input, regex("^ +| +$|( ) +"), "$1");

	const unsigned int maxInputArgs = 3;
	vector<string> temp;
	temp.reserve(maxInputArgs);

	// split input by space 
	int idxPrevSpace = -1, i = 0;
	for (; i <= inputNoExtraSpaces.length(); i++) {
		if (inputNoExtraSpaces[i] == ' ' || i == inputNoExtraSpaces.length()) {
			temp.push_back(inputNoExtraSpaces.substr(idxPrevSpace + 1, i - idxPrevSpace - 1));
			idxPrevSpace = i;
		}
	}

	while (temp.size() < maxInputArgs) {
		temp.push_back("");
	}
	return temp;
}