#include <iostream>

// ofcourse, the file name doesn't make sense
template<typename T, int size>
class StaticArray {
private:
    int m_length{size};
    T m_array[size]{};

public:
    T* getArray();

    T& operator[](int index) {
        return m_array[index];
    }
};

template<typename T, int size>
T* StaticArray<T, size>::getArray() {
    return m_array;
}

int main() {
    StaticArray<int, 5> array{};

    for(int i{0}; i < 5; ++i) {
        array[i] = i;
    }

    for(int i{4}; i >= 0; --i) {
        std::cout << array[i] << " ";
    }

    return 0;
}
