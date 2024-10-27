#ifndef QUANLYTHONGBAO_H
#define QUANLYTHONGBAO_H

#include<bits/stdc++.h>
using namespace std;

class ThongBao {
public:
    // Thông báo đăt phòng
    void GuiThongBaoDatPhong(const string &filePhong, const string &fileKhachHang);
    //thông báo đánh giá phòng
    void DanhGiaKhachSan(const string &fileKhachHang);
    //Thông báo thanh toán
    void ThongBaoThanhToan(const string &filePhong);
    //Thông Báo Dịch vụ(nhân viên)
    void ThongBaoDichVuKH(const string &filedichvu, const string &filephong);
    //Thông báo kiểm tra phòng(nhân viên)
    void guiThongBaoKiemTraPhong(const string &filePhong);
    //thông báo lương cho nv
    void GuiThongBaoLuongThuong(const string &fileNhanVien);

private:
    vector<string> noidungthongbao; // Lưu trữ thông báo đã gửi
    void saveNotification(const string &message); // Lưu thông báo vào file
};

#endif