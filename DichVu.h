#ifndef DICHVU_H
#define DICHVU_H


#include<bits/stdc++.h>
using namespace std;

class DichVuUuDai {
private:
    string tenKhachHang;
    string thongTinLienHe;
    int diemTichLuy;
    string mucDoThanThiet;
    vector<DichVuUuDai> danhSachDichVu;

public:
    void hienThi() const;
    void taiDanhSachDichVu(vector<DichVuUuDai>& danhSach);
    void themDichVu(vector<DichVuUuDai>& danhSachDichVu);
    void hienThiDanhSachDichVu(const vector<DichVuUuDai>& danhSachDichVu);
    void timKiemDichVu(const vector<DichVuUuDai>& danhSachDichVu, const string& thongTinLienHe);
    void suaDichVu(vector<DichVuUuDai>& danhSachDichVu, const string& thongTinLienHe);
    void xoaDichVu(vector<DichVuUuDai>& danhSachDichVu, const string& thongTinLienHe);
    void luuDanhSachDichVu(const vector<DichVuUuDai>& danhSachDichVu);
    // Getter và Setter
    void setTenKhachHang(const string& _tenKhachHang) { tenKhachHang = _tenKhachHang; }
    string getTenKhachHang() const { return tenKhachHang; }

    void setThongTinLienHe(const string& _thongTinLienHe) { thongTinLienHe = _thongTinLienHe; }
    string getThongTinLienHe() const { return thongTinLienHe; }

    void setDiemTichLuy(int _diemTichLuy) { diemTichLuy = _diemTichLuy; }
    int getDiemTichLuy() const { return diemTichLuy; }

    void setMucDoThanThiet(const string& _mucDoThanThiet) { mucDoThanThiet = _mucDoThanThiet; }
    string getMucDoThanThiet() const { return mucDoThanThiet; }
};

#endif