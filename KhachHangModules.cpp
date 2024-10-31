#include<bits/stdc++.h>
#include "KhachHang.h"

using namespace std;

// void KhachHang::luuDanhSachKhachHang(const vector<KhachHang>& danhSach) {
//     ofstream file("logs/KhachHang.txt");
//     if (!file) {
//         cerr << "Khong the mo tep de luu du lieu." << endl;
//         return;
//     }
//     for (const auto& kh : danhSach) {
//         file <<kh.getMkh() <<"," <<kh.getTen() << "," << kh.getDob() << "," <<kh.getDiaChi() 
// 		<< "," <<kh.getSoDienThoai() << "," <<kh.getEmail() << "," <<kh.getSoCCCD() <<endl;
//     }
//     file.close(); 
// }
void KhachHang::luuDanhSachKhachHang(const vector<KhachHang>& danhSach) {
    ofstream file("logs/KhachHang.txt");
    if (!file) {
        cerr << "Khong the mo tep de luu du lieu." << endl;
        return;
    }

    for (const auto& kh : danhSach) {
        // Kiểm tra và tạo chuỗi thông tin
        string line;
        if (!kh.getMkh().empty()) line += kh.getMkh() + ",";
        if (!kh.getTen().empty()) line += kh.getTen() + ",";
        if (!kh.getDob().empty()) line += kh.getDob() + ",";
        if (!kh.getDiaChi().empty()) line += kh.getDiaChi() + ",";
        if (!kh.getSoDienThoai().empty()) line += kh.getSoDienThoai() + ",";
        if (!kh.getEmail().empty()) line += kh.getEmail() + ",";
        if (!kh.getSoCCCD().empty()) line += kh.getSoCCCD();

        // Kiểm tra xem dòng có dữ liệu không trước khi ghi
        if (!line.empty() && line.back() == ',') {
            line.pop_back(); // Xóa dấu phẩy cuối nếu có
        }

        if (!line.empty()) {
            file << line << endl; // Ghi vào file
        }
    }

    file.close(); 
}

// hàm t?i danh sách khách hàng t? t?p khachhang.txt
void KhachHang::taiDanhSachKhachHang(vector<KhachHang>& danhSach) {
    ifstream file("logs/KhachHang.txt");
    if (!file) {
        cerr << "Khong the mo tep de tai du lieu." << endl;
        return;
    }
    KhachHang kh;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
		
		getline(ss, temp, ',');
        kh.setMkh(temp);
        getline(ss, temp, ',');
        kh.setTen(temp);
        getline(ss, temp, ',');
        kh.setDob(temp);
        getline(ss, temp, ',');
        kh.setDiaChi(temp);
        getline(ss, temp, ',');
        kh.setSoDienThoai(temp);
        getline(ss, temp, ',');
        kh.setEmail(temp);
        getline(ss, temp);
        kh.setSoCCCD(temp);

        danhSach.push_back(kh);
    }
    file.close(); 
}

// hàm thêm khách hàng vào dang sách
void KhachHang::themKhachHang(vector<KhachHang>& danhSach) {
    KhachHang kh;
    string temp;
    
    cout << "Nhap ma khach hang:";
    cin.ignore();
    getline(cin,temp);
    kh.setMkh(temp);
    cout << "Nhap ten khach hang:";
    getline(cin, temp);
    kh.setTen(temp);
    cout << "Nhap ngay sinh:";
    getline(cin, temp);
    kh.setDob(temp);
    cout << "Nhap dia chi:";
    getline(cin, temp);
    kh.setDiaChi(temp);
    cout << "Nhap so dien thoai:";
    getline(cin, temp);
    kh.setSoDienThoai(temp);
    cout << "Nhap email:";
    getline(cin, temp);
    kh.setEmail(temp);
    cout << "Nhap so CCCD:";
    getline(cin, temp);
    kh.setSoCCCD(temp);
    
	danhSach.push_back(kh);
    luuDanhSachKhachHang(danhSach);
}

// hàm hiển thị danh sách khách hàng 
void KhachHang::hienThiDanhSachKhachHang(const vector<KhachHang>& danhSach) {
    if (danhSach.empty()) {
        cout << "Danh sach khach hang trong." << endl;
        return;
    }
    for (size_t i = 0; i < danhSach.size(); i++) {
        danhSach[i].hienThi(i + 1);
    }
}

// hàm t?m ki?m khách hàng theo ma khach hang
void KhachHang::timKiemKhachHang(const vector<KhachHang>& danhSach, const string& Mkh) {
    for (size_t i = 0; i < danhSach.size(); i++) {
        if (danhSach[i].getMkh() == Mkh) {
            danhSach[i].hienThi(i + 1);
            return;
        }
    }
    cout << "Khong tim thay khach hang co ma khach hang:" << Mkh << endl;
}

// hàm s?a thông tin khách hàng theo m? khách hàng 
void KhachHang::suaKhachHang(vector<KhachHang>& danhSach, const string& Mkh) {
    for (auto& kh : danhSach) {
        if (kh.getMkh() == Mkh) {
            string temp;
            
            cout << "Nhap thong tin moi cho khach hang co ma khach hang " << kh.getMkh() << ":" << endl;
            cout << "Ma khach hang:";
            getline(cin,temp);
            kh.setMkh(temp);
            cout << "Ten khach hang:";
            getline(cin, temp);
            kh.setTen(temp);
            cout << "Nhap ngay sinh:";
            getline(cin, temp);
            kh.setDob(temp);
            cout << "Dia chi:";
            getline(cin, temp);
            kh.setDiaChi(temp);
            cout << "So dien thoai:";
            getline(cin, temp);
            kh.setSoDienThoai(temp);
            cout << "Email:";
            getline(cin, temp);
            kh.setEmail(temp);
            cout << "So CCCD:";
            getline(cin, temp);
            kh.setSoCCCD(temp); 
            luuDanhSachKhachHang(danhSach);
            return;
        }
    }
    cout << "Khong tim thay khach hang co ma khach hang:" << Mkh << endl;
}

// hàm xóa khách hàng theo ma khách hàng
void KhachHang::xoaKhachHang(vector<KhachHang>& danhSach, const string& Mkh) {
    for (size_t i = 0; i < danhSach.size(); ++i) {
        if (danhSach[i].getMkh() == Mkh) {
            danhSach.erase(danhSach.begin() + i);
            luuDanhSachKhachHang(danhSach);
            cout << "Da xoa khach hang co ma khach hang:" << danhSach[i].getMkh() << endl;
            return;
        }
    }
    cout << "Khong tim thay khach hang co ma khach hang:" << Mkh << endl;
}