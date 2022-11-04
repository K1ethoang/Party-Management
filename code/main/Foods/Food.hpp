#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Food
{
private:
    string name;
    float price;

public:
    Food();
    Food(const string &_name, const float &_price);
    ~Food();
    void setName(const string &_name);
    string getName();
    void setPrice(const float &_price);
    float getPrice();
    friend istream &operator>>(istream &is, Food &_food);
    friend ostream &operator<<(ostream &os, Food _food);
};

Food::Food()
{
    name = "empty";
    price = -1;
}

Food::Food(const string &_name, const float &_price)
    : name(_name), price(_price) {}

Food::~Food() {}

void Food::setName(const string &_name)
{
    name = _name;
}

string Food::getName()
{
    return name;
}

void Food::setPrice(const float &_price)
{
    price = _price;
}

float Food::getPrice()
{
    return price;
}

istream &operator>>(istream &is, Food &_food)
{
    cout << "\n\t\tNhap ten mon an: ";
    fflush(stdin);
    getline(is, _food.name);
    cout << "\n\t\tNhap gia tien: ";
    is >> _food.price;
    return is;
}

ostream &operator<<(ostream &os, Food _food)
{
    os << "\n\t\tMon an: " << _food.name << endl;
    os << "\n\t\tGia tien: " << _food.price << endl;
    return os;
}
