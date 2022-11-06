#pragma once
#include <iostream>
#include <string>
#include "./Food.hpp"
using namespace std;

// NodeF
class NodeF
{
public:
    string typeFood;
    Queue<ItemF> *data;
    NodeF *prev;
    NodeF *next;
    NodeF();
    NodeF(const string &_typeFood, Queue<ItemF> *_ptr);
    void displayANode();
};

// NodeF
NodeF::NodeF()
{
    typeFood = "";
    data = NULL;
    prev = next = NULL;
}

NodeF::NodeF(const string &_typeFood, Queue<ItemF> *_ptr)
{
    typeFood = _typeFood;
    data = _ptr;
    prev = next = NULL;
}

void NodeF::displayANode()
{
    cout << "\n\t\t\t" << typeFood << endl;
    Node<ItemF> *t = data->getFront();
    for (int i = 0; i < data->sizeOf(); i++)
    {
        cout << i + 1 << ". " << t->data.getName() << "   " << t->data.getPrice() << endl;
        t = t->pNext;
    }
}
