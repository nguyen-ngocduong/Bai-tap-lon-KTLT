#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "QuanLyNhanSu.h"
using namespace std;

// Class quan ly nhan su khach san
void QuanLyNhanSu::docTuFile() {
    ifstream file(fileDuLieu);
    if (!file.is_open()) {
        cout << "Khong the mo file " << fileDuLieu << " de doc du lieu.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string ten, chucVu, hieuSuat;
        double luong;

        getline(ss, ten, ',');
        getline(ss, chucVu, ',');
        ss >> luong;
        ss.ignore(); // Bo qua dau phay
        getline(ss, hieuSuat, ',');

        NhanVien nv(ten, chucVu, luong, hieuSuat);
        danhSachNhanVien.push_back(nv);
    }

    file.close();
    cout << "Da doc danh sach nhan vien tu file " << fileDuLieu << ".\n";
}

    // Ham them nhan vien moi
void QuanLyNhanSu::themNhanVien() {
    NhanVien nv;
    cout << "Nhap ten nhan vien: ";
    cin.ignore();
    getline(cin, nv.ten);
    cout << "Nhap chuc vu: ";
    getline(cin, nv.chucVu);
    cout << "Nhap luong: ";
    cin >> nv.luong;
    cout << "Nhap hieu suat lam viec: ";
    cin.ignore();
    getline(cin, nv.hieuSuat);

    danhSachNhanVien.push_back(nv);
    cout << "Da them nhan vien thanh cong!\n";
}

    // Ham in danh sach nhan vien ra man hinh
void QuanLyNhanSu::inDanhSachNhanVien() const {
    if (danhSachNhanVien.empty()) {
        cout << "\nDanh sach nhan vien trong!\n";
        return;
    }

    cout << "\nDanh sach nhan vien:\n";
    for (size_t i = 0; i < danhSachNhanVien.size(); ++i) {
        cout << "Nhan vien " << i + 1 << ": \n";
        cout << "Ten: " << danhSachNhanVien[i].ten << "\n";
        cout << "Chuc vu: " << danhSachNhanVien[i].chucVu << "\n";
        cout << "Luong: " << danhSachNhanVien[i].luong << "\n";
        cout << "Hieu suat: " << danhSachNhanVien[i].hieuSuat << "\n\n";
    }
}

    // Ham xoa nhan vien khoi danh sach
void QuanLyNhanSu::xoaNhanVien() {
    if (danhSachNhanVien.empty()) {
        cout << "\nDanh sach nhan vien trong!\n";
        return;
    }

    int index;
    cout << "Nhap so thu tu cua nhan vien can xoa: ";
    cin >> index;

    if (index > 0 && index <= danhSachNhanVien.size()) {
        danhSachNhanVien.erase(danhSachNhanVien.begin() + index - 1);
        cout << "Da xoa nhan vien thanh cong!\n";
    } else {
        cout << "So thu tu khong hop le!\n";
    }
}

    // Ham sua thong tin nhan vien
void QuanLyNhanSu::suaNhanVien() {
    if (danhSachNhanVien.empty()) {
        cout << "\nDanh sach nhan vien trong!\n";
        return;
    }

    int index;
    cout << "Nhap so thu tu cua nhan vien can sua: ";
    cin >> index;

    if (index > 0 && index <= danhSachNhanVien.size()) {
        NhanVien &nv = danhSachNhanVien[index - 1];
        cout << "Sua thong tin cho nhan vien " << nv.ten << ":\n";
        cout << "Nhap ten moi (hoac giu nguyen): ";
        cin.ignore();
        getline(cin, nv.ten);
        cout << "Nhap chuc vu moi (hoac giu nguyen): ";
        getline(cin, nv.chucVu);
        cout << "Nhap luong moi (hoac giu nguyen): ";
        cin >> nv.luong;
        cout << "Nhap hieu suat moi (hoac giu nguyen): ";
        cin.ignore();
        getline(cin, nv.hieuSuat);

        cout << "Da cap nhat thong tin nhan vien.\n";
    } else {
        cout << "So thu tu khong hop le!\n";
    }
}

    // Ham luu danh sach nhan vien vao file nhanvien.txt
void QuanLyNhanSu::luuDanhSachRaFile() const {
    ofstream file(fileDuLieu);
    if (file.is_open()) {
        for (const auto& nv : danhSachNhanVien) {
            file << nv.ten << "," << nv.chucVu << "," << nv.luong << "," << nv.hieuSuat << "\n";
        }
        file.close();
        cout << "Danh sach da duoc luu vao file " << fileDuLieu << " thanh cong!\n";
    } else {
        cout << "Khong the mo file de luu!\n";
    }
}
