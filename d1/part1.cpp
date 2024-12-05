#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

    freopen("input.txt", "r", stdin);

    std::vector<int> list1(1000), list2(1000);
    for (int i = 0; i < 1000; i++) {
        std::cin >> list1[i] >> list2[i];
    }

    int difference = 0;

    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    for (int i = 0; i < 1000; i++) {
        difference += std::abs(list1[i] - list2[i]);
    }

    std::cout << difference << '\n';

}