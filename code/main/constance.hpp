#pragma once
#include <string>
using namespace std;

// Trạng thái bữa tiệc
const string ACCOMPLISHED = "Da hoan thanh"; // > 0
const string GOING_ON = "Dang dien ra";      // 0
const string COMING_SOON = "Sap dien ra";    // < 0

// Trạng thái thanh toán
const string PAID = "Da thanh toan";
const string UNPAID = "Chua thanh toan";

// Đường dẫn dữ liệu
const string TYPE_PARTY_DATA_PATH = "../data/Tiec/loaiTiec.txt";
const string PARTY_DATA_PATH = "../data/Tiec/tiec.txt";
const string BILL_SAVER_FOLDER_PATH = "../data/Hoa-Don";
const string MENU_SAVER_FOLDER_OF_CUSTOMER_PATH = "../data/Thuc-Don-Cua-Khach";
const string FOOD_SAVER_FOLDER_PATH = "../data/Thuc-Don";

// Số file food
const int NUMBER_FOOD_PATH = 5;

// ASCII các phím thông dụng
const int ESC_ASCII = 27;         // Phím ESC
const int TAB_ASCII = 9;          // Phím tab
const int ENTER_ASCII = 13;       // Phím Enter
const int DEL_ASCII = 83;         // Phím Del
const int LEFT_ARROW_ASCII = 75;  // Mũi tên trái
const int RIGHT_ARROW_ASCII = 77; // Mũi tên phải
const int SPACE_ASCII = 32;       // phím space
                                  // const int NUMBER_0_ASCII = 48;
                                  // const int NUMBER_1_ASCII = 49;
                                  // const int NUMBER_2_ASCII = 50;
                                  // const int NUMBER_3_ASCII = 51;
                                  // const int NUMBER_4_ASCII = 52;
                                  // const int NUMBER_5_ASCII = 53;
                                  // const int NUMBER_6_ASCII = 54;
                                  // const int NUMBER_7_ASCII = 55;
                                  // const int NUMBER_8_ASCII = 56;
                                  // const int NUMBER_9_ASCII = 57;