#include <iostream>

class IErrorLog {

public:
    virtual bool openLog(std::string log) const = 0;
    virtual bool closeLog(std::string log) const = 0;
    virtual void writeError(std::string error) const = 0;

    virtual ~IErrorLog() = default;
};

class FileLogError: public IErrorLog {

public:
    bool openLog(std::string log) const{
        std::cout << "opening log \n";
        return true;
    }

    bool closeLog(std::string log) const{
        std::cout << "closing log \n";
        return true;
    }

    void writeError(std::string error) const {
        std::cout << error << '\n';
    }
};

int main() {
    return 0;
}
