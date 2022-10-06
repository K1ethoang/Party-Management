#pragma once
#include <iostream>
#include "Party.hpp"
#include "../Customers/Customer.hpp"

#define ItemP Party

using namespace std;

class NodeP
{
public:
    ItemP data;
    NodeP *left;
    NodeP *right;
    // Methods
    NodeP();
    NodeP(ItemP _data);
};

NodeP::NodeP()
{
    left = right = NULL;
}

NodeP::NodeP(ItemP _data)
{
    data = _data;
    left = right = NULL;
}

class BST
{
private:
    NodeP *root;
    long size;

    // methods private
private:
    void addPrivate(NodeP *&root, ItemP val); // thêm node
    void preOrderPrivate(NodeP *root);        // duyệt đầu
    void inOrderPrivate(NodeP *root);         // duyệt giữa
    void postOrderPrivate(NodeP *root);       // duyệt sau
    void freeMemory(NodeP *root);             // giải phóng bộ nhớ
    ItemP returnNodePrivate(NodeP *root, const long &ID);

    // methods public
public:
    BST();  // hàm tạo
    ~BST(); // hàm huỷ
    NodeP *getRoot();
    long getSize();
    void add();         // thêm tiệc
    void searchParty(); // tìm tiệc
    void display();     // xuất các tiệc
};

// Methods private
void BST::addPrivate(NodeP *&root, ItemP val)
{
    if (root == NULL)
        root = new NodeP(val);
    else
    {
        if (val.getID() < root->data.getID())
            addPrivate(root->left, val);
        else if (val.getID() > root->data.getID())
            addPrivate(root->right, val);
    }
}

void BST::freeMemory(NodeP *root)
{
    if (root != NULL)
    {
        freeMemory(root->left);
        freeMemory(root->right);
        delete root;
        size--;
    }
}

void BST::preOrderPrivate(NodeP *root)
{
    if (root != NULL)
    {
        cout << root->data;
        preOrderPrivate(root->left);
        preOrderPrivate(root->right);
    }
}

void BST::inOrderPrivate(NodeP *root)
{
    if (root != NULL)
    {
        inOrderPrivate(root->left);
        cout << root->data;
        inOrderPrivate(root->right);
    }
}

void BST::postOrderPrivate(NodeP *root)
{
    if (root != NULL)
    {
        postOrderPrivate(root->left);
        postOrderPrivate(root->right);
        cout << root->data;
    }
}

ItemP BST::returnNodePrivate(NodeP *root, const long &ID)
{
    // Nếu node rỗng trả về NULL
    if (root == NULL)
        return ItemP();
    else
    {
        // Nếu phần tử cần tìm nhỏ hơn node hiện tại
        if (ID < root->data.getID())
            returnNodePrivate(root->left, ID);
        else if (ID > root->data.getID())
            returnNodePrivate(root->right, ID);
        else
            return root->data;
    }
}

// Methods public
BST::BST()
{
    root = NULL;
    size = 0;
}

BST::~BST()
{
    if (size == 0)
        return;
    freeMemory(root);
}

NodeP *BST::getRoot()
{
    return root;
}

long BST::getSize()
{
    return size;
}

void BST::add()
{
    Customer c;
    cin >> c;
    cout << c;
    Party p;
    cin >> p;
    cout << p;
    addPrivate(root, p);
    size++;
    cout << "Them thanh cong!" << endl;

    // Party p;
    // cout << "Nhap thong tin tiec can them: " << endl;
    // cin >> p;
    // addPrivate(root, p);
    // size++;
}

void BST::searchParty()
{
    long ID;
    bool isExist = false;
    do
    {
        cout << "Nhap id cua tiec: ";
        cin >> ID;
        Party res = returnNodePrivate(root, ID);
        if (res.getID() < 0)
        {
            cout << "Id ban vua nhap khong dung hoac khong co tiec nay!!" << endl;
        }
        else
        {
            cout << res;
            isExist = true;
        }
    } while (!isExist);
}

void BST::display()
{
    preOrderPrivate(root);
}
