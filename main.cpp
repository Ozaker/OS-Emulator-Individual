#include <iostream>
#include <string>
#include <vector>
#include "Config.h"
#include "ConsoleManager.h"


int main() {
    Config config;
    ConsoleManager pm(&config);
    pm.start();
}
