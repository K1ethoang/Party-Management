#pragma once
#include <iostream>
using namespace std;

void checkExit(bool &isExit, bool &isSaved);

void checkExit(bool &isExit, bool &isSaved)
{
    int option;
    bool back = false;
    if (isSaved)
        isExit = true;
    else
    {
        do
        {
            system("cls");
            cout << "\n\t\t\tBan chua luu thong tin, chac chan muon thoat?";
            cout << "\n\t\t\t\t1. Luu va thoat";
            cout << "\n\t\t\t\t2. Khong luu va thoat";
            cout << "\n\t\t\t\t0. Tro ve";
            cout << "\n\t\t\tLua chon cua ban -> ";
            cin >> option;
            switch (option)
            {
            case 1:
                isSaved = true;
                isExit = true;
                back = true;
                break;
            case 2:
                isExit = true;
                back = true;
                break;
            case 0:
                back = true;
                break;
            }
        } while (!back);
    }
}