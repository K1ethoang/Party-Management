#include "program.hpp"

#define ItemP Party

inline void addDisplay(BST &parties);
void saveData(BST &parties, ItemP data);

inline void addDisplay(BST &parties)
{
    int choose;
    bool isExit = false, isSaved = false;
    ItemP p;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t+ ============== THEM ============== +";
        cout << "\n\t\t\t\t| 1.1. Nhap thong tin khach hang     |";
        cout << "\n\t\t\t\t| 1.2. Nhap thong tin tiec           |";
        cout << "\n\t\t\t\t| 1.3. Chon mon an                   |";
        cout << "\n\t\t\t\t| 1.4. Luu thong tin                 |";
        cout << "\n\t\t\t\t| 0. Tro ve                          |";
        cout << "\n\t\t\t\t+ ================================== +";
        cout << "\n\t\t\t\tNhap lua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 0:
        {
            if (isSaved)
                isExit = true;
            else
            {
                cout << "\n\t\t\t\tLuu thong tin truoc khi thoat!!";
                pressAnyKey();
            }
            break;
        }
        case 1:
        {
            cout << "\n\t\t\t\t1.1. Nhap thong tin khach hang\n";
            pressAnyKey();
            isSaved = false;
            break;
        }
        case 2:
        {
            cout << "\n\t\t\t\t1.2. Nhap thong tin tiec\n";
            cin >> p;
            cout << "\n\t\t\t\tThong tin tiec vua nhap\n";
            cout << p;
            pressAnyKey();
            isSaved = false;
            break;
        }
        case 3:
        {
            cout << "\n\t\t\t\t1.3. Chon mon an\n";
            pressAnyKey();
            isSaved = false;
            break;
        }
        case 4:
        {
            cout << "\n\t\t\t\t1.4. Luu thong tin\n";

            isSaved = true;
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

void saveData(BST &parties, ItemP data)
{
    parties.add(data);
    cout << "\n\t\t\t\tLuu thanh cong\n";
    cout << data;
}