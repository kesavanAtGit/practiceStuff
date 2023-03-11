#ifndef DATE_H
#define DATE_H

class Date
{
private:
    int m_date{};
    int m_month{};
    int m_year{};

public:
    Date(int date, int month, int year);
    void setDate(int date, int month, int year);
    void printDate();

    Date& addToDate(int value);
    Date& subToDate(int value);
    Date& mulToDate(int value);
};

#endif // !#ifndef DATE_H
