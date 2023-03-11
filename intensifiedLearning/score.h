#include <iostream>

#ifndef SCORE_H
#define SCORE_H

class Score
{
private:
    int m_score{};
    int m_anotherScore{};

public:
    Score(int score): m_score{score} {}
    int getScore() const{return m_score;}
    Score operator+(int value);

    friend void printScore(const Score& s);
    friend std::ostream& operator<< (std::ostream& out, const Score& score);
    friend std::istream& operator>> (std::istream& in, Score& score);
};

#endif
