#pragma once
#include <iostream>
#include <string>
#include "Food.hpp"
#include "Queue.hpp"
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
    NodeF *t = NULL;
    while (head != NULL)
    {
        t = head;
        head = head->next;
        delete t;
    }
    size = 0;
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
    if(size == 0)
    {
        
    }
}
