#pragma once
#include <iostream>
using namespace std;

class Person
{
protected:
    string fullName;
    string phoneNumber;
    string CCCD;

public:
    virtual string getFullName() = 0;
    virtual void setFullName(const string &_fullName) = 0;
    virtual string getPhoneNumber() = 0;
    virtual void setPhoneNumber(const string &_phoneNumber) = 0;
    virtual string getCCCD() = 0;
    virtual void setCCCD(const string &_CCCD) = 0;
};
