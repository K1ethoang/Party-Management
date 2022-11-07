#include "./program/program.hpp"
#include "conio.h"

int main()
{
    // program();
    // đọc file
    FoodsCDLL l;
    for (int i = 0; i < NUMBER_FOOD_PATH; i++)
    {
        string foodPath;
        foodPath = FOOD_SAVER_FOLDER_PATH + "/" + to_string(i + 1) + ".txt";
        l.importFood(foodPath);
    }

    // xem thực đơn
    char keyPress;
    NodeF *head = l.getHead();
    int page = 1;
    do
    {
        system("cls");
        // cout << "\n\tTrang " << page << endl;
        head->displayANode();
        cout << endl;
        // cout << "\t\t+=================================================================================+" << endl;
        // cout << "\t\t                                                                    +=============+" << endl;
        // cout << "\t\t                                                                |     <- 2 ->     |" << endl
        cout << "\n\t\tESC de thoat                                                           <-  " << setiosflags(ios::left) << page << "/" << setw(2) << l.getSize() << " ->   " << endl;
        // cout << "\t\t                                                                    +=============+" << endl;
        // cout << "\nDung mui ten <- & -> de xem danh sach";
        // cout << "\nESC de thoat";
        fflush(stdin);
        keyPress = getch();
        if (keyPress == RIGHT_ARROW_ASCII)
        {
            head = head->next;
            if (page == l.getSize())
                page = 1;
            else
                page++;
        }
        else if (keyPress == LEFT_ARROW_ASCII)
        {
            head = head->prev;
            if (page == 1)
                page = l.getSize();
            else
                page--;
        }
        if (keyPress == ESC_ASCII)
            break;
    } while (keyPress != ESC_ASCII);

    cout << "\nThoat chuong trinh thanh cong !";
    pressAnyKey();
    return 0;
}
