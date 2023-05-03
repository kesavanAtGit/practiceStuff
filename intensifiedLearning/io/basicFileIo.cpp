#include <iostream>
#include <fstream>

// io me daddy

int main() {
    std::ofstream out{"out.txt"};
    out << "daddy is called father \n";
    out << "mommy is called mother \n";

    out.close();

    ///std::ifstream in{"out.txt"};

    ///if(!in) {
    ///    std::cerr << "oops! can't read from the file.\n";
    ///    return 1;
    ///}

    ///while(in) {
    ///    std::string strValue{};
    ///    std::getline(in, strValue);
    ///    std::cout << strValue << '\n';
    ///}
    ///in.close();

    out.open("out.txt", std::ios::app);
    out << "sissy is called sister \n";
    out.close();

    return 0;
}
