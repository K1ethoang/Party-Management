#include "program.hpp"

inline void editDisplay(PartiesBST &parties, FoodsCDLL foods, const long &ID);
void chooseFunctionParty(ItemP &party);
void chooseFunctionCustomer(ItemC &customer);

inline void editDisplay(PartiesBST &parties, FoodsCDLL foods, const long &ID)
{
    bool isExit = false, isSaved = true;
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
        cout << "\n\t\t\t\t\t\t| 2.0. Tro ve                             |";
        cout << "\n\t\t\t\t\t\t+ ======================================= +";
        int choose = returnChoose("Nhap lua chon cua ban -> ");
        switch (choose)
        {
        case 1:
        {
            system("cls");
            chooseFunctionCustomer(customerNeedToEdit);
            isSaved = false;
            break;
        }
        case 2:
        {
            system("cls");
            chooseFunctionParty(partyNeedToEdit);
            isSaved = false;
            break;
        }
        case 3:
        {
            system("cls");
            vector<ItemF> _menu = foods.chooseMenu();
            if (_menu.size() != 0)
                partyNeedToEdit.setMenu(_menu);
            isSaved = false;
            break;
        }
        case 4:
        {
            cout << "\n\t\t\t\t\t\t\tLUU THONG TIN\n";
            partyNeedToEdit.setCustomer(customerNeedToEdit);
            parties.update(partyNeedToEdit);
            cout << "\n\t\t\t\t\t\t</> Luu thanh cong </>\n";
            customerNeedToEdit.outputCustomer();
            cout << "\n\n";
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
    bool isExit = false;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t\t+ ======= CHINH SUA THONG TIN TIEC ====== +";
        cout << "\n\t\t\t\t\t\t| 2.2.1. Loai tiec                        |";
        cout << "\n\t\t\t\t\t\t| 2.2.2. So ban                           |";
        cout << "\n\t\t\t\t\t\t| 2.2.3. Thoi gian to chuc                |";
        cout << "\n\t\t\t\t\t\t| 2.2.4. Xem thong tin                    |";
        cout << "\n\t\t\t\t\t\t| 2.2.0. Tro ve                           |";
        cout << "\n\t\t\t\t\t\t+ ======================================= +";
        int choose = returnChoose("Nhap lua chon cua ban -> ");
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
            newTableNumber = returnChoose("Nhap so ban moi: ");
            party.setTableNumber(newTableNumber);
            pressAnyKey();
            break;
        }
        case 3:
        {
            Date _newDate;
            cout << "\n\t\t\t\t\t\tNhap thoi gian to chuc moi: " << endl;
            _newDate.inputDate("(!) Ngay thang khong hop le (!)");
            party.setDate(_newDate);
            party.setPartyStatus();
            pressAnyKey();
            break;
        }
        case 4:
        {
            cout << "\n\t\t\t\t\t\t</> Thong tin moi cap nhat </>\n";
            party.outputParty();
            pressAnyKey();
            break;
        }
        case 0:
        {
            isExit = true;
            break;
        }
        default:
            cout << "\n\t\t\t\t\t\t(!) Lua chon khong hop le (!)";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}

void chooseFunctionCustomer(ItemC &customer)
{
    bool isExit = false;
    do
    {
        system("cls");
        cout << "\n\t\t\t\t\t\t+ ====== CHINH SUA THONG TIN KHACH HANG ======= +";
        cout << "\n\t\t\t\t\t\t| 2.1.1. Ho ten                                 |";
        cout << "\n\t\t\t\t\t\t| 2.1.2. So dien thoai                          |";
        cout << "\n\t\t\t\t\t\t| 2.1.3. Can cuoc cong dan                      |";
        cout << "\n\t\t\t\t\t\t| 2.1.4. Xem thong tin                          |";
        cout << "\n\t\t\t\t\t\t| 2.1.0. Tro ve                                 |";
        cout << "\n\t\t\t\t\t\t+ ============================================= +";
        int choose = returnChoose("Nhap lua chon cua ban -> ");
        switch (choose)
        {
        case 1:
        {
            string newNameCustomer;
            fflush(stdin);
            cout << "\n\t\t\t\t\t\tNhap ho va ten moi: ";
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
            customer.setPhoneNumber(newPhoneNumberCustomer);
            pressAnyKey();
            break;
        }
        case 3:
        {
            string newIdentityCardCustomer;
            do
            {
                cout << "\n\t\t\t\t\t\tNhap so CCCD moi: ";
                fflush(stdin);
                getline(cin, newIdentityCardCustomer);
                if (!isValidIdentityCard(newIdentityCardCustomer))
                    cout << "\n\t\t\t\t\t\t(!) So CCCD khong hop le (!)\n";
            } while (!isValidIdentityCard(newIdentityCardCustomer));
            customer.setIdentityCard(newIdentityCardCustomer);
            pressAnyKey();
            break;
        }
        case 4:
        {
            cout << "\n\t\t\t\t\t\t</> Thong tin moi cap nhat </>\n";
            customer.outputCustomer();
            pressAnyKey();
            break;
        }
        case 0:
        {
            isExit = true;
            break;
        }
        default:
            cout << "\n\t\t\t\t\t\t(!) Lua chon khong hop le (!)";
            pressAnyKey();
            break;
        }
    } while (!isExit);
}