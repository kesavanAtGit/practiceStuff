#include <iostream>
#include <cstring>

template <typename T, int size>
class Static_BaseClass {
protected:
    T m_array[size]{};

public:
    T* returnArray() {
        return m_array;
    }

    T& operator[](int index) {
        return m_array[index];
    }

    void print() {
        for (int i{0}; i < size; ++i) {
            std::cout << m_array[i] << " ";
        }
    }
};

template <typename T, int size>
class StaticArray: public Static_BaseClass<T, size> {
};

template <int size>
class StaticArray<double, size> : public Static_BaseClass<double, size> {
public:
    void print() {
        for (int i{0}; i < size; ++i) {
            std::cout << std::scientific << this -> m_array[i] << " ";
        }
    }
};

int main() {
    StaticArray<double, 2> doubleArray{};
    doubleArray[0] = 1.2;
    doubleArray[1] = 2.2;

    doubleArray.print();
    return 0;
}
