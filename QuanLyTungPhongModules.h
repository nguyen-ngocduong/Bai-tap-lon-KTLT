#ifndef QUANLYTUNGPHONGMODULES_H
#define QUANLYTUNGPHONGMODULES_H

#include<bits/stdc++.h>
#include "QuanLyTungPhong.h"
using namespace std;

void QuanLyTungPhong(){
    TungPhong tp;
    int soLuong = 0;
    PhongKS danhSachPhong[100]; // co toi da 100 phong
    tp.docDanhSachPhong(danhSachPhong, soLuong);
    int luaChon;
    do {
        cout << "\n--- CHUONG TRINH QUAN LI PHONG KHACH SAN ---\n";
        cout << "1. Them phong\n";
        cout << "2. Xoa phong\n";
        cout << "3. Sua thong tin phong\n";
        cout << "4. Xem danh sach phong\n";
        cout << "5. Tim kiem phong\n";
        cout << "6. Luu du lieu vao file\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon) {
        case 1:
            tp.themPhong(danhSachPhong, soLuong);
            break;
        case 2: {
            string soPhongCanXoa;
            cout << "Nhap so phong can xoa: ";
            getline(cin, soPhongCanXoa);
            tp.xoaPhong(danhSachPhong, soLuong, soPhongCanXoa);
            break;
        }
        case 3: {
            string soPhongCanSua;
            cout << "Nhap so phong can sua: ";
            getline(cin, soPhongCanSua);
            tp.suaPhong(danhSachPhong, soLuong, soPhongCanSua);
            break;
        }
        case 4:
            tp.xemDanhSachPhong(danhSachPhong, soLuong);
            break;
        case 5:
            tp.timKiemPhong(danhSachPhong, soLuong);
            break;
        case 6:
            tp.luuDanhSachPhong(danhSachPhong, soLuong);
            break;
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le! Vui Long Chon Lai.\n";
            break;
        }
    } while (luaChon != 0);
}
#endif