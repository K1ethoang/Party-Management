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

struct Date
{
    int dd, mm, yyyy;
};

class Party : public ID
{
private:
    static int order;
    int stt;
    string typeParty; // ID cua buoi tiec
    int tableNumber;  // So ban cua buoi tiec
    Date date;        // Thoi gian to chuc buoi tiec
    string status;
    Customer c;
    Queue<string> menu;

public:
    Party();
    ~Party();

    int getOrder();
    int getStt();

    Customer getCustomer();

    void set_TypeParty();
    string get_TypeParty();

    void setDate(const Date &_date);
    Date getDate();
    void setDate(const int &_day, const int &_month, const int &_year);

    void setTableNumber(const int &_tableNumber);
    int getTableNumber();

    void setStatus();
    string getStatus();

    void setMenu();
    Queue<string> getMenu();

    friend istream &operator>>(istream &is, Party &p);
    friend ostream &operator<<(ostream &os, Party &p);
};

Customer Party::getCustomer()
{
    return c;
};

int Party::order = 1;
int Party::getStt()
{
    return stt;
};

Party::Party()
{
    // order ++;
    stt = order;
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

int Party::getOrder()
{
    return order;
}

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

void Party::set_TypeParty()
{
    int select;
    string _typeParty[6] = {"Tiec Tra", "Tiec Cuoi", "Tiec Sinh Nhat", "Tiec Buffet", "Tiec Set Menu"};
    do
    {
        cout << "-----------LOAI TIEC-----------" << endl;
        cout << "1. Tiec tra" << endl;
        cout << "2. Tiec cuoi" << endl;
        cout << "3. Tiec sinh nhat" << endl;
        cout << "4. Tiec ruou" << endl;
        cout << "5. Tiec Buffet" << endl;
        cout << "6. Tiec Set Menu" << endl;
        cout << "SELECT: ";
        cin >> select;

        for (int i = 0; i < 6; i++)
        {
            if (select == i + 1)
            {
                typeParty = _typeParty[i];
                cout << "Da chon!" << endl;
                break;
            }
        }

    } while (select < 1 || select > 6);
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

void Party::setMenu()
{
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
            menu.push(name_Food);
        }
        else
        {
            cout << "Vui long nhap lai lua chon cua ban!!!" << endl;
        }
    }
}
Queue<string> Party::getMenu()
{
    return menu;
}

istream &operator>>(istream &is, Party &p)
{
    p.order++;
    is >> p.c;
    p.set_TypeParty();
    p.InputID();
    cout << "Nhap so ban cua buoi tiec: ";
    is >> p.tableNumber; // So ban cua buoi tiec
    cout << "Nhap thoi gian to chuc tiec " << endl;
    inputDate(p.date, "Ngay thang khong hop le"); // Thoi gian to chuc buoi tiec
    p.setStatus();
    p.setMenu();
    return is;
}

ostream &operator<<(ostream &os, Party &p)
{
    os << "\n\t\t|   " << setiosflags(ios::left) << setw(6) << p.getStt() << "|"
       << "       " << setw(22) << p.typeParty << "|"
       << "   " << setw(9) << p.tableNumber << "|"
       << "        " << setw(10) << p.OutputID() << "|"
       << "    " << setw(2) << p.date.dd << "/" << setw(2) << p.date.mm << "/" << setw(15) << p.date.yyyy << "|"
       << "    " << setw(20) << p.status << "|";
    os << "\n\t\t+=========+=============================+============+==================+=========================+========================+";
    p.getMenu().display();
    return os;
}
