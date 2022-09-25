#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Customer
{
private:
    string fullName;
    string phoneNumber;
    long idOfParty;

public:
    Customer();
    Customer(const string &_fullName, const string &_phoneNumber, const long &_idOfParty);
    ~Customer();
    string getFullName();
    void setFullName(const string &_fullName);
    string getPhoneNumber();
    void setPhoneNumber(string _phoneNumber);
    long getIdOfParty();
    void setIdOfParty(const long &_idOfParty);
    friend istream &operator>>(istream &is, Customer &c);
    friend ostream &operator<<(ostream &os, Customer c);
};

Customer::Customer()
{
    fullName = "UNKNOWN";
    phoneNumber = "1234567890";
    idOfParty = 0;
}

Customer::Customer(const string &_fullName, const string &_phoneNumber, const long &_idOfParty)
{
    fullName = _fullName;
    setPhoneNumber(_phoneNumber);
    setIdOfParty(_idOfParty);
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

long Customer::getIdOfParty()
{
    return idOfParty;
}

void Customer::setIdOfParty(const long &_idOfParty)
{
    if (_idOfParty > 0)
        idOfParty = _idOfParty;
    else
        cout << "\nId cua bua tiec khong hop le!";
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
    cout << "\nSo dien thoai: " << c.phoneNumber;

    return os;
}