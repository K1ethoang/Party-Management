#include <iostream>
#include "./Customers/Customer.hpp"
#include "./Customers/Customers.hpp"
// #include "./Parties/Party.hpp"
// #include "./Parties/Parties.hpp"
// #pragma once

using namespace std;

int main()
{
    int n = 0;
    BST bst;
    cout << "\n\t\t-----THONG TIN CUA BUOI TIEC DA NHAP-----\n";
    bst.add();
    // cout << "\n\t\t-----THONG TIN CUA BUOI TIEC DA NHAP-----\n";
    // bst.add();
    // cout << "\n\t\t-----THONG TIN CUA BUOI TIEC DA NHAP-----\n";
    // bst.add();

    cout << "\n\t\t+==========================================================================================================================+" ;
    cout << "\n\t\t|                                                 PARTIES INFORMATION LIST                                                 |" ;
    cout << "\n\t\t+=========+=============================+============+==================+=========================+========================+" ;
    cout << "\n\t\t|   STT   |       Loai tiec             |   So ban   |        ID        |    Thoi gian to chuc    |    Trang thai          |" ;
    cout << "\n\t\t+=========+=============================+============+==================+=========================+========================+" ;
    bst.display();
    cout << "\n\t\t+=========+=============================+============+==================+=========================+========================+" ;
    // Customer c;
    // cin >> c;
    // cout << c;

    return 0;
}