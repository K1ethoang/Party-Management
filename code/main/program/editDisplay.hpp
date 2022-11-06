#include "program.hpp"

inline void editDisplay(PartiesBST &parties, const long &ID);
void chooseFunctionParty(ItemP &party);
void chooseFunctionCustomer(ItemC &customer);

inline void editDisplay(PartiesBST &parties, const long &ID)
{
    int choose;
    bool isExit = false, isSaved = false;
    ItemP partyNeedToEdit = parties.search(ID); // search ID có party cần chỉnh sửa
    ItemC customerNeedToEdit = partyNeedToEdit.getCustomer();
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t\t+ ============== CHINH SUA ============== +";
        cout << "\n\t\t\t\t\t\t| 2.1. Thong tin khach hang               |";
        cout << "\n\t\t\t\t\t\t| 2.2. Thong tin tiec                     |";
        cout << "\n\t\t\t\t\t\t| 2.3. Mon an                             |";
        cout << "\n\t\t\t\t\t\t| 2.4. Luu thong tin                      |";
        cout << "\n\t\t\t\t\t\t| 0. Tro ve                               |";
        cout << "\n\t\t\t\t\t\t+ ======================================= +";
        cout << "\n\t\t\t\t\t\tNhap lua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t2.1. Thong tin khach hang\n";
            chooseFunctionCustomer(customerNeedToEdit);
            isSaved = false;
            break;
        }
        case 2:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t2.2. Thong tin tiec\n";
            chooseFunctionParty(partyNeedToEdit);
            partyNeedToEdit.outputParty();
            isSaved = false;
            break;
        }
        case 3:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t2.3. Mon an\n";
            pressAnyKey();
            isSaved = false;
            break;
        }
        case 4:
        {
            cout << "\n\t\t\t\t\t\t2.4. Luu thong tin\n";
            parties.update(partyNeedToEdit);
            cout << "\n\t\t\t\t\t\t<\\> Luu thanh cong <\\>\n";
            partyNeedToEdit.outputParty();
            pressAnyKey();
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
            cout << "\n\t\t\t\t\t\tLua chon khong hop le !! Nhap lai";
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
        cout << "\n\t\t\t\t\t\t1. Loai tiec";
        cout << "\n\t\t\t\t\t\t2. So ban";
        cout << "\n\t\t\t\t\t\t3. Thoi gian to chuc";
        cout << "\n\t\t\t\t\t\t4. Mon an";
        cout << "\n\t\t\t\t\t\t5. Luu";
        cout << "\n\t\t\t\t\t\t0. Thoat";
        cout << "\n\t\t\t\t\t\tNhap lua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            string newTypeParty = chooseTypeParty();
            party.setTypeParty(newTypeParty);
            pressAnyKey();
            break;
        }
        case 2:
        {
            int newTableNumber;
            cout << "\n\t\t\t\t\t\tNhap so ban moi: ";
            cin >> newTableNumber;
            party.setTableNumber(newTableNumber);
            pressAnyKey();
            break;
        }
        case 3:
        {
            Date newDate;
            cout << "\n\t\t\t\t\t\tNhap thoi gian to chuc moi: " << endl;
            newDate.inputDate("\t\t\t\t\t\t\t\t\t(!) Ngay thang khong hop le (!)");
            party.setDate(newDate);
            party.setPartyStatus();
            pressAnyKey();
            break;
        }
        case 4:
        {
            cout << "\n\tNhap thoi gian to chuc moi\n";
            pressAnyKey();
            break;
        }
        case 5:
        {
            cout << "\n\t\t\t\t\t\t<\\> Luu thanh cong <\\>\n";
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
            cout << "\n\t\t\t\t\t\tLua chon khong hop le !! Nhap lai";
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
        cout << "\n\t\t\t\t\t\t1. Ho ten";
        cout << "\n\t\t\t\t\t\t2. So dien thoai";
        cout << "\n\t\t\t\t\t\t3. Dia chi";
        cout << "\n\t\t\t\t\t\t4. Luu";
        cout << "\n\t\t\t\t\t\t0. Thoat";
        cout << "\n\t\t\t\t\t\tNhap lua chon cua ban -> ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            string newNameCustomer;
            cout << "\n\t\t\t\t\t\t\t\tNhap ho va ten moi: ";
            fflush(stdin);
            getline(cin, newNameCustomer);
            formatName(newNameCustomer);
            customer.setFullName(newNameCustomer);
            pressAnyKey();
            break;
        }
        case 2:
        {
            string newPhoneNumberCustomer;
            do
            {
                cout << "\n\t\t\t\t\t\tNhap so dien thoai moi: ";
                fflush(stdin);
                getline(cin, newPhoneNumberCustomer);
                if (!isValidPhoneNumber(newPhoneNumberCustomer))
                    cout << "\n\t\t\t\t\t\t(!) So dien thoai khong hop le (!)\n";
            } while (!isValidPhoneNumber(newPhoneNumberCustomer));
            pressAnyKey();
            break;
        }
        case 3:
        {
            string newCCCDCustomer;
            cout << "\n\t\t\t\t\t\t\t\tNhap dia chi moi: ";
            fflush(stdin);
            getline(cin, newCCCDCustomer);
            formatName(newCCCDCustomer);
            customer.setCCCD(newCCCDCustomer);
            pressAnyKey();
            break;
        }
        case 4:
        {
            system("cls");
            cout << "\n\t\t\t\t\t\t<\\> Luu thanh cong <\\>\n";
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
            cout << "\n\t\t\t\t\t\t\t\tLua chon khong hop le !! Vui long nhap lai";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}