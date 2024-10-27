#ifndef QUANLYPHONGKHACHSANMODULES_H
#define QUANLYPHONGKHACHSANMODULES_H

#include<bits/stdc++.h>
#include "QuanLyPhongKhachSan.h"
using namespace std;

void QuanLyPhongKhachSan() {
    qlTungPhong tp;
    int soLuong = 0;
    qlPhong danhSachPhong[100]; // 100 phòng
    int luaChon;
    do {
        cout << "\n--- CHUONG TRINH QUAN LI PHONG KHACH SAN ---\n";
        cout << "1. Them phong\n";
        cout << "2. Xoa phong\n";
        cout << "3. Sua phong\n";
        cout << "4. Xem danh sach phong\n";
        cout << "5. Tim kiem phong \n"; 
        cout << "6. Luu danh sach phong vao file\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                tp.themPhong(danhSachPhong, soLuong);
                break;
            }
            case 2: {
                string soPhongCanXoa;
                cout << "Nhap so phong can xoa: ";
                cin >> soPhongCanXoa;
                tp.xoaPhong(danhSachPhong, soLuong, soPhongCanXoa);
                break;
            }
            case 3: {
                string soPhongCanSua;
                cout << "Nhap so phong can sua: ";
                cin >> soPhongCanSua;
                tp.suaPhong(danhSachPhong, soLuong, soPhongCanSua);
                break;
            }
            case 4: {
                tp.xemDanhSachPhong(danhSachPhong, soLuong);
                break;
            }
            case 5:{
            	tp.timKiemPhong(danhSachPhong, soLuong);
				break;
			} 
			case 6: {
                tp.luuDanhSachPhong(danhSachPhong, soLuong);
                break;
            }
            case 0: {
                cout << "Thoat chuong trinh...\n";
                break;
            }
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }

    } while (luaChon != 0);
}

#endif