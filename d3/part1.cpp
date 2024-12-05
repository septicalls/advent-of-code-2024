#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main(void) {

    std::ifstream inputFile("input.txt");
    std::string line((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    std::regex multiplyInstruction("mul\\((\\d{1,3}),(\\d{1,3})\\)");

    auto matchesBegin = std::sregex_iterator(line.begin(), line.end(), multiplyInstruction);

    int result = 0;

    for (std::sregex_iterator i = matchesBegin; i != std::sregex_iterator(); i++) {
        int a = std::stoi((*i)[1]);
        int b = std::stoi((*i)[2]);

        result += a * b;
    }

    std::cout << result << '\n';

}