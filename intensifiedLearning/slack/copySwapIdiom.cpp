#include <iostream>
#include <cstddef>
#include <type_traits>

// let's learn a better way to handle self assignment bad thingy
class array_daddy {
private:
    std::size_t m_size{};
    int* m_array{};

public:
    // default constructor
    array_daddy(std::size_t size):
        m_size{size},
        m_array{(m_size? new int[m_size]: nullptr)} {}

    // copy constructor
    array_daddy(const array_daddy& daddyArray):
        m_size{daddyArray.m_size},
        m_array{(m_size? new int[m_size]: nullptr)} {
            std::cout << "I am a copy constructor baby! \n";
        }

    friend void swap(array_daddy& daddyArrayOne, array_daddy& daddyArrayTwo) {
        // can't swap a const function you bakayaro
        std::swap(daddyArrayOne.m_size, daddyArrayTwo.m_size);
        std::swap(daddyArrayOne.m_array, daddyArrayTwo.m_array);
    }

    // ne need for self-checking
    // handles exception guarantee
    // no code duplication
    array_daddy& operator= (const array_daddy& daddyArray) {
        array_daddy temp{daddyArray};
        swap(*this, temp);
        return *this;
    }

    // destruct the array daddy
    ~array_daddy() {
        delete[] m_array;
    }

    friend std::ostream& operator<<(std::ostream& out, const array_daddy& daddyArray) {
        std::cout << daddyArray.m_size;
        return out;
    }
};

int main() {
    array_daddy arrayMeDaddy{4};
    array_daddy someOtherArray = arrayMeDaddy;
    return 0;
}
