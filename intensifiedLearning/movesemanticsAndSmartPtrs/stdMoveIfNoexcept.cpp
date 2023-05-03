#include <iostream>
#include <utility>
#include <exception>
#include <stdexcept>

// this is going to a pain in the butt
class MoveClass {
private:
    int* m_resource{};

public:
    MoveClass() = default;
    MoveClass(int resource)
        :m_resource{new int{resource}} {}

    // now for the copy constructor
    MoveClass(const MoveClass& moveClass) {
        if(moveClass.m_resource != nullptr) {
            m_resource = new int{*moveClass.m_resource};
        }
    }

    MoveClass(MoveClass&& moveClass)
        :m_resource{moveClass.m_resource} {
            moveClass.m_resource = nullptr;
        }

    ~MoveClass() {
        std::cout << "destroying " << *this << '\n';
        delete m_resource;
    }

    friend std::ostream& operator<<(std::ostream& out, const MoveClass& moveClass) {
        out << "MoveClass(";
        if(moveClass.m_resource == nullptr) {
            std::cout << "moveClass:empty";
        }else {
            std::cout << *moveClass.m_resource;
        }
        std::cout << ")";
        return out;
    }
};

class CopyClass {
public:
    bool m_throw{};
    CopyClass() = default;
    CopyClass(const CopyClass& copyClass)
        :m_throw{copyClass.m_throw} {
            if(m_throw) {
                throw std::runtime_error{"abort"};
            }
        }
};

int main() {
    std::pair myPair{MoveClass{13}, CopyClass{}};
    std::cout << myPair.first << '\n';

    try {
        std::pair movedPair{std::move_if_noexcept(myPair)};
    }catch (std::exception& exception) {
        std::cout << exception.what();
    }
    std::cout << myPair.first << '\n';
    return 0;
}

