#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "..\ID.hpp"
#include "../EditString/editString.hpp"
#include "../Person/Person.hpp"
using namespace std;

class Customer : public ID, public Person
{
public:
    Customer();
    Customer(const string &_fullName, const string &_phoneNumber);
    ~Customer();
    string getFullName();
    void setFullName(const string &_fullName);
    string getPhoneNumber();
    void setPhoneNumber(const string &_phoneNumber);
    string getAddress();
    void setAddress(const string &_address);
    void outputCustomer();
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

string Customer::getAddress()
{
    return address;
};

void Customer::setAddress(const string &_address)
{
    address = _address;
};

void Customer::outputCustomer()
{
    cout << "\n\t\t\t\t\t\t\t\t\t[THONG TIN KHACH HANG DA NHAP]";
    cout << "\n\t\t\t\t\t\t\t\t\t> Ho va ten: " << fullName;
    cout << "\n\t\t\t\t\t\t\t\t\t> So dien thoai: " << phoneNumber;
    cout << "\n\t\t\t\t\t\t\t\t\t> Dia chi: " << address;
    OutputID();
}

istream &operator>>(istream &is, Customer &c)
{
    cout << "\n\t\t\t\t\t\t\t\t\tNhap ho va ten: ";
    fflush(stdin);
    getline(is, c.fullName);
    editString_(c.fullName);
    do
    {
        cout << "\t\t\t\t\t\t\t\t\tNhap so dien thoai: ";
        getline(is, c.phoneNumber);
        if (c.phoneNumber.length() != 10)
            cout << "\n\t\t\t\t\t\t\t\t\t<!> So dien thoai khong hop le! Nhap lai\n";
    } while (c.phoneNumber.length() != 10);
    cout << "\t\t\t\t\t\t\t\t\tNhap dia chi: ";
    fflush(stdin);
    getline(is, c.address);
    editString_(c.address);
    return is;
}

ostream &operator<<(ostream &os, Customer c)
{
    cout << "\n\t\t\t\t\t\t\t\t\t[Thong tin khach hang da nhap]\n";
    cout << "\n\t\t\t\t\t\t\t\t\tHo va ten: " << c.fullName;
    cout << "\n\t\t\t\t\t\t\t\t\tSo dien thoai: " << c.phoneNumber;
    cout << "\n\t\t\t\t\t\t\t\t\tDia chi: " << c.address << endl;
    c.OutputID();
    return os;
}