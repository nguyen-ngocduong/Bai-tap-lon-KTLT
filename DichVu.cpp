#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "DichVu.h"
using namespace std;


void DichVuUuDai::hienThi() const {
    cout << "Ten Khach Hang: " << tenKhachHang << endl;
    cout << "Thong Tin Lien He: " << thongTinLienHe << endl;
    cout << "Diem Tich Luy: " << diemTichLuy << endl;
    cout << "Muc Do Than Thiet: " << mucDoThanThiet << endl;
}
void DichVuUuDai::luuDanhSachDichVu(const vector<DichVuUuDai>& danhSach) {
    ofstream file("logs/DichVu.txt");
    if (!file) {
        cerr << "Khong the mo tep de luu du lieu." << endl;
        return;
    }
    for (const auto& dv : danhSach) {
        file << dv.getTenKhachHang() << "," << dv.getThongTinLienHe() << "," 
             << dv.getDiemTichLuy() << "," << dv.getMucDoThanThiet() << endl;
    }
    file.close(); 
}

void DichVuUuDai::taiDanhSachDichVu(vector<DichVuUuDai>& danhSach) {
    ifstream file("logs/DichVu.txt");
    if (!file) {
        cerr << "Khong the mo tep de tai du lieu." << endl;
        return;
    }
    DichVuUuDai dv;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;

        getline(ss, temp, ',');
        dv.setTenKhachHang(temp);
        getline(ss, temp, ',');
        dv.setThongTinLienHe(temp);
        
        int diem;
        ss >> diem;
        dv.setDiemTichLuy(diem);
        getline(ss, temp);
        dv.setMucDoThanThiet(temp);

        danhSach.push_back(dv);
    }
    file.close(); // Đảm bảo tệp được đóng
}

// Hàm thêm dịch vụ
void DichVuUuDai::themDichVu(vector<DichVuUuDai>& danhSach) {
    DichVuUuDai dv;
    string temp;

    cout << "Nhap ten khach hang: ";
    getline(cin, temp);
    dv.setTenKhachHang(temp);

    cout << "Nhap thong tin lien he: ";
    getline(cin, temp);
    dv.setThongTinLienHe(temp);

    int diem;
    cout << "Nhap diem tich luy: ";
    cin >> diem;
    dv.setDiemTichLuy(diem);
    cin.ignore(); // Bỏ qua ký tự newline sau khi đọc số

    cout << "Nhap muc do than thiet: ";
    getline(cin, temp);
    dv.setMucDoThanThiet(temp);

    danhSach.push_back(dv);
    luuDanhSachDichVu(danhSach);
}

// Hàm hiển thị danh sách dịch vụ
void DichVuUuDai::hienThiDanhSachDichVu(const vector<DichVuUuDai>& danhSach) {
    if (danhSach.empty()) {
        cout << "Danh sach dich vu trong." << endl;
        return;
    }

    for (const auto& dv : danhSach) {
        dv.hienThi();
    }
}

// Hàm tìm kiếm dịch vụ
void DichVuUuDai::timKiemDichVu(const vector<DichVuUuDai>& danhSach, const string& thongTinLienHe) {
    for (const auto& dv : danhSach) {
        if (dv.getThongTinLienHe() == thongTinLienHe) {
            dv.hienThi();
            return;
        }
    }
    cout << "Khong tim thay dich vu voi khach hang co lien he: " << thongTinLienHe << endl;
}

// Hàm sửa dịch vụ
void DichVuUuDai::suaDichVu(vector<DichVuUuDai>& danhSach, const string& thongTinLienHe) {
    for (auto& dv : danhSach) {
        if (dv.getThongTinLienHe() == thongTinLienHe) {
            string temp;
            cout << "Nhap thong tin moi cho dich vu cua khach hang co thong tin lien he" << thongTinLienHe << ":" << endl;

            cout << "Ten khach hang: ";
            getline(cin, temp);
            dv.setTenKhachHang(temp);
            
            cout << "Thong tin lien he: ";
            getline(cin, temp);
            dv.setThongTinLienHe(temp);
            
            int diem;
            cout << "Diem tich luy: ";
            cin >> diem;
            dv.setDiemTichLuy(diem);
            cin.ignore(); // Bỏ qua ký tự newline
            
            cout << "Muc do than thiet: ";
            getline(cin, temp);
            dv.setMucDoThanThiet(temp);
            
            luuDanhSachDichVu(danhSach);
            return;
        }
    }
    cout << "Khong tim thay dich vu voi khach hang co lien he: " << thongTinLienHe << endl;
}

// Hàm xóa dịch vụ
void DichVuUuDai::xoaDichVu(vector<DichVuUuDai>& danhSach, const string& thongTinLienHe) {
    for (size_t i = 0; i < danhSach.size(); ++i) {
        if (danhSach[i].getThongTinLienHe() == thongTinLienHe) {
            danhSach.erase(danhSach.begin() + i);
            luuDanhSachDichVu(danhSach);
            cout << "Da xoa dich vu cua khach hang co thong tin lien he: " << thongTinLienHe << endl;
            return;
        }
    }
    cout << "Khong tim thay dich vu voi khach hang co thong tin lien he: " << thongTinLienHe << endl;
}

