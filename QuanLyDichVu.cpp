#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "QuanLyDichVu.h"
using namespace std;

    // Ham doc danh sach dich vu tu file dichvu.txt
void QuanLyDichVu::docTuFile() {
    ifstream file(fileDuLieu);
    if (!file.is_open()) {
        cout << "Khong the mo file " << fileDuLieu << " de doc du lieu.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string tenDichVu, trangThai;
        double gia;

        getline(ss, tenDichVu, ',');
        ss >> gia;
        ss.ignore(); // Bo qua dau phay
        getline(ss, trangThai, ',');

        DichVu dv(tenDichVu, gia, trangThai);
        danhSachDichVu.push_back(dv);
    }

    file.close();
    cout << "Da doc danh sach dich vu tu file " << fileDuLieu << ".\n";
}

    // Ham them dich vu moi
void QuanLyDichVu::themDichVu() {
    DichVu dv;
    cout << "Nhap ten dich vu: ";
    cin.ignore();
    getline(cin, dv.tenDichVu);
    cout << "Nhap gia: ";
    cin >> dv.gia;
    cout << "Nhap trang thai (hoat dong/ngung): ";
    cin.ignore();
    getline(cin, dv.trangThai);

    danhSachDichVu.push_back(dv);
    cout << "Da them dich vu thanh cong!\n";
}

    // Ham in danh sach dich vu ra man hinh
void QuanLyDichVu::inDanhSachDichVu() const {
    if (danhSachDichVu.empty()) {
        cout << "\nDanh sach dich vu trong!\n";
        return;
    }

    cout << "\nDanh sach dich vu:\n";
    for (size_t i = 0; i < danhSachDichVu.size(); ++i) {
        cout << "Dich vu " << i + 1 << ": \n";
        cout << "Ten dich vu: " << danhSachDichVu[i].tenDichVu << "\n";
        cout << "Gia: " << danhSachDichVu[i].gia << "\n";
        cout << "Trang thai: " << danhSachDichVu[i].trangThai << "\n\n";
    }
}

    // Ham xoa dich vu khoi danh sach
void QuanLyDichVu::xoaDichVu() {
    if (danhSachDichVu.empty()) {
        cout << "\nDanh sach dich vu trong!\n";
        return;
    }

    int index;
    cout << "Nhap so thu tu cua dich vu can xoa: ";
    cin >> index;

    if (index > 0 && index <= danhSachDichVu.size()) {
        danhSachDichVu.erase(danhSachDichVu.begin() + index - 1);
        cout << "Da xoa dich vu thanh cong!\n";
    } else {
        cout << "So thu tu khong hop le!\n";
    }
}

// Ham sua thong tin dich vu
void QuanLyDichVu::suaDichVu() {
    if (danhSachDichVu.empty()) {
        cout << "\nDanh sach dich vu trong!\n";
        return;
    }

    int index;
    cout << "Nhap so thu tu cua dich vu can sua: ";
    cin >> index;

    if (index > 0 && index <= danhSachDichVu.size()) {
        DichVu &dv = danhSachDichVu[index - 1];
        cout << "Sua thong tin cho dich vu " << dv.tenDichVu << ":\n";
        cout << "Nhap ten moi (hoac giu nguyen): ";
        cin.ignore();
        getline(cin, dv.tenDichVu);
        cout << "Nhap gia moi (hoac giu nguyen): ";
        cin >> dv.gia;
        cout << "Nhap trang thai moi (hoac giu nguyen): ";
        cin.ignore();
        getline(cin, dv.trangThai);

        cout << "Da cap nhat thong tin dich vu.\n";
    } else {
        cout << "So thu tu khong hop le!\n";
    }
}

// Ham luu danh sach dich vu vao file dichvu.txt
void QuanLyDichVu::luuDanhSachRaFile() const {
    ofstream file(fileDuLieu);
    if (file.is_open()) {
        for (const auto& dv : danhSachDichVu) {
            file << dv.tenDichVu << "," << dv.gia << "," << dv.trangThai << "\n";
        }
        file.close();
        cout << "Danh sach da duoc luu vao file " << fileDuLieu << " thanh cong!\n";
    } else {
        cout << "Khong the mo file de luu!\n";
    }
}
// Ham tim kiem dich vu
void QuanLyDichVu::timDichVu() const {
    if (danhSachDichVu.empty()) {
        cout << "\nDanh sach dich vu trong!\n";
        return;
    }

    string tenDichVu;
    cout << "Nhap ten dich vu can tim: ";
    cin.ignore();
    getline(cin, tenDichVu);

    bool found = false;
    for (const auto& dv : danhSachDichVu) {
        if (dv.tenDichVu == tenDichVu) {
            cout << "Dich vu tim thay:\n";
            cout << "Ten dich vu: " << dv.tenDichVu << "\n";
            cout << "Gia: " << dv.gia << "\n";
            cout << "Trang thai: " << dv.trangThai << "\n";
            found = true;
            break; // Nếu muốn tìm tất cả dịch vụ có cùng tên, hãy bỏ dòng này
        }
    }

    if (!found) {
        cout << "Khong tim thay dich vu \"" << tenDichVu << "\".\n";
    }
}