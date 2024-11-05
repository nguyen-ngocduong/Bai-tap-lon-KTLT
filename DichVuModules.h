#ifndef DICHVUMODULES_H
#define DICHVUMODULES_H

#include<bits/stdc++.h>
#include "DichVu.h"

using namespace std;

void quanlydichvu() {
    DichVuUuDai dv;
    int choice;
    vector<DichVuUuDai> danhSachDichVu;
    dv.taiDanhSachDichVu(danhSachDichVu);
    do {
        cout << "\n--- QUAN LY DICH VU UU DAI---\n";
        cout << "1. Them dich vu uu dai\n";
        cout << "2. Hien thi danh sach dich vu uu dai\n";
        cout << "3. Tim kiem dich vu uu dai\n";
        cout << "4. Sua dich vu uu dai\n";
        cout << "5. Xoa dich vu uu dai\n";
        cout << "0. Quay lai\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        cin.ignore();
        
        string sdt;  // Khai báo biến này chỉ một lần ở đây

        switch(choice) {
            case 0:
                cout << "Thoat Chuong Trinh.\n" <<endl;
                break;
            case 1:
                dv.themDichVu(danhSachDichVu); 
                break;
            case 2:
                dv.hienThiDanhSachDichVu(danhSachDichVu);
                break;
            case 3:
                cout << "Nhap thong tin lien he khach hang can tim dich vu uu dai: ";
                getline(cin, sdt);
                dv.timKiemDichVu(danhSachDichVu, sdt);
                break;
            case 4:
                cout << "Nhap thong tin lien he khach hang can sua dich vu uu dai: ";
                getline(cin, sdt);
                dv.suaDichVu(danhSachDichVu, sdt);
                break;
            case 5:
                cout << "Nhap thong tin lien he khach hang can xoa dich vu uu dai: ";
                getline(cin, sdt);
                dv.xoaDichVu(danhSachDichVu, sdt);
                break;
            default: 
                cout << "Lua chon khong hop le. Vui long thu lai." << endl;
        }
    } while(choice != 0);
}
#endif
