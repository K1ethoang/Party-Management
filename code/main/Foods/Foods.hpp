#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "NodeF.hpp"
#include "Food.hpp"
#include "conio.h"
#include "../program/pressAnykey.hpp"
using namespace std;

// FoodsCDLL
class FoodsCDLL
{
private:
    NodeF *head;
    NodeF *tail;
    long size;

public:
    FoodsCDLL();
    ~FoodsCDLL();
    void setHead(NodeF *_head);
    NodeF *getHead();
    void setTail(NodeF *_tail);
    NodeF *getTail();
    void setSize(const long &_size);
    long getSize();
    void addLast(const NodeF &_value);
    void importFood(const string &fileInPath);
    void display();
    vector<ItemF> chooseMenu();
};

// Hàm ngoài
void displayListMenu(vector<ItemF> _menu);
void getFoods2Vector(vector<ItemF> &_menu, Queue<ItemF> *_foods);

// FoodsCDLL
FoodsCDLL::FoodsCDLL()
{
    head = tail = NULL;
    size = 0;
}

FoodsCDLL::~FoodsCDLL()
{
    NodeF *t = head;
    for (long i = 0; i < size; i++)
    {
        delete t;
        t = t->next;
        size--;
    }
}

void FoodsCDLL::setHead(NodeF *_head)
{
    head = _head;
}

NodeF *FoodsCDLL::getHead()
{
    return head;
}

void FoodsCDLL::setTail(NodeF *_tail)
{
    tail = _tail;
}

NodeF *FoodsCDLL::getTail()
{
    return tail;
}

void FoodsCDLL::setSize(const long &_size)
{
    size = _size;
}

long FoodsCDLL::getSize()
{
    return size;
}

void FoodsCDLL::addLast(const NodeF &_value)
{
    NodeF *n = new NodeF(_value.typeFood, _value.data);
    if (size == 0)
    {
        head = tail = n;
        head->next = tail;
        head->prev = tail;
        tail->next = head;
        tail->prev = head;
    }
    else
    {
        n->next = head;
        n->prev = tail;
        tail->next = n;
        tail = n;
        head->prev = tail;
    }
    size++;
}

void FoodsCDLL::importFood(const string &fileInPath)
{
    ifstream fileIn(fileInPath);
    string _typeFood, _name, _newLine;
    ItemF _food;
    NodeF _data;
    long _price;
    getline(fileIn, _typeFood); // đọc kiêu food
    _data.typeFood = _typeFood;
    Queue<ItemF> *_foods = new Queue<ItemF>;
    while (!fileIn.eof()) // con trỏ chỉ vị chưa tới cuối
    {
        getline(fileIn, _name, '-'); // đọc tên của food
        fileIn >> _price;            // đọc giá của food
        getline(fileIn, _newLine);   // đọc kí tự enter
        _food.setName(_name);
        _food.setPrice(_price);
        _foods->push(_food);
    }
    _data.data = _foods;
    addLast(_data);
    fileIn.close();
}

void FoodsCDLL::display()
{
    if (size == 0)
        return;
    NodeF *t = head;
    for (long i = 0; i < size; i++)
    {
        t->displayANode();
        t = t->next;
    }
}

vector<ItemF> FoodsCDLL::chooseMenu()
{
    vector<ItemF> menu;
    if (size == 0)
    {
        cout << "\n\t\t\t\t\t\t(!) Danh sach thuc don trong (!)\n";
        return menu;
    }
    int currentPage = 1;
    char keyPress;
    do
    {
        int _choose;
        system("cls");
        head->displayANode();
        cout << endl;
        // cout << "\t\t+=================================================================================+" << endl;
        // cout << "\t\t                                                                    +=============+" << endl;
        // cout << "\t\t                                                                |     <- 2 ->     |" << endl
        cout << "\n\t\t- SPACE de chon mon                                                    <-  " << setiosflags(ios::left) << currentPage << "/" << setw(2) << size << " ->   " << endl;
        cout << "\n\t\t- TAB de xem menu da chon                                                           " << endl;
        cout << "\n\t\t- Nhan phim \"s\" de luu menu                                                       " << endl;
        cout << "\n\t\t- DEL de xoa mon trong menu da chon                                                 " << endl;
        cout << "\n\t\t- ESC de thoat                                                                      " << endl;
        // cout << "\t\t                                                                    +=============+" << endl;
        fflush(stdin);
        keyPress = getch();
        switch (keyPress)
        {
        case RIGHT_ARROW_ASCII:
        {
            if (currentPage == size)
                currentPage = 1;
            else
                currentPage++;
            head = head->next;
            break;
        }
        case LEFT_ARROW_ASCII:
        {
            if (currentPage == 1)
                currentPage = size;
            else
                currentPage--;
            head = head->prev;
            break;
        }
        case SPACE_ASCII:
        {
            vector<ItemF> _foods;
            getFoods2Vector(_foods, head->data);
            cout << "\n\t\t\t\t\t\tNhap STT de chon mon an: ";
            cin >> _choose;
            if (_choose > 0 && _choose <= _foods.size())
            {
                menu.push_back(_foods[_choose - 1]);
                cout << "\n\t\t\t\t\t\t</> Chon mon an thanh cong </>" << endl;
                cout << _foods[_choose - 1];
            }
            else
                cout << "\n\t\t\t\t\t\t(!) Khong the chon mon an (!)" << endl;
            pressAnyKey();
            _foods.clear();
            break;
        }
        case TAB_ASCII:
        {
            system("cls");
            displayListMenu(menu);
            pressAnyKey();
            break;
        }
        case 's':
        {
            cout << "\n\t\t\t\t\t\t</> Luu thanh cong </>" << endl;
            pressAnyKey();
            return menu;
            break;
        }
        case DEL_ASCII:
        {
            system("cls");
            displayListMenu(menu);
            cout << "\n\t\t\t\t\t\tNhap STT de xoa mon an: ";
            cin >> _choose;
            if (_choose > 0 && _choose <= menu.size())
            {
                ItemF _food = menu[_choose - 1];
                menu.erase(menu.begin() + _choose - 1);
                cout << "\n\t\t\t\t\t\t</> Xoa thanh cong </>" << endl;
                cout << _food << endl;
            }
            else
                cout << "\n\t\t\t\t\t\t(!) Khong the xoa mon an (!)" << endl;
            pressAnyKey();
            break;
        }
        case ESC_ASCII:
        {
            menu.clear();
            break;
        }
        }
    } while (keyPress != ESC_ASCII);
    return menu;
}

void displayListMenu(vector<ItemF> _menu)
{
    for (int i = 0; i < _menu.size(); i++)
        cout << "\n\t\t\t\t\t" << i + 1 << "   " << _menu[i].getName() << "  " << _menu[i].getPrice() << endl;
}

void getFoods2Vector(vector<ItemF> &_menu, Queue<ItemF> *_foods)
{
    Node<ItemF> *head = _foods->getFront();
    for (int i = 0; i < _foods->sizeOf(); i++)
    {
        _menu.push_back(head->data);
        head = head->pNext;
    }
}
