#ifndef KHACHHANGMODULES_H
#define KHACHHANGMODULES_H

#include<bits/stdc++.h>
#include "KhachHang.h"
using namespace std;

void quanlyKhachHang() {
    KhachHang kh;
    int choice;
    vector<KhachHang> danhSach;
    kh.taiDanhSachKhachHang(danhSach);
    string MKH;
    do {
        cout << "\n--- Quan Ly Khach Hang ---\n";
        cout << "1. Them Khach Hang\n";
        cout << "2. Hien thi danh sach khach hang\n";
        cout << "3. Tim Kiem Khach Hang\n";
        cout << "4. Sua thong tin khach hang\n";
        cout << "5. Xoa khach hang\n";
        cout << "0. Quay lai\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        
        switch (choice){
            case 0:
                cout << "Quay lai menu chinh" << endl;
                break;
            case 1:
                kh.themKhachHang(danhSach);
                break;
            case 2:
                kh.hienThiDanhSachKhachHang(danhSach);
                break;
            case 3:
                cout << "Nhap ma khach hang can tim: ";
                cin.ignore();
                getline(cin, MKH);
                kh.timKiemKhachHang(danhSach, MKH);
                break;
            case 4:
                cout << "Nhap ma khach hang can sua: ";
                cin.ignore();
                getline(cin, MKH);
                kh.suaKhachHang(danhSach, MKH);
                break;
            case 5:
                cout << "Nhap ma khach hang can xoa: ";
                cin.ignore();
                getline(cin, MKH);
                kh.xoaKhachHang(danhSach, MKH);
                break;
            default : 
                cout << "Chuc nang khong hop le! Vui long chon lai." <<endl;
                break;
        }  
    }
    while(choice != 0);
}
#endif
