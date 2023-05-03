#include <iostream>
#include <string>

// insert that string into me daddy

int main () {
    std::string game{"cricket"};
    game.erase(4, 3);
    //game.insert(3, "s");

    std::string subString{"buzz"};
    game.insert(4, subString, 0, 4);

    //std::cout << game;

    //void insert(iterator it, size_type num, char c)
    //iterator string::insert(iterator it, char c)
    //void string::insert(iterator it, InputIterator begin, InputIterator end)

    //The first function inserts num instances of the character c before the iterator it.
    //The second inserts a single character c before the iterator it, and returns an iterator to the position of the character inserted.
    //The third inserts all characters between [begin,end) before the iterator it.

    std::string example{};
    example.insert(example.begin(), 4, 'z');
    example.push_back('i');
    std::cout << example << '\n';

    std::string exampleTwo{};
    exampleTwo.insert(exampleTwo.end(), 'a');
    exampleTwo.push_back('y');
    std::cout << exampleTwo << '\n';

    std::string exampleThree{};
    exampleThree.insert(exampleThree.begin(), example.begin(), example.end());
    std::cout << exampleThree << '\n';
    return 0;
}
