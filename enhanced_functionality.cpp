// enhanced_functionality.cpp

#include <iostream>
#include <cstdlib> // For system()
#include <cstring> // For strcmp
#include <string>

void printMessage(const std::string& message) {
    std::cout << "Message: " << message << std::endl;
}

void runCommand(const std::string& command) {
    // CWE-78: Improper Neutralization of Special Elements used in an OS Command ('OS Command Injection')
    // This allows an attacker to execute arbitrary commands on the host system
    system(command.c_str());
}

void handleUserInput(const std::string& input) {
    if (input == "hello") {
        printMessage("Hello, user!");
    } else if (input == "date") {
        // This allows an attacker to execute arbitrary commands on the host system
        runCommand("date");
    } else if (input.substr(0, 4) == "run ") {
        // This allows an attacker to execute arbitrary commands on the host system
        runCommand(input.substr(4));
    } else {
        printMessage("Unknown command: " + input);
    }
}

int main() {
    std::string input;
    while (true) {
        std::cout << "Enter a command (type 'exit' to quit): ";
        std::getline(std::cin, input);
        if (input == "exit") {
            break;
        }
        handleUserInput(input);
    }
    return 0;
}
