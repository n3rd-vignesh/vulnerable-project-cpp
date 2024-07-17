#include <iostream>
#include <cstring>
#include <cstdlib>

void processCommand(const char* command) {
    std::cout << "Executing command: " << command << std::endl;
    system(command); // Vulnerable to command injection
}

int main() {
    const char* command = "echo Hello, world!";
    processCommand(command);
    return 0;
}
