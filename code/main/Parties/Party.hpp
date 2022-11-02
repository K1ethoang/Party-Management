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
    string _typeParty[6] = {"Tiec Tra", "Tiec Cuoi", "Tiec Sinh Nhat", "Tiec Buffet", "Tiec Ruou", "Tiec Set Menu"};
    do
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\t __________LOAI TIEC__________ " << endl;
        cout << "\t\t\t\t\t\t\t\t\t|                             |" << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << "\t\t\t\t\t\t\t\t\t| " << i + 1 << ". " << setiosflags(ios::left) << setw(25) << _typeParty[i] << "|" << endl;
        }
        cout << "\t\t\t\t\t\t\t\t\t|_____________________________|" << endl;
        cout << "\t\t\t\t\t\t\t\t\tNhap loai tiec muon chon -> ";
        cin >> select;

        for (int i = 0; i < 6; i++)
        {
            if (select == i + 1)
            {
                cout << "\t\t\t\t\t\t\t\t\t--> Da chon thanh cong!" << endl;
                return _typeParty[i];
            }
        }

    } while (select < 1 || select > 6);
}

Queue<string> Menu()
{
    Queue<string> menu_;
    char luachon;
    while (true)
    {
        // system("cls");
        string name_Food;
        cout << "<+> Ban co muon THEM mon an vao Menu? (1.YES / 0.NO)?" << endl;
        cout << "\tSelect -> ";
        cin >> luachon;
        if (luachon == '0')
        {
            break;
        }
        else if (luachon == '1')
        {
            cout << "\tNhap mon an: ";
            fflush(stdin);
            getline(cin, name_Food);
            menu_.push(name_Food);
        }
        else
        {
            cout << "<!> Vui long nhap lai lua chon cua ban!!!" << endl;
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
    float sumMoney;
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
    void setMenu(Queue<string> _menu);
    Queue<string> getMenu();
    void outputParty();
    // void setSumMoney(const);
    float getSumMoney();
    void ThanhToan();
    void printBill(); // in bill

    friend istream &operator>>(istream &is, Party &p);
    friend ostream &operator<<(ostream &os, Party &p);
};

// void Party::setSumMoney(const float _sumMoney){

// }
float Party::getSumMoney()
{
    return sumMoney;
}

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
        cout << "\t\t\t\t\t\t\t\t\t   > Nhap ngay : ";
        cin >> date.dd;
        cout << "\t\t\t\t\t\t\t\t\t   > Nhap thang: ";
        cin >> date.mm;
        cout << "\t\t\t\t\t\t\t\t\t   > Nhap nam  : ";
        cin >> date.yyyy;
        if (!isValidDate(date.dd, date.mm, date.yyyy))
            cout << "\n"
                 << msg << "\n";
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

void Party::setMenu(Queue<string> _menu)
{
    if (menu.sizeOf() != 0)
        menu.clear();
    while (_menu.sizeOf() != 0)
    {
        menu.push(_menu.front());
        _menu.pop();
    }
}

Queue<string> Party::getMenu()
{
    return menu;
}

void Party::outputParty()
{
    cout << "\t\t\t\t\t\t\t\t\tID cua tiec       : " << OutputID() << endl;
    cout << "\t\t\t\t\t\t\t\t\tLoai tiec         : " << typeParty << endl;
    cout << "\t\t\t\t\t\t\t\t\tSo ban cua tiec   : " << tableNumber << endl;
    cout << "\t\t\t\t\t\t\t\t\tThoi gian dat tiec: " << date.dd << "/" << date.mm << "/" << date.yyyy << endl;
}
void Party::ThanhToan()
{
}
void Party::printBill()
{
    cout << "\t\t\t+==================================>>>HOA DON THANH TOAN<<<==================================+" << endl;
    cout << "\t\t\t|                                                                                            |" << endl;
    cout << "\t\t\t|                                                          13/03/2003 14:03                  |" << endl;
    cout << "\t\t\t|                                                                                            |" << endl;
    cout << "\t\t\t|    > Ten: " << setiosflags(ios::left) << setw(81) << c.getFullName() << "|" << endl;
    cout << "\t\t\t|    > SDT: " << setiosflags(ios::left) << setw(81) << c.getPhoneNumber() << "|" << endl;
    cout << "\t\t\t|    > Dia chi: " << setiosflags(ios::left) << setw(77) << c.getAddress() << "|" << endl;
    cout << "\t\t\t|                                                                                            |" << endl;
    cout << "\t\t\t|    > ID: " << setiosflags(ios::left) << setw(82) << OutputID() << "|" << endl;
    cout << "\t\t\t|    > Loai tiec: " << setiosflags(ios::left) << setw(75) << typeParty << "|" << endl;
    cout << "\t\t\t|    > So ban: " << setiosflags(ios::left) << setw(78) << tableNumber << "|" << endl;
    cout << "\t\t\t|    > Thoi gian to chuc: " << setiosflags(ios::left) << setw(2) << date.dd << "/" << setw(2) << date.mm << "/" << setw(61) << date.yyyy << "|" << endl;
    cout << "\t\t\t|                                                                                            |" << endl;
    cout << "\t\t\t|    +----------------------------------------------------------------------------------+    |" << endl;
    cout << "\t\t\t|    |   STT  |               Mon                 |   So luong   |        Gia ca        |    |" << endl;
    cout << "\t\t\t|    +----------------------------------------------------------------------------------+    |" << endl;
    cout << "\t\t\t|    |   12   |   lau                             |              |                      |    |" << endl;
    cout << "\t\t\t|    |   " << setiosflags(ios::left) << setw(5) << "|"
         << "   " << setw(32) << " "
         << "|" << endl;
    // cout << "name: " << c.getFullName();
    // cout << "sdt: " << c.getPhoneNumber();
    // cout << "ID: " << OutputID() << endl;
}

istream &operator>>(istream &is, Party &p)
{
    // is >> p.c;
    string res = typeParty_();
    p.set_TypeParty(res);
    p.InputID();
    cout << "\t\t\t\t\t\t\t\t\tNhap so ban cua buoi tiec: ";
    is >> p.tableNumber; // So ban cua buoi tiec
    cout << "\t\t\t\t\t\t\t\t\tNhap thoi gian to chuc tiec:" << endl;
    inputDate(p.date, "\t\t\t\t\t\t\t\t\t!!! Ngay thang khong hop le!"); // Thoi gian to chuc buoi tiec
    p.setStatus();
    system("pause");
    // Queue<string> resMenu = Menu(); // food của menu
    // p.setMenu(resMenu);
    return is;
}

ostream &operator<<(ostream &os, Party &p)
{
    // p.outputParty();
    os << "\n\t\t\t" << setiosflags(ios::left) << "|"
       << "        " << setw(10) << p.OutputID() << "|"
       << "               " << setw(24) << p.typeParty << "|"
       << "          " << setw(12) << p.tableNumber << "|"
       << "         " << setw(2) << p.date.dd << "/" << setw(2) << p.date.mm << "/" << setw(12) << p.date.yyyy << "|"
       << "        " << setw(18) << p.status << "|";
    os << "\n\t\t\t+==================+=======================================+======================+===========================+==========================+";
    // os << "Name: " << p.c.getFullName() << endl;
    p.getMenu().display();

    return os;
}
