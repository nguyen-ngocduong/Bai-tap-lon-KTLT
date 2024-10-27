#ifndef QUANLYNHANSUMODULES_H
#define QUANLYNHANSUMODULES_H

#include<bits/stdc++.h>
#include "QuanLyNhanSu.h"
using namespace std;

void khoiDong() {
    QuanLyNhanSu ns;
    int luaChon;

    // Doc danh sach nhan vien tu file nhanvien.txt khi khoi dong chuong trinh
    ns.docTuFile();

    do {
        cout << "\n--- Quan ly nhan su khach san ---\n";
        cout << "1. Them nhan vien\n";
        cout << "2. In danh sach nhan vien\n";
        cout << "3. Xoa nhan vien\n";
        cout << "4. Sua thong tin nhan vien\n";
        cout << "5. Luu danh sach ra file\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
        case 1:
            ns.themNhanVien();
            break;
        case 2:
            ns.inDanhSachNhanVien();
            break;
        case 3:
            ns.xoaNhanVien();
            break;
        case 4:
            ns.suaNhanVien();
            break;
        case 5:
            ns.luuDanhSachRaFile();
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