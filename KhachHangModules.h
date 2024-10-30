#ifndef KHACHHANGMODULES_H
#define KHACHHANGMODULES_H

#include<bits/stdc++.h>
#include "KhachHang.h"
using namespace std;

void quanlyKhachHang() {
    KhachHang kh;
    int choice;
    string makhachhang;
    vector<KhachHang> danhSach;
    string mkh;
    do {
        cout << "\n--- Quan Ly Khach Hang ---\n";
        cout << "1. Them Khach Hang\n";
        cout << "2. Xem Danh Sach Khach Hang\n";
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
                kh.themkhachhang(danhSach);
                break;
            case 2:
                kh.docdanhsach(danhSach);
                break;
            case 3:
                cout << "Nhap ma khach hang can tim: ";
                cin.ignore();
                getline(cin, mkh);
                kh.timKiemKhachHang(danhSach, mkh);
                break;
            case 4:
                cout << "Nhap ma khach hang can sua: ";
                cin.ignore();
                getline(cin, mkh);
                kh.suaKhachHang(danhSach, mkh);
                break;
            case 5:
                cout << "Nhap ma khach hang can xoa: ";
                cin.ignore();
                getline(cin, mkh);
                kh.xoakhachhang(danhSach, mkh);
                break;
            default : 
                cout << "Chuc nang khong hop le! Vui long chon lai." <<endl;
                break;
        }  
    }
    while(choice != 0);
}
#endif
