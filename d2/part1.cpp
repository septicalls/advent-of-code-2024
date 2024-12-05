#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

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
        } else continue;

        if (!invalid) safe++;
    }

    std::cout << safe << '\n';

}