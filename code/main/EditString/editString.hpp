#include <iostream>
using namespace std;

void editString_(string &string)
{
    for (int i = 0; i < string.length(); i++)
    {
        if (i == 0 || (i > 0 && string[i - 1] == 32))
        { // x[i-1] = khoang trang
            if (string[i] >= 97 && string[i] <= 122)
            {
                string[i] = string[i] - 32;
            }
        }
        else
        {
            if (string[i] >= 65 && string[i] <= 90)
            {
                string[i] = string[i] + 32;
            }
        }
    }
}