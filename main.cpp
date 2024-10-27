#include <bits/stdc++.h>
#include "KhachHangModules.h"
#include "PhongModules.h"
#include "QuanLyThongBaoModules.h"
#include "DichVuModules.h"
#include "QuanLyTungPhongModules.h"
#include "QuanLyPhongKhachSanModules.h"
#include "QuanLyDichVuModules.h"
#include "QuanLyNhanSuModules.h"
using namespace std;


int main() {
    int choice;
    do {
        cout << "\n--- He Thong Quan Ly ---\n";
        cout << "1. Quan Ly Khach Hang\n";
        cout << "2. Quan Ly Dat Phong\n";
        cout << "3. Quan Ly Thong Bao\n";
        cout << "4. Quan Ly Thong Tin Dich Vu Uu Dai\n";
        cout << "5. Quan Ly Thong Tin Phong Khach San\n";
        cout << "6. Quan Ly Phong Khach San\n";
        cout << "7. Quan Ly Dich Vu Khach San\n";
        cout << "8. Quan Ly Nhan Su Khach San\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                quanlyKhachHang();
                break;
            case 2:
                quanlydatPhong();
                break;
            case 3:
                QuanLyThongBao();
                break;
            case 4:
                quanlydichvu();
                break;
            case 5:
                QuanLyTungPhong();
                break;
            case 6: 
                QuanLyPhongKhachSan();
                break;
            case 7:
                QLDichVu();
                break;
            case 8:
                khoiDong();
                break;
            case 0:
                cout << "Thoat chuong trinh!\n";
                break;
            default:
                cout << "Chuc nang khong hop le. Vui long chon lai.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
