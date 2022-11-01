#pragma once
#include <iostream>
// #include "Customer.hpp"
using namespace std;
#include "Food.hpp"

struct nodeF
{
    TypeFood fData;
    nodeF *fNext;
};
typedef TypeFood ItemF;

class Foods
{
private:
    /* data */
    nodeF *fHead;
    nodeF *fTail;
    long fSize;

public:
    Foods();
    ~Foods();
    nodeF *getfHead();
    nodeF *getfTail();
    long getfSize();
    nodeF *createnodeF(const ItemF &_fData);
    void addfLast(const ItemF &_fData);
    void removefFirst();
    void removefLast();

    void InputFood();
    void displayFoods();
    // void remove(const long &id);
    // void find(const long &id);
    // void edit(const long &id);
};

Foods::Foods(/* args */)
{
    fHead = fTail = NULL;
    fSize = 0;
}

Foods::~Foods()
{
    nodeF *t = NULL;
    while (fHead != NULL)
    {
        t = fHead;
        fHead = fHead->fNext;
        delete t;
    }
    fSize = 0;
}

nodeF *Foods::getfHead()
{
    return fHead;
}

nodeF *Foods::getfTail()
{
    return fTail;
}

long Foods::getfSize()
{
    return fSize;
}

nodeF *Foods::createnodeF(const ItemF &_fData)
{
    nodeF *p = new nodeF;
    p->fData = _fData;
    p->fNext = NULL;
    return p;
}
void Foods::addfLast(const ItemF &_fData)
{
    nodeF *p = createnodeF(_fData);
    if (fHead == NULL)
    {
        fHead = p;
        fTail = p;
    }
    else
    {
        fTail->fNext = p;
        fTail = p;
    }
    fSize++;
}

void Foods::InputFood()
{
    // cout << "Nhap"
}
void Foods::displayFoods()
{
    // cout << "\n\t\t+=====================================================================================================+" ;
    // cout << "\n\t\t|                                              LIST FOOD                                              |" ;
    // cout << "\n\t\t+=========+====================================================================+======================+" ;
    // cout << "\n\t\t|   STT   |                                 FOOD                               |        PRICE         |" << endl;
    for (nodeF *k = fHead; k != NULL; k = k->fNext)
    {
        cout << "Loai food: " << k->fData.nameTypefood << endl;
        for (int i = 0; i < k->fData.listFood.size(); i++)
        {
            // fflush(stdin);
            cout << "Ten food: " << k->fData.listFood[i].foodName << endl;
            cout << "Gia food: " << k->fData.listFood[i].foodPrice << endl;
        }
        cout << "==================================" << endl;
    }
}
