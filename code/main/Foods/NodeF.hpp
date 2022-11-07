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
    cout << "\t\t+=================================================================================+" << endl;
    cout << "\t\t|                                                                                 |" << endl;
    // cout << "\t\t|                                   Do Uong                                       |" << endl;
    cout << "\t\t|                                   " << setiosflags(ios::left) << setw(46) << typeFood << "|" << endl;
    cout << "\t\t|                                                                                 |" << endl;
    cout << "\t\t+=================================================================================+" << endl;
    cout << "\t\t|                                                                                 |" << endl;
    cout << "\t\t|     STT        MON AN                                            GIA            |" << endl;
    cout << "\t\t|                                                                                 |" << endl;
    // cout << "\t\t|       1.                                                      30000000  Vnd     |" << endl;

    // cout << "\n\t\t\t" << typeFood << endl;
    Node<ItemF> *t = data->getFront();
    for (int i = 0; i < data->sizeOf(); i++)
    {
        cout << "\t\t|      " << setiosflags(ios::left) << setw(10) << i + 1 << setw(48) << t->data.getName() << "  " << setw(9) << t->data.getPrice() << "VND   |" << endl;
        t = t->pNext;
    }
    cout << "\t\t|                                                                                 |" << endl;
    cout << "\t\t+=================================================================================+" << endl;
}
