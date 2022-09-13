#pragma once
#include <iostream>
using namespace std;

class Party
{
private:
    long id;          // ID cua buoi tiec
    int tableNumber;  // So ban cua buoi tiec
    int dd, mm, yyyy; // Thoi gian to chuc buoi tiec
public:
    void Input();
    void Output();
    Party();
    ~Party();
    long getID();
    void setID(const long &_id);
};

void Party::Input()
{
    cout << " Nhap ID cua buoi tiec: ";
    cin >> id; // ID cua buoi tiec
    cout << " Nhap so ban cua buoi tiec: ";
    cin >> tableNumber; // So ban cua buoi tiec
    cout << " Nhap thoi gian to chuc tiec: ";
    cin >> dd >> mm >> yyyy; // Thoi gian to chuc buoi tiec
}

void Party::Output()
{
    cout << " ID cua buoi tiec: " << id << endl;
    cout << " So ban: " << tableNumber << endl;
    cout << " Thoi gian dat tiec: " << dd << "/" << mm << "/" << yyyy;
}

void Party::setID(const long &_id)
{
    id = _id;
}

long Party::getID()
{
    return id;
}
