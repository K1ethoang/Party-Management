#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include "time.h"
#include "string.h"
// #include "..\ID.hpp"
#include "../Customers/Customer.hpp"
#include "../Customers/Customers.hpp"
#include "../Template\Queue/Queue.hpp"
using namespace std;

const string coming_Soon = "Sap dien ra";
const string going_On = "Dang dien ra";
const string Accomplished = "Da hoan thanh";

string typeParty_()
{
    int select;
    string _typeParty[6] = {"Tiec Tra", "Tiec Cuoi", "Tiec Sinh Nhat", "Tiec Buffet", "Tiec Set Menu"};
    do
    {
        cout << "-----------LOAI TIEC-----------" << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << i + 1 << ". " << _typeParty[i] << endl;
        }
        cin >> select;

        for (int i = 0; i < 6; i++)
        {
            if (select == i + 1)
            {
                cout << "Da chon!" << endl;
                return _typeParty[i];
            }
        }

    } while (select < 1 || select > 6);
}

Queue<string> Menu()
{
    Queue<string> menu_;
    int luachon;
    while (true)
    {
        string name_Food;
        cout << "Ban co muon nhap mon an vao Menu? " << endl;
        cout << "1. Yes" << endl;
        cout << "0. No" << endl;
        cin >> luachon;
        if (luachon == 0)
        {
            break;
        }
        else if (luachon == 1)
        {
            cout << "nhap ten mon an: ";
            fflush(stdin);
            getline(cin, name_Food);
            menu_.push(name_Food);
        }
        else
        {
            cout << "Vui long nhap lai lua chon cua ban!!!" << endl;
        }
    }
    return menu_;
}
//
struct Date
{
    int dd, mm, yyyy;
};

class Party : public ID
{
private:
    string typeParty; // loai tiec
    int tableNumber;  // So ban cua buoi tiec
    Date date;        // Thoi gian to chuc buoi tiec
    string status;
    Customer c;
    Queue<string> menu;

public:
    Party();
    ~Party();

    void setCustomer(const Customer &_c);
    Customer getCustomer();

    void set_TypeParty(const string &_typeParty);
    string get_TypeParty();

    void setDate(const Date &_date);
    Date getDate();
    void setDate(const int &_day, const int &_month, const int &_year);

    void setTableNumber(const int &_tableNumber);
    int getTableNumber();

    void setStatus();
    string getStatus();

    void setMenu(const Queue<string> &_menu);
    Queue<string> getMenu();

    void outputParty();

    friend istream &operator>>(istream &is, Party &p);
    friend ostream &operator<<(ostream &os, Party &p);
};

void Party::setCustomer(const Customer &_c)
{
    c = _c;
}

Customer Party::getCustomer()
{
    return c;
};

Party::Party()
{
    typeParty = "UNKNOWN";
    tableNumber = -1;
    date.dd = 0;
    date.mm = 0;
    date.yyyy = 0;
}

Party::~Party()
{
}

// Khởi tạo các hàm thuộc tính

void Party::setTableNumber(const int &_tableNumber)
{
    tableNumber = _tableNumber;
}

int Party::getTableNumber()
{
    return tableNumber;
}

void Party::setDate(const Date &_date)
{
    date.dd = _date.dd;
    date.mm = _date.mm;
    date.yyyy = _date.yyyy;
}

void Party::setDate(const int &_day, const int &_month, const int &_year)
{
    date.dd = _day;
    date.mm = _month;
    date.yyyy = _year;
}

Date Party::getDate()
{
    return date;
}

bool isValidDate(int day, int month, int year) // kiểm tra ngày nhập
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
void inputDate(Date &date, const string &msg)
{
    do
    {
        cout << "Nhap ngay: ";
        cin >> date.dd;
        cout << "Nhap thang: ";
        cin >> date.mm;
        cout << "Nhap nam: ";
        cin >> date.yyyy;
        if (!isValidDate(date.dd, date.mm, date.yyyy))
            cout << "\n\t" << msg << "\n";
    } while (!isValidDate(date.dd, date.mm, date.yyyy));
}

void Party::set_TypeParty(const string &_typeParty)
{
    typeParty = _typeParty;
}

string Party::get_TypeParty()
{
    return typeParty;
}

void Party::setStatus()
{
    time_t now = time(0);
    tm *tgian = localtime(&now);
    // cout << tgian->tm_year+1900;
    // kh.tg.ngay = tgian->tm_mday;
    // kh.tg.thang = tgian->tm_mon + 1;
    // kh.tg.nam = tgian->tm_year + 1900 ;
    // kh.tg.gio = tgian->tm_hour ;
    // kh.tg.phut = tgian->tm_min;
    // kh.tg.giay = tgian->tm_sec;
    if ((date.yyyy < tgian->tm_year + 1900) || ((date.yyyy == tgian->tm_year + 1900) && (date.mm < tgian->tm_mon + 1)) || ((date.yyyy == tgian->tm_year + 1900) && (date.mm == tgian->tm_mon + 1) && (date.dd < tgian->tm_mday)))
    {
        status = Accomplished;
    }
    else if (date.yyyy == tgian->tm_year + 1900 && date.mm == tgian->tm_mon + 1 && date.dd == tgian->tm_mday)
    {
        status = going_On;
    }
    else
    {
        status = coming_Soon;
    }
}

string Party::getStatus()
{
    return status;
}

void Party::setMenu(const Queue<string> &_menu)
{
    menu = _menu;
}
Queue<string> Party::getMenu()
{
    return menu;
}

void Party::outputParty()
{

    cout << "\t\tID cua tiec: " << OutputID() << endl;
    cout << "\t\tLoai tiec: " << typeParty << endl;
    cout << "\t\tSo ban cua tiec: " << tableNumber << endl;
    cout << "\t\tThoi gian dat tiec: " << date.dd << "/" << date.mm << "/" << date.yyyy << endl;
}

istream &operator>>(istream &is, Party &p)
{
    // is >> p.c;
    string res = typeParty_();
    p.set_TypeParty(res);
    p.InputID();
    cout << "Nhap so ban cua buoi tiec: ";
    is >> p.tableNumber; // So ban cua buoi tiec
    cout << "Nhap thoi gian to chuc tiec " << endl;
    inputDate(p.date, "Ngay thang khong hop le"); // Thoi gian to chuc buoi tiec
    p.setStatus();
    Queue<string> resMenu = Menu(); // food của menu
    p.setMenu(resMenu);
    return is;
}

ostream &operator<<(ostream &os, Party &p)
{
    // p.outputParty();
    os << "\n\t\t|   " << setiosflags(ios::left) << setw(6) << " "
       << "|"
       << "       " << setw(22) << p.typeParty << "|"
       << "   " << setw(9) << p.tableNumber << "|"
       << "        " << setw(10) << p.OutputID() << "|"
       << "    " << setw(2) << p.date.dd << "/" << setw(2) << p.date.mm << "/" << setw(15) << p.date.yyyy << "|"
       << "    " << setw(20) << p.status << "|";
    os << "\n\t\t+=========+=============================+============+==================+=========================+========================+";
    p.getMenu().display();
    return os;
}
