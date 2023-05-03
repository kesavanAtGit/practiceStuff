#include <iostream>
#include <chrono>

class Timer {
private:
    using Clock = std::chrono::high_resolution_clock;
    using Second = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<Clock> m_beg{Clock::now()};

public:
    void reset() {
        m_beg = Clock::now();
    }

    double elapsed() const {
        return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }
};

template <typename T>
class DynamicArray {
private:
    int m_length{};
    T* m_array{};

public:
    DynamicArray(int length)
        :m_length{length}, m_array{new T[length]} {}

    ~DynamicArray() {
        delete[] m_array;
    }

    int getLength() const {
        return m_length;
    }

    T& operator[](int index) {return m_array[index];}
    const T& operator[](int index) const {return m_array[index];}

    T& operator*() const {return *m_array;}
    T* operator->() const {return m_array;}

    // move constructor
    DynamicArray(DynamicArray&& array) noexcept
        :m_length{array.m_length}, m_array{array.m_array} {
            array.m_length = 0;
            array.m_array = nullptr;
        }

    DynamicArray& operator=(DynamicArray&& array)noexcept{
        if(&array == this)
            return *this;

        delete[] m_array;
        m_length = array.m_length;
        m_array = array.m_array;

        array.m_length = 0;
        array.m_array = nullptr;
        return *this;
    }
};

DynamicArray<int> cloneAndDouble(const DynamicArray<int>& array) {
    DynamicArray<int> someArray{array.getLength()};
    for(int i{0}; i < someArray.getLength(); ++i) {
        someArray[i] = array[i] * 2;
    }
    return someArray;
}

int main() {
    Timer t;
    DynamicArray<int> array{100};
    for(int i{0}; i < array.getLength(); ++i) {
        array[i] = i;
    }

    array = cloneAndDouble(array);

    for(int i{0}; i < array.getLength(); ++i) {
        std::cout << array[i] << " ";
    }

    std::cout << t.elapsed() << '\n';
    return 0;
}
