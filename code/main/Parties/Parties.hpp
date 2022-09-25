#pragma once
#include <iostream>
#include "Party.hpp"

#define Party Party

using namespace std;

class Node
{
public:
    Party data;
    Node *left;
    Node *right;
    // Methods
    Node();
    Node(Party _data);
};

Node::Node()
{
    left = right = NULL;
}

Node::Node(Party _data)
{
    data = _data;
    left = right = NULL;
}

class BST
{
private:
    Node *root;
    long size;

    // methods private
private:
    void addPrivate(Node *&root, Party val); // thêm node
    void preOrderPrivate(Node *root);        // duyệt đầu
    void inOrderPrivate(Node *root);         // duyệt giữa
    void postOrderPrivate(Node *root);       // duyệt sau
    void freeMemory(Node *root);             // giải phóng bộ nhớ
    Party returnNodePrivate(Node *root, const long &ID);

    // methods public
public:
    BST();  // hàm tạo
    ~BST(); // hàm huỷ
    Node *getRoot();
    long getSize();
    void add();         // thêm tiệc
    void searchParty(); // tìm tiệc
    void display();     // xuất các tiệc
};

// Methods private
void BST::addPrivate(Node *&root, Party val)
{
    if (root == NULL)
        root = new Node(val);
    else
    {
        if (val.getID() < root->data.getID())
            addPrivate(root->left, val);
        else if (val.getID() > root->data.getID())
            addPrivate(root->right, val);
    }
}

void BST::freeMemory(Node *root)
{
    if (root != NULL)
    {
        freeMemory(root->left);
        freeMemory(root->right);
        delete root;
        size--;
    }
}

void BST::preOrderPrivate(Node *root)
{
    if (root != NULL)
    {
        cout << root->data;
        preOrderPrivate(root->left);
        preOrderPrivate(root->right);
    }
}

void BST::inOrderPrivate(Node *root)
{
    if (root != NULL)
    {
        inOrderPrivate(root->left);
        cout << root->data;
        inOrderPrivate(root->right);
    }
}

void BST::postOrderPrivate(Node *root)
{
    if (root != NULL)
    {
        postOrderPrivate(root->left);
        postOrderPrivate(root->right);
        cout << root->data;
    }
}

Party BST::returnNodePrivate(Node *root, const long &ID)
{
    // Nếu node rỗng trả về NULL
    if (root == NULL)
        return Party();
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

Node *BST::getRoot()
{
    return root;
}

long BST::getSize()
{
    return size;
}

void BST::add()
{
    Party p;
    cout << "Nhap thong tin tiec can them: " << endl;
    cin >> p;
    addPrivate(root, p);
    size++;
    cout << "Them thanh cong!" << endl;
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
