#ifndef PHONG_H
#define PHONG_H

#include <bits/stdc++.h>
#include "KhachHang.h" // Bao gồm file KhachHang.h
using namespace std;

class Phong {
private:
    string MaPhong;
    string MaKhachHang; // Thêm thuộc tính mã khách hàng
    string NgayDatPhong; // Ngày đặt phòng
    string NgayTraPhong; // Ngày trả phòng
    string TrangThai;
public:
    Phong();
    Phong(string maKH, string maphong, string ngayDat, string ngayTra, string trangThai);
    
    void nhapthongtin();
    void themphong(vector<Phong>& danhsachPhong, const string& maKhachHang, const string& ngayDat, const string& ngayTra);
    void xuatthongtin(vector<Phong>& danhsachPhong);
    void luudanhsach(const vector<Phong>& danhsachPhong);
    void xoaphong(vector<Phong>& danhsachPhong, const string& MaPhong);
    void suaphong(vector<Phong>& danhsachPhong, const string& MaPhong);
    void timkiemphong(const string& MaPhong);
    void docdanhsach(vector<Phong>& danhsachPhong);
    
    // Getters
    string getMaPhong() const { return MaPhong; }
    string getMaKhachHang() const { return MaKhachHang; }
    string getNgayDatPhong() const { return NgayDatPhong; }
    string getNgayTraPhong() const { return NgayTraPhong; }
    string getTrangThai() const {return TrangThai;}

    // Setters
    void setMaPhong(const string& ma) { MaPhong = ma; }
    void setMaKhachHang(const string& maKH) { MaKhachHang = maKH; }
    void setNgayDatPhong(const string& ngay) { NgayDatPhong = ngay; }
    void setNgayTraPhong(const string& ngay) { NgayTraPhong = ngay; }
    void setTrangThai(const string& trangThai) {TrangThai = trangThai;}
};

#endif