#include <iostream>
#include <string>
#include <vector>
#include "config.h"

using std::string, std::vector, std::cout, std::cin;

string ASCII =
    "   _____  _____  ____  _____  ______  _______     __\n"
    "  / ____|/ ____|/ __ \\|  __ \\|  ____|/ ____\\ \\   / /\n"
    " | |    | (___ | |  | | |__) | |__  | (___  \\ \\_/ / \n"
    " | |     \\___ \\| |  | |  ___/|  __|  \\___ \\  \\   /  \n"
    " | |____ ____) | |__| | |    | |____ ____) |  | |   \n"
    "  \\_____|_____/ \\____/|_|    |______|_____/   |_|   ";

string header = ASCII + '\n' + "\033[32mHello, Welcome to CSOPESY commandline!\033[0m" + '\n' + "\033[93mType 'exit' to quit, 'clear' to clear the screen\033[0m" + '\n';

vector<string> validCommands = vector<string>({
    "initialize",
    "screen",
    "scheduler-test", 
    "scheduler-stop", 
    "report-util", 
    "clear", 
    "exit"
});

string takeUserInput() {
    string input;
    while (true) {
        cout << "Enter a command: ";
        cin >> input;

        // check if valid comands contains input
        if (find(validCommands.begin(), validCommands.end(), input) != validCommands.end()) { 
            return input;
        }
        cout << input + " command does not exist.\n";
    }
}

bool executeCommand(string input) {
    if (input == "exit") {
        return true;
    } 
    else if (input == "clear") {
        system("CLS");
        cout << header;
        return false;
    }
    else {
        cout << input + " command recognized. Doing something.\n";
    }

    return false;
}

void run() {
    cout << header;

    bool stop = false;
    while (!stop) {
        string input = takeUserInput();
        stop = executeCommand(input);
    }
}

int main() {
    Config configs;

    run();    
}
