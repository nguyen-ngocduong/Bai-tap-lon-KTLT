// PhongModules.h
#ifndef PHONGMODULES_H
#define PHONGMODULES_H

#include<bits/stdc++.h>
#include "Phong.h"

using namespace std;

void quanlydatPhong(){
    Phong phong;
    int choice;
    string sophong;
    vector<Phong> danhsachPhong;
    phong.docdanhsach();
    do {
        cout << "\n--- Quan Ly Dat Phong ---\n";
        cout << "1.Khach Hang Dat Them Phong \n";
        cout << "2.Xem Danh Sach Phong Da Dat \n";
        cout << "3.Khach Hang Da Tra Phong \n";
        cout << "4.Khach Hang Da Thay Doi Sang Phong \n";
        cout << "5.Tim Kiem Phong \n";
        cout << "0.Quay Lai Menu Chinh! \n";
        cout << "Vui Long Nhap Lua Chon Cua Ban:";
        cin >> choice;
        switch (choice) {
            case 0:
                cout << "Thoat Chuong Trinh.\n" <<endl;
                break;
            case 1:
                phong.themphong(danhsachPhong);
                break;
            case 2:
                phong.xuatthongtin(danhsachPhong);
                break;
            case 3:
                cout << "Nhap Phong Khach Hang Da Tra:  ";
                cin.ignore();
                getline(cin, sophong);
                phong.xoaphong(danhsachPhong,sophong);
                break;
            case 4:
                cout << "Nhap Phong Khach Hang Muon Doi: ";
                cin.ignore();
                getline(cin,sophong);
                phong.suaphong(danhsachPhong, sophong);
                break;
            case 5:
                cout << "Nhap Ma Phong Can Tim: ";
                cin.ignore();
                getline(cin,sophong);
                phong.timkiemphong(sophong);
                break;
            default :
                cout << "Chuc Nang Khong Hop Le. Vui Long Chon Lai.\n";
                break;
        }
    }
    while(choice != 0);
}


#endif
// PHONGMODULES_H