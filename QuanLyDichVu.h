#ifndef QUANLYDICHVU_H
#define QUANLYDICHVU_H
#include<bits/stdc++.h>
using namespace std;

class QuanLyDichVu {
private:
    struct DichVu {
        string tenDichVu;
        double gia;
        string trangThai;

        DichVu() {}

        DichVu(string tenDichVu, double gia, string trangThai) {
            this->tenDichVu = tenDichVu;
            this->gia = gia;
            this->trangThai = trangThai;
        }
    };

    vector<DichVu> danhSachDichVu;
    string fileDuLieu = "logs/qldichvu.txt";  // Tep de luu va doc dich vu

public:
    void docTuFile();
    void themDichVu();
    void inDanhSachDichVu() const;
    void xoaDichVu();
    void suaDichVu();
    void luuDanhSachRaFile() const;
};

#endif