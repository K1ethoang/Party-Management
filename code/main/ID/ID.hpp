#include <iostream>
using namespace std;

class ID
{
private:
    long id;

public:
    ID();
    long getID();
    void setID(const long &_id);
    void inputID();
};

ID::ID()
{
    id = -1;
}

long ID::getID()
{
    return id;
}

void ID::setID(const long &_id)
{
    id = _id;
}

void ID::inputID()
{
    do
    {
        cout << "\n\t\t\t\t\t\tNhap ID: ";
        cin >> id;
        if (id <= 0)
            cout << "\n\t\t\t\t\t(!) Id vua nhap khong hop le (!)\n";
    } while (id <= 0);
}
