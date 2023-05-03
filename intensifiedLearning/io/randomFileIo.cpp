#include <fstream>
#include <iostream>
#include <string>

int main() {

    std::fstream file{"Sample.txt", std::ios::out};
    file << "This is a line \n";
    file.close();

    std::fstream iofile{ "Sample.txt", std::ios::in | std::ios::out };

    if (!iofile) {
        std::cerr << "Uh oh, Sample.txt could not be opened!\n";
        return 1;
    }

    char chChar{};

    while (iofile.get(chChar)) {
        switch (chChar) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':

                iofile.seekg(-1, std::ios::cur);
                iofile << '#';
                iofile.seekg(iofile.tellg(), std::ios::beg);
                break;
        }
    }
    return 0;
}
