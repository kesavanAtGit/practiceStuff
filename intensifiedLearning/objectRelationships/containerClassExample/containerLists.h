#ifndef CONTAINER_LISTS
#define CONTAINER_LISTS

#include <cassert>
#include <cstdlib>
#include <initializer_list>

class IntArray
{
public:
    int m_length{};
    int* m_data{};

public:
    IntArray() = default;

    // or could be m_data{new int[m_length]{ in the memberwise initialization list
    IntArray(int length)
        : m_length{length}, m_data{new int[m_length]} {}

    IntArray(std::initializer_list<int> arrayList)
        : IntArray(static_cast<int>(arrayList.size())) {
            int count{0};
            for(auto element: arrayList) {
                m_data[count] = element;
                ++count;
            }
        }

    ~IntArray() {
        delete[] m_data;
    }

    int& operator[] (int index) {
        return m_data[index];
    }

    IntArray(const IntArray&) = delete; // to avoid copy constructing by the compiler
    IntArray& operator= (IntArray& array) = delete; // to avoid shallow copies

    IntArray& operator= (std::initializer_list<int> elementsList) {
        int newLength{static_cast<int>(elementsList.size())};

        if(newLength != m_length) {
            delete[] m_data;
            m_length = newLength;
            m_data = new int[m_length];
        }

        int count{0};
        for(auto element: elementsList) {
            m_data[count] = element;
            ++count;
        }
        return *this;
    }

    void erase() {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int getLength() const{return m_length;}

    // this deletes all the elements and is fast
    void reallocate(int newLength) {
        assert(newLength >= 0 && "new length me daddy");

        erase();
        m_length = newLength;
        m_data = new int[m_length];
    }

    void resize(int newLength) {
        if(m_length == newLength)
            return;

        if(newLength <= 0) {
            erase();
            return;
        }

        int* data{new int[m_length]};

        if(m_length > 0) {
            int elementsToCopy{ ( newLength > m_length? m_length: newLength) };
            for(int i{0}; i < elementsToCopy; ++i) {
                data[i] = m_data[i];
            }
        }
        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }

    void insertElement(int value, int index) {
        assert(index >= 0 && index <= m_length);

        int* data{new int[m_length + 1]};
        for(int i{0}; i < index; ++i) {
            data[i] = m_data[i];
        }

        data[index] = value;
        for(int i{index}; i < m_length; ++i) {
            data[i + 1] = m_data[i];
        }

        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void removeElement(int index) {
        if(m_length == 1) {
            erase();
            return;
        }

        int* data{new int[m_length - 1]};
        for(int i{0}; i < index; ++i) {
            data[i] = m_data[i];
        }

        for(int i{index + 1}; i < m_length; ++i) {
            data[i - 1] = m_data[i];
        }
        delete[] m_data;
        m_data = data;
        --m_length;
    }

    // additional functionality for convenience
    void insertAtBeginning(int value) {insertElement(value, 0);}
    void insertAtEnd(int value) {insertElement(value, m_length);}
};

#endif
