#ifndef QUANLYDICHVUMODULES_H
#define QUANLYDICHVUMODULES_H

#include<bits/stdc++.h>
#include "QuanLyDichVu.h"
using namespace std;

void QLDichVu() {
    QuanLyDichVu qlDichVu;
    int luaChon;

    // Doc danh sach dich vu tu file dichvu.txt khi khoi dong chuong trinh
    qlDichVu.docTuFile();

    do {
        cout << "\n--- Quan ly dich vu khach san ---\n";
        cout << "1. Them dich vu\n";
        cout << "2. In danh sach dich vu\n";
        cout << "3. Xoa dich vu\n";
        cout << "4. Sua thong tin dich vu\n";
        cout << "5. Luu danh sach ra file\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            qlDichVu.themDichVu();
            break;
        case 2:
            qlDichVu.inDanhSachDichVu();
            break;
        case 3:
            qlDichVu.xoaDichVu();
            break;
        case 4:
            qlDichVu.suaDichVu();
            break;
        case 5:
            qlDichVu.luuDanhSachRaFile();
            break;
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
    } while (luaChon != 0);
}

#endif