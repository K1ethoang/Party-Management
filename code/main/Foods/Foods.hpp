#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "./Food.hpp"
using namespace std;

typedef Food ItemF;

// NodeF
class NodeF
{
public:
    ItemF data;
    NodeF *prev;
    NodeF *next;
    NodeF();
    NodeF(const ItemF &_value);
};

// FoodsDLL
class FoodsDLL
{
private:
    NodeF *head;
    NodeF *tail;
    long size;

public:
    FoodsDLL();
    ~FoodsDLL();
    void setHead(NodeF *_head);
    NodeF *getHead();
    void setTail(NodeF *_tail);
    NodeF *getTail();
    void setSize(const long &_size);
    long getSize();
    void addLast(const ItemF &value);
    void importFood(const string &fileInPath);
    void display();
};

// NodeF
NodeF::NodeF()
{
    prev = next = NULL;
}

NodeF::NodeF(const ItemF &_value)
{
    data = _value;
    prev = next = NULL;
}

// FoodsDLL
FoodsDLL::FoodsDLL()
{
    head = tail = NULL;
    size = 0;
}

FoodsDLL::~FoodsDLL()
{
    NodeF *t = head;
    for (long i = 0; i < size; i++)
    {
        delete t;
        t = t->next;
        size--;
    }
}

void FoodsDLL::setHead(NodeF *_head)
{
    head = _head;
}

NodeF *FoodsDLL::getHead()
{
    return head;
}

void FoodsDLL::setTail(NodeF *_tail)
{
    tail = _tail;
}

NodeF *FoodsDLL::getTail()
{
    return tail;
}
void FoodsDLL::setSize(const long &_size)
{
    size = _size;
}

long FoodsDLL::getSize()
{
    return size;
}

void FoodsDLL::addLast(const ItemF &value)
{
    NodeF *n = new NodeF(value);
    if (size == 0)
        head = tail = n;
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

void FoodsDLL::importFood(const string &fileInPath)
{
    ifstream fileIn(fileInPath);
    string _typeName, _name, _newLine;
    ItemF _food;
    long _price;
    getline(fileIn, _typeName);   // đọc kiêu food
    while (fileIn.eof() == false) // con trỏ chỉ vị chưa tới cuối
    {
        getline(fileIn, _name, '-'); // đọc tên của food
        fileIn >> _price;            // đọc giá của food
        getline(fileIn, _newLine);   // đọc kí tự enter
        _food.setName(_name);
        _food.setPrice(_price);
        addLast(_food);
    }
    fileIn.close();
}

void FoodsDLL::display()
{
    if (size == 0)
        return;
    NodeF *t = head;
    for (long i = 0; i < size; i++)
    {
        cout << t->data.getName() << " " << t->data.getPrice() << endl;
        t = t->next;
    }
}
