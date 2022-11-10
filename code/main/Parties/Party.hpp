#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "time.h"
#include "../Foods/Food.hpp"
#include "../Date/Date.hpp"
#include "../Template/Queue/Queue.hpp"
#include "../constance.hpp"
using namespace std;

// Party
typedef class Party : public ID
{
private:
    Customer customer;    // Thông tin khách hàng
    string typeParty;     // Loại tiệc
    int tableNumber;      // Số bàn tiệc
    Date date;            // Thời gian tổ chức
    int partyStatus;      // Trạng thái tiệc
    bool isPaymentStatus; // Trạng thái thanh toán
    bool isDeposited;     // Đã đặt cọc
    float sumMoney;       // Tiền của buổi tiệc
    vector<ItemF> menu;   // Thực đơn của tiệc

private:
    string returnPartyStatusPrivate();               // Lấy trạng thái dạng tiệc
    string returnPaymentStatus(const bool &_isPaid); // lấy trạng thái thanh toán
    float amountMoneyPartyPrivate();                 // tính tổng tiền

public:
    Party();
    ~Party();
    void setCustomer(const Customer &_customer);
    Customer getCustomer();
    void setTypeParty(const string &typeParties);
    string getTypeParty();
    void setDate(const Date &_date);
    Date getDate();
    void setTableNumber(const int &_tableNumber);
    int getTableNumber();
    void setPartyStatus();
    int getPartyStatus();
    void setIsPaymentStatus(const bool &_isPaymentStatus);
    bool getIsPaymentStatus();
    void setIsDeposited(const bool &_isDeposited);
    bool getIsDeposited();
    void setSumMoney(const float &_sumMoney);
    float getSumMoney();
    void setMenu(vector<ItemF> _menu);
    vector<ItemF> getMenu();

    void outputParty();
    void printBill();      // in hoá đơn
    void seeDetailParty(); // xem chi tiết party
    friend istream &operator>>(istream &is, Party &p);
    friend ostream &operator<<(ostream &os, Party &p);
    void readAParty(ifstream &fileIn);
    void writeAParty(ofstream &fileOut);
    void readAMenu(const string &_fileInPath);
    void writeAMenu(const string &_fileOutPath);
    void writeABill(ofstream &fileOut);
} ItemP;

// Hàm ngoài
vector<string> readTypeParty();
string chooseTypeParty();
// Queue<ItemF> chooseMenu(const FoodsCDLL &foods);

// Hàm ngoài
vector<string> readTypeParty()
{
    vector<string> typeParties;
    ifstream fileIn(TYPE_PARTY_DATA_PATH);
    if (fileIn.is_open())
    {
        while (!fileIn.eof())
        {
            string typeParty;
            getline(fileIn, typeParty);
            typeParties.push_back(typeParty);
        }
    }
    else
        cout << "\nCo loi khi mo file \"loai tiec\"" << endl;
    return typeParties;
}

string chooseTypeParty()
{
    vector<string> typeParties = readTypeParty();
    int select;
    do
    {
        cout << "\n\n\t\t\t\t\t\t __________LOAI TIEC__________ " << endl;
        cout << "\t\t\t\t\t\t|                             |" << endl;
        for (int i = 0; i < typeParties.size(); i++)
        {
            cout << "\t\t\t\t\t\t| " << i + 1 << ". " << setiosflags(ios::left) << setw(25) << typeParties[i] << "|" << endl;
        }
        cout << "\t\t\t\t\t\t|_____________________________|" << endl;
        cout << "\t\t\t\t\t\tLua chon cua ban -> ";
        cin >> select;

        for (int i = 0; i < typeParties.size(); i++)
        {
            if (select == i + 1)
            {
                cout << "\n\t\t\t\t\t\t</> Da chon thanh cong </>" << endl;
                return typeParties[i];
            }
        }
    } while (select < 1 || select > typeParties.size());
    return "";
}

// Queue<ItemF> chooseMenu(const FoodsCDLL &foods)
// {
//     Queue<ItemF> menu;

//     for (int i = 0; i < NUMBER_FOOD_PATH; i++)
//     {
//     }
//     return menu;
// }

// Party
// Private
string Party::returnPartyStatusPrivate()
{
    if (partyStatus > 0)
        return ACCOMPLISHED;
    else if (partyStatus < 0)
        return COMING_SOON;
    return GOING_ON;
}

string Party::returnPaymentStatus(const bool &_isPaid)
{
    return (_isPaid ? PAID : UNPAID);
}

float Party::amountMoneyPartyPrivate()
{
    float _sumMoney = 0;
    if (menu.size() != 0)
    {
        for (int i = 0; i < menu.size(); i++)
            _sumMoney += (menu[i].getPrice() * tableNumber);
    }
    return _sumMoney;
}

// Public
void Party::setSumMoney(const float &_sumMoney)
{
    sumMoney = _sumMoney;
}

float Party::getSumMoney()
{
    return sumMoney;
}

void Party::setCustomer(const Customer &_customer)
{
    customer = _customer;
}

Customer Party::getCustomer()
{
    return customer;
};

Party::Party()
{
    typeParty = "";
    tableNumber = 0;
    partyStatus = -1;
    isPaymentStatus = 0;
    isDeposited = 0;
    sumMoney = 0;
}

Party::~Party()
{
}

void Party::setTableNumber(const int &_tableNumber)
{
    tableNumber = _tableNumber;
    setSumMoney(amountMoneyPartyPrivate());
}

int Party::getTableNumber()
{
    return tableNumber;
}

void Party::setDate(const Date &_date)
{
    date = _date;
}

Date Party::getDate()
{
    return date;
}

void Party::setTypeParty(const string &typeParties)
{
    typeParty = typeParties;
}

string Party::getTypeParty()
{
    return typeParty;
}

void Party::setPartyStatus()
{
    time_t now = time(0);
    tm *tgian = localtime(&now);
    // cout << tgian->tm_year+1900;
    // kh.tg.ngay = tgian->tm_mday;
    // kh.tg.thang = tgian->tm_mon + 1;
    // kh.tg.nam = tgian->tm_year + 1900 ;
    // kh.tg.gio = tgian->tm_hour ;
    // kh.tg.phut = tgian->tm_min;
    // kh.tg.giay = tgian->tm_sec;
    if ((date.getYear() < tgian->tm_year + 1900) || ((date.getYear() == tgian->tm_year + 1900) && (date.getMonth() < tgian->tm_mon + 1)) || ((date.getYear() == tgian->tm_year + 1900) && (date.getMonth() == tgian->tm_mon + 1) && (date.getDay() < tgian->tm_mday)))
    {
        partyStatus = 1;
    }
    else if (date.getYear() == tgian->tm_year + 1900 && date.getMonth() == tgian->tm_mon + 1 && date.getDay() == tgian->tm_mday)
    {
        partyStatus = 0;
    }
    else
    {
        partyStatus = -1;
    }
}

int Party::getPartyStatus()
{
    return partyStatus;
}

void Party::setIsPaymentStatus(const bool &_isPaymentStatus)
{
    isPaymentStatus = _isPaymentStatus;
}

bool Party::getIsPaymentStatus()
{
    return isPaymentStatus;
}

void Party::setIsDeposited(const bool &_isDeposited)
{
    isDeposited = _isDeposited;
}

bool Party::getIsDeposited()
{
    return isDeposited;
}

void Party::setMenu(vector<ItemF> _menu)
{
    menu.clear();
    menu = _menu;
    setSumMoney(amountMoneyPartyPrivate());
}

vector<ItemF> Party::getMenu()
{
    return menu;
}

void Party::outputParty()
{
    cout << "\n\t\t\t\t\t\tID cua tiec          : " << getID() << endl;
    cout << "\t\t\t\t\t\tLoai tiec            : " << typeParty << endl;
    cout << "\t\t\t\t\t\tSo ban cua tiec      : " << tableNumber << endl;
    cout << "\t\t\t\t\t\tThoi gian dat tiec   : ";
    date.outputDate();
    cout << endl;
    cout << "\t\t\t\t\t\tTien                 : " << (sumMoney == 0 ? 0 : (size_t)sumMoney) << " VND" << endl;
    cout << "\t\t\t\t\t\tTrang thai cua tiec  : " << returnPartyStatusPrivate() << endl;
    cout << "\t\t\t\t\t\tThanh toan           : " << returnPaymentStatus(isPaymentStatus) << endl;
}

void Party::printBill()
{
    time_t now = time(0);
    tm *tgian = localtime(&now);
    // kh.tg.ngay = tgian->tm_mday;
    // kh.tg.thang = tgian->tm_mon + 1;
    // kh.tg.nam = tgian->tm_year + 1900 ;
    // kh.tg.gio = tgian->tm_hour ;
    // kh.tg.phut = tgian->tm_min;
    cout << "\t\t\t+==================================>>>HOA DON THANH TOAN<<<==================================+" << endl;
    cout << "\t\t\t|                                                                                            |" << endl;
    cout << "\t\t\t|                                                          " << setiosflags(ios::left) << setw(2) << tgian->tm_mday << "/" << setw(2) << tgian->tm_mon + 1 << "/" << setw(4) << tgian->tm_year + 1900 << "   " << setw(2) << tgian->tm_hour << ":" << setw(18) << tgian->tm_min << "|" << endl;
    cout << "\t\t\t|                                                                                            |" << endl;
    cout << "\t\t\t|    > Ten: " << setiosflags(ios::left) << setw(81) << customer.getFullName() << "|" << endl;
    cout << "\t\t\t|    > SDT: " << setiosflags(ios::left) << setw(81) << customer.getPhoneNumber() << "|" << endl;
    cout << "\t\t\t|    > So CCCD: " << setiosflags(ios::left) << setw(77) << customer.getIdentityCard() << "|" << endl;
    cout << "\t\t\t|                                                                                            |" << endl;
    cout << "\t\t\t|    > ID: " << setiosflags(ios::left) << setw(82) << getID() << "|" << endl;
    cout << "\t\t\t|    > Loai tiec: " << setiosflags(ios::left) << setw(75) << typeParty << "|" << endl;
    cout << "\t\t\t|    > So ban: " << setiosflags(ios::left) << setw(78) << tableNumber << "|" << endl;
    cout << "\t\t\t|    > Thoi gian to chuc: " << setiosflags(ios::left) << setw(2) << date.getDay() << "/" << setw(2) << date.getMonth() << "/" << setw(61) << date.getYear() << "|" << endl;
    cout << "\t\t\t|                                                                                            |" << endl;
    cout << "\t\t\t|    +----------------------------------------------------------------------------------+    |" << endl;
    cout << "\t\t\t|    |   STT  |                      Mon an                      |        Gia ca        |    |" << endl;
    cout << "\t\t\t|    +----------------------------------------------------------------------------------+    |" << endl;
    // for ()
    for (int i = 0; i < menu.size(); i++)
    {
        cout << "\t\t\t|    |   " << setiosflags(ios::left) << setw(5) << i + 1 << "|   " << setw(47) << menu[i].getName() << "|        " << setw(14) << menu[i].getPrice() << "|    |" << endl;
    }

    cout << "\t\t\t|    +----------------------------------------------------------------------------------+    |" << endl;
    cout << "\t\t\t|    |                                                  TONG TIEN:    " << setiosflags(ios::left) << setw(11) << (sumMoney == 0 ? 0 : (size_t)sumMoney) << "VND    |    |" << endl;

    // cout << "\t\t\t|    |            TONG TIEN: " << setiosflags(ios::left) << setw(59) << sumMoney << "|    |" << endl;
    cout << "\t\t\t|    +----------------------------------------------------------------------------------+    |" << endl;
    // cout << "\t\t\t|    |   " << setiosflags(ios::left) << setw(5) << "|"
    //  << "   " << setw(32) << " "
    //  << "|" << endl;
    cout << "\t\t\t|                                                                                            |" << endl;
    cout << "\t\t\t+==================================>>>HOA DON THANH TOAN<<<==================================+" << endl;
    // cout << "name: " << c.getFullName();
    // cout << "sdt: " << c.getPhoneNumber();
    // cout << "ID: " << getID() << endl;
}

void Party::seeDetailParty()
{
    cout << "\t\t\t+==================================>>>HOA DON THANH TOAN<<<==================================+" << endl;
    cout << "\t\t\t|                                                                                            |" << endl;
    cout << "\t\t\t|    > Ten: " << setiosflags(ios::left) << setw(81) << customer.getFullName() << "|" << endl;
    cout << "\t\t\t|    > SDT: " << setiosflags(ios::left) << setw(81) << customer.getPhoneNumber() << "|" << endl;
    cout << "\t\t\t|    > So CCCD: " << setiosflags(ios::left) << setw(77) << customer.getIdentityCard() << "|" << endl;
    cout << "\t\t\t|                                                                                            |" << endl;
    cout << "\t\t\t|    > ID: " << setiosflags(ios::left) << setw(82) << getID() << "|" << endl;
    cout << "\t\t\t|    > Loai tiec: " << setiosflags(ios::left) << setw(75) << typeParty << "|" << endl;
    cout << "\t\t\t|    > So ban: " << setiosflags(ios::left) << setw(78) << tableNumber << "|" << endl;
    cout << "\t\t\t|    > Thoi gian to chuc: " << setiosflags(ios::left) << setw(2) << date.getDay() << "/" << setw(2) << date.getMonth() << "/" << setw(61) << date.getYear() << "|" << endl;
    cout << "\t\t\t|                                                                                            |" << endl;
    cout << "\t\t\t|    +----------------------------------------------------------------------------------+    |" << endl;
    cout << "\t\t\t|    |   STT  |                      Mon an                      |        Gia ca        |    |" << endl;
    cout << "\t\t\t|    +----------------------------------------------------------------------------------+    |" << endl;
    // for ()
    for (int i = 0; i < menu.size(); i++)
    {
        cout << "\t\t\t|    |   " << setiosflags(ios::left) << setw(5) << i + 1 << "|   " << setw(47) << menu[i].getName() << "|        " << setw(14) << menu[i].getPrice() << "|    |" << endl;
    }

    cout << "\t\t\t|    +----------------------------------------------------------------------------------+    |" << endl;
    cout << "\t\t\t|    |                                                  TONG TIEN:    " << setiosflags(ios::left) << setw(11) << (sumMoney == 0 ? 0 : (size_t)sumMoney) << "VND    |    |" << endl;

    cout << "\t\t\t|    +----------------------------------------------------------------------------------+    |" << endl;
    cout << "\t\t\t|                                                                                            |" << endl;
    cout << "\t\t\t+==================================>>>HOA DON THANH TOAN<<<==================================+" << endl;
}

istream &operator>>(istream &is, Party &p)
{
    p.inputID();
    string res = chooseTypeParty();
    p.setTypeParty(res);
    cout << "\n\t\t\t\t\t\tNhap so ban cua buoi tiec: ";
    is >> p.tableNumber;
    cout << "\n\t\t\t\t\t\tNhap thoi gian to chuc tiec:" << endl;
    p.date.inputDate("(!) Ngay thang khong hop le (!)");
    p.setPartyStatus();
    system("pause");
    return is;
}

ostream &operator<<(ostream &os, Party &p)
{
    os << "\n\t\t" << setiosflags(ios::left) << "|"
       << "   " << setw(5) << p.getID() << "|"
       << "   " << setw(2) << p.date.getDay() << "/" << setw(2) << p.date.getMonth() << "/" << setw(6) << p.date.getYear() << "|"
       << "     " << setw(24) << p.customer.getFullName() << "|"
       << "  " << setw(12) << p.customer.getPhoneNumber() << "|"
       << "   " << setw(16) << p.typeParty << "|"
       << "  " << setw(6) << p.tableNumber << "|"
       << "  " << setw(17) << p.returnPartyStatusPrivate() << "|"
       << " " << setw(15) << p.returnPaymentStatus(p.isPaymentStatus) << "|";
    os << "\n\t\t+========+===============+=============================+==============+===================+========+===================+================+";
    // os << "Name: " << p.c.getFullName() << endl;
    return os;
}

void Party::readAParty(ifstream &fileIn)
{
    customer.readACustomer(fileIn);
    setID(customer.getID());
    getline(fileIn, typeParty);
    fileIn >> tableNumber;
    Date _date;
    _date.readDate(fileIn);
    setDate(_date);
    setPartyStatus();
    fileIn >> partyStatus >> isPaymentStatus >> isDeposited;
    fileIn >> sumMoney;
    readAMenu(MENU_SAVER_FOLDER_OF_CUSTOMER_PATH + "/" + to_string(getID()) + ".txt");
}

void Party::writeAParty(ofstream &fileOut)
{
    customer.writeACustomer(fileOut);
    fileOut << endl;
    fileOut << typeParty << endl;
    fileOut << tableNumber << endl;
    date.writeDate(fileOut);
    setPartyStatus();
    fileOut << "\n"
            << partyStatus << " " << isPaymentStatus << " " << isDeposited << endl;
    fileOut << (sumMoney == -1 ? 0 : (size_t)sumMoney);
    writeAMenu(MENU_SAVER_FOLDER_OF_CUSTOMER_PATH + "/" + to_string(getID()) + ".txt");
}

void Party::readAMenu(const string &_fileInPath)
{
    ifstream fileIn(_fileInPath);
    if (fileIn.is_open())
    {
        string nLine, _name;
        float _price;
        ItemF _food;
        getline(fileIn, nLine); // đọc '\n'
        while (!fileIn.eof())   // con trỏ chỉ vị chưa tới cuối
        {
            getline(fileIn, _name, '-'); // đọc tên của food
            fileIn >> _price;            // đọc giá của food
            getline(fileIn, nLine);      // đọc kí tự enter
            _food.setName(_name);
            _food.setPrice(_price);
            menu.push_back(_food);
        }
    }
    fileIn.close();
}

void Party::writeAMenu(const string &_fileOutPath)
{

    ofstream fileOut(_fileOutPath);
    if (fileOut.is_open())
    {
        for (int i = 0; i < menu.size(); i++)
        {
            fileOut << endl;
            fileOut << menu[i].getName() << "-" << menu[i].getPrice();
        }
    }
    fileOut.close();
}

void Party::writeABill(ofstream &fileOut)
{
    time_t now = time(0);
    tm *tgian = localtime(&now);
    // kh.tg.ngay = tgian->tm_mday;
    // kh.tg.thang = tgian->tm_mon + 1;
    // kh.tg.nam = tgian->tm_year + 1900 ;
    // kh.tg.gio = tgian->tm_hour ;
    // kh.tg.phut = tgian->tm_min;
    fileOut << "\t\t\t+==================================>>>HOA DON THANH TOAN<<<==================================+" << endl;
    fileOut << "\t\t\t|                                                                                            |" << endl;
    fileOut << "\t\t\t|                                                          " << setiosflags(ios::left) << setw(2) << tgian->tm_mday << "/" << setw(2) << tgian->tm_mon + 1 << "/" << setw(4) << tgian->tm_year + 1900 << "   " << setw(2) << tgian->tm_hour << ":" << setw(18) << tgian->tm_min << "|" << endl;
    fileOut << "\t\t\t|                                                                                            |" << endl;
    fileOut << "\t\t\t|    > Ten: " << setiosflags(ios::left) << setw(81) << customer.getFullName() << "|" << endl;
    fileOut << "\t\t\t|    > SDT: " << setiosflags(ios::left) << setw(81) << customer.getPhoneNumber() << "|" << endl;
    fileOut << "\t\t\t|    > So CCCD: " << setiosflags(ios::left) << setw(77) << customer.getIdentityCard() << "|" << endl;
    fileOut << "\t\t\t|                                                                                            |" << endl;
    fileOut << "\t\t\t|    > ID: " << setiosflags(ios::left) << setw(82) << getID() << "|" << endl;
    fileOut << "\t\t\t|    > Loai tiec: " << setiosflags(ios::left) << setw(75) << typeParty << "|" << endl;
    fileOut << "\t\t\t|    > So ban: " << setiosflags(ios::left) << setw(78) << tableNumber << "|" << endl;
    fileOut << "\t\t\t|    > Thoi gian to chuc: " << setiosflags(ios::left) << setw(2) << date.getDay() << "/" << setw(2) << date.getMonth() << "/" << setw(61) << date.getYear() << "|" << endl;
    fileOut << "\t\t\t|                                                                                            |" << endl;
    fileOut << "\t\t\t|    +----------------------------------------------------------------------------------+    |" << endl;
    fileOut << "\t\t\t|    |   STT  |                      Mon an                      |        Gia ca        |    |" << endl;
    fileOut << "\t\t\t|    +----------------------------------------------------------------------------------+    |" << endl;
    // for ()
    for (int i = 0; i < menu.size(); i++)
    {
        fileOut << "\t\t\t|    |   " << setiosflags(ios::left) << setw(5) << i + 1 << "|   " << setw(47) << menu[i].getName() << "|        " << setw(14) << menu[i].getPrice() << "|    |" << endl;
    }
    fileOut << "\t\t\t|    +----------------------------------------------------------------------------------+    |" << endl;
    fileOut << "\t\t\t|    |                                                  TONG TIEN:    " << setiosflags(ios::left) << setw(11) << (sumMoney == 0 ? 0 : (size_t)sumMoney) << "VND    |    |" << endl;
    fileOut << "\t\t\t|    +----------------------------------------------------------------------------------+    |" << endl;
    fileOut << "\t\t\t|                                                                                            |" << endl;
    fileOut << "\t\t\t+==================================>>>HOA DON THANH TOAN<<<==================================+" << endl;
}