#ifndef QUANLYPHONGKHACHSAN_H
#define QUANLYPHONGKHACHSAN_H

#include<bits/stdc++.h>
using namespace std;

class qlPhong {
public:
    string IDPhong;       // Thay doi thanh kieu string
    string loaiPhong;  
    string TrangThai;  
    double giaPhong;   
    qlPhong() {}   
    qlPhong(string so, string loai, string tt, double gia) 
        : IDPhong(so), loaiPhong(loai), TrangThai(tt), giaPhong(gia){}
    void hienThiThongTin() {
        cout << "So phong: " << IDPhong << endl;
        cout << "Loai phong: " << loaiPhong << endl;
        cout << "Trang thai: " << TrangThai << endl;
        cout << "Gia phong: " << giaPhong << " VND" << endl;
        cout << "--------------------------" << endl;
    }
};

class qlTungPhong {
public:
    void themPhong(qlPhong danhSach[], int &soLuong);
    void xoaPhong(qlPhong danhSach[], int &soLuong, string soPhongCanXoa);
    void suaPhong(qlPhong danhSach[], int soLuong, string soPhongCanSua);
    void xemDanhSachPhong(qlPhong danhSach[], int soLuong);
    void luuDanhSachPhong(qlPhong danhSach[], int soLuong);
    void docDanhSachPhong(qlPhong danhSach[], int &soLuong);
    void timKiemPhong(qlPhong danhSach[], int soLuong);
};

#endif