#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ASCII =
    string("   _____  _____  ____  _____  ______  _______     __\n")
    .append("  / ____|/ ____|/ __ \\|  __ \\|  ____|/ ____\\ \\   / /\n")
    .append(" | |    | (___ | |  | | |__) | |__  | (___  \\ \\_/ / \n")
    .append(" | |     \\___ \\| |  | |  ___/|  __|  \\___ \\  \\   /  \n")
    .append(" | |____ ____) | |__| | |    | |____ ____) |  | |   \n")
    .append("  \\_____|_____/ \\____/|_|    |______|_____/   |_|   \n");

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
        cout << "~!: ";
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
        return false;
    }
    else {
        cout << input + " command recognized. Doing something.\n";
    }

    return false;
}

int main() {
    cout << ASCII + '\n';

    bool stop = false;
    while (!stop) {
        string input = takeUserInput();
        stop = executeCommand(input);
    }

    return 0;
}