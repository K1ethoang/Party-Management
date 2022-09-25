#include <iostream>
#include "./Customers/Customer.hpp"
#include "./Customers/Customers.hpp"

#include "./Parties/Party.hpp"

using namespace std;

int main()
{
    Customer cc;
    Customers c;
    cin >> cc;
    cc.setIdOfParty(2);
    cout << cc;
    // c.addLast(cc);
    // cout << c.getSize();
    // c.edit(2);
    cc.setFullName("test");
    cc.setPhoneNumber("9999999999");
    cout << cc;
    return 0;
}