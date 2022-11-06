#pragma once
#include "program.hpp"

inline void exportBillParty(ItemP _party);

inline void exportBillParty(ItemP _party)
{
    ItemC _customer = _party.getCustomer();
    string save_path = BILL_SAVER_FOLDER_PATH + '/' + to_string(_customer.getID()) + '_' + _customer.getFullName() + ".txt";
    ofstream fileOut(save_path);
    if (fileOut.is_open())
    {
        _party.writeABill(fileOut);
        _party.printBill();
        cout << endl;
        cout << "\n\t\t\t\tHoa don cua ban duoc luu theo duong dan sau: " << endl;
        cout << "\n\t\t\tcode -> data -> Hoa-Don -> " << _customer.getID() << "_" << _customer.getFullName() << ".txt" << endl;
    }
    fileOut.close();
}