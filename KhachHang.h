#ifndef KHACHHANG_H
#define KHACHHANG_H
#include<bits/stdc++.h>
using namespace std;
class KhachHang{
private:
    string MaKhachHang, Ten, CMND, DoB, DiaChi, Email;
    vector<KhachHang> danhSach;
public:
    KhachHang(); // Constructor
    KhachHang(string MKH, string ten, string cmnd, string ns, string dc, string mail);// Overloaded constructor
    void hienThi(int soThuTu) const;
    void nhapthongtin();
    void luuDanhSachKhachHang(const vector<KhachHang>& danhSach);
    void themkhachhang(vector<KhachHang>& danhSach);
    void timKiemKhachHang(const vector<KhachHang>& danhSach, const string& MKH);
    void suaKhachHang(vector<KhachHang>& danhSach, const string& MKH);
    void docdanhsach(vector<KhachHang>& danhSach);
    void xoakhachhang(vector<KhachHang>& danhSach, const string& MKH);
    //Getter
    string getMaKhachHang() const { return MaKhachHang; }
    string getTen() const { return Ten; }
    string getCMND() const { return CMND; }
    string getDoB() const { return DoB; }
    string getDiaChi() const { return DiaChi; }
    string getEmail() const { return Email; }
    //Setter
    void setMaKhachHang(const string& _MaKhachHang) {MaKhachHang = _MaKhachHang;}
    void setTen(const string& _Ten) {Ten = _Ten;}
    void setCMND(const string& _CMND) {CMND = _CMND;}
    void setDoB(const string& _DoB) {DoB = _DoB;}
    void setDiaChi(const string& _DiaChi) {DiaChi = _DiaChi;}
    void setEmail(const string& _Email) {Email = _Email;}
};

#endif