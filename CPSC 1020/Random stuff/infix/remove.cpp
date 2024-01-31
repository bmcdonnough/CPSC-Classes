#include <iostream>
#include <string>
#include <regex>

int main(int argc, char* argv[]) {
    // Define regex pattern to match line numbers and period at the end
    std::regex pattern(R"(\d+\.\s)");

    // Read from stdin (file redirect)
    std::string line;
    while (std::getline(std::cin, line)) {
        // Remove line number and period at the end using regex
        std::string modified_line = std::regex_replace(line, pattern, "");
        
        // Output the modified line to stdout
        std::cout << modified_line << std::endl;
    }

    return 0;
}
