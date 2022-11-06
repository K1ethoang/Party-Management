#pragma once
#include <iostream>
using namespace std;

class Person
{
protected:
    string fullName;
    string phoneNumber;
    string identityCard;

public:
    virtual string getFullName() = 0;
    virtual void setFullName(const string &_fullName) = 0;
    virtual string getPhoneNumber() = 0;
    virtual void setPhoneNumber(const string &_phoneNumber) = 0;
    virtual string getIdentityCard() = 0;
    virtual void setIdentityCard(const string &_identityCard) = 0;
};
