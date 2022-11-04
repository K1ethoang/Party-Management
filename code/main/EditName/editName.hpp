#pragma once
#include <iostream>
using namespace std;

void removeWhiteSpaceInString(string &_string);
void formatName(string &name);

void removeWhiteSpaceInString(string &_string)
{
    // vd:Hoang     Gia   Kiet -> Hoang Gia Kiet
    int lengthOfString = _string.length();
    for (int i = 0; i < lengthOfString; i++)
    {
        if ((i == 0 && _string[i] == ' '))
        {
            _string.erase(0, 1);
            i--;
        }
        else
        {
            if (_string[i] == ' ' && _string[i + 1] == ' ')
            {
                _string.erase(i + 1, 1);
                i--;
            }
        }
    }
}

void formatName(string &name)
{
    // vd: nGUyeN VAN a -> Nguyen Van A
    removeWhiteSpaceInString(name);
    int lengthOfName = name.length();
    for (int i = 0; i < lengthOfName; i++)
    {
        if (i == 0 || (i > 0 && name[i - 1] == ' '))
        {
            if (name[i] >= 'a' && name[i] <= 'z')
                name[i] = name[i] - 32;
        }
        else
        {
            if (name[i] >= 'A' && name[i] <= 'Z')
                name[i] = name[i] + 32;
        }
    }
}