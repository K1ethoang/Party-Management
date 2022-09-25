#pragma once
#include <iostream>
#include "Customer.hpp"
using namespace std;

struct Node
{
    Customer data;
    Node *pNext;
};

typedef Customer Item;

class Customers
{
private:
    Node *Head;
    Node *Tail;
    long Size;

public:
    Customers();
    ~Customers(); // hàm hủy
    Node *createNode(const Item &val);
    void addLast(const Item &val);
    void removeFirst();
    void removeLast();
    void remove(const long &id);
};

Customers::Customers()
{
    Head = Tail = NULL;
    Size = 0;
}
Customers::~Customers() // duyệt qua từng phần tử để giải phóng
{
    Node *t = NULL;
    while (Head != NULL)
    {
        t = Head;
        Head = Head->pNext;
        delete t;
    }
    Size = 0;
}

Node *Customers::createNode(const Item &val)
{
    Node *node = new Node;
    node->data = val;
    node->pNext = NULL;
    return node;
}

void Customers::addLast(const Item &val)
{
    Node *p = createNode(val);
    if (Head == NULL)
    {
        Head = p;
        Tail = p;
    }
    else
    {
        Tail->pNext = p;
        Tail = p;
    }
    Size++;
}

void Customers::removeFirst()
{

    if (Head == NULL)
    {
        return;
    }

    Node *l = Head;     // node l là node sẽ xóa
    Head = Head->pNext; // cập nhật lại head là phần tử tiếp theo
    delete l;
    Size--;
}

void Customers::removeLast()
{
    if (Head == NULL)
    {
        return;
    }
    for (Node *i = Head; i != NULL; i = i->pNext)
    {
        // phát hiện kế cuối
        if (i->pNext == Tail)
        {
            delete Tail;     // xóa phần tử cuối
            i->pNext = NULL; // cho con trỏ kế cuối trỏ đến NULL
            Tail = i;        // cập nhật lại kế cuối là tail
            Size--;
            return;
        }
    }
}

void Customers::remove(const long &id)
{

    if (Head->data.getIdOfParty() == id)
    {
        removeFirst();
    }
    else if (Tail->data.getIdOfParty() == id)
    {
        removeLast();
    }
    else
    {
        Node *m = new Node;
        for (Node *k = Head; k != NULL; k = k->pNext)
        {
            // phát hiện ra phần tử cần xóa
            if (k->data.getIdOfParty() == id)
            {
                Node *g = k;
                m->pNext = k->pNext;
                delete g;
                Size--;
                return;
            }
            m = k;
        }
    }
}
