#ifndef QUANLYTHONGBAOMODULES_H
#define QUANLYTHONGBAOMODULES_H

#include<bits/stdc++.h>
#include "QuanLyThongBao.h"

using namespace std;
void QuanLyThongBao() {
    ThongBao tb;
    int luaChonChinh, luaChonPhu;
    do {
        cout << "\n-----Quan Ly Thong Bao-----\n";
        cout << "1.Quan ly thong bao den khach hang\n";
        cout << "2.Quan ly thong bao den nhan vien\n";
        cout << "0.Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChonChinh;
        cin.ignore(); 
        switch (luaChonChinh) {
            case 1: 
                do {
                    cout <<"\n-----Quan Ly Gui Thong Bao Den Khach Hang-----\n";
                    cout <<"1. Gui Phieu Thong Bao Xac Nhan Dat Phong\n";
                    cout <<"2. Gui Thong Bao Dang Danh Gia Khach San\n";
                    cout <<"3. Gui Thong Bao Thanh Toan Hoa Don\n";
                    cout <<"0.Quay lai\n";
                    cout <<"Nhap lua chon cua ban: ";
                    cin >> luaChonPhu;
                    cin.ignore();
                    switch (luaChonPhu) {
                        case 1:  
                            tb.GuiThongBaoDatPhong("logs/Phong.txt", "logs/KhachHang.txt");
							break;
                        case 2:
                            tb.DanhGiaKhachSan("logs/KhachHang.txt");//chỉ lấy mã khách hàng để gửi thông báo  
							break;
                        case 3: 
                            tb.ThongBaoThanhToan("logs/Phong.txt");
                            break;
                        case 0: 
                            cout <<"Thoat chuong trinh." << endl;
							break;
                        default:
                            cout <<"Lua chon khong hop le. Vui long thu lai." << endl;
                    }
                } while (luaChonPhu != 0);
                break;
            case 2:
                do {
                    cout <<"\n---Quan Ly Gui Thong Bao Den Nhan Vien---\n";
                    cout <<"1. Gui Thong Bao Yeu Cau Dich Vu Cua Khach\n";
                    cout <<"2. Gui Thong Bao Lich Kiem Tra Phong\n"; // lấy thông tin từ Phong.txt để lấy thuộc tính ngày trả phòng
                    cout <<"3. Gui Thong Bao Luong Thuong Ca Nhan\n";
                    cout <<"0.Quay lai\n";
                    cout <<"Nhap lua chon cua ban: ";
                    cin >> luaChonPhu;
                    cin.ignore(); // Bỏ qua ký tự newline

                    switch (luaChonPhu) {
                        case 1:
                            tb.ThongBaoDichVuKH("logs/qldichvu.txt", "logs/Phong.txt");
                            break;
                        case 2: 
                            tb.guiThongBaoKiemTraPhong("logs/Phong.txt");
                            break;
                        case 3:
                            tb.GuiThongBaoLuongThuong("logs/NhanVien.txt");
                            break;
                        case 0: 
                            break; // Quay lại
                        default: 
                            cout <<"Lua chon khong hop le. Vui long thu lai." << endl;
                    }
                } while (luaChonPhu != 0);
                break;
            case 0:
                cout <<"Thoat chuong trinh." << endl;
                break;
            default:
                cout <<"Lua chon khong hop le. Vui long thu lai." << endl;
        }
    } while (luaChonChinh != 0);
}
#endif