#include <iostream>
#include <cstdint>

template <typename T>
class Storage8 {
private:
    T m_value[8];

public:
    void set(int index, const T& value) {
        m_value[index] = value;
    }

    const T& get(int index) {
        return m_value[index];
    }
};

template<>
class Storage8<bool> {

private:
    std::uint8_t m_value{};

public:
    void set(int index, bool value) {
        auto mask{ 1 << index };
        if(value)
            m_value |= mask;
        else
            m_value &= ~mask;
    }

    bool get(int index) {
        auto mask{ 1 << index };
        return (m_value & mask);
    }
};

int main() {

    Storage8<int> intStorage{};
    for(int i{0}; i < 8; ++i) {
        intStorage.set(i, i);
    }

    for(int i{0}; i < 8; ++i) {
        std::cout << intStorage.get(i) << '\n';
    }

    Storage8<bool> boolStorage{};
    std::cout << std::boolalpha;

    for(int i{0}; i < 8; ++i) {
        boolStorage.set(i, i);
    }

    for(int i{0}; i < 8; ++i) {
        std::cout << boolStorage.get(i) << '\n';
    }

    return 0;
}
