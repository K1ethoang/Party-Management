#include <iostream>
#include "./Customers/Customer.hpp"
#include "./Parties/Party.hpp"
#include "./Parties/Parties.hpp"

using namespace std;

int main()
{
    BST p;
    p.add();
    p.display();
    p.searchParty();
    return 0;
}