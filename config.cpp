#include "config.h"

using std::string, std::stoi, std::getline;

Config::Config() {
	string temp;
	
	// open config file
	std::ifstream file("config.txt");
	
	this->numCpu = stoi(getSettingValue(file)); 
	this->scheduler = getSettingValue(file).substr(1, 2);
	this->quantumCycles = stoi(getSettingValue(file));
	this->batchProcessFreq = stoi(getSettingValue(file));
	this->minIns = stoi(getSettingValue(file));
	this->maxIns = stoi(getSettingValue(file));
	this->delayPerExec = stoi(getSettingValue(file));

	file.close();
}

string Config::getSettingValue(std::ifstream& file) {
	string temp;
	getline(file, temp);

	int i = 0;
	while (temp[i] != ' ') {
		i++;
	}

	return temp.substr(i + 1, temp.size() - i - 1);
}

void Config::log() {
	std::cout
		<< "num-cpu " << this->numCpu << '\n'
		<< "scheduler " << this->scheduler << '\n'
		<< "quantum-cycles " << this->quantumCycles << '\n'
		<< "batch-process-freq " << this->batchProcessFreq << '\n'
		<< "min-ins " << this->minIns << '\n'
		<< "max-ins " << this->maxIns << '\n'
		<< "delay-per-exec " << this->delayPerExec << '\n';
}