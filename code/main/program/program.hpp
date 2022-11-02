#pragma once
#include <iostream>
#include "../Parties/Parties.hpp"
#include "pressAnykey.hpp"
#include "checkReturn.hpp"
#include "./addDisplay.hpp"
#include "./editDisplay.hpp"

using namespace std;

void pressAnyKey();

void program()
{
    BST parties;
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
            addDisplay(parties);
            break;
        }
        case 2:
        {
            long ID;
            cout << "\n\t\t\t\t\t\t\t\t\tNhap ID tiec can sua: ";
            cin >> ID;
            if (!parties.isExistID(ID))
            {
                system("cls");
                cout << "\n\t\t\t\t\t\t\t\t\t<!> Khong co ton tai tiec nay";
                pressAnyKey();
            }
            else
                editDisplay(parties, ID);
            break;
        }
        case 3:
        {
            cout << "\n\t\t\t+==================+=======================================+======================+===========================+==========================+" << endl;
            cout << "\t\t\t|                                                           DANH SACH CAC TIEC                                                           |" << endl;
            cout << "\t\t\t+==================+=======================================+======================+===========================+==========================+" << endl;
            cout << "\t\t\t|        ID        |               Loai tiec               |        So ban        |         Thoi gian         |        Trang thai        |" << endl;
            cout << "\t\t\t+==================+=======================================+======================+===========================+==========================+";
            cout << "\t\t\t";
            parties.display();
            pressAnyKey();
            break;
        }
        case 4:
        {
            long ID;
            cout << "\n\t\t\t\t\t\t\t\t\tNhap ID tiec can xoa: ";
            cin >> ID;
            if (!parties.isExistID(ID))
            {
                cout << "\n\t\t\t\t\t\t\t\t\t>>> Khong co ton tai tiec nay <<<";
            }
            else
            {
                parties.remove(ID);
                cout << "\n\t\t\t\t\t\t\t\t\t>>> Xoa thanh cong! <<<\n";
            }
            pressAnyKey();
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
                ItemP partyNeedToPrintBill = parties.search(ID);
                partyNeedToPrintBill.outputParty();
                // parties.remove(ID);
                cout << "\n\t\t\t\t\t\t\t\t\t>>> In hoa don thanh cong! <<<\n";
            }
            pressAnyKey();
            break;
        }
        default:
            cout << "\n\t\t\t\t\t\t\t\t\t>>> Lua chon khong hop le !! Nhap lai <<<";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}
