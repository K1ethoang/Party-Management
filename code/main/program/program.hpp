#pragma once
#include <iostream>
#include <string>
#include "../Customers/Customers.hpp"
#include "../Parties/Parties.hpp"
#include "../Foods/Foods.hpp"
#include "pressAnykey.hpp"
#include "checkReturn.hpp"
#include "./addDisplay.hpp"
#include "./editDisplay.hpp"
#include "./viewDisplay.hpp"
#include "../constance.hpp"

using namespace std;

void program();
void pressAnyKey();

void program()
{
    PartiesBST parties;
    parties.importPartiesData(PARTY_DATA_PATH);
    int choose;
    bool isExit = false;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t\t+ ============== QUAN LY TIEC ============== +";
        cout << "\n\t\t\t\t\t\t| 1. Them                                    |";
        cout << "\n\t\t\t\t\t\t| 2. Chinh sua                               |";
        cout << "\n\t\t\t\t\t\t| 3. Xem danh sach                           |";
        cout << "\n\t\t\t\t\t\t| 4. Xoa                                     |";
        cout << "\n\t\t\t\t\t\t| 5. Thanh toan                              |";
        cout << "\n\t\t\t\t\t\t| 6. In hoa don                              |";
        cout << "\n\t\t\t\t\t\t| 0. Thoat chuong trinh                      |";
        cout << "\n\t\t\t\t\t\t+ ========================================== +";
        cout << "\n\t\t\t\t\t\tNhap lua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 0:
            isExit = true;
            break;
        case 1:
        {
            addDisplay(parties);
            parties.exportPartiesData(PARTY_DATA_PATH);
            break;
        }
        case 2:
        {
            long _ID;
            cout << "\n\t\t\t\t\t\tNhap ID tiec can sua: ";
            cin >> _ID;
            if (parties.isExistID(_ID))
                editDisplay(parties, _ID);
            else
            {
                cout << "\n\t\t\t\t\t\t(!) Khong co ton tai tiec nay (!)";
                pressAnyKey();
            }
            parties.exportPartiesData(PARTY_DATA_PATH);
            break;
        }
        case 3:
        {
            viewDisplay(parties);
            break;
        }
        case 4:
        {
            long ID;
            cout << "\n\t\t\t\t\t\tNhap ID tiec can xoa: ";
            cin >> ID;
            if (parties.isExistID(ID))
            {
                char answer;
                do
                {
                    cout << "\n\t\t\t\t\tBan co chac chan muon xoa? (y/n): ";
                    fflush(stdin);
                    cin >> answer;
                    if (answer == 'y')
                    {
                        parties.remove(ID);
                        parties.exportPartiesData(PARTY_DATA_PATH);
                        cout << "\n\t\t\t\t\t\t</> Xoa thanh cong </>\n";
                        pressAnyKey();
                    }
                    else if (answer == 'n')
                        break;
                } while (answer != 'y' && answer != 'n');
            }
            else
                cout << "\n\t\t\t\t\t\t>>> Khong co ton tai tiec nay <<<";
            break;
        }
        case 5:
        {
            parties.displayByPaymentStatus(0);
            long _ID;
            cout << endl;
            cout << "\n\t\t\t\t\t\tNhap ID tiec can thanh toan: ";
            cin >> _ID;
            ItemP _party = parties.search(_ID);
            if (_party.getID() != -1)
            {
                _party.setIsPaymentStatus(1);
                parties.update(_party);
                parties.exportPartiesData(PARTY_DATA_PATH);
                cout << "\n\t\t\t\t\t\t</> Thanh toan thanh cong </>\n";
            }
            else
                cout << "\n\t\t\t\t\t\t(!) Khong co ton tai tiec nay (!)";
            pressAnyKey();
            break;
        }
        case 6:
        {
            long _ID;
            cout << "\n\t\t\t\t\t\tNhap ID tiec can in bill: ";
            cin >> _ID;
            ItemP _party = parties.search(_ID);
            if (_party.getID() != -1)
            {
                ItemC _customer = _party.getCustomer();
                string save_path = BILL_SAVER_FOLDER_PATH + '/' + to_string(_customer.getID()) + '_' + _customer.getFullName() + ".txt";
                ofstream fileOut(save_path);
                if (fileOut.is_open())
                {
                    _party.writeABill(fileOut);
                    cout << "\n\t\t\t\tHoa don cua ban duoc luu theo duong dan sau: " << endl;
                    cout << "\t\t\tcode -> data -> Hoa-Don -> " << _customer.getID() << "_" << _customer.getFullName() << ".txt";
                }
                fileOut.close();
            }
            else
            {
                parties.getRoot()->data.printBill();
                // parties.remove(ID);
                cout << "\n\t\t\t\t\t\t\t\t\t>>> Da xem ! <<<\n";
            }

            // pressAnyKey();

            cout << "\n\t\t\t\t\t\t(!) Khong co ton tai tiec nay (!)";
            pressAnyKey();
            break;
        }
        default:
            cout << "\n\t\t\t\t\t\t(!) Lua chon khong hop le (!)";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}
