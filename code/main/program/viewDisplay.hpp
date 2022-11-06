#include "program.hpp"

inline void viewDisplay(PartiesBST &parties);

inline void viewDisplay(PartiesBST &parties)
{
    int choose;
    bool isExit = false;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t\t+ =========== XEM DANH SACH =========== +";
        cout << "\n\t\t\t\t\t\t| 3.1. Tat ca                           |";
        cout << "\n\t\t\t\t\t\t| 3.2. Chua thanh toan                  |";
        cout << "\n\t\t\t\t\t\t| 3.3. Da thanh toan                    |";
        cout << "\n\t\t\t\t\t\t| 3.4. Chi tiet                         |";
        cout << "\n\t\t\t\t\t\t| 3.0. Tro ve                           |";
        cout << "\n\t\t\t\t\t\t+ ===================================== +";
        cout << "\n\t\t\t\t\t\tNhap lua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t\t\t[TAT CA]\n";
            parties.display();
            pressAnyKey();
            break;
        }
        case 2:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t\t\t[CHUA THANH TOAN]\n";
            parties.displayByPaymentStatus(0);
            pressAnyKey();
            break;
        }
        case 3:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t\t\t[DA THANH TOAN]\n";
            parties.displayByPaymentStatus(1);
            pressAnyKey();
            break;
        }
        case 4:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t\t\t[XEM CHI TIET]\n";
            parties.display();
            long _ID;
            cout << endl;
            cout << "\n\t\t\t\t\t\tNhap ID tiec can xem chi tiet: ";
            cin >> _ID;
            cout << endl;
            ItemP _party = parties.search(_ID);
            if (_party.getID() != -1)
            {
                system("cls");
                _party.printBill();
            }
            else
                cout << "\n\t\t\t\t\t\t(!) Khong co ton tai tiec nay (!)";
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