#pragma once
#include "../Customers/Customers.hpp"
#include "../Parties/Parties.hpp"
#include "../Foods/Foods.hpp"
#include "pressAnykey.hpp"
#include "checkReturn.hpp"
#include "./addDisplay.hpp"
#include "./editDisplay.hpp"
#include "../constance.hpp"

using namespace std;

void program();
void pressAnyKey();

void program()
{
    CustomersSLL customers;
    PartiesBST parties;
    parties.importPartiesData(PARTY_DATA_PATH);
    customers.importCustomersData(CUSTOMER_DATA_PATH);
    customers.sortByID();
    customers.exportCustomersData(CUSTOMER_DATA_PATH);
    int choose;
    bool isExit = false;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t\t\t\t\t+ ============== QUAN LY TIEC ============== +";
        cout << "\n\t\t\t\t\t\t\t\t\t| 1. Them                                    |";
        cout << "\n\t\t\t\t\t\t\t\t\t| 2. Chinh sua                               |";
        cout << "\n\t\t\t\t\t\t\t\t\t| 3. Xem danh sach                           |";
        cout << "\n\t\t\t\t\t\t\t\t\t| 4. Xoa                                     |";
        cout << "\n\t\t\t\t\t\t\t\t\t| 5. Thanh toan                              |";
        cout << "\n\t\t\t\t\t\t\t\t\t| 6. In hoa don                              |";
        cout << "\n\t\t\t\t\t\t\t\t\t| 0. Thoat chuong trinh                      |";
        cout << "\n\t\t\t\t\t\t\t\t\t+ ========================================== +";
        cout << "\n\t\t\t\t\t\t\t\t\tNhap lua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 0:
            isExit = true;
            cout << "\nThoat chuong trinh thanh cong !";
            pressAnyKey();
            break;
        case 1:
        {
            addDisplay(parties, customers);
            parties.exportPartiesData(PARTY_DATA_PATH);
            break;
        }
        case 2:
        {
            long _ID;
            cout << "\n\t\t\t\t\t\t\t\t\tNhap ID tiec can sua: ";
            cin >> _ID;
            if (parties.isExistID(_ID))
                editDisplay(parties, _ID);
            else
            {
                cout << "\n\t\t\t\t\t\t\t\t\t<!> Khong co ton tai tiec nay";
                pressAnyKey();
            }
            parties.exportPartiesData(PARTY_DATA_PATH);

            break;
        }
        case 3:
        {
            parties.display();
            pressAnyKey();
            break;
        }
        case 4:
        {
            long ID;
            cout << "\n\t\t\t\t\t\t\t\t\tNhap ID tiec can xoa: ";
            cin >> ID;
            if (parties.isExistID(ID))
            {
                char answer;
                do
                {
                    cout << "\n\t\t\t\t\t\t\t\tBan co chac chan muon xoa? (y/n): ";
                    fflush(stdin);
                    cin >> answer;
                    if (answer == 'y')
                    {
                        parties.remove(ID);
                        parties.exportPartiesData(PARTY_DATA_PATH);
                        cout << "\n\t\t\t\t\t\t\t\t\t>>> Xoa thanh cong! <<<\n";
                        pressAnyKey();
                    }
                    else if (answer == 'n')
                        break;
                } while (answer != 'y' && answer != 'n');
            }
            else
                cout << "\n\t\t\t\t\t\t\t\t\t>>> Khong co ton tai tiec nay <<<";
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            long ID;
            cout << "\n\t\t\t\t\t\t\t\t\tNhap ID tiec can xem hoa don: ";
            cin >> ID;
            if (!parties.isExistID(ID))
            {
                cout << "\n\t\t\t\t\t\t\t\t\t>>> Khong co ton tai tiec nay <<<";
            }
            else
            {
                parties.getRoot()->data.printBill();
                // parties.remove(ID);
                cout << "\n\t\t\t\t\t\t\t\t\t>>> Da xem ! <<<\n";
            }
            break;
            // pressAnyKey();
        }
        default:
            cout << "\n\t\t\t\t\t\t\t\t\t(!) Lua chon khong hop le (!)";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}
