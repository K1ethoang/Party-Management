#include <iostream>
#include "./Customers/Customer.hpp"
#include "./Customers/Customers.hpp"
#include "./Parties/Party.hpp"
#include "./Parties/Parties.hpp"
#include "./ListFood/Foods.hpp"
#include "./Template\Queue/Queue.hpp"

#pragma once
using namespace std;

// using namespace std;

int main()
{
    // listFood food1("Muc chien gion", 150000), 
    //         food2("Banh bao chien", 15000),
    //         food3("Trai cay thap cam", 100000),
    //         food4("Soup cua hai san", 20000),
    //         food5("Tom hap bia", 400000),
    //         food6("Bo ham bi do", 400000),
    //         food7("Ga hap", 500000),
    //         food8("Ca hap", 200000),
    //         food9("Goi buoi hai san", 250000),
    //         food10("Nho My", 100000), food11;
    // // cin >> food11;
    // Queue <listFood>q;
    // q.push(listFood(food1));
    // q.push(listFood(food2));
    // q.push(listFood(food3));
    // q.push(listFood(food4));
    // q.push(listFood(food5));
    // q.push(listFood(food6));
    // q.push(listFood(food7));
    // q.push(listFood(food8));
    // q.push(listFood(food9));
    // q.push(listFood(food10));
    // q.push(listFood(food11));
    // cout << "\n\t\t+=====================================================================================================+" ;
    // cout << "\n\t\t|                                              LIST FOOD                                              |" ;
    // cout << "\n\t\t+=========+====================================================================+======================+" ;
    // cout << "\n\t\t|   STT   |                                 FOOD                               |        PRICE         |" << endl;
    // // q.display();
    // cout << "\t\t+=========+====================================================================+======================+" ;
    // int n = 0;
    BST bst;
    cout << "\n\t\t-----THONG TIN CUA BUOI TIEC DA NHAP-----\n";
    bst.add();
    cout << "\n\t\t-----THONG TIN CUA BUOI TIEC DA NHAP-----\n";
    bst.add();
    // cout << "\n\t\t-----THONG TIN CUA BUOI TIEC DA NHAP-----\n";
    // bst.add(); 

    // cout << "\n\t\t+==========================================================================================================================+" ;
    // cout << "\n\t\t|                                                 PARTIES INFORMATION LIST                                                 |" ;
    // cout << "\n\t\t+=========+=============================+============+==================+=========================+========================+" ;
    // cout << "\n\t\t|   STT   |       Loai tiec             |   So ban   |        ID        |    Thoi gian to chuc    |    Trang thai          |" ;
    // cout << "\n\t\t+=========+=============================+============+==================+=========================+========================+" ;
    // bst.display();
    // cout << "\n\t\t+=========+=============================+============+==================+=========================+========================+" ;
    TypeFood _tf;
    food _food;
    DocFileDoUong(_tf, _food);

    TypeFood _tf2;
    food _food2;
    DocFileKhaiVi(_tf2, _food2);

    Foods foods;
    foods.addfLast(_tf);
    foods.addfLast(_tf2);
    foods.displayFoods();

    return 0;
}