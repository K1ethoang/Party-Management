#include <iostream>

#include "./Parties/Party.hpp"
#include "./Customers/Customer.hpp"
using namespace std;

int main()
{
    Party p;
    // cin >> p;
    p.Input();
    p.Output();
    
    Customer c;
    cin >> c;
    cout << c;
    return 0;
}


 