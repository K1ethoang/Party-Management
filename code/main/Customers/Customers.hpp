#pragma once
#include <iomanip>
#include "Customer.hpp"

struct NodeC
{
    Customer data;
    NodeC *pNext;
};

class CustomersSLL
{
private:
    NodeC *Head;
    NodeC *Tail;
    long Size;

public:
    CustomersSLL();
    ~CustomersSLL(); // hàm hủy
    NodeC *getHead();
    NodeC *getTail();
    long getSize();
    NodeC *createNode(const ItemC &val);
    void addLast(const ItemC &val);
    void removeFirst();
    void removeLast();
    void remove(const long &id);
    void find(const long &id);
    void sortByID();
    void edit(const long &id);
    void display();
    void importCustomersData(const string &_fileInPath);
    void exportCustomersData(const string &_fileOutPath);
};

CustomersSLL::CustomersSLL()
{
    Head = Tail = NULL;
    Size = 0;
}
CustomersSLL::~CustomersSLL() // duyệt qua từng phần tử để giải phóng
{
    NodeC *t = NULL;
    while (Head != NULL)
    {
        t = Head;
        Head = Head->pNext;
        delete t;
    }
    Size = 0;
}

NodeC *CustomersSLL::getHead()
{
    return Head;
}

NodeC *CustomersSLL::getTail()
{
    return Tail;
}

long CustomersSLL::getSize()
{
    return Size;
}

NodeC *CustomersSLL::createNode(const ItemC &val)
{
    NodeC *p = new NodeC;
    p->data = val;
    p->pNext = NULL;
    return p;
}

void CustomersSLL::addLast(const ItemC &val)
{
    NodeC *p = createNode(val);
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

void CustomersSLL::removeFirst()
{
    if (Head == NULL)
        return;
    NodeC *l = Head;    // node l là node sẽ xóa
    Head = Head->pNext; // cập nhật lại head là phần tử tiếp theo
    delete l;
    Size--;
}

void CustomersSLL::removeLast()
{
    if (Head == NULL)
        return;
    for (NodeC *i = Head; i != NULL; i = i->pNext)
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

void CustomersSLL::remove(const long &id)
{

    if (Head->data.getID() == id)
        removeFirst();
    else if (Tail->data.getID() == id)
        removeLast();
    else
    {
        NodeC *m = new NodeC;
        for (NodeC *k = Head; k != NULL; k = k->pNext)
        {
            // phát hiện ra phần tử cần xóa
            if (k->data.getID() == id)
            {
                NodeC *g = k;
                m->pNext = k->pNext;
                delete g;
                Size--;
                return;
            }
            m = k;
        }
    }
}

void CustomersSLL::find(const long &id)
{
    for (NodeC *i = Head; i != NULL; i = i->pNext)
    {
        if (i->data.getID() == id)
        {
            cout << i->data;
            break;
        }
    }
}

void CustomersSLL::sortByID() // thuật toán sắp xếp chọn
{
    for (NodeC *i = Head; i != Tail; i = i->pNext)
    {
        NodeC *minIndex = i;
        for (NodeC *j = i->pNext; j != NULL; j = j->pNext)
        {
            if (minIndex->data.getID() > j->data.getID())
                minIndex = j;
        }
        if (minIndex != i)
            swap(i->data, minIndex->data);
    }
}

// void CustomersSLL::edit(const long &id)
// {
//     bool exist = false;

//     for (NodeC *i = Head; i != NULL; i = i->pNext)
//     {

//         if (i->data.getID() == id)
//         {
//             exist = true;
//             int choose;
//             bool exit = false;
//             do
//             {
//                 system("cls");
//                 cout << "\n\t\tNOI DUNG CAN CHINH SUA" << endl;
//                 cout << "1. Ho va ten" << endl;
//                 cout << "2. So dien thoai" << endl;
//                 cout << "0. Thoat" << endl;
//                 cout << "\nNhap lua chon cua ban: ";
//                 cin >> choose;
//                 switch (choose)
//                 {
//                 case 1:
//                 {
//                     string Name;
//                     cout << "\nNhap ho va ten moi: ";
//                     fflush(stdin);
//                     getline(cin, Name);
//                     cout << Name << endl;
//                     i->data.setFullName(Name);
//                     cout << "\nCap nhat thanh cong!" << endl;
//                     break;
//                 }
//                 case 2:
//                 {
//                     string phoneNumber;
//                     cout << "\nNhap so dien thoai moi: ";
//                     fflush(stdin);
//                     cin >> phoneNumber;
//                     i->data.setPhoneNumber(phoneNumber);
//                     cout << "\nCap nhat thanh cong!" << endl;
//                     break;
//                 }
//                 case 0:
//                     exit = true;
//                 default:
//                     break;
//                 }
//                 cout << i->data;
//                 system("pause");
//             } while (!exit);
//             break;
//         }
//     }
//     if (exist == false)
//     {
//         cout << "\nKhong ton tai khach hang nay" << endl;
//     }
// }

void CustomersSLL::display()
{
    int count = 1;
    cout << "\n\t\t\t+=============================================================================================================================+" << endl;
    cout << "\t\t\t|                                               DANH SACH THONG TIN KHACH HANG                                                |" << endl;
    cout << "\t\t\t+==================+===========================================+=========================+====================================+" << endl;
    cout << "\t\t\t|        ID        |                 HO VA TEN                 |           SDT           |                CCCD                |" << endl;
    cout << "\t\t\t+==================+===========================================+=========================+====================================+";
    cout << "\t\t\t";
    for (NodeC *t = Head; t != NULL; t = t->pNext)
    {
        cout << "\n\t\t\t" << setiosflags(ios::left) << "|"
             << "        " << setw(10) << t->data.getID() << "|"
             << "           " << setw(32) << t->data.getFullName() << "|"
             << "       " << setw(18) << t->data.getPhoneNumber() << "|"
             << "            " << setw(24) << t->data.getCCCD() << "|";
        cout << "\n\t\t\t+==================+===========================================+=========================+====================================+";
    }
}

void CustomersSLL::importCustomersData(const string &_fileInPath)
{
    ifstream fileIn(_fileInPath);
    if (fileIn.is_open())
    {
        string newline;
        getline(fileIn, newline);
        while (!fileIn.eof())
        {
            ItemC _customer;
            _customer.readACustomer(fileIn);
            addLast(_customer);
        }
    }
    else
        cout << "\n\t\t(!) Loi khi mo file \"khachHang.txt\"" << endl;
    fileIn.close();
}

void CustomersSLL::exportCustomersData(const string &_fileOutPath)
{
    ofstream fileOut(_fileOutPath);
    if (fileOut.is_open())
    {
        for (NodeC *t = Head; t != NULL; t = t->pNext)
            t->data.writeACustomer(fileOut);
    }
    else
        cout << "\n\t\t(!) Loi khi mo file \"khachHang.txt\"" << endl;
    fileOut.close();
}