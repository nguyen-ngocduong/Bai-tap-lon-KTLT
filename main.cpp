#include <bits/stdc++.h>
#include "KhachHangModules.h"
#include "PhongModules.h"
#include "QuanLyThongBaoModules.h"
#include "DichVuModules.h"
using namespace std;


int main() {
    int choice;
    do {
        cout << "\n--- He Thong Quan Ly ---\n";
        cout << "1. Quan Ly Khach Hang\n";
        cout << "2. Quan Ly Dat Phong\n";
        cout << "3. Quan Ly Thong Bao\n";
        cout << "4. Quan ly thong tin dich vu uu dai\n";
        // cout << "5. Quan Ly Lop Hoc Phan\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> choice;

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
            // case 5:
            //     quanLyLopHocPhan();
            //     break;
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
