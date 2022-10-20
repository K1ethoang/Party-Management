#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include "string.h"
using namespace std;

class listFood{
    private:
        string foodName;    // Tên món an
        long foodPrice;
    public:
        string getfoodName(string &_foodName);
        long getfoodPrice(long &_foodPrice);
        listFood();
        listFood(string _nameFood, long _foodPrice);
        ~listFood();
        friend istream &operator>>(istream &is, listFood &f);
        friend ostream &operator<<(ostream &os, listFood f);
};

string listFood::getfoodName(string &_foodName){
    foodName = _foodName;
    return foodName;
};

long listFood::getfoodPrice(long &_foodPrice){
    foodPrice = _foodPrice;
    return foodPrice;
};
listFood::listFood(){
    foodName = "UNKNOWN";
    foodPrice = 0;
};
listFood::listFood(string _nameFood, long _foodPrice){
    foodName = _nameFood;
    foodPrice = _foodPrice;
};
listFood::~listFood(){};

istream &operator>>(istream &is, listFood &f){
    cout << "==========LIST FOOD==========" << endl;
    cout << "Nhap mon an them: ";  fflush(stdin);
    getline(is, f.foodName);
    cout << "Gia mon an: " ; 
    is >> f.foodPrice;

    return is;
    
}
ostream &operator<<(ostream &os, listFood f){
    // os << "\n\t\t|   " << setiosflags(ios:: left) << setw(6) << i <<"|" ;
    // os << "Mon an: " << f.foodName << endl;
    // os << "gia: " << f.foodPrice << endl;

    os << "     "  <<setw(63) << f.foodName <<"|" << "        "  <<setw(14) << f.foodPrice << "|";

    return os;
}