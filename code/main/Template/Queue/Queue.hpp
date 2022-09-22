#include "Node.hpp"

template <class T>
class Queue
{
private:
    Node<T> *pFront; // con trỏ đầu queue
    Node<T> *pBack;  // con trỏ cuối queue
    int size;

public:
    Queue();
    ~Queue();
    bool isEmpty();
    void push(const T &value);
    void pop();
    T front();
    T back();
    int sizeOf();
    void display();
};

template <class T>
Queue<T>::Queue()
    : pFront(NULL), pBack(NULL), size(0) {}

template <class T>
Queue<T>::~Queue()
{
    Node<T> *t = NULL;
    while (pFront != NULL)
    {
        t = pFront;
        pFront = pFront->pNext;
        delete t;
    }
    size = 0;
}

template <class T>
bool Queue<T>::isEmpty()
{
    if (pFront == NULL)
        return 1;
    return 0;
}

template <class T>
void Queue<T>::push(const T &value) // thêm vào cuối
{
    Node<T> *p = new Node(value);
    if (p == NULL)
    {
        cout << "\n\t\t(!) Not enough memory to allocation (!)" << endl;
        return;
    }
    else
    {
        if (isEmpty())
        {
            pFront = pBack = p;
        }
        else
        {
            pBack->pNext = p;
            pBack = p;
        }
        size++;
    }
}

template <class T>
void Queue<T>::pop()
{
    if (isEmpty())
        return;
    else
    {
        Node<T> *t = pFront;
        pFront = pFront->pNext; // cập nhật lại Node đầu là Node kế tiếp
        delete t;
        size--;
    }
}

template <class T>
T Queue<T>::front()
{
    return pFront->data;
}

template <class T>
T Queue<T>::back()
{
    return pBack->data;
}

template <class T>
int Queue<T>::sizeOf()
{
    return this->size;
}

template <class T>
void Queue<T>::display()
{
    for (Node<T> *t = pFront; t != NULL; t = t->pNext)
        cout << t->data << " ";
}