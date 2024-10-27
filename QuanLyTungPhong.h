#ifndef QUANLYTUNGPHONG_H
#define QUANLYTUNGPHONG_H

#include <bits/stdc++.h>
using namespace std;

// Khai báo lớp PhongKS
class PhongKS {
public:
    string soPhong;      
    string DichVuPhongSD;  
    string trangThai;  
    string GhiChu; 

    PhongKS() {}
    PhongKS(string so, string dichVu, string tt, string ghiChu)
        : soPhong(so), DichVuPhongSD(dichVu), trangThai(tt), GhiChu(ghiChu) {}

    void hienThiThongTin() {
        cout << "So phong: " << soPhong << endl;
        cout << "Dich vu phong da su dung: " << DichVuPhongSD << endl;
        cout << "Trang thai: " << trangThai << endl;
        cout << "Ghi chu: " << GhiChu << endl;
        cout << "--------------------------" << endl;
    }
};

class TungPhong {
public: 
    void themPhong(PhongKS danhSach[], int &soLuong);
    void xoaPhong(PhongKS danhSach[], int &soLuong, string soPhongCanXoa);
    void suaPhong(PhongKS danhSach[], int soLuong, string soPhongCanSua);
    void xemDanhSachPhong(PhongKS danhSach[], int soLuong);
    void luuDanhSachPhong(PhongKS danhSach[], int soLuong);
    void docDanhSachPhong(PhongKS danhSach[], int &soLuong);
    void timKiemPhong(PhongKS danhSach[], int soLuong);
};

#endif