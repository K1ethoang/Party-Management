#pragma once
#include "program.hpp"

inline void paymentDisplay(PartiesBST &parties, ItemP _party);

inline void paymentDisplay(PartiesBST &parties, ItemP _party)
{
    int choose;
    bool isExit = false;
    do
    {
        system("cls");
        _party.seeDetailParty();
        cout << endl;
        cout << "\n\t\t\t\t\t\t+ =========== THANH TOAN =========== +";
        cout << "\n\t\t\t\t\t\t| 5.1. Thanh toan                    |";
        cout << "\n\t\t\t\t\t\t| 5.2. Huy thanh toan                |";
        cout << "\n\t\t\t\t\t\t| 5.3. In hoa don                    |";
        cout << "\n\t\t\t\t\t\t| 5.0. Tro ve                        |";
        cout << "\n\t\t\t\t\t\t+ ================================== +";
        cout << "\n\t\t\t\t\t\t";
        choose = returnChoose("Nhap lua chon cua ban -> ");
        switch (choose)
        {
        case 1:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t\t\t[THANH TOAN]\n";
            _party.setIsPaymentStatus(1);
            parties.update(_party);
            parties.exportPartiesData(PARTY_DATA_PATH);
            cout << "\n\t\t\t\t\t\t</> Thanh toan thanh cong </>\n";
            pressAnyKey();
            break;
        }
        case 2:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t\t\t[THANH TOAN]\n";
            _party.setIsPaymentStatus(0);
            parties.update(_party);
            parties.exportPartiesData(PARTY_DATA_PATH);
            cout << "\n\t\t\t\t\t\t</> Huy thanh toan thanh cong </>\n";
            pressAnyKey();
            break;
        }
        case 3:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t\t\t[IN HOA DON]\n";
            exportBillParty(_party);
            pressAnyKey();
            break;
        }
        case 0:
        {
            isExit = true;
            break;
        }
        default:
            cout << "\n\t\t\t\t\t\tLua chon khong hop le !! Nhap lai";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}