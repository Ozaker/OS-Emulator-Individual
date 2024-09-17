#pragma once
#include <string>
#include <iostream>
#include <fstream>

using std::string;

struct Config {
	int numCpu;
	std::string scheduler;
	int quantumCycles;
	int batchProcessFreq;
	int minIns;
	int maxIns;
	int delayPerExec;

	Config();
	
	static string getSettingValue(std::ifstream& file);
	void log();
};