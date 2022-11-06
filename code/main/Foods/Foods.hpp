#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "NodeF.hpp"
#include "Food.hpp"
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
};

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
