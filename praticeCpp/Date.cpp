#include <iostream>
#include "Date.h"

// member functions for the date Class are defined here
// constructor function defined outside the class
Date::Date(int date, int month, int year) : m_date{date}, m_month{month}, m_year{year}
{
    setDate(date, month, year);
}

void Date::setDate(int date, int month, int year)
{
    m_date = date;
    m_month = month;
    m_year = year;
}

void Date::printDate()
{
    std::cout << "The date is " << m_date << "/" << m_month << "/" << m_year << "\n";
}

Date& Date::addToDate(int value)
{
    m_date += value;
    return *this;
}

Date& Date::subToDate(int value)
{
    m_date -= value;
    return *this;
}

Date& Date::mulToDate(int value)
{
    m_date *= value;
    return *this;
}
