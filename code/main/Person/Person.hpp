#pragma once
#include <iostream>
using namespace std;

class Person
{
protected:
    string fullName;
    string phoneNumber;
    string address;

public:
    virtual string getFullName() = 0;
    virtual void setFullName(const string &_fullName) = 0;
    virtual string getPhoneNumber() = 0;
    virtual void setPhoneNumber(const string &_phoneNumber) = 0;
    virtual string getAddress() = 0;
    virtual void setAddress(const string &_address) = 0;
};
