#ifndef PHONG_H
#define PHONG_H

#include<bits/stdc++.h>
using namespace std;

class Phong {
private: 
    string MaPhong, LoaiPhong, Hang;
    vector<Phong> danhsachPhong;
public:
    Phong();
    Phong(string Ma, string loai, string hang);
    void nhapthongtin();
    void xuatthongtin(vector<Phong>& danhsachPhong);
    void luudanhsach(const vector<Phong>& danhsachPhong);
    void themphong(vector<Phong>& danhsachPhong);
    void xoaphong(vector<Phong>& danhsachPhong, const string& MaPhong);
    void suaphong(vector<Phong>& danhsachPhong, const string& MaPhong);
    void timkiemphong(const string& MaPhong);
    void docdanhsach();
    // Getter
    string getMaPhong() const { return MaPhong; }
    string getLoaiPhong() const { return LoaiPhong; }
    string getHang() const { return Hang; }  
    // Setter
    void setMaPhong(const string& ma) { MaPhong = ma; }
    void setLoaiPhong(const string& loai) { LoaiPhong = loai; }
    void setHang(const string& hang) { Hang = hang; } 
};


#endif