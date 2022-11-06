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
    Customer(const string &_fullName, const string &_phoneNumber, const string &_identityCard);
    ~Customer();
    string getFullName();
    void setFullName(const string &_fullName);
    string getPhoneNumber();
    void setPhoneNumber(const string &_phoneNumber);
    string getIdentityCard();
    void setIdentityCard(const string &_identityCard);
    void outputCustomer();
    friend istream &operator>>(istream &is, Customer &c);
    friend ostream &operator<<(ostream &os, Customer c);
    void readACustomer(ifstream &fileIn);
    void writeACustomer(ofstream &fileOut);
};

typedef Customer ItemC;

// hàm ngoài
bool isValidPhoneNumber(const string &_phoneNumber);
bool isValidIdentityCard(const string &_identityCard);

// hàm ngoài
bool isValidPhoneNumber(const string &_phoneNumber)
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
bool isValidIdentityCard(const string &_identityCard)
{
    bool isValid = false;
    int lengthIdentityCard = _identityCard.length();
    if (lengthIdentityCard == 12)
    {
        for (int i = 0; i < lengthIdentityCard; i++)
        {
            if (_identityCard[i] - 48 >= 0 && _identityCard[i] - 48 <= 9)
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
    identityCard = "123456789012";
}

Customer::Customer(const string &_fullName, const string &_phoneNumber, const string &_identityCard)
{
    fullName = _fullName;
    setPhoneNumber(_phoneNumber);
    identityCard = _identityCard;
}

Customer::~Customer() {}

string Customer::getFullName()
{
    return fullName;
}

void Customer::setFullName(const string &_fullName)
{
    // formatName(fullName);
    fullName = _fullName;
}

string Customer::getPhoneNumber()
{
    return phoneNumber;
}

void Customer::setPhoneNumber(const string &_phoneNumber)
{
    phoneNumber = _phoneNumber;
}

string Customer::getIdentityCard()
{
    return identityCard;
}

void Customer::setIdentityCard(const string &_identityCard)
{
    identityCard = _identityCard;
}

void Customer::outputCustomer()
{
    cout << "\n\t\t\t\t\t\t> Ho va ten     : " << fullName;
    cout << "\n\t\t\t\t\t\t> So dien thoai : " << phoneNumber;
    cout << "\n\t\t\t\t\t\t> So CCCD       : " << identityCard;
    getID();
}

istream &operator>>(istream &is, Customer &c)
{
    cout << "\n\t\t\t\t\t\tNhap ho va ten: ";
    fflush(stdin);
    getline(is, c.fullName);
    formatName(c.fullName);
    // Nhập sđt và kiểm tra
    do
    {
        cout << "\t\t\t\t\t\tNhap so dien thoai: ";
        getline(is, c.phoneNumber);
        if (!isValidPhoneNumber(c.phoneNumber))
            cout << "\n\t\t\t\t\t\t(!) So dien thoai khong hop le! (!)\n";
    } while (!isValidPhoneNumber(c.phoneNumber));
    // Nhập số identityCard và kiểm tra
    do
    {
        cout << "\t\t\t\t\t\tNhap so CCCD: ";
        getline(is, c.identityCard);
        if (!isValidIdentityCard(c.identityCard))
            cout << "\n\t\t\t\t\t\t(!) So CCCD khong hop le! (!)\n";
    } while (!isValidIdentityCard(c.identityCard));

    return is;
}

ostream &operator<<(ostream &os, Customer c)
{
    cout << "\n\t\t\t" << setiosflags(ios::left) << "|"
         << "        " << setw(10) << c.getID() << "|"
         << "           " << setw(32) << c.getFullName() << "|"
         << "       " << setw(18) << c.getPhoneNumber() << "|"
         << "            " << setw(24) << c.getIdentityCard() << "|";
    cout << "\n\t\t\t+==================+===========================================+=========================+====================================+";
    c.getID();
    return os;
}

void Customer::readACustomer(ifstream &fileIn)
{
    getline(fileIn, fullName);
    getline(fileIn, phoneNumber);
    getline(fileIn, identityCard);
}

void Customer::writeACustomer(ofstream &fileOut)
{
    fileOut << "\n"
            << getID() << endl;
    fileOut << fullName << endl;
    fileOut << phoneNumber << endl;
    fileOut << identityCard;
}
