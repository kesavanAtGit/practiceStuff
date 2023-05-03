#include <iostream>
#include <vector>
#include <deque>

// Container classes fall into three categories
// Sequence containers
// Associative containers
// Container adapters

// ------------------------------------------------------------------

// Sequence containers
// array, vector, deque, list, forward_list, basic_string

// ------------------------------------------------------------------

// Associative containers
// set - stores unique elements, disallows duplicate elements, sorts them according to the values
// multiset - allows duplicate elements
// map - each element is a key/value pair. key is used for sorting and indexing and the value is the actual data
// multimap - allows duplicate keys, keys are sorted in ascending order

// ------------------------------------------------------------------

// Container adapters
// stack - uses deque by default
// queue - uses deque
// priority queue - a type of queue where elements are sorted when pushed and popping off the first elements
// returns the highest priority item

// ------------------------------------------------------------------

int main() {

    // vec me daddy
    std::vector<int> intVect{};
    // deque me daddy
    std::deque<int> intDeque{};

    for(int i=0; i < 5; ++i) {
        intDeque.push_back(i);
        intDeque.push_front(10 - i);
    }

    for(int i{0}; i < 10; ++i) {
        std::cout << intDeque[i] << " ";
    }
    return 0;
}
