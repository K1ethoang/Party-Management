#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "../Parties/Party.hpp"

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

void Customer::setPhoneNumber(string _phoneNumber)
{
    do
    {
        if (_phoneNumber.length() != 10)
        {
            cout << "\nSo dien thoai khong hop le!!" << endl;
            cout << "\nNhap lai: ";
            fflush(stdin);
            cin >> _phoneNumber;
        }
        phoneNumber = _phoneNumber;

    } while (_phoneNumber.length() != 10);
}

istream &operator>>(istream &is, Customer &c)
{
    string phoneNumber;
    cout << "\n\t\t-----NHAP THONG TIN KHACH HANG-----\n";
    cout << "\nNhap ho va ten: ";
    fflush(stdin);
    getline(is, c.fullName);
    cout << "\nNhap so dien thoai: ";
    cin >> phoneNumber;
    c.setPhoneNumber(phoneNumber);
    return is;
}

ostream &operator<<(ostream &os, Customer c)
{

    cout << "\n\t\t-----THONG TIN KHACH HANG DA NHAP-----\n";
    cout << "\nid: " << c.idOfParty;
    cout << "\nHo va ten: " << c.fullName;
<<<<<<< HEAD
    cout << "\nSo dien thoai: " << c.phoneNumber << endl;
    c.OutputID();
=======
    cout << "\nSo dien thoai: " << c.phoneNumber;

>>>>>>> 3502dfa868877bd7fb4b21b9f0b93848c100c45f
    return os;
}