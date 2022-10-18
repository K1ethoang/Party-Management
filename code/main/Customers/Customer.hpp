#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "..\ID.hpp"

using namespace std;

class Customer : public ID
{
private:
    string fullName;
    string phoneNumber;

public:
    Customer();
    Customer(const string &_fullName, const string &_phoneNumber);
    ~Customer();
    string getFullName();
    void setFullName(const string &_fullName);
    string getPhoneNumber();
    void setPhoneNumber(const string &_phoneNumber);
    friend istream &operator>>(istream &is, Customer &c);
    friend ostream &operator<<(ostream &os, Customer c);
};

Customer::Customer()
{
    fullName = "UNKNOWN";
    phoneNumber = "1234567890";
}

Customer::Customer(const string &_fullName, const string &_phoneNumber)
{
    fullName = _fullName;
    setPhoneNumber(_phoneNumber);
}

Customer::~Customer() {}

string Customer::getFullName()
{
    return fullName;
}

void Customer::setFullName(const string &_fullName)
{
    fullName = _fullName;
}

string Customer::getPhoneNumber()
{
    return phoneNumber;
}

void Customer::setPhoneNumber(const string &_phoneNumber)
{
    if (_phoneNumber.length() != 10)
        cout << "\nSo dien thoai khong hop le!";
    else
        phoneNumber = _phoneNumber;
}

istream &operator>>(istream &is, Customer &c)
{
    cout << "\n\t\tNHAP THONG TIN KHACH HANG\n";
    cout << "\nNhap ho va ten: ";
    fflush(stdin);
    getline(is, c.fullName);
    do
    {
        cout << "\nNhap so dien thoai: ";
        getline(is, c.phoneNumber);
        if (c.phoneNumber.length() != 10)
            cout << "\nSo dien thoai khong hop le! Nhap lai";
    } while (c.phoneNumber.length() != 10);

    return is;
}

ostream &operator<<(ostream &os, Customer c)
{
    cout << "\n\t\tTHONG TIN KHACH HANG DA NHAP\n";
    cout << "\nHo va ten: " << c.fullName;
    cout << "\nSo dien thoai: " << c.phoneNumber << endl;
    c.OutputID();
    return os;
}