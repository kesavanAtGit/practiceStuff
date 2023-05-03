#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>

int main () {

    //std::list<int> list(10);
    //std::iota(list.begin(), list.end(), 0);
    //std::cout << *std::min_element(list.begin(), list.end()) << " "  << *std::max_element(list.begin(), list.end());

    //auto it{std::find(list.begin(), list.end(), 5)};

    //list.insert(it, 55);
    //for (int i : list) {
    //    std::cout << i << " ";
    //}

    std::vector<int> intVec{-12, 34, 3, -1, 21};
    std::sort(intVec.begin(), intVec.end(), std::greater<>{});

    for (int i : intVec) {
        std::cout << i << " ";
    }
    std::cout << '\n';

    //std::reverse(intVec.begin(), intVec.end());
    //for (int i : intVec) {
    //    std::cout << i << " ";
    //}
    return 0;
}
