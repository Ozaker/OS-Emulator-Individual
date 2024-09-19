#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::string, std::ifstream;

class Config {
public:
	int numCpu;
	string scheduler;
	int quantumCycles;
	int batchProcessFreq;
	int minIns;
	int maxIns;
	int delayPerExec;

	//Config();

	void loadFromFile(string filename); 
	void log(); // for debugging - prints all attributes

private:
	static string getSettingValue(ifstream& file);
};