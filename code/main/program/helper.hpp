#pragma once
#include <iostream>
using namespace std;

inline void program();
void checkExit(bool &isExit, bool &isSaved);
bool checkNumber(string _value);
int returnChoose(const string &_question);

inline void pressAnyKey()
{
    cout << endl;
    system("pause");
}

void checkExit(bool &isExit, bool &isSaved)
{
    bool back = false;
    if (isSaved)
    {
        isExit = true;
        return;
    }
    else
    {
        do
        {
            system("cls");
            cout << "\n\t\t\t\t\t\tBan chua luu thong tin, chac chan muon thoat?";
            cout << "\n\t\t\t\t\t\t\t1. Luu va thoat";
            cout << "\n\t\t\t\t\t\t\t2. Khong luu va thoat";
            cout << "\n\t\t\t\t\t\t\t0. Tro ve";
            int choose = returnChoose("Nhap lua chon cua ban -> ");
            switch (choose)
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

bool checkNumber(string _value)
{
    for (int i = 0; i < _value.length(); i++)
    {
        if (!isdigit(_value[i]))
            return false;
    }
    return true;
}

int returnChoose(const string &_question)
{
    string choose;
    do
    {
        cout << "\n\t\t\t\t\t\t " << _question;
        cin >> choose;
    } while (!checkNumber(choose));
    int result = stoi(choose);
    return result;
}