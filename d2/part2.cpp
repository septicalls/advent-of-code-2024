#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

bool isSafe(std::vector<int> levels) {

    int invalid = 0;

    /* Decreasing (possibly) */
    if (levels.front() > levels.back()) {

        for (int j = 1; j < levels.size(); j++) {

            if (levels[j] >= levels[j - 1]
            || levels[j] < (levels[j - 1] - 3)) invalid++;
        }

    /* Increasing (possibly) */
    } else if (levels.front() < levels.back()) {

        for (int j = 1; j < levels.size(); j++) {

            if (levels[j] <= levels[j - 1]
            || levels[j] > (levels[j - 1] + 3)) invalid++;
        }

    /* Else front() == back() which is unsafe */
    } else return false;

    return invalid == 0;

}

int main(void) {

    std::ifstream inputFile("input.txt");
    std::vector<int> levels;
    std::string line;

    int safe = 0;

    while (std::getline(inputFile, line)) {

        int l = 0;
        levels.clear();

        std::istringstream iss(line);

        while (iss >> l) {
            levels.push_back(l);
        }

        if (levels.size() > 3) {
            int valid = 0;

            for (int i = 0; i < levels.size(); i++) {
                std::vector<int> updatedLevels;

                for (int j = 0; j < levels.size(); j++) {
                    if (j != i) updatedLevels.push_back(levels[j]);
                }

                if (isSafe(updatedLevels)) valid++;
            }

            if (valid) safe++;

        }

    }

    std::cout << safe << '\n';

}