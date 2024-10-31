#ifndef KHACHHANG_H
#define KHACHHANG_H
#include<bits/stdc++.h>
using namespace std;
class KhachHang {
private:
	string mkh, ten, dob, diaChi, soDienThoai, soCCCD, email;
    vector<KhachHang> danhSach;
public:
    void luuDanhSachKhachHang(const vector<KhachHang>& danhSach);
    void taiDanhSachKhachHang(vector<KhachHang>& danhSach);
    void themKhachHang(vector<KhachHang>& danhSach);
    void hienThiDanhSachKhachHang(const vector<KhachHang>& danhSach);
    void timKiemKhachHang(const vector<KhachHang>& danhSach, const string& Mkh);
    void suaKhachHang(vector<KhachHang>& danhSach, const string& Mkh);
    void xoaKhachHang(vector<KhachHang>& danhSach, const string& Mkh);
    void hienThi(int soThuTu) const {
        cout <<soThuTu <<".Ma khach hang:" << mkh << ", Ten khach hang:" <<ten << ", Ngay Sinh:" << dob << 
		", Dia chi:" <<diaChi <<", SDT:" <<soDienThoai <<", Email:" << email <<", CCCD:" << soCCCD <<endl;
    }
    void setMkh(const string& _mkh){
    	mkh = _mkh;}
	string getMkh() const {
		return mkh;}
    void setTen(const string& _ten){ 
		ten = _ten; }
    string getTen() const { 
		return ten; }
	void setDob(const string& _dob){
		dob = _dob;}
	string getDob() const{
		return dob;}
    void setDiaChi(const string& _diaChi){ 
		diaChi = _diaChi; }
    string getDiaChi() const { 
		return diaChi; }
    void setSoDienThoai(const string& _soDienThoai){ 
		soDienThoai = _soDienThoai; }
    string getSoDienThoai() const{ 
		return soDienThoai; }
    void setEmail(const string& _email){ 
		email = _email; }
    string getEmail() const{ 
		return email; }
    void setSoCCCD(const string& _soCCCD) { 
		soCCCD = _soCCCD; }
    string getSoCCCD() const { 
		return soCCCD; }
};

#endif