#include "./program/program.hpp"

int main()
{
    Party p;
    Customer c;
    cin >> c;
    p.setCustomer(c);
    p.printBill();
    // program();
    return 0;
}
