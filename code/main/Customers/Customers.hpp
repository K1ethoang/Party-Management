#pragma once
#include <iostream>
#include "Customer.hpp"
using namespace std;

struct node
{
    Customer data;
    node *pNext;
};

typedef Customer Item;

class Customers
{
private:
    node *Head;
    node *Tail;
    long Size;

public:
    Customers();
    ~Customers(); // hàm hủy
    node *getHead();
    node *getTail();
    long getSize();
    node *createnode(const Item &val);
    void addLast(const Item &val);
    void removeFirst();
    void removeLast();
    void remove(const long &id);
    void find(const long &id);
    void edit(const long &id);
};

Customers::Customers()
{
    Head = Tail = NULL;
    Size = 0;
}
Customers::~Customers() // duyệt qua từng phần tử để giải phóng
{
    node *t = NULL;
    while (Head != NULL)
    {
        t = Head;
        Head = Head->pNext;
        delete t;
    }
    Size = 0;
}

node *Customers::getHead()
{
    return Head;
}

node *Customers::getTail()
{
    return Tail;
}

long Customers::getSize()
{
    return Size;
}

node *Customers::createnode(const Item &val)
{
    node *p = new node;
    p->data = val;
    p->pNext = NULL;
    return p;
}

void Customers::addLast(const Item &val)
{
    node *p = createnode(val);
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

    node *l = Head;     // node l là node sẽ xóa
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
    for (node *i = Head; i != NULL; i = i->pNext)
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

    if (Head->data.getID() == id)
    {
        removeFirst();
    }
    else if (Tail->data.getID() == id)
    {
        removeLast();
    }
    else
    {
        node *m = new node;
        for (node *k = Head; k != NULL; k = k->pNext)
        {
            // phát hiện ra phần tử cần xóa
            if (k->data.getID() == id)
            {
                node *g = k;
                m->pNext = k->pNext;
                delete g;
                Size--;
                return;
            }
            m = k;
        }
    }
}

void Customers::find(const long &id)
{
    for (node *i = Head; i != NULL; i = i->pNext)
    {
        if (i->data.getID() == id)
        {
            cout << i->data;
            break;
        }
    }
}

void Customers::edit(const long &id)
{
    bool exist = false;

    for (node *i = Head; i != NULL; i = i->pNext)
    {

        if (i->data.getID() == id)
        {
            exist = true;
            int choose;
            bool exit = false;
            do
            {
                system("cls");
                cout << "\n\t\tNOI DUNG CAN CHINH SUA" << endl;
                cout << "1. Ho va ten" << endl;
                cout << "2. So dien thoai" << endl;
                cout << "0. Thoat" << endl;
                cout << "\nNhap lua chon cua ban: ";
                cin >> choose;
                switch (choose)
                {
                case 1:
                {
                    string Name;
                    cout << "\nNhap ho va ten moi: ";
                    fflush(stdin);
                    getline(cin, Name);
                    cout << Name << endl;
                    i->data.setFullName(Name);
                    cout << "\nCap nhat thanh cong!" << endl;
                    break;
                }
                case 2:
                {
                    string phoneNumber;
                    cout << "\nNhap so dien thoai moi: ";
                    fflush(stdin);
                    cin >> phoneNumber;
                    i->data.setPhoneNumber(phoneNumber);
                    cout << "\nCap nhat thanh cong!" << endl;
                    break;
                }
                case 0:
                    exit = true;
                default:
                    break;
                }
                cout << i->data;
                system("pause");
            } while (!exit);
            break;
        }
    }
    if (exist == false)
    {
        cout << "\nKhong ton tai khach hang nay" << endl;
    }
}