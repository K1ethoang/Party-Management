#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "../ID/ID.hpp"
#include "../EditName/editName.hpp"

using namespace std;

// Customer
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
    void outputCustomer();
    friend istream &operator>>(istream &is, Customer &c);
    friend ostream &operator<<(ostream &os, Customer c);
    void readACustomer(ifstream &fileIn);
    void writeACustomer(ofstream &fileOut);
};

typedef Customer ItemC;

// hàm ngoài
bool isValidPhoneNumber(string _phoneNumber);

// hàm ngoài
bool isValidPhoneNumber(string _phoneNumber)
{
    bool isValid = false;
    int lengthPhoneNumber = _phoneNumber.length();
    if (lengthPhoneNumber == 10)
    {
        for (int i = 0; i < lengthPhoneNumber; i++)
        {
            if (_phoneNumber[i] - 48 >= 0 && _phoneNumber[i] - 48 <= 9)
                isValid = true;
            else
                isValid = false;
        }
    }
    else
        isValid = false;

    return isValid;
}

// Customer
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
    formatName(fullName);
}

string Customer::getPhoneNumber()
{
    return phoneNumber;
}

void Customer::setPhoneNumber(const string &_phoneNumber)
{
    phoneNumber = _phoneNumber;
}

void Customer::outputCustomer()
{
    cout << "\n\t\t\t\t\t\t\t\t\tHo va ten      : " << fullName;
    cout << "\n\t\t\t\t\t\t\t\t\tSo dien thoai  : " << phoneNumber << endl;
    outputID();
}

istream &operator>>(istream &is, Customer &c)
{
    cout << "\n\t\t\t\t\t\t\t\t\tNhap ho va ten: ";
    fflush(stdin);
    getline(is, c.fullName);
    formatName(c.fullName);
    do
    {
        cout << "\t\t\t\t\t\t\t\t\tNhap so dien thoai: ";
        getline(is, c.phoneNumber);
        if (!isValidPhoneNumber(c.phoneNumber))
            cout << "\n\t\t\t\t\t\t\t\t\t<!> So dien thoai khong hop le! Nhap lai\n";
    } while (!isValidPhoneNumber(c.phoneNumber));
    return is;
}

ostream &operator<<(ostream &os, Customer c)
{
    cout << "\n\t\t\t\t\t\t\t\t\t[Thong tin khach hang da nhap]\n";
    cout << "\n\t\t\t\t\t\t\t\t\tHo va ten      : " << c.fullName;
    cout << "\n\t\t\t\t\t\t\t\t\tSo dien thoai  : " << c.phoneNumber << endl;
    c.outputID();
    return os;
}

void Customer::readACustomer(ifstream &fileIn)
{
    string newLine;
    long ID;
    fileIn >> ID;
    setID(ID);
    getline(fileIn, newLine);
    getline(fileIn, fullName);
    getline(fileIn, phoneNumber);
}

void Customer::writeACustomer(ofstream &fileOut)
{

    fileOut << "\n"
            << getID() << endl;
    fileOut << fullName << endl;
    fileOut << phoneNumber;
}
