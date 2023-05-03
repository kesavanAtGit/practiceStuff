#include <iostream>

// overloading the operators and function templates
class Score
{
private:
    int m_score{};

public:
    Score(int score): m_score{score} {}

    Score& operator+= (const Score& score) {
        m_score += score.m_score;
        return *this;
    }

    Score& operator/= (int x) {
        m_score /= x;
        return *this;
    }

    friend bool operator< (const Score& x, const Score& y) {
        return ( x.m_score < y.m_score );
    }

    friend bool operator> (const Score& x, const Score& y) {
        return ( x.m_score > y.m_score );
    }

    friend std::ostream& operator<< (std::ostream& out, const Score& score) {
        std::cout << score.m_score;
        return out;
    }
};

template <typename T>
const T& max(const T& x, const T& y) {
    return ( x < y )? y : x;
}

template <typename T>
T average(const T* x, int number) {
    T sum{0};
    for(int i{0}; i < number; ++i) {
        sum += x[i];
    }
    sum /= number;
    return sum;
}

int main() {
    Score score[] {Score{10}, Score{20}, Score{3}};
    std::cout << average(score, 3);

    return 0;
}
