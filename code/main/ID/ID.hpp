#include <iostream>
using namespace std;

class ID
{
private:
    long id;

public:
    ID();
    long getID();
    void setID(long &_id);
    void inputID();
    long outputID();
};

ID::ID()
{
    id = -1;
}

long ID::getID()
{
    return id;
}

void ID::setID(long &_id)
{
    do
    {
        if (_id <= 0)
        {
            cout << "\n\t\t\t\t\t\tId vua nhap khong hop le!!";
            cout << "\n\t\t\t\t\t\t\t\tNhap lai: ";
            cin >> _id;
        }
        else
            id = _id;
    } while (_id <= 0);
}

void ID::inputID()
{
    long _id;
    cout << "\n\t\t\t\t\t\tNhap ID: ";
    cin >> _id;
    setID(_id);
}

long ID::outputID()
{
    return id;
}
