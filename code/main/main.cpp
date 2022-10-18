#include "./program/program.hpp"

int main()
{
<<<<<<< HEAD
     
    TypeFood _tf;
    food _food;
    DocFileDoUong(_tf, _food);

    TypeFood _tf2;
    food _food2;
    DocFileKhaiVi(_tf2, _food2);

    Foods foods;
    foods.addfLast(_tf);
    foods.addfLast(_tf2);
    foods.displayFoods();


    // cout << "\n\t\t+=====================================================================================================+" ;
    // cout << "\n\t\t|                                              LIST FOOD                                              |" ;
    // cout << "\n\t\t+=========+====================================================================+======================+" ;
    // cout << "\n\t\t|   STT   |                                 FOOD                               |        PRICE         |" << endl;
    // // q.display();
    // cout << "\t\t+=========+====================================================================+======================+" ;
    // int n = 0;
    BST bst;
    cout << "\n\t\t-----THONG TIN CUA BUOI TIEC DA NHAP-----\n";
    bst.add();
    cout << "\n\t\t-----THONG TIN CUA BUOI TIEC DA NHAP-----\n";
    bst.add();
    // cout << "\n\t\t-----THONG TIN CUA BUOI TIEC DA NHAP-----\n";
    // bst.add(); 

    cout << "\n\t\t+==========================================================================================================================+" ;
    cout << "\n\t\t|                                                 PARTIES INFORMATION LIST                                                 |" ;
    cout << "\n\t\t+=========+=============================+============+==================+=========================+========================+" ;
    cout << "\n\t\t|   STT   |       Loai tiec             |   So ban   |        ID        |    Thoi gian to chuc    |    Trang thai          |" ;
    cout << "\n\t\t+=========+=============================+============+==================+=========================+========================+" ;
    bst.display();
    cout << "\n\t\t+=========+=============================+============+==================+=========================+========================+" ;

=======
    program();
>>>>>>> 848de0e44fbb6261fcd4c223149157032c392d6e
    return 0;
}