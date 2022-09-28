#include <iostream>
#include "./Customers/Customer.hpp"
#include "./Customers/Customers.hpp"
// #include "./Parties/Party.hpp"
// #include "./Parties/Parties.hpp"

using namespace std;

int main()
{
    int n = 0;
    

    Party p;
    cout << "\n\t\t-----THONG TIN CUA BUOI TIEC DA NHAP-----\n";
    cin >> p;
    cout << "\n\t\t-----XUAT THONG TIN CUA BUOI TIEC-----\n";
    cout << p;

    Customer c;
    cin >> c;
    cout << c;

    return 0;
}