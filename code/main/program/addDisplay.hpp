#include "program.hpp"

inline void addDisplay(PartiesBST &parties, CustomersSLL &customers);
void saveParty(PartiesBST &parties, ItemP party);

inline void addDisplay(PartiesBST &parties, CustomersSLL &customers)
{
    int choose;
    bool isExit = false, isSaved = true;
    ItemC c;
    ItemP p;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t\t\t\t\t+ ============== THEM ============== +";
        cout << "\n\t\t\t\t\t\t\t\t\t| 1.1. Nhap thong tin khach hang     |";
        cout << "\n\t\t\t\t\t\t\t\t\t| 1.2. Nhap thong tin tiec           |";
        cout << "\n\t\t\t\t\t\t\t\t\t| 1.3. Chon mon an                   |";
        cout << "\n\t\t\t\t\t\t\t\t\t| 1.4. Luu thong tin                 |";
        cout << "\n\t\t\t\t\t\t\t\t\t| 1.0. Tro ve                        |";
        cout << "\n\t\t\t\t\t\t\t\t\t+ ================================== +";
        cout << "\n\t\t\t\t\t\t\t\t\tNhap lua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t\t\t\t[1.1. NHAP THONG TIN KHACH HANG]\n";
            cin >> c;
            system("cls");
            c.outputCustomer();
            p.setCustomer(c);
            pressAnyKey();
            isSaved = false;
            break;
        }
        case 2:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t\t\t\t[1.2. NHAP THONG TIN TIEC]";
            cin >> p;
            long _id = p.getID();
            do
            {
                if (parties.isExistID(p.getID()))
                {
                    cout << "\n\t\t\tDa ton tai ID nay, nhap lai: ";
                    cin >> _id;
                    p.setID(_id);
                }
            } while (parties.isExistID(p.getID()));
            c.setID(_id);
            system("cls");
            cout << "\n\t\t\t\t\t\t\t\t\t[Thong tin tiec vua nhap]\n\n";
            p.outputParty();
            pressAnyKey();
            isSaved = false;
            break;
        }
        case 3:
        {
            cout << "\n\t\t\t\t\t\t\t\t\t[1.3. Chon mon an]\n";
            // Queue<string> resMenu = Menu(); // food của menu
            // p.setMenu(resMenu);
            // resMenu = p.getMenu();
            // resMenu.display();
            pressAnyKey();
            isSaved = false;
            break;
        }
        case 4:
        {
            if (p.getID() != -1)
            {
                cout << "\n\t\t\t\t\t\t\t\t\t<\\> Luu thanh cong <\\>\n";
                isSaved = true;
            }
            else
                cout << "\n\t\t\t\t\t\t\t\t\t(!) Khong the luu vi ban chua nhap tiec (!)\n";
            pressAnyKey();
            break;
        }
        case 0:
        {
            checkExit(isExit, isSaved);
            if (isSaved && p.getID() != -1)
                saveParty(parties, p);
            break;
        }
        default:
            cout << "\n\t\t\t\t\t\t\t\t\tLua chon khong hop le !! Nhap lai";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}

void saveParty(PartiesBST &parties, ItemP party)
{
    parties.add(party);
}
