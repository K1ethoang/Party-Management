#include <iostream>
#include "./Customers/Customer.hpp"
#include "./Customers/Customers.hpp"
// #include "./Parties/Party.hpp"
// #include "./Parties/Parties.hpp"

using namespace std;

int main()
{
    Customer c;
    Customers l;
    cin >> c;
    c.setIdOfParty(2);
    cout << c;
    l.addLast(c);
    l.edit(2);
    cout << l.getHead()->data;
    system("pause");
    return 0;
}