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
