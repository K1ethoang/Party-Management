#pragma once
#include <string>
using namespace std;

// trạng thái bữa tiệc
const string ACCOMPLISHED = "Da hoan thanh"; // > 0
const string GOING_ON = "Dang dien ra";      // 0
const string COMING_SOON = "Sap dien ra";    // < 0

// đường dẫn dữ liệu
const string TYPE_PARTY_DATA_PATH = "../data/loaiTiec.txt";
const string CUSTOMER_DATA_PATH = "../data/Khach-Hang/khachHang.txt";
const string PARTY_DATA_PATH = "../data/Tiec/tiec.txt";