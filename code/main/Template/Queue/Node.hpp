#pragma once
#include <cstddef>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *pNext;

public:
    Node();
    Node(T value);
};

template <class T>
Node<T>::Node() {}

template <class T>
Node<T>::Node(T value)
    : data(value), pNext(NULL) {}