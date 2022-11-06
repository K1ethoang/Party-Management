#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "../ID/ID.hpp"
#include "../EditName/editName.hpp"
#include "../Person/Person.hpp"
using namespace std;

// Customer
class Customer : public ID, public Person
{
public:
    Customer();
    Customer(const string &_fullName, const string &_phoneNumber, const string &_CCCD);
    ~Customer();
    string getFullName();
    void setFullName(const string &_fullName);
    string getPhoneNumber();
    void setPhoneNumber(const string &_phoneNumber);
    string getCCCD();
    void setCCCD(const string &_CCCD);
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

// hàm ngoài
bool isValidCCDD(string _CCCD);

// hàm ngoài
bool isValidCCDD(string _CCCD)
{
    bool isValid = false;
    int lengthCCCD = _CCCD.length();
    if (lengthCCCD == 12)
    {
        for (int i = 0; i < lengthCCCD; i++)
        {
            if (_CCCD[i] - 48 >= 0 && _CCCD[i] - 48 <= 9)
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
    CCCD = "1234567890";
}

Customer::Customer(const string &_fullName, const string &_phoneNumber, const string &_CCCD)
{
    fullName = _fullName;
    setPhoneNumber(_phoneNumber);
    CCCD = _CCCD;
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

string Customer::getCCCD()
{
    return CCCD;
}

void Customer::setCCCD(const string &_CCCD)
{
    CCCD = _CCCD;
}

void Customer::outputCustomer()
{
    cout << "\n\t\t\t\t\t\t\t\t\t[THONG TIN KHACH HANG DA NHAP]";
    cout << "\n\t\t\t\t\t\t\t\t\t> Ho va ten     : " << fullName;
    cout << "\n\t\t\t\t\t\t\t\t\t> So dien thoai : " << phoneNumber;
    cout << "\n\t\t\t\t\t\t\t\t\t> So CCCD       : " << CCCD;
    outputID();
}

istream &operator>>(istream &is, Customer &c)
{
    cout << "\n\t\t\t\t\t\t\t\t\tNhap ho va ten: ";
    fflush(stdin);
    getline(is, c.fullName);
    formatName(c.fullName);
    // Nhập sđt và kiểm tra
    do
    {
        cout << "\t\t\t\t\t\t\t\t\tNhap so dien thoai: ";
        getline(is, c.phoneNumber);
        if (!isValidPhoneNumber(c.phoneNumber))
            cout << "\n\t\t\t\t\t\t\t\t\t<!> So dien thoai khong hop le! Nhap lai\n";
    } while (!isValidPhoneNumber(c.phoneNumber));
    // Nhập số CCCD và kiểm tra
    do
    {
        cout << "\t\t\t\t\t\t\t\t\tNhap so CCCD: ";
        getline(is, c.CCCD);
        if (!isValidCCDD(c.CCCD))
            cout << "\n\t\t\t\t\t\t\t\t\t<!> So dien thoai khong hop le! Nhap lai\n";
    } while (!isValidCCDD(c.CCCD));

    return is;
}

ostream &operator<<(ostream &os, Customer c)
{
    cout << "\n\t\t\t" << setiosflags(ios::left) << "|"
         << "        " << setw(10) << c.getID() << "|"
         << "           " << setw(32) << c.getFullName() << "|"
         << "       " << setw(18) << c.getPhoneNumber() << "|"
         << "            " << setw(24) << c.getCCCD() << "|";
    cout << "\n\t\t\t+==================+===========================================+=========================+====================================+";
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
    getline(fileIn, CCCD);
}

void Customer::writeACustomer(ofstream &fileOut)
{
    fileOut << "\n"
            << getID() << endl;
    fileOut << fullName << endl;
    fileOut << phoneNumber << endl;
    fileOut << CCCD;
}
