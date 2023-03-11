#include <iostream>
#include <cstdint>
#include <cassert>
#include <algorithm>

class Average
{
private:
    std::int32_t m_sum{};
    std::int8_t m_num{};

public:
    Average& operator+= (int value) {
        m_sum += value;
        ++m_num;
        return *this;
    }

    friend std::ostream& operator<< (std::ostream& out, const Average& average) {
        std::cout << static_cast<double>(average.m_sum) / average.m_num;
        return out;
    }
};

class IntArray
{
private:
    int m_size{};
    int* m_array{};

public:
    IntArray(int length): m_size{length} {
        assert(length > 0 && "length me daddy");
        m_array = (m_size? new int[m_size]: nullptr);
    }

    IntArray(const IntArray& array): m_size{array.m_size} {
        m_array = (m_size? new int[m_size]: nullptr);

        for(int i{0}; i < m_size; ++i) {
            m_array[i] = array.m_array[i];
        }
    }

    ~IntArray() {
        delete[] m_array;
    }

    int& operator[] (const int index) {
        assert( index >= 0 && "oh no" );
        assert( index < m_size && "oh no again" );
        return m_array[index];
    }

    IntArray& operator= (IntArray& array) {
        if(this == &array)
            return *this;

        delete[] m_array;
        m_size = array.m_size;
        m_array = (m_size? new int[m_size]: nullptr);

        for(int i{0}; i < m_size; ++i) {
            m_array[i] = array.m_array[i];
        }
        return *this;
    }

    friend std::ostream& operator<< (std::ostream& out, const IntArray& array) {
        for(int i{0}; i < array.m_size; i++) {
            std::cout << array.m_array[i] << " ";
        }
        return out;
    }
};

IntArray fillArray() {
    IntArray a{4};
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    a[3] = 40;
    return a;
}

int main() {
    IntArray arr{fillArray()};
    std::cout << arr << "\n";

    IntArray& ref{arr};
    arr = ref;
    // doing this to avoid the self-assignment errors
    IntArray anotherArr{1};
    anotherArr = arr;
    std::cout << anotherArr << "\n";

    return 0;
}
