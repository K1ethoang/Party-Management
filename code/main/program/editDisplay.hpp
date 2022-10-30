#include "program.hpp"

inline void editDisplay(BST &parties, const long &ID);
void chooseFunctionParty(ItemP &party);
void chooseFunctionCustomer(ItemC &customer);

inline void editDisplay(BST &parties, const long &ID)
{
    int choose;
    bool isExit = false, isSaved = false;
    ItemP partyNeedToEdit = parties.search(ID); // search ID có party cần chỉnh sửa
    ItemC customerNeedToEdit = partyNeedToEdit.getCustomer();
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
            chooseFunctionCustomer(customerNeedToEdit);
            isSaved = false;
            break;
        }
        case 2:
        {
            system("cls");
            cout << "\n\t\t\t\t2.2. Thong tin tiec\n";
            chooseFunctionParty(partyNeedToEdit);
            partyNeedToEdit.outputParty();
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
            parties.update(partyNeedToEdit);
            cout << "\n\t\t\t\tLuu thanh cong\n";
            partyNeedToEdit.outputParty();
            isSaved = true;
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

void chooseFunctionParty(ItemP &party)
{
    int choose;
    bool isExit = false, isSaved = false;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t1. Loai tiec";
        cout << "\n\t\t\t\t2. So ban";
        cout << "\n\t\t\t\t3. Thoi gian to chuc";
        cout << "\n\t\t\t\t4. Mon an";
        cout << "\n\t\t\t\t5. Luu";
        cout << "\n\t\t\t\t0. Thoat";
        cout << "\n\t\t\t\tNhap lua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            string newTypeParty = typeParty_();
            party.set_TypeParty(newTypeParty);
            pressAnyKey();
            break;
        }
        case 2:
        {
            int newTableNumber;
            cout << "\n\t\t\tNhap so ban moi: ";
            cin >> newTableNumber;
            party.setTableNumber(newTableNumber);
            pressAnyKey();
            break;
        }
        case 3:
        {
            Date newDate;
            cout << "\n\t\t\tNhap thoi gian to chuc moi: ";
            inputDate(newDate, "Ngay thang khong hop le"); // Thoi gian to chuc buoi tiec
            party.setDate(newDate);
            party.setStatus();
            pressAnyKey();
            break;
        }
        case 4:
        {
            cout << "\n\t\t\tNhap thoi gian to chuc moi\n";
            pressAnyKey();
            break;
        }
        case 5:
        {
            cout << "\n\t\t\tLuu thanh cong\n\n";
            isSaved = true;
            party.outputParty();
            pressAnyKey();
            break;
        }
        case 0:
        {
            checkExit(isExit, isSaved);
            break;
        }
        default:
            cout << "\n\t\t\t\tLua chon khong hop le !! Nhap lai";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}

void chooseFunctionCustomer(ItemC &customer)
{
    int choose;
    bool isExit = false, isSaved = false;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t1. Ho ten";
        cout << "\n\t\t\t\t2. So dien thoai";
        cout << "\n\t\t\t\t3. Luu";
        cout << "\n\t\t\t\t0. Thoat";
        cout << "\n\t\t\t\tNhap lua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            string newNameCustomer;
            cout << "\n\t\t\tNhap ho va ten moi: ";
            fflush(stdin);
            getline(cin, newNameCustomer);
            customer.setFullName(newNameCustomer);
            pressAnyKey();
            break;
        }
        case 2:
        {
            string newPhoneNumberCustomer;
            cout << "\n\t\t\tNhap so dien thoai moi: ";
            fflush(stdin);
            getline(cin, newPhoneNumberCustomer);
            customer.setPhoneNumber(newPhoneNumberCustomer);
            pressAnyKey();
            break;
        }
        case 3:
        {
            cout << "\n\t\t\tLuu thanh cong\n\n";
            isSaved = true;
            customer.outputCustomer();
            pressAnyKey();
            break;
        }
        case 0:
        {
            checkExit(isExit, isSaved);
            break;
        }
        default:
            cout << "\n\t\t\t\tLua chon khong hop le !! Nhap lai";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}