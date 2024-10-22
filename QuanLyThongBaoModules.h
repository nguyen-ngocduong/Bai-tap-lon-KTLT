#ifndef QUANLYTHONGBAOMODULES_H
#define QUANLYTHONGBAOMODULES_H

#include<bits/stdc++.h>
#include "QuanLyThongBao.h"
using namespace std;

void QuanLyThongBao() {
    ThongBao tb;
    int choice;
    do {
        cout << "\n--- Quan Ly Thong Bao ---\n";
        cout << "0. Quay Lai Menu! \n";
        cout << "1. Dien Thong Tin Dang Ky \n";
        cout << "2. Xem Thong Tin Da Dang Ky\n";
        cout << "3. Xuat Phieu Tra Khach\n";
        cout << "4. Thong Bao Tra Phong. \n";
        cout << "Chon Chuc Nang: ";
        cin >> choice;
        switch(choice) {
            case 0:
                cout << "Quay Lai Menu Chinh" << endl;
                break;
            case 1:
                tb.nhapthongtin();
                tb.themthongtin();
                break;
            case 2:
                tb.docthongbao();
                break;
            case 3:
                tb.xuatphieu();
                break;
            case 4:
                tb.thongBaoTraPhong();
                tb.xoakhachhangquahan();
                break;
            default:
                cout << "Chuc Nang Khong Hop Le! Vui Long Chon Lai." <<endl;
                break;
        }
    }
    while(choice != 0);
}

#endif