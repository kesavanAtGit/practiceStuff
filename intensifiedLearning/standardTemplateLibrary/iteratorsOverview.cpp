#include <iostream>
#include <memory>
#include <list>
#include <vector>
#include <set>
#include <map>

int main () {
    // this is iterating through a vector and a list
    //std::list<int> intList{};

    //for(int i{0}; i < 5; ++i) {
    //    intList.push_back(i);
    //}

    //std::list<int>::const_iterator it{};
    //it = intList.cbegin();

    //while(it != intList.cend()) {
    //    std::cout << *it << " ";
    //    ++it;
    //}

    //std::set<int> intSet{};
    //intSet.insert(-10);
    //intSet.insert(0);
    //intSet.insert(1);
    //intSet.insert(-1);
    //intSet.insert(-1); // we can see that it disallows duplicated elements pretty dope
    //intSet.insert(4);
    //intSet.insert(2);

    //std::set<int>::const_iterator setIterator{};
    //setIterator = intSet.cbegin();

    //while(setIterator != intSet.cend()) {
    //    std::cout << *setIterator << " ";
    //    ++setIterator;
    //}

    std::map<int, std::string> myMap{};
    myMap.insert(std::make_pair(5, "priya"));
    myMap.insert(std::make_pair(4, "kesavan"));
    myMap.insert(std::make_pair(3, "monisha"));
    myMap.insert(std::make_pair(2, "palanivel"));
    myMap.insert(std::make_pair(1, "jayamani"));

    auto it{myMap.cbegin()};
    while (it != myMap.cend()) {
        std::cout << it->first << "=" << it->second << '\n';
        ++it;
    }
    return 0;
}
