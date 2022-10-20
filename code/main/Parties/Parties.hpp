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
    bool isExistIDPrivate(NodeP *root, const long &_ID);
    void addPrivate(NodeP *&root, ItemP val);              // thêm node
    void preOrderPrivate(NodeP *root);                     // duyệt đầu
    void inOrderPrivate(NodeP *root);                      // duyệt giữa
    void postOrderPrivate(NodeP *root);                    // duyệt sau
    void freeMemory(NodeP *root);                          // giải phóng bộ nhớ
    ItemP returnNodePrivate(NodeP *root, const long &_ID); // tìm node
    void updateNodePrivate(NodeP *root, ItemP value);      // cập nhật node
    long findSmallestPrivate(NodeP *root);
    void removeNodePrivate(NodeP *root, const long &_ID); // xoá node

    // methods public
public:
    BST();  // hàm tạo
    ~BST(); // hàm huỷ
    NodeP *getRoot();
    long getSize();
    bool isExistID(const long &_ID); // kiểm tra trùng ID
    void add(const ItemP &value);    // thêm tiệc
    ItemP search(const long &ID);    // tìm tiệc
    void update(const ItemP &value); // chỉnh sửa tiệc
    long findSmallest(NodeP *root);
    void remove(const long &ID); // xoá tiệc
    void display();              // xuất các tiệc
};

// Methods private
bool BST::isExistIDPrivate(NodeP *root, const long &_ID)
{
    if (root == NULL)
        return false;
    if (root->data.getID() == _ID)
        return true;
    else
    {
        if (_ID < root->data.getID())
            return isExistIDPrivate(root->left, _ID);
        else if (_ID > root->data.getID())
            return isExistIDPrivate(root->right, _ID);
    }
    return false;
}

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

ItemP BST::returnNodePrivate(NodeP *root, const long &_ID)
{
    // Nếu node rỗng trả về NULL
    if (root == NULL)
        return ItemP();
    else
    {
        if (root->data.getID() == _ID)
            return root->data;
        else
        {
            // Nếu phần tử cần tìm nhỏ hơn node hiện tại
            if (_ID < root->data.getID())
                returnNodePrivate(root->left, _ID);
            else if (_ID > root->data.getID())
                returnNodePrivate(root->right, _ID);
        }
    }
    return ItemP();
}

void BST::updateNodePrivate(NodeP *root, ItemP value)
{
    if (root != NULL)
    {
        if (root->data.getID() == value.getID())
            root->data = value;
        else
        {
            if (value.getID() < root->data.getID())
                updateNodePrivate(root->left, value);
            else if (value.getID() > root->data.getID())
                updateNodePrivate(root->right, value);
        }
    }
}

long BST::findSmallestPrivate(NodeP *root)
{
}

void BST::removeNodePrivate(NodeP *root, const long &_ID)
{
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

bool BST::isExistID(const long &_ID)
{
    if (isExistIDPrivate(root, _ID))
        return true;
    return false;
}

void BST::add(const ItemP &value)
{
    addPrivate(root, value);
    size++;
}

ItemP BST::search(const long &ID)
{
    return returnNodePrivate(root, ID);
}

void BST::update(const ItemP &value)
{
    updateNodePrivate(root, value);
}

long BST::findSmallest(NodeP *root)
{
    return findSmallestPrivate(root);
}

void BST::remove(const long &ID)
{
    removeNodePrivate(root, ID);
}

void BST::display()
{
    preOrderPrivate(root);
}
