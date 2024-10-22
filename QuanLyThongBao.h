#ifndef QUANLYTHONGBAO_H
#define QUANLYTHONGBAO_H

#include<bits/stdc++.h>
#include "KhachHang.h"
#include "Phong.h"
using namespace std;

class ThongBao : public KhachHang, public Phong{
private:
    string madatphong, ngaydat, ngaytra; 
public: 
    ThongBao();
    ThongBao(
        string madatphong, string ngaydat,
        string ngaytra, string maphong,
        string loaiphong, string hang,
        string mkh, string tenkh,
        string cmnd, string dob,
        string diachi, string email
    );
    void themthongtin();
    void nhapthongtin();
    void xuatphieu();
    void docthongbao();
    void xoakhachhangquahan();
    void thongBaoTraPhong();
};


#endif