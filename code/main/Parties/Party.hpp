#pragma once
#include <iostream>
#include <fstream>
#include "time.h"
#include "string.h"
using namespace std;

const string coming_Soon = "Sắp tới";
const string going_On = "Ðang diễn ra ";
const string Accomplished = "Ðã hoàn thành";

struct Date
{
    int dd, mm, yyyy;

};

class Party {
    private:
        string typeParty;
        long id;                                                         // ID cua buoi tiec 
        int tableNumber;                                                 // So ban cua buoi tiec
        Date date;                                                       // Thoi gian to chuc buoi tiec
        string status;                                          
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

        void setStatus();
        string getStatus();


        friend istream &operator>>(istream &is, Party &p);
        friend ostream &operator<<(ostream &os, Party &p); 
};

Party::Party(){
    typeParty = "UNKNOWN";
    id = -1;
    tableNumber = -1;
    date.dd = 0;
    date.mm = 0;
    date.yyyy = 0;
}
Party::~Party(){

}


// Khởi tạo các hàm thuộc tính
void Party::setID(const long &_id)
{
    if(id > 0)
    {
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
}



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
    if(month<1 || month>12)
	{
		return 0;
	}
	while (month>=1 && month <=12)
	{
		switch (month)
		{
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				if(day <1 || day >31)
				{
					return 0;
				}
				break; 
			case 4: case 6: case 9: case 11:
				if(day <1 || day >30)
				{
					return 0;
				}
				break; 
			case 2:
				if(year % 4 ==0  || year % 400 ==0)
				{
					if(day <1 || day >29)	
					{
						return 0;
					}
				} 
				else 
				{
					if(day <1 || day >28)	
					{
						return 0;
					}
				}
		}
		break;
	}
    return 1;
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



void Party::setStatus()
{
    time_t now=time(0);
	tm *tgian = localtime(&now);
    cout << tgian->tm_year+1900;
	// kh.tg.ngay = tgian->tm_mday;
	// kh.tg.thang = tgian->tm_mon + 1;
	// kh.tg.nam = tgian->tm_year + 1900 ; 
	// kh.tg.gio = tgian->tm_hour ; 
	// kh.tg.phut = tgian->tm_min;
	// kh.tg.giay = tgian->tm_sec;	
    if((date.yyyy < tgian->tm_year+1900) || ((date.yyyy == tgian->tm_year+1900) && (date.mm < tgian->tm_mon+1)) || ((date.yyyy == tgian->tm_year+1900) && (date.mm == tgian->tm_mon+1) && (date.dd < tgian->tm_mday)))
    {
        status = Accomplished;
    }
    else if(date.yyyy == tgian->tm_year+1900 && date.mm == tgian->tm_mon+1 && date.dd == tgian->tm_mday)
    {
        status = going_On;
    }
    else
    {
        status = coming_Soon;
    }
}
string Party::getStatus()
{
    return status;
}


istream& operator >> (istream &is, Party &p){
    p.set_TypeParty();
    // cout << "Nhap ID cua buoi tiec: ";
    // is >> p.id; // ID cua buoi tiec
    cout << "Nhap so ban cua buoi tiec: ";
    is >> p.tableNumber; // So ban cua buoi tiec
    cout << "Nhap thoi gian to chuc tiec " << endl;
    inputDate(p.date); // Thoi gian to chuc buoi tiec
    
    p.setStatus();
    return is;
}
ostream& operator << (ostream &os, Party &p){
    os << "Loai tiec: " << p.typeParty << endl;;
    os<< "ID cua buoi tiec: " << p.id << endl;
    os << "So ban: " << p.tableNumber << endl;
    os << "Thoi gian dat tiec: " << p.date.dd << "/" << p.date.mm << "/" << p.date.yyyy << endl;
    os << "Trang thai cua buoi tiec: " << p.status << endl;
    return os;
}




