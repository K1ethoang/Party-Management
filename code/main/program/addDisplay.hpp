#include "program.hpp"

inline void addDisplay(PartiesBST &parties);
void saveParty(PartiesBST &parties, const ItemP &party);

inline void addDisplay(PartiesBST &parties)
{
    int choose;
    bool isExit = false, isSaved = true;
    ItemC customer;
    ItemP party;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t\t+ ============== THEM ============== +";
        cout << "\n\t\t\t\t\t\t| 1.1. Thong tin khach hang          |";
        cout << "\n\t\t\t\t\t\t| 1.2. Thong tin tiec                |";
        cout << "\n\t\t\t\t\t\t| 1.3. Chon mon an                   |";
        cout << "\n\t\t\t\t\t\t| 1.4. Luu thong tin                 |";
        cout << "\n\t\t\t\t\t\t| 1.0. Tro ve                        |";
        cout << "\n\t\t\t\t\t\t+ ================================== +";
        cout << "\n\t\t\t\t\t\tNhap lua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t[NHAP THONG TIN KHACH HANG]\n";
            cin >> customer;
            system("cls");
            cout << "\n\t\t\t\t\t\t[THONG TIN KHACH HANG VUA NHAP]\n";
            customer.setID(party.getID());
            customer.outputCustomer();
            pressAnyKey();
            isSaved = false;
            break;
        }
        case 2:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t[NHAP THONG TIN TIEC]\n";
            cin >> party;
            long _id = party.getID();
            do
            {
                if (parties.isExistID(party.getID()))
                {
                    cout << "\n\t\t\t(!) Da ton tai ID nay, nhap lai: ";
                    cin >> _id;
                    party.setID(_id);
                }
            } while (parties.isExistID(party.getID()));
            customer.setID(party.getID());
            party.setCustomer(customer);
            system("cls");
            cout << "\n\t\t\t\t\t\t[THONG TIN TIEC VUA NHAP]\n";
            party.outputParty();
            isSaved = false;
            pressAnyKey();
            break;
        }
        case 3:
        {
            cout << "\n\t\t\t\t\t\t[CHON MON AN]\n";
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
            if (party.getID() != -1 && customer.getID() != -1)
            {
                cout << "\n\t\t\t\t\t\t</> Luu thanh cong </>\n";
                customer.outputCustomer();
                cout << "\n\n";
                party.outputParty();
                isSaved = true;
            }
            else
                cout << "\n\t\t\t\t\t\t(!) Khong the luu vi ban chua nhap du thong tin (!)\n";
            pressAnyKey();
            break;
        }
        case 0:
        {
            checkExit(isExit, isSaved);
            if (isSaved && (party.getID() != -1 && customer.getID() != -1))
                saveParty(parties, party);
            break;
        }
        default:
            cout << "\n\t\t\t\t\t\tLua chon khong hop le !! Nhap lai";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}

void saveParty(PartiesBST &parties, const ItemP &party)
{
    parties.add(party);
}
