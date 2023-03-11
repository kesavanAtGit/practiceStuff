#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <cassert>

class Stack
{
    // create an array and keep track of its length
    std::array<int, 10> m_stackArray{};
    int m_stackSize{static_cast<int>(m_stackArray.size())};

    // this is to iterate through the array and push and pop values
    // pretty useful
    int m_index{0};

public:
    void reset()
    {
        m_stackSize = 0;
    }

    bool push(int pushValue)
    {
        // don't index 10 in the array stupid
        if(m_index == m_stackSize)
            return false;

        m_stackArray[m_index] = pushValue;
        ++m_index;

        // returns false if the array is already full
        return (!m_stackArray[m_stackSize - 1]);
    }

    int pop()
    {
        // popping off the last element in the array
        assert(m_index > 0 && "Empty me daddy");

        return m_stackArray[--m_index];
    }

    void printStack()
    {
        std::cout << "( ";
        for(int i{0}; i < m_index; ++i)
        {
            std::cout << m_stackArray[i] << " ";
        }
        std::cout << ")";
    }
};

int main()
{
    Stack stack{};
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    stack.push(80);
    stack.push(90);
    stack.push(100);

    stack.pop();
    stack.printStack();
    return 0;
}
