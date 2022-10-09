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
    filein.open("C:\\Users\\tranh\\Documents\\BIAIAPLON\\Party-Management\\code\\data\\Thuc-Don\\DoUong.txt");
    getline(filein, _tf.nameTypefood);          // đọc kiêu food
    string d;
    while(filein.eof() == false)                // con trỏ chỉ vị chưa tới cuối
    { 
        
        getline(filein, _food.foodName, '-');   // đọc tên của food
        filein >> _food.foodPrice;              // đọc giá của food
        getline(filein, d);                     // đọc kí tự enter
        _tf.listFood.push_back(_food);
    }
    filein.close();
}
void DocFileKhaiVi(TypeFood &_tf2, food &_food2)
{   
    ifstream filein;
    filein.open("C:\\Users\\tranh\\Documents\\BIAIAPLON\\Party-Management\\code\\data\\Thuc-Don\\TrangMieng.txt");
    getline(filein, _tf2.nameTypefood);          // đọc kiêu food
    string d;
    while(filein.eof() == false)                // con trỏ chỉ vị chưa tới cuối
    { 
        
        getline(filein, _food2.foodName, '-');   // đọc tên của food
        filein >> _food2.foodPrice;              // đọc giá của food
        getline(filein, d);                     // đọc kí tự enter
        _tf2.listFood.push_back(_food2);
    }
    filein.close();
}

// class Food{
//     private:
//         string foodName;    // Tên món an
//         long foodPrice;
//     public:
//         string getfoodName(string &_foodName);
//         long getfoodPrice(long &_foodPrice);
//         Food();
//         Food(string _nameFood, long _foodPrice);
//         ~Food();
//         friend istream &operator>>(istream &is, Food &f);
//         friend ostream &operator<<(ostream &os, Food f);
// };

// string Food::getfoodName(string &_foodName){
//     foodName = _foodName;
//     return foodName;
// };

// long Food::getfoodPrice(long &_foodPrice){
//     foodPrice = _foodPrice;
//     return foodPrice;
// };
// Food::Food(){
//     foodName = "UNKNOWN";
//     foodPrice = 0;
// };
// Food::Food(string _nameFood, long _foodPrice){
//     foodName = _nameFood;
//     foodPrice = _foodPrice;
// };
// Food::~Food(){};

// istream &operator>>(istream &is, Food &f){
//     cout << "Nhap mon an them: ";  fflush(stdin);
//     getline(is, f.foodName);
//     cout << "Gia mon an: " ; 
//     is >> f.foodPrice;

//     return is;
    
// }
// ostream &operator<<(ostream &os, Food f){
//     // os << "\n\t\t|   " << setiosflags(ios:: left) << setw(6) << i <<"|" ;
//     // os << "Mon an: " << f.foodName << endl;
//     // os << "gia: " << f.foodPrice << endl;

//     os << "     "  <<setw(63) << f.foodName <<"|" << "        "  <<setw(14) << f.foodPrice << "|";

//     return os;
// }