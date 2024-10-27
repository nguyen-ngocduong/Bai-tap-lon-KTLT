#include <iostream>
#include <string>
#include <fstream>
#include "QuanLyPhongKhachSan.h"
using namespace std;

// Chuc nang them phong
void qlTungPhong::themPhong(qlPhong danhSach[], int &soLuong) {
    string soPhong;
    string loaiPhong, trangThai;
    double giaPhong;

    cout << "Nhap so phong : ";
    cin >> soPhong;
    cin.ignore(); 
    
    cout << "Nhap loai phong: ";
    getline(cin, loaiPhong);

    cout << "Nhap trang thai phong: ";
    getline(cin, trangThai);

    cout << "Nhap gia phong: ";
    cin >> giaPhong;
    danhSach[soLuong] = qlPhong(soPhong, loaiPhong, trangThai, giaPhong);
    soLuong++;
    cout << "Da them phong thanh cong!\n";
}

// Chuc nang xoa phong
void qlTungPhong::xoaPhong(qlPhong danhSach[], int &soLuong, string soPhongCanXoa) {
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].IDPhong == soPhongCanXoa) {
            for (int j = i; j < soLuong - 1; j++) {
                danhSach[j] = danhSach[j + 1]; // doi cac phan tu ve truoc 
            }
            soLuong--;
            cout << "Da xoa phong thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay phong voi so phong " << soPhongCanXoa << endl;
}

// Chuc nang sua phong
void qlTungPhong::suaPhong(qlPhong danhSach[], int soLuong, string soPhongCanSua) {
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].IDPhong == soPhongCanSua) {
            string loaiPhong, trangThai;
            double giaPhong;
            cout << "Nhap loai phong moi : ";
            cin.ignore();
            getline(cin, loaiPhong);

            cout << "Nhap trang thai phong : ";
            getline(cin, trangThai);

            cout << "Nhap gia phong moi: ";
            cin >> giaPhong;

            danhSach[i].loaiPhong = loaiPhong;
            danhSach[i].TrangThai = trangThai;
            danhSach[i].giaPhong = giaPhong;

            cout << "Da sua thong tin thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay phong voi so phong : " << soPhongCanSua << endl;
}

// Chuc nang xem danh sach phong
void qlTungPhong::xemDanhSachPhong(qlPhong danhSach[], int soLuong) {
    if (soLuong == 0) {
        cout << "Danh sach phong trong!\n";
        return;
    }

    cout << "Danh sach cac phong:\n";
    for (int i = 0; i < soLuong; i++) {
        danhSach[i].hienThiThongTin();
    }
}

// Luu thong tin vao file
void qlTungPhong::luuDanhSachPhong(qlPhong danhSach[], int soLuong) {
    ofstream file("logs/danh_sach_phong.txt");
    if (file.is_open()) {
        for (int i = 0; i < soLuong; i++) {
            file << danhSach[i].IDPhong << "," 
                 << danhSach[i].loaiPhong << "," 
                 << danhSach[i].TrangThai << "," 
                 << danhSach[i].giaPhong << endl;
        }
        file.close();
        cout << "Da luu thong tin vao file thanh cong!\n";
    } else {
        cout << "Khong the mo file de luu du lieu!\n";
    }
}

// Doc thong tin tu file
void qlTungPhong::docDanhSachPhong(qlPhong danhSach[], int &soLuong) {
    ifstream file("logs/danh_sach_phong.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue; // Bo qua dong trong
            
            qlPhong phong;
            size_t pos = 0;

            pos = line.find(",");
            phong.IDPhong = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            phong.loaiPhong = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            phong.TrangThai = line.substr(0, pos);
            line.erase(0, pos + 1);

            phong.giaPhong = stod(line);

            danhSach[soLuong++] = phong;
        }
        file.close();
        cout << "Doc thong tin phong tu file thanh cong!\n";
    } else {
        cout << "Khong the mo file de doc du lieu!\n";
    }
}
// Chuc nang tim kiem phong
void qlTungPhong::timKiemPhong(qlPhong danhSach[], int soLuong) {
    int luaChonTimKiem;
    cout << "\n--- TIM KIEM PHONG ---\n";
    cout << "Tim kiem theo tieu chi:\n";
    cout << "1. So phong\n";
    cout << "2. Loai phong\n";
    cout << "3. Trang thai phong\n";
    cout << "4. Gia phong\n";
    cout << "Nhap lua chon cua ban: ";
    cin >> luaChonTimKiem;
    cin.ignore();  // Loai bo ky tu xuong dong trong buffer

    bool timThay = false;

    switch (luaChonTimKiem) {
        case 1: {
            // Tim kiem theo so phong
            string soPhongCanTim;
            cout << "Nhap so phong can tim: ";
            getline(cin, soPhongCanTim);

            for (int i = 0; i < soLuong; i++) {
                if (danhSach[i].IDPhong == soPhongCanTim) {
                    danhSach[i].hienThiThongTin();
                    timThay = true;
                }
            }
            break;
        }
        case 2: {
            // Tim kiem theo loai phong
            string loaiPhongCanTim;
            cout << "Nhap loai phong can tim: ";
            getline(cin, loaiPhongCanTim);

            for (int i = 0; i < soLuong; i++) {
                if (danhSach[i].loaiPhong == loaiPhongCanTim) {
                    danhSach[i].hienThiThongTin();
                    timThay = true;
                }
            }
            break;
        }
        case 3: {
            // Tim kiem theo trang thai phong
            string trangThaiCanTim;
            cout << "Nhap trang thai phong can tim: ";
            getline(cin, trangThaiCanTim);

            for (int i = 0; i < soLuong; i++) {
                if (danhSach[i].TrangThai == trangThaiCanTim) {
                    danhSach[i].hienThiThongTin();
                    timThay = true;
                }
            }
            break;
        }
        case 4: {
            // Tim kiem theo gia phong
            double giaPhongCanTim;
            cout << "Nhap gia phong can tim: ";
            cin >> giaPhongCanTim;

            for (int i = 0; i < soLuong; i++) {
                if (danhSach[i].giaPhong == giaPhongCanTim) {
                    danhSach[i].hienThiThongTin();
                    timThay = true;
                }
            }
            break;
        }
        default:
            cout << "Lua chon khong hop le!\n";
            return;
    }

    if (!timThay) {
        cout << "Khong tim thay phong voi tieu chi da nhap.\n";
    }
}
