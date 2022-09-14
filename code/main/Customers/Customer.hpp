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

public:
    friend istream &operator>>(istream &is, Customer &c);
    friend ostream &operator<<(ostream &os, Customer c);
};

istream &operator>>(istream &is, Customer &c)
{
    cout << "\n\t\t-----NHAP THONG TIN KHACH HANG-----\n";
    cout << "\nNhap ho va ten khach hang: ";
    fflush(stdin);
    getline(is, c.fullName);
    do
    {
        cout << "\nNhap so dien thoai khach hang: ";
        getline(is, c.phoneNumber);

    } while (c.phoneNumber.length() != 10);

    return is;
}

ostream &operator<<(ostream &os, Customer c)
{
    cout << "\n\t\t-----THONG TIN KHACH HANG DA NHAP-----\n";
    cout << "\nHo va ten: " << c.fullName;
    cout << "\nSo dien thoai: " << c.phoneNumber;
    return os;
