#include "program.hpp"

inline void editDisplay(BST &parties);

inline void editDisplay(BST &parties)
{
    int choose;
    bool isExit = false;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t+ ============== CHINH SUA ============== +";
        cout << "\n\t\t\t\t| 2.1. Thong tin khach hang               |";
        cout << "\n\t\t\t\t| 2.2. Thong tin tiec                     |";
        cout << "\n\t\t\t\t| 2.3. Mon an                             |";
        cout << "\n\t\t\t\t| 2.4. Luu thay doi                       |";
        cout << "\n\t\t\t\t| 0. Tro ve                               |";
        cout << "\n\t\t\t\t+ ======================================= +";
        cout << "\n\t\t\t\tNhap lua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 0:
            isExit = true;
            break;
        case 1:
        {
            cout << "\n\t\t\t\t2.1. Nhap thong tin khach hang\n";
            pressAnyKey();
            break;
        }
        case 2:
        {
            cout << "\n\t\t\t\t2.2. Nhap thong tin tiec\n";
            pressAnyKey();
            break;
        }
        case 3:
        {
            cout << "\n\t\t\t\t2.3. Chon mon an\n";
            pressAnyKey();
            break;
        }
        case 4:
        {
            cout << "\n\t\t\t\t2.4. Luu thong tin\n";
            pressAnyKey();
            break;
        }
        default:
            cout << "\n\t\t\t\tLua chon khong hop le !! Nhap lai";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}