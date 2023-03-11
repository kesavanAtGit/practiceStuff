#include <iostream>
#include "score.h"

Score Score::operator+(int value) {
    return Score{ m_score + value };
}

std::ostream& operator<< (std::ostream& out, const Score& score) {
    out << score.m_score;
    return out;
}

std::istream& operator>> (std::istream& in, Score& score) {
    in >> score.m_score ;
    return in;
}

void printScore(const Score& s) {
    std::cout << s.m_score << "\n";
}
