#include <iostream>
using namespace std;

void editName_(string &name)
{
    for (int i = 0; i < name.length(); i++)
    {
        if (i == 0 || (i > 0 && name[i - 1] == 32))
        { // x[i-1] = khoang trang
            if (name[i] >= 97 && name[i] <= 122)
            {
                name[i] = name[i] - 32;
            }
        }
        else
        {
            if (name[i] >= 65 && name[i] <= 90)
            {
                name[i] = name[i] + 32;
            }
        }
    }
}