#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Date
{
    int dd, mm, yyyy;
};

class Party {
    private:
        string typeParty;
        long id;                                                         // ID cua buoi tiec 
        int tableNumber;                                                 // So ban cua buoi tiec
        Date date;                                            // Thoi gian to chuc buoi tiec
    public:
        Party();
        ~Party();

        void set_TypeParty();
        string get_TypeParty();

        void setID(const long &_id);
        long getID();

        void setDate(const Date &_date);
        Date getDate();
        void setDate(const int &_day, const int &_month, const int &_year);

        void setTableNumber(const int &_tableNumber);
        int getTableNumber(); 

        friend istream& operator >> (istream &, Party &);
        friend ostream& operator << (ostream &, Party &);
};

Party::Party(){

}
Party::~Party(){

}

// Khởi tạo các hàm thuộc tính
void Party::setID(const long &_id)
{
    if(id > 0){
        id = _id;
    }
}
long Party::getID()
{
    return id;
}


void Party::setTableNumber(const int &_tableNumber){
    tableNumber = _tableNumber;
}
int Party::getTableNumber(){
    return  tableNumber;
};


void Party::setDate(const Date &_date){
    date.dd = _date.dd;
    date.mm = _date.mm;
    date.yyyy = _date.yyyy;
}
void Party::setDate(const int &_day, const int &_month, const int &_year){
    date.dd = _day;
    date.mm = _month;
    date.yyyy = _year;
}
Date Party::getDate(){
    return date;
}


bool isValidDate(int day, int month, int year) // kiểm tra ngày nhập
{
    if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > 31 || year >= 2022)
        return 0;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day <= 31)
            return 1;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day <= 30)
            return 1;
    }
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        if (day <= 29)
            return 1;
    }
    else
    {
        if (day <= 28)
            return 1;
    }
    return 0;
}
void inputDate(Date &date)
{
    do
    {
        cout << "Nhap ngay: ";
        cin >> date.dd;
        cout << "Nhap thang: ";
        cin >> date.mm;
        cout << "Nhap nam: ";
        cin >> date.yyyy;
        if (!isValidDate(date.dd, date.mm, date.yyyy))
            printf("\n\t%40c(!) Ngay sinh khong hop le - Nhap lai (!)\n\a", ' ');
    }while (!isValidDate(date.dd, date.mm, date.yyyy));
}

void Party::set_TypeParty(){
    int select;
    string _typeParty[6] = {"tiec tra", "tiec cuoi", "tiec sinh nhat", "tiec buffet", "tiec set menu"};
    cout << "-----------LOAI TIEC-----------" << endl;
    cout << "1. Tiec tra" << endl;
    cout << "2. Tiec cuoi" << endl;
    cout << "3. Tiec sinh nhat" << endl;
    cout << "4. Tiec ruou" << endl;
    cout << "5. Tiec Buffet" << endl;
    cout << "6. Tiec Set Menu" << endl;

    cout << "SELECT: "; cin >> select;

    for(int i=0; i<6; i++){
        if(select == i+1){
            typeParty = _typeParty[i];
            break;
        }
    }
    cout << "Loai tiec ban vua chon: " << typeParty << endl;;
}
string Party::get_TypeParty(){
    return typeParty;
}


istream& operator >> (istream &is, Party &p){
    p.set_TypeParty();
    cout << "Nhap ID cua buoi tiec: ";
    is >> p.id; // ID cua buoi tiec
    cout << "Nhap so ban cua buoi tiec: ";
    is >> p.tableNumber; // So ban cua buoi tiec
    cout << "Nhap thoi gian to chuc tiec " << endl;
    inputDate(p.date); // Thoi gian to chuc buoi tiec
    return is;
}
ostream& operator << (ostream &os, Party &p){
    os << "Loai tiec: " << p.typeParty << endl;;
    os<< "ID cua buoi tiec: " << p.id << endl;
    os << "So ban: " << p.tableNumber << endl;
    os << "Thoi gian dat tiec: " << p.date.dd << "/" << p.date.mm << "/" << p.date.yyyy;
    return os;
}
