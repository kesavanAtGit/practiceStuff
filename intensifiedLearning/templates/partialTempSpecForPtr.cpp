#include <iostream>
#include <cstring>

template <typename T>
class Storage {
private:
    T m_value{};

public:
    Storage(T value)
        :m_value{value} {}

    void print() {
        std::cout << m_value;
    }

    ~Storage() {};
};

// partial specialization for pointer types for our storage class
template <typename T>
class Storage<T*> {
private:
    T* m_someValue{};

public:
    Storage(T* value)
        :m_someValue{new T{*value}} {}

    ~Storage() {
        delete m_someValue;
    }

    void print() {
        std::cout << *m_someValue;
    }
};

int main() {
    int x{10};

    Storage<int*> intStorage{&x};
    intStorage.print();
    return 0;
}
