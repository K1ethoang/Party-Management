#include <iostream>
using namespace std;

class ID
{
private:
    long id;

public:
    void InputID();
    long OutputID();
    ID();
    void setID(long &_id);
    long getID();
};

void ID::InputID()
{
    long _id;
    cout << "\n\t\t\t\t\t\t\t\t\tNhap ID: ";
    cin >> _id;
    setID(_id);
}

long ID::OutputID()
{
    return id;
}

ID::ID()
{
    id = -1;
}

void ID::setID(long &_id)
{
    do
    {
        if (_id <= 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\tId vua nhap khong hop le!!";
            cout << "\n\t\t\t\t\t\t\t\tNhap lai: ";
            cin >> _id;
        }
        else
            id = _id;
    } while (_id <= 0);
}

long ID::getID()
{
    return id;
}
