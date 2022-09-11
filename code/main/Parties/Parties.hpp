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
    Node(const Party &_data);
};

Node::Node()
{
}

Node::Node(const Party &_data)
{
    data = _data;
    left = right = NULL;
}

class BST
{
private:
    Node *root;
    long size;

public:
    BST();                       // hàm tạo
    void freeMemory(Node *root); // hàm huỷ
    long getId();
};

BST::BST()
{
    root = NULL;
    size = 0;
}

void BST::freeMemory(Node *root)
{
    if (root)
    {
        freeMemory(root->left);
        freeMemory(root->right);
    }
    delete root;
}