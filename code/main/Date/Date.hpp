#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date();
    Date(const int &_day, const int &_month, const int &_year);
    ~Date();
    int getDay();
    void setDay(const int &_day);
    int getMonth();
    void setMonth(const int &_month);
    int getYear();
    void setYear(const int &_year);
    void inputDate(const string &msgWhenIsValidDate);
    void outputDate();
    bool isValidDate();
    void readDate(ifstream &fileIn);
    void writeDate(ofstream &fileOut);
};

Date::Date()
{
    day = month = year = -1;
}

Date::Date(const int &_day, const int &_month, const int &_year)
{
    day = _day;
    month = _month;
    year = _year;
}

Date::~Date() {}

int Date::getDay()
{
    return day;
}

void Date::setDay(const int &_day)
{
    day = _day;
}

int Date::getMonth()
{
    return month;
}

void Date::setMonth(const int &_month)
{
    month = _month;
}

int Date::getYear()
{
    return year;
}

void Date::setYear(const int &_year)
{
    year = _year;
}

void Date::inputDate(const string &msgWhenIsValidDate)
{
    do
    {
        cout << "\t\t\t\t\t\t   > Nhap ngay: ";
        cin >> day;
        cout << "\t\t\t\t\t\t   > Nhap thang: ";
        cin >> month;
        cout << "\t\t\t\t\t\t   > Nhap nam: ";
        cin >> year;
        if (!isValidDate())
            cout << "\n\t\t\t\t\t" << msgWhenIsValidDate << "\n";
    } while (!isValidDate());
}

void Date::outputDate()
{
    cout << day << "/" << month << "/" << year;
}

bool Date::isValidDate()
{
    if (month < 1 || month > 12)
    {
        return 0;
    }
    while (month >= 1 && month <= 12)
    {
        switch (month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day < 1 || day > 31)
            {
                return 0;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day < 1 || day > 30)
            {
                return 0;
            }
            break;
        case 2:
            if (year % 4 == 0 || year % 400 == 0)
            {
                if (day < 1 || day > 29)
                {
                    return 0;
                }
            }
            else
            {
                if (day < 1 || day > 28)
                {
                    return 0;
                }
            }
        }
        break;
    }
    return 1;
}

void Date::readDate(ifstream &fileIn)
{
    fileIn >> day >> month >> year;
}

void Date::writeDate(ofstream &fileOut)
{
    fileOut << day << " " << month << " " << year;
}