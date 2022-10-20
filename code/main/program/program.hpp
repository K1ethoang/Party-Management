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
        cout << "\n\t\t\t\t+ ============== QUAN LY TIEC ============== +";
        cout << "\n\t\t\t\t| 1. Them                                    |";
        cout << "\n\t\t\t\t| 2. Chinh sua                               |";
        cout << "\n\t\t\t\t| 3. Xem danh sach                           |";
        cout << "\n\t\t\t\t| 4. Xoa                                     |";
        cout << "\n\t\t\t\t| 5. Thanh toan                              |";
        cout << "\n\t\t\t\t| 6. In hoa don                              |";
        cout << "\n\t\t\t\t| 0. Thoat chuong trinh                      |";
        cout << "\n\t\t\t\t+ ========================================== +";
        cout << "\n\t\t\t\tNhap lua chon cua ban -> ";
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
            cout << "\n\t\t\tNhap ID tiec can sua: ";
            cin >> ID;
            if (!parties.isExistID(ID))
            {
                cout << "\n\t\t\tKhong co ton tai tiec nay";
                pressAnyKey();
            }
            else
                editDisplay(parties, ID);
            break;
        }
        case 3:
        {
            cout << "\n\t\t\t\tDanh sach cac tiec\n";
            parties.display();
            pressAnyKey();
            break;
        }
        case 4:
        {
            long ID;
            cout << "\n\t\t\t\tNhap ID tiec can xoa: ";
            cin >> ID;
            if (!parties.isExistID(ID))
            {
                cout << "\n\t\t\tKhong co ton tai tiec nay";
                pressAnyKey();
            }
            else
                parties.remove(ID);
            break;
        }
        default:
            cout << "\n\t\t\t\tLua chon khong hop le !! Nhap lai";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}