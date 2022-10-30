#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include "string.h"
#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct food
{
    string foodName;
    long foodPrice;
};

struct TypeFood
{
    string nameTypefood;
    vector<food> listFood;
};

void DocFileDoUong(TypeFood &_tf, food &_food)
{
    ifstream filein;
    filein.open("../../data/Thuc-Don/DoUong.txt");
    getline(filein, _tf.nameTypefood); // đọc kiêu food
    string d;
    while (filein.eof() == false) // con trỏ chỉ vị chưa tới cuối
    {

        getline(filein, _food.foodName, '-'); // đọc tên của food
        filein >> _food.foodPrice;            // đọc giá của food
        getline(filein, d);                   // đọc kí tự enter
        _tf.listFood.push_back(_food);
    }
    filein.close();
}
void DocFileKhaiVi(TypeFood &_tf2, food &_food2)
{
    ifstream filein;
    filein.open("../../data/Thuc-Don/TrangMieng.txt");
    getline(filein, _tf2.nameTypefood); // đọc kiêu food
    string d;
    while (filein.eof() == false) // con trỏ chỉ vị chưa tới cuối
    {

        getline(filein, _food2.foodName, '-'); // đọc tên của food
        filein >> _food2.foodPrice;            // đọc giá của food
        getline(filein, d);                    // đọc kí tự enter
        _tf2.listFood.push_back(_food2);
    }
    filein.close();
}
