#pragma once
#include <iostream>
#include <string>
#include "../Customers/Customers.hpp"
#include "../Parties/Parties.hpp"
#include "../Foods/Foods.hpp"
#include "pressAnykey.hpp"
#include "exportBillParty.hpp"
#include "checkReturn.hpp"
#include "./addDisplay.hpp"
#include "./editDisplay.hpp"
#include "./viewDisplay.hpp"
#include "./paymentDisplay.hpp"
#include "../constance.hpp"

using namespace std;

void program();

void program()
{
    PartiesBST parties;
    FoodsCDLL l;
    parties.importPartiesData(PARTY_DATA_PATH);
    // for (int i = 0; i < NUMBER_FOOD_PATH; i++)
    // {
    //     string foodPath;
    //     foodPath = FOOD_SAVER_FOLDER_PATH + "/" + to_string(i + 1) + ".txt";
    //     l.importFood(foodPath);
    // }
    // l.display();
    // pressAnyKey();
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
            {
                editDisplay(parties, _ID);
                parties.exportPartiesData(PARTY_DATA_PATH);
            }
            else
            {
                cout << "\n\t\t\t\t\t\t(!) Khong co ton tai tiec nay (!)";
                pressAnyKey();
            }
            break;
        }
        case 3:
        {
            viewDisplay(parties);
            break;
        }
        case 4:
        {
            parties.display();
            cout << endl;
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
                    }
                    else if (answer == 'n')
                        break;
                } while (answer != 'y' && answer != 'n');
            }
            else
                cout << "\n\t\t\t\t\t\t>>> Khong co ton tai tiec nay <<<";
            pressAnyKey();
            break;
        }
        case 5:
        {
            parties.displayByPaymentStatus(0);
            cout << endl;
            long _ID;
            cout << "\n\t\t\t\t\t\tNhap ID tiec can thanh toan: ";
            cin >> _ID;
            cout << endl;
            ItemP _party = parties.search(_ID);
            if (parties.isPaid(_party.getID()) && _party.getID() != -1)
                cout << "\n\t\t\t\t\t\t(!) Tiec nay da thanh toan (!)";
            else if (_party.getID() != -1)
                paymentDisplay(parties, _party);
            else
            {
                cout << "\n\t\t\t\t\t\t(!) Khong co ton tai tiec nay (!)";
                pressAnyKey();
            }
            break;
        }
        case 6:
        {
            parties.display();
            cout << endl;
            long _ID;
            cout << "\n\t\t\t\t\t\tNhap ID tiec can in bill: ";
            cin >> _ID;
            ItemP _party = parties.search(_ID);
            system("cls");
            if (_party.getID() != -1)
                exportBillParty(_party);
            else
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
