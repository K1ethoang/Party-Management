#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "time.h"
#include "../Foods/Food.hpp"
#include "../Date/Date.hpp"
#include "../Template/Queue/Queue.hpp"
#include "../constance.hpp"
using namespace std;

// Party
typedef class Party : public ID
{
private:
    Customer customer;  // Thông tin khách hàng
    string typeParty;   // Loại tiệc
    int tableNumber;    // Số bàn tiệc
    Date date;          // Thời gian tổ chức
    int partyStatus;    // Trạng thái tiệc
    bool paymentStatus; // Trạng thái thanh toán
    float sumMoney;     // Tiền của buổi tiệc
    // Queue<Food> menu;   // Thực đơn của tiệc

private:
    string returnPartyStatusPrivate(); // Lấy trạng thái dạng chuỗi

public:
    Party();
    ~Party();
    void setCustomer(const Customer &_customer);
    Customer getCustomer();
    void setTypeParty(const string &typeParties);
    string getTypeParty();
    void setDate(const Date &_date);
    Date getDate();
    void setTableNumber(const int &_tableNumber);
    int getTableNumber();
    void setPartyStatus();
    int getPartyStatus();
    void setPaymentStatus(const bool &_value);
    bool getPaymentStatus();
    // void setMenu(Queue<Food> _menu);
    // Queue<Food> getMenu();
    void setSumMoney(const float &_sumMoney);
    float getSumMoney();

    void outputParty();
    void ThanhToan();
    void printBill(); // in bill
    friend istream &operator>>(istream &is, Party &p);
    friend ostream &operator<<(ostream &os, Party &p);
    void readAParty(ifstream &fileIn);
    void writeAParty(ofstream &fileOut);
} ItemP;

// Hàm ngoài
vector<string> readTypeParty();
string chooseTypeParty();

// Hàm ngoài
vector<string> readTypeParty()
{
    vector<string> typeParties;
    ifstream fileIn(TYPE_PARTY_DATA_PATH);
    if (fileIn.is_open())
    {
        while (!fileIn.eof())
        {
            string typeParty;
            getline(fileIn, typeParty);
            typeParties.push_back(typeParty);
        }
    }
    else
        cout << "\nCo loi khi mo file \"loai tiec\"" << endl;
    return typeParties;
}

string chooseTypeParty()
{
    vector<string> typeParties = readTypeParty();
    int select;
    do
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\t __________LOAI TIEC__________ " << endl;
        cout << "\t\t\t\t\t\t\t\t\t|                             |" << endl;
        for (int i = 0; i < typeParties.size(); i++)
        {
            cout << "\t\t\t\t\t\t\t\t\t| " << i + 1 << ". " << setiosflags(ios::left) << setw(25) << typeParties[i] << "|" << endl;
        }
        cout << "\t\t\t\t\t\t\t\t\t|_____________________________|" << endl;
        cout << "\t\t\t\t\t\t\t\t\tNhap loai tiec muon chon -> ";
        cin >> select;

        for (int i = 0; i < typeParties.size(); i++)
        {
            if (select == i + 1)
            {
                cout << "\n\t\t\t\t\t\t\t\t\t--> Da chon thanh cong!" << endl;
                return typeParties[i];
            }
        }
    } while (select < 1 || select > typeParties.size());
    return "";
}

// Party
// Private
string Party::returnPartyStatusPrivate()
{
    if (partyStatus > 0)
        return ACCOMPLISHED;
    else if (partyStatus < 0)
        return COMING_SOON;
    return GOING_ON;
}

// Public
void Party::setSumMoney(const float &_sumMoney)
{
    sumMoney = _sumMoney;
}

float Party::getSumMoney()
{
    return sumMoney;
}

void Party::setCustomer(const Customer &_customer)
{
    customer = _customer;
}

Customer Party::getCustomer()
{
    return customer;
};

Party::Party()
{
    typeParty = "";
    tableNumber = -1;
    partyStatus = -1;
    paymentStatus = 0;
    sumMoney = -1;
}

Party::~Party()
{
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
    date = _date;
}

Date Party::getDate()
{
    return date;
}

void Party::setTypeParty(const string &typeParties)
{
    typeParty = typeParties;
}

string Party::getTypeParty()
{
    return typeParty;
}

void Party::setPartyStatus()
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
    if ((date.getYear() < tgian->tm_year + 1900) || ((date.getYear() == tgian->tm_year + 1900) && (date.getMonth() < tgian->tm_mon + 1)) || ((date.getYear() == tgian->tm_year + 1900) && (date.getMonth() == tgian->tm_mon + 1) && (date.getDay() < tgian->tm_mday)))
    {
        partyStatus = 1;
    }
    else if (date.getYear() == tgian->tm_year + 1900 && date.getMonth() == tgian->tm_mon + 1 && date.getDay() == tgian->tm_mday)
    {
        partyStatus = 0;
    }
    else
    {
        partyStatus = -1;
    }
    cout << "\nStatus: " << partyStatus << endl;
}

int Party::getPartyStatus()
{
    return partyStatus;
}

void Party::setPaymentStatus(const bool &_value)
{
    paymentStatus = _value;
}

bool Party::getPaymentStatus()
{
    return paymentStatus;
}

// void Party::setMenu(Queue<Food> _menu)
// {
//     if (menu.sizeOf() != 0)
//         menu.clear();
//     while (_menu.sizeOf() != 0)
//     {
//         menu.push(_menu.front());
//         _menu.pop();
//     }
// }

// Queue<Food> Party::getMenu()
// {
//     return menu;
// }

void Party::outputParty()
{
    cout << "\n\t\t\t\t\t\t\t\t\tID cua tiec          : " << outputID() << endl;
    cout << "\t\t\t\t\t\t\t\t\tLoai tiec            : " << typeParty << endl;
    cout << "\t\t\t\t\t\t\t\t\tSo ban cua tiec      : " << tableNumber << endl;
    cout << "\t\t\t\t\t\t\t\t\tThoi gian dat tiec   : ";
    date.outputDate();
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t\tTien                 : " << (size_t)sumMoney << " VND" << endl;
    cout << "\t\t\t\t\t\t\t\t\tTrang thai cua tiec  : " << returnPartyStatusPrivate() << endl;
    cout << "\t\t\t\t\t\t\t\t\tThanh toan           : " << (paymentStatus ? "Da thanh toan" : "Chua thanh toan") << endl;
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
    cout << "\t\t\t|    > Ten: " << setiosflags(ios::left) << setw(81) << customer.getFullName() << "|" << endl;
    cout << "\t\t\t|    > SDT: " << setiosflags(ios::left) << setw(81) << customer.getPhoneNumber() << "|" << endl;
    cout << "\t\t\t|                                                                                            |" << endl;
    cout << "\t\t\t|    > ID: " << setiosflags(ios::left) << setw(82) << outputID() << "|" << endl;
    cout << "\t\t\t|    > Loai tiec: " << setiosflags(ios::left) << setw(75) << typeParty << "|" << endl;
    cout << "\t\t\t|    > So ban: " << setiosflags(ios::left) << setw(78) << tableNumber << "|" << endl;
    cout << "\t\t\t|    > Thoi gian to chuc: " << setiosflags(ios::left) << setw(2) << date.getDay() << "/" << setw(2) << date.getMonth() << "/" << setw(61) << date.getYear() << "|" << endl;
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
    // cout << "ID: " << outputID() << endl;
}

istream &operator>>(istream &is, Party &p)
{
    p.inputID();
    string res = chooseTypeParty();
    p.setTypeParty(res);
    cout << "\n\t\t\t\t\t\t\t\t\tNhap so ban cua buoi tiec: ";
    is >> p.tableNumber;
    cout << "\n\t\t\t\t\t\t\t\t\tNhap thoi gian to chuc tiec:" << endl;
    p.date.inputDate("\n\t\t\t\t\t\t\t\t\t(!) Ngay thang khong hop le (!)");
    p.setPartyStatus();
    system("pause");
    return is;
}

ostream &operator<<(ostream &os, Party &p)
{
    os << "\n\t\t\t" << setiosflags(ios::left) << "|"
       << "        " << setw(10) << p.outputID() << "|"
       << "               " << setw(24) << p.typeParty << "|"
       << "          " << setw(12) << p.tableNumber << "|"
       << "         " << setw(2) << p.date.getDay() << "/" << setw(2) << p.date.getMonth() << "/" << setw(12) << p.date.getYear() << "|"
       << "        " << setw(18) << p.returnPartyStatusPrivate() << "|";
    os << "\n\t\t\t+==================+=======================================+======================+===========================+==========================+";
    // os << "Name: " << p.c.getFullName() << endl;
    return os;
}

void Party::readAParty(ifstream &fileIn)
{
    string newLine;
    long _ID;
    fileIn >> _ID;
    setID(_ID);
    getline(fileIn, newLine); // xoá ký tự xuống dòng
    getline(fileIn, typeParty);
    fileIn >> tableNumber;
    Date _date;
    _date.readDate(fileIn);
    setDate(_date);
    fileIn >> partyStatus;
    fileIn >> paymentStatus;
    fileIn >> sumMoney;
}

void Party::writeAParty(ofstream &fileOut)
{
    fileOut << "\n"
            << getID() << endl;
    fileOut << typeParty << endl;
    fileOut << tableNumber << endl;
    date.writeDate(fileOut);
    fileOut << "\n"
            << partyStatus << endl;
    fileOut << paymentStatus << endl;
    fileOut << (size_t)sumMoney;
}