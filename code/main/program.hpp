#pragma once
#include <iostream>
using namespace std;

void program();

void program()
{
    int choose;
    bool isExit = false;
    do
    {
        cout << "\n1. Them tiec";
        cout << "\n2. Chinh sua tiec";
        cout << "\n3. Xem danh sach cac tiec";
        cout << "\n4. Xoa tiec";
    } while (!isExit);
}