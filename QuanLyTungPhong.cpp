#include <iostream>
#include <string>
#include <fstream>
#include "QuanLyTungPhong.h"
using namespace std;

// Chuc nang them phong
void TungPhong::themPhong(PhongKS danhSach[], int &soLuong) {
    string soPhong;
    string DichVuPhongSD, trangThai, GhiChu;

    cout << "Nhap so phong : ";
    cin >> soPhong;
    cin.ignore(); 
    
    cout << "Nhap dich vu phong da su dung: ";
    getline(cin, DichVuPhongSD);

    cout << "Nhap trang thai phong: ";
    getline(cin, trangThai);

    cout << "Nhap ghi chu: ";
    getline(cin, GhiChu);

    danhSach[soLuong] = PhongKS(soPhong, DichVuPhongSD, trangThai, GhiChu);
    soLuong++;
    cout << "Da them phong thanh cong!\n";
}

// Chuc nang xoa phong
void TungPhong::xoaPhong(PhongKS danhSach[], int &soLuong, string soPhongCanXoa) {
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].soPhong == soPhongCanXoa) {
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
void TungPhong::suaPhong(PhongKS danhSach[], int soLuong, string soPhongCanSua) {
    for (int i = 0; i < soLuong; i++) {
        if (danhSach[i].soPhong == soPhongCanSua) {
            string DichVuPhongSD, trangThai, GhiChu;
            cout << "Nhap dich vu phong da su dung moi : ";
            cin.ignore();
            getline(cin, DichVuPhongSD);

            cout << "Nhap trang thai phong moi: ";
            getline(cin, trangThai);

            cout << "Nhap ghi chu moi: ";
            getline(cin, GhiChu);

            danhSach[i].DichVuPhongSD = DichVuPhongSD;
            danhSach[i].trangThai = trangThai;
            danhSach[i].GhiChu = GhiChu;

            cout << "Da sua thong tin thanh cong!\n";
            return;
        }
    }
    cout << "Khong tim thay phong voi so phong : " << soPhongCanSua << endl;
}

// Chuc nang xem danh sach phong
void TungPhong::xemDanhSachPhong(PhongKS danhSach[], int soLuong) {
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
void TungPhong::luuDanhSachPhong(PhongKS danhSach[], int soLuong) {
    ofstream file("logs/TTdanh_sach_phong.txt");
    if (file.is_open()) {
        for (int i = 0; i < soLuong; i++) {
            file << danhSach[i].soPhong << "," 
                 << danhSach[i].DichVuPhongSD << "," 
                 << danhSach[i].trangThai << "," 
                 << danhSach[i].GhiChu << endl;
        }
        file.close();
        cout << "Da luu thong tin vao file thanh cong!\n";
    } else {
        cout << "Khong the mo file de luu du lieu!\n";
    }
}

// Doc thong tin tu file
void TungPhong::docDanhSachPhong(PhongKS danhSach[], int &soLuong) {
    ifstream file("logs/TTdanh_sach_phong.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue; // Bo qua dong trong
            
            PhongKS phong;
            size_t pos = 0;

            pos = line.find(",");
            phong.soPhong = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            phong.DichVuPhongSD = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            phong.trangThai = line.substr(0, pos);
            line.erase(0, pos + 1);

            phong.GhiChu = line;

            danhSach[soLuong++] = phong;
        }
        file.close();
        cout << "Doc thong tin phong tu file thanh cong!\n";
    } else {
        cout << "Khong the mo file de doc du lieu!\n";
    }
}

// Chuc nang tim kiem phong
void TungPhong::timKiemPhong(PhongKS danhSach[], int soLuong) {
    int luaChonTimKiem;
    cout << "\n--- TIM KIEM PHONG ---\n";
    cout << "Tim kiem theo tieu chi:\n";
    cout << "1. So phong\n";
    cout << "2. Dich vu phong da su dung\n";
    cout << "3. Trang thai phong\n";
    cout << "4. Ghi chu\n";
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
                if (danhSach[i].soPhong == soPhongCanTim) {
                    danhSach[i].hienThiThongTin();
                    timThay = true;
                }
            }
            break;
        }
        case 2: {
            // Tim kiem theo dich vu phong da su dung
            string dichVuCanTim;
            cout << "Nhap dich vu phong da su dung can tim: ";
            getline(cin, dichVuCanTim);

            for (int i = 0; i < soLuong; i++) {
                if (danhSach[i].DichVuPhongSD == dichVuCanTim) {
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
                if (danhSach[i].trangThai == trangThaiCanTim) {
                    danhSach[i].hienThiThongTin();
                    timThay = true;
                }
            }
            break;
        }
        case 4: {
            // Tim kiem theo ghi chu
            string ghiChuCanTim;
            cout << "Nhap ghi chu can tim: ";
            getline(cin, ghiChuCanTim);

            for (int i = 0; i < soLuong; i++) {
                if (danhSach[i].GhiChu == ghiChuCanTim) {
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
