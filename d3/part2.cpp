#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

int main(void) {

    std::ifstream inputFile("input.txt");
    std::string line((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

    long result = 0;

    std::regex multiplyInstruction("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    std::regex branchInstruction("(?:(do)|(don't))\\(\\)");

    auto multiplyBegin = std::sregex_iterator(line.begin(), line.end(), multiplyInstruction);
    auto branchesBegin = std::sregex_iterator(line.begin(), line.end(), branchInstruction);

    std::vector<std::pair<int, bool>> branches;
    branches.push_back({0, true});

    for (std::sregex_iterator i = branchesBegin; i != std::sregex_iterator(); i++) {

        /* "do()" has a length of 4 while don't() has a length of 7 */
        /* this is a quick and dirty way to check if the match was a do or don't */
        bool enabled = (*i).length() < 5;

        if (enabled != branches.back().second) {
            branches.push_back({
                (*i).position(),
                enabled
            });
        }

    }

    int lastMatch = 0;

    for (std::sregex_iterator i = multiplyBegin; i != std::sregex_iterator(); i++) {

        int matchPosition = (*i).position();

        while (lastMatch + 1 < branches.size()) {
            if (branches[lastMatch + 1].first < matchPosition) lastMatch++;
            else break;
        }

        if (branches[lastMatch].second) {
            long a = std::stoi((*i)[1]);
            long b = std::stoi((*i)[2]);

            result += a * b;
        }

    }

    std::cout << result << '\n';
}