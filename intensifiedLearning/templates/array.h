#ifndef ARRAY_H
#define ARRAY_H

#include<cassert>

template <typename T>
class Array {
private:
    int m_length{};
    T* m_data{};

public:
    Array(int length) {
        assert(length > 0 && "length me daddy");
        m_length = length;
        m_data = new T[m_length];
    }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    ~Array() {
        delete[] m_data;
    }

    T& operator[](int index) {
        return m_data[index];
    }

    int getLength() const;
};
//#include "array.inl"
#endif // !ARRAY_H

