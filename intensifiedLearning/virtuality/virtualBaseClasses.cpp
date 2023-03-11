#include <iostream>

class PoweredDevice {
private:
    int m_power{};

public:
    PoweredDevice(int power)
        :m_power{power} {
            std::cout << "PoweredDevice " << power << '\n';
        }
};

class Scanner: public virtual PoweredDevice {
public:
    Scanner(int scanner, int power)
        :PoweredDevice(power) {
            std::cout << "Scanner : " << scanner << '\n';
        }
};

class Printer: public virtual PoweredDevice {
public:
    Printer(int printer, int power)
        :PoweredDevice(power) {
            std::cout << "Scanner : " << printer << '\n';
        }
};

class Copier: public Scanner, public Printer {
public:
    Copier(int scanner, int printer, int power)
        :Scanner{scanner, power},
         Printer{printer, power},
         // gets constructed only once
         PoweredDevice{power} {}
};

int main() {
    Copier copier{12, 14, 16};
    return 0;
}
