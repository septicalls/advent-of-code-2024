#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

    freopen("input.txt", "r", stdin);

    std::vector<int> list1(1000), list2(1000);
    for (int i = 0; i < 1000; i++) {
        std::cin >> list1[i] >> list2[i];
    }

    int similarity = 0;

    std::sort(list2.begin(), list2.end());

    for (int i = 0; i < 1000; i++) {
        const int occurences = std::count(list2.begin(), list2.end(), list1[i]);
        if (occurences) {
            similarity += occurences * list1[i];
        }
    }

    std::cout << similarity << '\n';

}