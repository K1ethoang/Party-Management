#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include "string.h"
#include <bits/stdc++.h>
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

// struct food
// {
//     string name;
//     long price;
// };

// struct TypeFood
// {
//     string nameTypefood;
//     vector<food> listFood;
// };

// void DocFileDoUong(TypeFood &_tf, food &_food)
// {
//     ifstream filein;
//     filein.open("../../data/Thuc-Don/DoUong.txt");
//     getline(filein, _tf.nameTypefood); // đọc kiêu food
//     string d;
//     while (filein.eof() == false) // con trỏ chỉ vị chưa tới cuối
//     {

//         getline(filein, _food.name, '-'); // đọc tên của food
//         filein >> _food.price;            // đọc giá của food
//         getline(filein, d);               // đọc kí tự enter
//         _tf.listFood.push_back(_food);
//     }
//     filein.close();
// }

// void DocFileKhaiVi(TypeFood &_tf2, food &_food2)
// {
//     ifstream filein;
//     filein.open("../../data/Thuc-Don/TrangMieng.txt");
//     getline(filein, _tf2.nameTypefood); // đọc kiêu food
//     string d;
//     while (filein.eof() == false) // con trỏ chỉ vị chưa tới cuối
//     {

//         getline(filein, _food2.name, '-'); // đọc tên của food
//         filein >> _food2.price;            // đọc giá của food
//         getline(filein, d);                // đọc kí tự enter
//         _tf2.listFood.push_back(_food2);
//     }
//     filein.close();
// }
