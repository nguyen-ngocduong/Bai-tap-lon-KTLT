#ifndef QUANLYNHANSU_H
#define QUANLYNHANSU_H
#include<bits/stdc++.h>
using namespace std;

class QuanLyNhanSu {
private:
    class NhanVien {
    public:
        string ten;
        string chucVu;
        double luong;
        string hieuSuat;

        NhanVien() {}

        NhanVien(string ten, string chucVu, double luong, string hieuSuat) {
            this->ten = ten;
            this->chucVu = chucVu;
            this->luong = luong;
            this->hieuSuat = hieuSuat;
        }
    };

    vector<NhanVien> danhSachNhanVien;
    string fileDuLieu = "logs/nhanvien.txt";  // Su dung cung mot file cho dau vao va dau ra

public:
    void docTuFile();
    void themNhanVien();
    void inDanhSachNhanVien() const;
    void xoaNhanVien();
    void suaNhanVien();
    void luuDanhSachRaFile() const;
};

#endif