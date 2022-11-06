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
    NodeC *head;
    NodeC *tail;
    long size;

private:
    NodeC *returnMiddlePrivate(NodeC *start, NodeC *last); // tìm vị trí node ở giữa dslk
    NodeC *binarySearchPrivate(NodeC *head, const long &_IDKey);

public:
    CustomersSLL();
    ~CustomersSLL(); // hàm hủy
    long getSize();
    NodeC *createNode(const ItemC &val);
    void addLast(const ItemC &val);
    void removeFirst();
    void removeLast();
    void remove(const long &id);
    void sortByID();
    NodeC *findCustomerByID(const long &_IDKey); // binary search
    void update(ItemC value);
    void display();
    void importCustomersData(const string &_fileInPath);
    void exportCustomersData(const string &_fileOutPath);
};

// private
NodeC *CustomersSLL::returnMiddlePrivate(NodeC *start, NodeC *last)
{
    if (start == NULL)
        return NULL;
    NodeC *slow = start;
    NodeC *fast = start->pNext;
    while (fast != last)
    {
        fast = fast->pNext;
        if (fast != last)
        {
            slow = slow->pNext;
            fast = fast->pNext;
        }
    }
    return slow;
}

NodeC *CustomersSLL::binarySearchPrivate(NodeC *head, const long &_IDKey)
{
    NodeC *start = head, *last = NULL;
    do
    {
        NodeC *mid = returnMiddlePrivate(start, last);
        if (mid == NULL)
            return NULL;
        if (mid->data.getID() == _IDKey)
            return mid;
        else if (mid->data.getID() > _IDKey)
            start = mid->pNext;
        else
            last = mid;
    } while (last == NULL || last != start);
    return NULL;
}

// public
CustomersSLL::CustomersSLL()
{
    head = tail = NULL;
    size = 0;
}
CustomersSLL::~CustomersSLL() // duyệt qua từng phần tử để giải phóng
{
    NodeC *t = NULL;
    while (head != NULL)
    {
        t = head;
        head = head->pNext;
        size--;
        delete t;
    }
}

long CustomersSLL::getSize()
{
    return size;
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
    if (size == 0)
        head = tail = p;
    else
    {
        tail->pNext = p;
        tail = p;
    }
    size++;
}

void CustomersSLL::removeFirst()
{
    if (head == NULL)
        return;
    NodeC *l = head;    // node l là node sẽ xóa
    head = head->pNext; // cập nhật lại head là phần tử tiếp theo
    delete l;
    size--;
}

void CustomersSLL::removeLast()
{
    if (head == NULL)
        return;
    for (NodeC *i = head; i != NULL; i = i->pNext)
    {
        // phát hiện kế cuối
        if (i->pNext == tail)
        {
            delete tail;     // xóa phần tử cuối
            i->pNext = NULL; // cho con trỏ kế cuối trỏ đến NULL
            tail = i;        // cập nhật lại kế cuối là tail
            size--;
            return;
        }
    }
}

void CustomersSLL::remove(const long &id)
{

    if (head->data.getID() == id)
        removeFirst();
    else if (tail->data.getID() == id)
        removeLast();
    else
    {
        NodeC *m = new NodeC;
        for (NodeC *k = head; k != NULL; k = k->pNext)
        {
            // phát hiện ra phần tử cần xóa
            if (k->data.getID() == id)
            {
                NodeC *g = k;
                m->pNext = k->pNext;
                delete g;
                size--;
                return;
            }
            m = k;
        }
    }
}

void CustomersSLL::sortByID() // thuật toán sắp xếp chọn
{
    for (NodeC *i = head; i != tail; i = i->pNext)
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

NodeC *CustomersSLL::findCustomerByID(const long &_IDKey)
{
    sortByID();
    return binarySearchPrivate(head, _IDKey);
}

void CustomersSLL::update(ItemC value)
{
    if (size == 0)
        return;
    for (NodeC *t = head; t != NULL; t = t->pNext)
    {
        if (t->data.getID() == value.getID())
        {
            t->data = value;
            return;
        }
    }
}

void CustomersSLL::display()
{
    int count = 1;
    cout << "\n\t\t\t+=============================================================================================================================+" << endl;
    cout << "\t\t\t|                                               DANH SACH THONG TIN KHACH HANG                                                |" << endl;
    cout << "\t\t\t+==================+===========================================+=========================+====================================+" << endl;
    cout << "\t\t\t|        ID        |                 HO VA TEN                 |           SDT           |                CCCD                |" << endl;
    cout << "\t\t\t+==================+===========================================+=========================+====================================+";
    cout << "\t\t\t";
    for (NodeC *t = head; t != NULL; t = t->pNext)
    {
        cout << "\n\t\t\t" << setiosflags(ios::left) << "|"
             << "        " << setw(10) << t->data.getID() << "|"
             << "           " << setw(32) << t->data.getFullName() << "|"
             << "       " << setw(18) << t->data.getPhoneNumber() << "|"
             << "            " << setw(24) << t->data.getIdentityCard() << "|";
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
        for (NodeC *t = head; t != NULL; t = t->pNext)
            t->data.writeACustomer(fileOut);
    }
    else
        cout << "\n\t\t(!) Loi khi mo file \"khachHang.txt\"" << endl;
    fileOut.close();
}