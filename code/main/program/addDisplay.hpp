#include "program.hpp"

inline void addDisplay(BST &parties);
void saveData(BST &parties, ItemP party);

inline void addDisplay(BST &parties)
{
    int choose;
    bool isExit = false, isSaved = false;
    ItemC c;
    ItemP p;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t+ ============== THEM ============== +";
        cout << "\n\t\t\t\t| 1.1. Nhap thong tin khach hang     |";
        cout << "\n\t\t\t\t| 1.2. Nhap thong tin tiec           |";
        cout << "\n\t\t\t\t| 1.3. Chon mon an                   |";
        cout << "\n\t\t\t\t| 1.4. Luu thong tin                 |";
        cout << "\n\t\t\t\t| 1.0. Tro ve                        |";
        cout << "\n\t\t\t\t+ ================================== +";
        cout << "\n\t\t\t\tNhap lua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            cout << "\n\t\t\t\t1.1. Nhap thong tin khach hang\n";
            cin >> c;
            cout << c;
            p.setCustomer(c);
            pressAnyKey();
            isSaved = false;
            break;
        }
        case 2:
        {
            cout << "\n\t\t\t\t1.2. Nhap thong tin tiec\n";
            cin >> p;
            do
            {
                if (parties.isExistID(p.getID()))
                {
                    long id;
                    cout << "\n\t\t\tDa ton tai ID nay, nhap lai: ";
                    cin >> id;
                    p.setID(id);
                }
            } while (parties.isExistID(p.getID()));
            cout << "\n\t\t\t\tThong tin tiec vua nhap\n";
            p.outputParty();
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
            cout << "\n\t\t\t\t1.4. Luu thong tin\n\n";
            saveData(parties, p);
            isSaved = true;
            pressAnyKey();
            break;
        }
        case 0:
        {
            checkExit(isExit, isSaved);
            if (isSaved)
                saveData(parties, p);
            break;
        }
        default:
            cout << "\n\t\t\t\tLua chon khong hop le !! Nhap lai";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}

void saveData(BST &parties, ItemP party)
{
    parties.add(party);
    cout << "\n\t\t\t\tLuu thanh cong\n";
    party.outputParty();
}
