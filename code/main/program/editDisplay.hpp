#include "program.hpp"

inline void editDisplay(BST &parties, const long &ID);

inline void editDisplay(BST &parties, const long &ID)
{
    int choose;
    bool isExit = false, isSaved = false;
    ItemP partyNeedToEdit = parties.search(ID);
    ItemP p;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t+ ============== CHINH SUA ============== +";
        cout << "\n\t\t\t\t| 2.1. Thong tin khach hang               |";
        cout << "\n\t\t\t\t| 2.2. Thong tin tiec                     |";
        cout << "\n\t\t\t\t| 2.3. Mon an                             |";
        cout << "\n\t\t\t\t| 2.4. Luu thong tin                      |";
        cout << "\n\t\t\t\t| 0. Tro ve                               |";
        cout << "\n\t\t\t\t+ ======================================= +";
        cout << "\n\t\t\t\tNhap lua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            system("cls");
            cout << "\n\t\t\t\t2.1. Thong tin khach hang\n";
            pressAnyKey();
            isSaved = false;
            break;
        }
        case 2:
        {
            system("cls");
            cout << "\n\t\t\t\t2.2. Thong tin tiec\n";
            cin >> p;
            cout << p;
            pressAnyKey();
            isSaved = false;
            break;
        }
        case 3:
        {
            system("cls");
            cout << "\n\t\t\t\t2.3. Mon an\n";
            pressAnyKey();
            isSaved = false;
            break;
        }
        case 4:
        {
            cout << "\n\t\t\t\t2.4. Luu thong tin\n";
            partyNeedToEdit = p;
            parties.update(partyNeedToEdit);
            cout << "\n\t\t\t\tLuu thanh cong\n";
            cout << p;
            isSaved = true;
            pressAnyKey();
            break;
        }
        case 0:
        {
            checkExit(isExit, isSaved);
            if (isSaved)
                parties.update(partyNeedToEdit);
            break;
        }
        default:
            cout << "\n\t\t\t\tLua chon khong hop le !! Nhap lai";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}