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
        long id;                                                         // ID cua buoi tiec 
        int tableNumber;                                                 // So ban cua buoi tiec
        Date date;                                            // Thoi gian to chuc buoi tiec
    public:
        Party();
        ~Party();

        void setID(const long &_id);
        long getID();
        
        void setDate(const Date &_date);
        Date getDate();
        void settableNumber(const int &_tableNumber);
        int gettableNumber(); 
        friend istream& operator >> (istream &, Party &);
        friend ostream& operator >> (ostream &, Party &);
        void Input();
        void Output();
};

Party::Party(){

}

Party::~Party(){

}

// Khởi tạo các hàm thuộc tính
void Party::setID(const long &_id)
{
    id = _id;
}

long Party::getID()
{
    return id;
}

void Party::settableNumber(const int &_tableNumber){
    tableNumber = _tableNumber;
}


int Party::gettableNumber(){
    return  tableNumber;
};


void Party::setDate(const Date &_date){
    date.dd = _date.dd;
    date.mm = _date.mm;
    date.yyyy = _date.yyyy;
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

void Party::Input()
{
    cout << "Nhap ID cua buoi tiec: ";
    cin >> id; // ID cua buoi tiec
    cout << "Nhap so ban cua buoi tiec: ";
    cin >> tableNumber; // So ban cua buoi tiec
    cout << "Nhap thoi gian to chuc tiec " << endl;
    inputDate(date); // Thoi gian to chuc buoi tiec
}

void Party::Output()
{
    cout << "ID cua buoi tiec: " << id << endl;
    cout << "So ban: " << tableNumber << endl;
    cout << "Thoi gian dat tiec: " << date.dd << "/" << date.mm << "/" << date.yyyy;
}
