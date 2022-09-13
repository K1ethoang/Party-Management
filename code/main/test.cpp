#include <iostream>
#include "./Parties/Parties.hpp"
#include "./Parties/Party.hpp"

using namespace std;

int main()
{
    BST list;
    list.display();
    cout << "size: " << list.getSize() << endl;
    return 0;
}