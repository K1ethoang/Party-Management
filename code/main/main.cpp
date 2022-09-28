#include <iostream>
#include "./Customers/Customer.hpp"
#include "./Customers/Customers.hpp"
// #include "./Parties/Party.hpp"
// #include "./Parties/Parties.hpp"

using namespace std;

int main()
{
    int n = 0;
    BST bst;

    Party p, e, d;
    cout << "\n\t\t-----THONG TIN CUA BUOI TIEC DA NHAP-----\n";
    cin >> p;
    bst.add(p);
    cout << "\n\t\t-----THONG TIN CUA BUOI TIEC DA NHAP-----\n";
    cin >> e;
    bst.add(e);
    cout << "\n\t\t-----THONG TIN CUA BUOI TIEC DA NHAP-----\n";
    cin >> d;
    bst.add(d);

    // cout << "\n\t\t-----XUAT THONG TIN CUA BUOI TIEC-----\n";
    // bst.display();

    // Customer c;
    // cin >> c;
    // cout << c;

    return 0;
}